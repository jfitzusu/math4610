#include <stdlib.h>
double * action(double** matrix, double* vector, int s1, int s2) {
    double* result = (double*)malloc(s1 * sizeof(double));
    for (int i = 0; i < s1; i++) {
        result[i] = vectorDot(matrix[i], vector, s1);
    }

    return result;
}