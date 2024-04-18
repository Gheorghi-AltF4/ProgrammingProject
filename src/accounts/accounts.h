//
// Created by Andrei-Claudiu Gheorghiță on 16.03.2024.
//

#ifndef PP_ACCOUNTS_H
#define PP_ACCOUNTS_H

#define MAX_NAME_LENGTH 128
#define MAX_NUM 5

typedef enum{
    RON, EUR, USD
}currency_t;

extern char *currencies[]; //garanteaza ca va exista un simbol de linkuit

typedef struct{
    char IBAN[35];
    char owner[MAX_NAME_LENGTH];
    currency_t coin;
    int amount;
}account_t;

void create_account(char  *name, currency_t coin, int *size, account_t **accounts);

void print_account(account_t account);
void view_accounts(char *name, int *size, account_t *accounts);

void delete_account(char *name, char  *IBAN, int *size, account_t *accounts);

void edit_account(char  *name, char *IBAN, int amount, currency_t coin, int size, account_t *accounts);

void perform_transaction(char *IBAN_src, char *IBAN_dst, int amount, char *name, int *size, account_t *accounts);
#endif //PP_ACCOUNTS_H
