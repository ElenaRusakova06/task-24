#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

/*Коды ошибок*/
#define OK 0
#define ERR_EMPTY -1
#define ERR_INVALID -2
#define ERR_READ -3

/*
** находит среднее арифметическое локальных экстремумов
** (максимумов и минимумов) последовательности
**
** Аргументы:
**  file_input - указатель на открытый файл для чтения
**  result - указатель, куда записать найденное значение
** Возвращает: 
** OK - всё супер, результат в *result
** ERR_EMPTY - если файл пустой
** ERR_INVALID - в файле есть недопустимый символ
** ERR_READ - ошибка при чтении файла
*/
int find_max_sum(FILE *file_input, double *result);


/*
** Печатает ошибки
**
** Аргументы:
** code - код ошибки - берется из find_max_sum(..)
** 
** Выводит текстовые сообщения об ошибках
*/
void print_error(int code);

#endif