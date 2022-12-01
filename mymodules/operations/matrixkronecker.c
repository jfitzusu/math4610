
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4
float ** matrixKronecker(float** matrix1, float** matrix2, int s1, int s2, int s3, int s4, double* time) {
    int size1 = s1 * s3;
    int size2 = s2 * s4;
    double startTime = omp_get_wtime();
    float** result = (float**)malloc(size1 * sizeof(float*));
    for (int i = 0; i < size1; i++) {
        result[i] = (float*)malloc(size2 * sizeof(float));
    }

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id; i < size1; i += numThreads) {
            for (int j = 0; j < size2; j++) {
                result[i][j] += matrix1[i / s3][j / s4] * matrix2[i % s3][j % s4];
            }
        }
    }

    *time = omp_get_wtime() - startTime;
    return result;
}