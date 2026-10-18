#include <stdio.h>
#include "func_math_and_err.h"

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

/*коды ошибок на выход из файла*/
#define EXIT_OPEN_ERROR   1
#define EXIT_DATA_ERROR   2
#define EXIT_WRITE_ERROR  3

void print_error(int code);

/*вывод ошибки*/
void print_error(int code) {
    if (code == ERR_EMPTY) {
        fprintf(stderr, "файл %s пуст\n", INPUT_FILE);
    } 
    else if (code == ERR_INVALID) {
        fprintf(stderr, "в файле %s недопустимые символы\n", INPUT_FILE);
    }
    else if (code == ERR_READ) {
        fprintf(stderr, "не удалось прочитать файл %s\n", INPUT_FILE);
    }
    else {
        fprintf(stderr, "неизвестная ошибка: код %d\n", code);
    }
}

int main(void) {
    FILE *file_input;
    FILE *file_output;
    double result = 0.0;
    int return_func;

    file_input = fopen(INPUT_FILE, "r");
    if (file_input == NULL) {
        fprintf(stderr, "не удалось открыть файл %s.\n", INPUT_FILE);
        return EXIT_OPEN_ERROR;
    }

    return_func = find_max_sum(file_input, &result);
    
    fclose(file_input);

    if (return_func != OK) {
        print_error(return_func);
        return EXIT_DATA_ERROR;
    }

    file_output = fopen(OUTPUT_FILE, "w");
    if (file_output == NULL) {
        fprintf(stderr, "не удалось создать файл %s.\n", OUTPUT_FILE);
        return EXIT_WRITE_ERROR;
    }

    fprintf(file_output, "%.10g\n", result);
    fclose(file_output);

    return 0;
}