#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int mathOperations(long *leftOperand, long *rightOperand, char *operator);
int checkInput(int *userLeight, char *userArray[]);
void fillingAnswerArray(long *resultArray, char *userArray[], int *userLeightArray);
void outputAndDecoding(long *arrayAnswer, long key, int leightArray);

#endif

