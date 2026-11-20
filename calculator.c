#include "functions.h"

int main(long userArrayLen, char *userArray[])
{
	//Проверяем правильность ввода
        if (checkInput( &userArrayLen, userArray ) )
        {
        	//Массив результатов выражений
		long long resultArray[userArrayLen / 3 - 1];
		//Заполняем массив
		fillingAnswerArray(resultArray, userArray, &userArrayLen);
		//Взятие ключа
		long key = strtoll(userArray[userArrayLen - 1], NULL, 10);
		outputAndDecoding(resultArray, key, userArrayLen / 3 - 1);
	}
	return 0;
}
     
