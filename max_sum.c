#include "func_math_and_err.h"
#include <stdio.h>

int find_max_sum(FILE *file_input, double *result) {
    double prev, curr, next;
    double sum = 0.0;
    int count = 0;
    int num_count = 0;

    if (file_input == NULL || result == NULL) {
        return ERR_READ;
    }

    if (fscanf(file_input, "%lf", &prev) != 1) {
        if (feof(file_input)) return ERR_EMPTY;
        return ERR_INVALID;
    }
    num_count++;
    
    if (fscanf(file_input, "%lf", &curr) != 1) {
        if (feof(file_input)) {
            *result = 0.0;
            return OK;
        }
        return ERR_INVALID;
    }
    num_count++;

    while (fscanf(file_input, "%lf", &next) == 1) {
        num_count++;
        if ((curr > prev && curr > next) || (curr < prev && curr < next)) {
            sum += curr;
            count++;
        }
        prev = curr;
        curr = next;
    }

    if (ferror(file_input)) {
        return ERR_READ;
    }
    if (!feof(file_input)) {
        return ERR_INVALID;
    }

    if (count == 0) {
        *result = 0.0;
    } else {
        *result = sum / count;
    }
    
    return OK;
}