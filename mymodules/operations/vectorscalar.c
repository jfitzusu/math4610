#pragma once
#include <stdlib.h>

double * vectorScalar(double* v, double scalar, int s1) {
    double* result = (double*)malloc(s1 * sizeof(double));
    for (int i = 0; i < s1; i++) {
        result[i] = scalar * v[i];
    }

    return result;
}