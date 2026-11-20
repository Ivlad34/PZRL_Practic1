#include "functions.h"

//Эта функция принимает длинну массива и массив строк, после чего в нем проводятся
//проверки на правильность ввода  и возвращает 1 при правильности ввода 
int checkInput(long long *userLeight, char *userArray[])
{
	//Проверка на не нулеввой ввод
        if (*userLeight == 1 )
        {
                printf("Ошибка ввода: недостаточное количество входных данных\n");
                return 0;
        }
        int countInputOperator = 0;//Будет считать количество операторов в массиве строк
        for (long indexArray = 1; indexArray < (*userLeight - 3); ++indexArray)
        {
		//Проверка, является ли эта строка числом
                if ( (strtoll(userArray[indexArray], NULL, 10) || *userArray[indexArray] == '0') )
                {
			//Проверка на наличие в числе точку
                        if ( strchr(userArray[indexArray], '.') != NULL )
                        {
                                printf("Ошибка ввода: введено не целое число %c\n", lastSymbol);
                                return 0;
                        }
                }
		//Проверка являются ли две строки подряд числами
                else if ( (strtoll(userArray[indexArray], NULL, 10) || *userArray[indexArray] == '0') &&
                                (strtoll(userArray[indexArray+1], NULL, 10) || *userArray[indexArray+1] == '0'))
                {
			//Исключает случай, где число является концом выражение, а следующее число - начало нового
                        if ( (indexArray % 3) )
                        {
                                printf("Ошибка ввода: ввод нескольких операндов подряд\n");
                                return 0;
                        }
                }
                //Проверка на два идущих подряд операторы
                else if ( !strtoll(userArray[indexArray], NULL, 10) && *userArray[indexArray] != '0' &&
                                !strtoll(userArray[indexArray + 1], NULL, 10) && *userArray[indexArray + 1] != '0')
                {
                        printf("Ошибка ввода: ввод нескольких операторов подряд\n");
                        return 0;
                }
                //Проверка, что введено не отрицательное число и что это неправильный флаг
                else if ( strlen(userArray[indexArray]) > 1 && userArray[indexArray][0] == '-' &&
                                !strtoll(userArray[indexArray], NULL, 10))
                {
                        printf("Ошибка ввода: количество флагов больше требуемого или введен не кл\n");
                        return 0;
                }

                //Проврка на оператора, с последующим увеличением учета их количества
                if ( !strtoll(userArray[indexArray], NULL, 10) && *userArray[indexArray] != '0' )
                {
                        ++countInputOperator;
                }
        }

        //Проверка на стоящий в конце массива флаг, в таком случае после него нет ключа
        if ( !strcmp(userArray[*userLeight - 1], "-k") )
        {
                printf("Ошибка ввода: отсутствие ключа\n");
                return 0;
        }
        //Проверка на наличие предпоследним эллементом в массиве нужного флага
        else if ( strcmp(userArray[*userLeight - 2], "-k") )
        {
                printf("Ошибка ввода: введен неверный флаг или он невведен вовсе\n");
                return 0;
        }
	 //Проверка на значение ключа, чтобы он был long
        else if ( !strtoll(userArray[*userLeight - 1], NULL, 10) && *userArray[*userLeight - 1] != '0' )
        {
                printf("Ошибка ввода: введено недопустимое значение ключа\n");
                return 0;
        }
        //Проверка количества операторов с нужным количеством, так как при правильном вводе 
        //операторы должны занимать 1/3 от всех строк в массиве
        else if ( countInputOperator != (*userLeight - 3) / 3)
        {
                printf("Ошибка ввода: введены неполные вырожения\n");
                return 0;
        }

        return 1;
}


//Данная функция принимает 2 операнда и оператор, после чего возвращает значение выражение
long long mathOperations( long long *leftOperand, long long *rightOperand, char *operator )
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
void fillingAnswerArray(long long *resultArray, char *userArray[], long *userLeightArray)
{
        for(int indexArray = 1; indexArray < (*userLeightArray - 2); indexArray += 3)
        {
                long leftOperand = strtollong(userArray[indexArray], NULL, 10);
                long rightOperand = strtoll(userArray[indexArray + 2], NULL, 10);
                resultArray[indexArray/3] = mathOperations(&leftOperand, &rightOperand, userArray[indexArray+1]);
        }
}



//Данный массив получает массив, содержащий ответы на написанные пользователем выражения,
//ключ дешефрирования и длинну массива
void outputAndDecoding( long long *arrayAnswer, long long key, long long  leightArray)
{
        //Вывод получившихся результатов и вычитание значения ключа
        for ( long indexArray = 0; indexArray < leightArray ; ++indexArray )
        {
                printf("Ответ №%d: %ld \n", indexArray + 1, arrayAnswer[indexArray]);
                arrayAnswer[indexArray] -= key;
        }

        //Перевод массива в строку и последующий вывод результирующей строки
        char resultString[leightArray + 1];
        for ( long indexArray = 0; indexArray < leightArray; ++indexArray )
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
