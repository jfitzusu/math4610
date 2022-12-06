#pragma once
#include <math.h>
#include <stdlib.h>

double norm(double* v, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += v[i] * v[i];
    }

    return sqrt(result);
}