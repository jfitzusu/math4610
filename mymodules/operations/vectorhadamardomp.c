#pragma once
#include <omp.h>
#include <math.h>
#include <stdlib.h>

#define NUM_THREADS 4
double * vectorHadamardOMP(double* vector1, double* vector2, double size, double* time) {
    double* result =  (double*)malloc(size *  sizeof(double));
    double startTime = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    { 

        
    
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id; i < size; i+=numThreads) {
            result[i] = vector1[i] * vector2[i];
        }
    }

    *time = omp_get_wtime() - startTime;
    return result;
}