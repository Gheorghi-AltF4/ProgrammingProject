//
// Created by Andrei-Claudiu Gheorghiță on 18.03.2024.
//

#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "accounts.h"
#include <time.h>
char* currencies[] = {"RON", "EUR", "USD"};

void generate_IBAN(char *destination)
{
    srand(time(NULL));
    int upper_bound = 99;
    int value1 = rand() % (upper_bound + 1);
    upper_bound = 999999;
    int value2 = rand() % (upper_bound + 1);
    upper_bound = 99999999;
    int value3 = rand() % (upper_bound + 1);
    sprintf(destination,"RO%02dRNCB%06d%08d", value1, value2, value3);
}

void create_account(char *name, currency_t coin, int *size, account_t **accounts){
    //account_t *accounts = malloc(sizeof(account_t) * MAX_NUM);
    (*size) ++;
    *accounts = realloc(*accounts,(*size) * (sizeof(account_t)));
    account_t local;
    generate_IBAN(local.IBAN);
    local.coin = coin;
    strcpy(local.owner,name);
    local.amount = 0;
    memcpy(&(*accounts)[(*size) -1], &local, sizeof(account_t));
}

void print_account(account_t account){
    printf("%s,%s,%s,%d\n",account.IBAN,account.owner,currencies[account.coin],account.amount);
}

void view_accounts(char *name, int *size, account_t *accounts){
    for (int i = 0; i < *size; ++i) {
        if (strcmp(name,accounts[i].owner) == 0)
        {
            print_account(accounts[i]);
        }
    }
}

void delete_account(char *name, char *IBAN, int *size, account_t *accounts){
    for (int i = 0; i < *size; ++i) {
        if (strcmp(IBAN,accounts[i].IBAN) == 0)
        {
            if (strcmp(name,accounts[i].owner) == 0)
            {
                accounts[i] = accounts[*size - 1];
            }
        }
    }
    size--;
}

void edit_account(char *name, char *IBAN, int *amount, currency_t *coin, int size, account_t *accounts){
    for (int i = 0; i < size; ++i) {
        if (strcmp(name,accounts[i].owner) == 0)
        {
            if (strcmp(IBAN,accounts[i].IBAN) == 0)
            {
                accounts[i].amount = *amount;
                accounts[i].coin = *coin;
            }
        }
    }
}

void perform_transaction(char *IBAN_src, char *IBAN_dst, int amount, char *name, int *size, account_t *accounts){
    int index_src = -1, index_dst = -1; //nu valoare random
    for (int i = 0; i < *size; ++i) {
        if (strcmp(name,accounts[i].owner) == 0)
        {
            if (strcmp(IBAN_src,accounts[i].IBAN) == 0)
            {
                index_src = i;

            }
        }
        if (strcmp(accounts[i].IBAN,IBAN_dst) == 0)
        {
            index_dst = i;
        }
    }
    if (index_dst != -1 && index_src != -1)
    {
        accounts[index_src].amount -= amount;
        accounts[index_dst].amount += amount;
    }
}

/*
 * typedef enum{
E_ACCOUNT_NOT_FOUND,
E_INSUFFICIENT_FUNDS,
E_UNAUTHORIZED_OPERATION
E_INTERNAL_ERROR
E_OK} error_t
 */