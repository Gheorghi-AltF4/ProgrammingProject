//
// Created by Andrei-Claudiu Gheorghiță on 18.03.2024.
//

#include <stdlib.h>
#include "accounts.h"
#include "fileIO.h"
#define FILENAME "Data.csv"
#define MAX_LENGTH_LINE 256


int count_lines(FILE *f)
{
    int counter = 0; //pentru header ar trebui sa scadem 1
    while (!feof(f))
    {
        char c = fgetc(f);
        if (c == '\n')
            counter++;
    }
    rewind(f);
    return counter+1;
}

void ignore_line(FILE*f)
{
    char empty[MAX_LENGTH_LINE+1];
    fgets(empty, MAX_LENGTH_LINE, f);
}

account_t next_line(FILE*f)
{
    account_t t;
    char line[MAX_LENGTH_LINE+1]; //pt terminator de sir
    fgets(line, MAX_LENGTH_LINE, f);
    char *pch;
    pch = strtok (line,",");
    for (int i = 1; pch != NULL; ++i)
    {
        if (i==1)
            strcpy(t.IBAN,pch);
        if (i==2)
            strcpy(t.owner,pch);
        if (i==4)
            t.amount = atoi(pch);
        if (i==3)
            if (strcmp(pch,"RON") == 0)
                t.coin = RON;
        if (strcmp(pch,"EUR") == 0)
            t.coin = EUR;
        if (strcmp(pch,"USD") == 0)
            t.coin = USD;
        pch = strtok (NULL, ",");
    }
    return t;
}

account_t *initialize_db(int *size)
{
    FILE * f;
    f = openFile(FILENAME,"r");
    *size = count_lines(f) - 1;
    account_t *accounts =(account_t*)(malloc(*size *(sizeof(account_t))));
    ignore_line(f);
    for (int i = 0; i < *size; ++i) {
        accounts[i] = next_line(f);
    }
    return accounts;
}

void dump_db(account_t *accounts, int size){
    FILE* file = openFile(FILENAME,"w");
    fprintf(file,"IBAN,owner,coin,amount\n");
    for (int i = 0; i < size; ++i) {
        fprintf(file,"%s,%s,%s,%d\n",accounts[i].IBAN,accounts[i].owner,currencies[accounts[i].coin],accounts[i].amount);
    }
}

void readFromFile(int* output)
{
    FILE* file = openFile(FILENAME,"r");

    if (file == NULL)
        return;

    fscanf(file, "%d", output);
    fclose(file);
}

void readFromCSV()
{
    FILE* file = openFile(FILENAME,"r");

    if (file == NULL)
        return;

    char header[200];
    char data[200];

    char* col_data;
    char* next_col;

    fgets(header, 200, file);


    while (!feof(file))
    {
        fgets(data, 200, file);
        col_data = strtok(data, ",");

        while (col_data != NULL)
        {
            printf("I have read %s\n", col_data);
            col_data = strtok(NULL, ",");
        }
    }
}

void writeToFile(const char* message)
{
    if (message == NULL || strlen(message) == 0)
        return;

    FILE* file = openFile(FILENAME,"w");

    if (file == NULL)
        return;

    fprintf(file, "%s", message);
    fclose(file);
}

FILE* openFile(const char* filePath, const char* mode)
{
    // IF GUARD
    if (filePath == NULL || strlen(filePath) == 0 ||
        mode == NULL || strlen(mode) == 0)
        return NULL;

    FILE* file = NULL;

    file = fopen(filePath, mode);

    return file;
}