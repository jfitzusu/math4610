#include <omp.h>

float ** outerProduct(float* vector1, float* vector2, float size1, float size2, double* time) {
    float** result = (float**)malloc(size1 * sizeof(float*));
    for (int i = 0; i < size1; i++) {
        result[i] = (float*)malloc(size2 * sizeof(float));
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