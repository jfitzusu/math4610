
#include <omp.h>
#include <stdlib.h>

#define NUM_THREADS 4
double * actionOMP(double** matrix, double* vector, int s1, int s2) {
    double* result = (double*)malloc(s1 * sizeof(double));

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    { 
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id; i < s1; i+= numThreads) {
            result[i] = vectorDot(matrix[i], vector, s1);
        }
    }

    return result;
}