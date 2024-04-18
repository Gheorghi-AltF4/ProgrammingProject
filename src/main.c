#include <stdio.h>
#include <string.h>
#include "fileIO/fileIO.h"
#include "accounts/accounts.h"

void handle_input_error()
{
    printf("Invalid input provided!\n");
}

void print_menu()
{
    printf("\n 1 = Create Account \n 2 = View Account \n 3 = Delete Account \n 4 = Edit Account \n 5 = Perform Transaction \n 0 = Exit \n");
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1],"login") != 0)
    {
        printf("Invalid arguments!\n");
        printf("usage: PP login [NAME] [SURNAME]");
        return 1;
    }
    printf("Hello, %s %s!\n", argv[2], argv[3]);
    char name[MAX_NAME_LENGTH];
    strcpy(name,argv[2]);
    strcat(name,argv[3]);
    printf("%s",name);
    account_t *accounts;
    int size;
    accounts = initialize_db(&size);
    while (1)
    {
        print_menu();
        int input;
        scanf("%d",&input);
        if (input == 1) {
            currency_t input_currency;
            printf("Choose a currency: RON = 0, EUR = 1, USD = 2\n");
            if (scanf("%d", &input_currency) == 0 || input_currency >= 3)
            {
                handle_input_error();
                continue;
            }
            create_account(name, input_currency, &size, &accounts);
            printf("Created new account with IBAN: %s\n", accounts[size - 1].IBAN);
        }
        else if (input == 2)
        {
            view_accounts(name, &size, accounts);
        }
        else if (input == 3)
        {
            char iban[40];
            printf("Provide an IBAN:\n");
            if (scanf("%40s", iban) == 0 || strlen(iban) != 24)
            {
                handle_input_error();
                continue;
            }
            delete_account(name, iban, &size, accounts);
        }
        else if (input == 4)
             {
                 char iban[40];
                 printf("Provide an IBAN:\n");
                 if (scanf("%40s", iban) == 0 || strlen(iban) != 24)
                 {
                     handle_input_error();
                     continue;
                 }
                 int amount;
                 printf("Provide an amount:\n");
                 if (scanf("%d", &amount) == 0 || amount <= 0)
                 {
                     handle_input_error();
                     continue;
                 }
                 currency_t input_currency;
                 printf("Choose a currency: RON = 0, EUR = 1, USD = 2\n");
                 if (scanf("%d", &input_currency) == 0 || input_currency >= 3)
                 {
                     handle_input_error();
                     continue;
                 }
                 edit_account(name,iban,amount,input_currency,size,accounts);
             }
            // if (input == 5) {
            //     perform_transaction(IBAN_src,IBAN_dst,amount,name,&size,accounts);
            // }
        else if (input == 0)
        {
            printf("Goodbye!...\n");
            break;
        }
        else
        {
            handle_input_error();
        }
    }
    // delete_account("Claudiu", "5678", &size, accounts);
    dump_db(accounts, size);
    return 0;
}