#include <stdlib.h>

double * vectorAdd(double* v1, double* v2, int s1) {
    double* result = (double*)malloc(s1 * sizeof(double));
    for (int i = 0; i < s1; i++) {
        result[i] =  v1[i] + v2[i];
    }

    return result;
}