#pragma once
#include <stdlib.h>

double * laction(double** matrix, double* vector, int s1, int s2) {
    double* result = (double*)malloc(s1 * sizeof(double));
    for (int i = 0; i < s1; i++) {
        result[i] = 0;
        for (int j = 0; j < i; j++) {
            result[i] += matrix[i][j] * vector[j];
        }

    }

    return result;
}