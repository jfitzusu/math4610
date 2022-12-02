#include <omp.h>
#include <stdlib.h>

double ** outerProduct(double* vector1, double* vector2, double size1, double size2, double* time) {
    double** result = (double**)malloc(size1 * sizeof(double*));
    for (int i = 0; i < size1; i++) {
        result[i] = (double*)malloc(size2 * sizeof(double));
    }

    double startTime = omp_get_wtime();
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[i][j] = vector1[i] * vector2[j];
        }
    }

    *time = omp_get_wtime() - startTime;
    return result;
}