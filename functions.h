#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

long mathOperations(long *leftOperand, long *rightOperand, char *operator);
int checkInput(long long *userLeight, char *userArray[]);
void fillingAnswerArray(long long *resultArray, char *userArray[], long long *userLeightArray);
void outputAndDecoding(long long *arrayAnswer, long long key, long long leightArray);

#endif

