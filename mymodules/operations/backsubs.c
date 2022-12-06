#pragma once
#include <stdlib.h>

double * backSubs(double** matrix, double* vector, int s1, int s2) {
    double* result = (double*)malloc(s1 * sizeof(double));
    for (int i = s1 - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < s1; j++) {
            sum += matrix[i][j] * result[j];
        }
        result[i] = (vector[i] - sum) / matrix[i][i]; 
    }

    return result;
}