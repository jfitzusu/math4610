#include <omp.h>
#include <stdlib.h>

double * vectorHadamard(double* vector1, double* vector2, double size, double* time) {
    double* result = (double*)malloc(size * sizeof(double));
    double startTime = omp_get_wtime();
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }

    *time = omp_get_wtime() - startTime;
    return result;
}