//
// Created by Andrei-Claudiu Gheorghiță on 18.03.2024.
//

#ifndef PP_FILEIO_H
#define PP_FILEIO_H


#pragma once

#include <stdio.h>
#include <string.h>
#include "../accounts/accounts.h"

account_t *initialize_db(int *size);
void dump_db(account_t *accounts, int size);

void readFromCSV();
void readFromFile(int * output);

void writeToFile(const char *message);
FILE* openFile(const char* filePath, const char *mode);

#endif //PP_FILEIO_H
