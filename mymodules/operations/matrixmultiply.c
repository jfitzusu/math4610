
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4
float ** matrixMultiply(float** matrix1, float** matrix2, int s1, int s2, int s3) {
    float** result = (float**)malloc(s1 * sizeof(float*));
    for (int i = 0; i < s1; i++) {
        result[i] = (float*)malloc(s3 * sizeof(float));
    }

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id; i < s1; i += numThreads) {
            for (int j = 0; j < s3; j++) {
                for (int k = 0; k < s2; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    return result;
}