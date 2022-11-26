#include <omp.h>

float * vectorHadamard(float* vector1, float* vector2, float size, double* time) {
    float* result = (float*)malloc(size * sizeof(float));
    double startTime = omp_get_wtime();
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] * vector2[i];
    }

    *time = omp_get_wtime() - startTime;
    return result;
}