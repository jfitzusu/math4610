
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4
double ** matrixMultiply(double** matrix1, double** matrix2, int s1, int s2, int s3) {
    double** result = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        result[i] = (double*)malloc(s3 * sizeof(double));
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