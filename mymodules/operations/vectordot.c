#include <stdlib.h>

double vectorDot(double* v1, double* v2, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }

    return result;
}