#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Данная функция принимает 2 операнда и оператор, после чего возвращает значение выражение
int mathOperations( long *leftOperand, long *rightOperand, char *operator )
{
        switch( *operator)
        {
                case '+':
                        return *leftOperand + *rightOperand;
                case '-':
                        return *leftOperand - *rightOperand;
                case '*':
                        return *leftOperand * *rightOperand;
                case '%':
                        if ( *rightOperand == 0)
                        {
                                printf("Ошибка ввода: несуществует остатка от деления на 0\n");
                                exit(EXIT_FAILURE);
                        }
                        return *leftOperand % *rightOperand;
                default:
                        printf("Ошибка ввода: недоспустимый оператор\n");
                        exit(EXIT_FAILURE);
        }
}

//Перевод массива строк в массив long, в котором будет лежать значения выражений
void fillingAnswerArray(long *resultArray, char *userArray[], int *userLeightArray)
{
        for(int indexArray = 1; indexArray < (*userLeightArray - 2); indexArray += 3)
        {
                long leftOperand = strtol(userArray[indexArray], NULL, 10);
                long rightOperand = strtol(userArray[indexArray + 2], NULL, 10);
                resultArray[indexArray/3] = mathOperations(&leftOperand, &rightOperand, userArray[indexArray+1]);
        }
}



//Данный массив получает массив, содержащий ответы на написанные пользователем выражения,
//ключ дешефрирования и длинну массива
void outputAndDecoding( long *arrayAnswer, long key, int leightArray)
{
        //Вывод получившихся результатов и вычитание значения ключа
        for ( int indexArray = 0; indexArray < leightArray ; ++indexArray )
        {
                printf("Ответ №%d: %ld \n", indexArray + 1, arrayAnswer[indexArray]);
                arrayAnswer[indexArray] -= key;
        }

        //Перевод массива в строку и последующий вывод результирующей строки
        char resultString[leightArray + 1];
        for ( int indexArray = 0; indexArray < leightArray; ++indexArray )
        {
                //Проверка на отрицательные числа, так как при переводе отрицателных чисел по таблице
                //ASCII будет некоректный перевод
                if ( arrayAnswer[indexArray] > -1 )
                {
                        resultString[indexArray] = (char)arrayAnswer[indexArray];
                }
                else
                {
                        printf("Ошибка вычисления: невозможен корректный перевод отрицательно числа по таблице ASCII\n");
                        exit(EXIT_FAILURE);
                }
        }

        //Добавлям \0 для корректного вывода строки
        resultString[leightArray] = '\0';
        printf("Результирующая строка: %s \n", resultString);
}


int main(int userArrayLen, char *userArray[])
{
        //Массив результатов выражений
	long resultArray[userArrayLen / 3 - 1];
	//Заполняем массив
	fillingAnswerArray(resultArray, userArray, &userArrayLen);
	//Взятие ключа
	long key = strtol(userArray[userArrayLen - 1], NULL, 10);
	outputAndDecoding(resultArray, key, userArrayLen / 3 - 1);
	return 0;
}
     
