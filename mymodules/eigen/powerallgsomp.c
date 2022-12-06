#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "powerOMP.c"
#include "powerinversegs.c"
#include "powershiftedgs.c"


#define NUM_THREADS 4
double * powerAllGSOMP(double** A,  double* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();

    double fakeTime;
    double max = powerOMP(A, v0, tol, maxIter, s1, &fakeTime);
    double min = powerInverseGS(A, v0, tol, maxIter, s1, &fakeTime);

    double step = (max - min) / (s1 - 1);

    double * results = (double*)malloc(s1 * sizeof(double));
    results[0] = min;
    results[s1 - 1] = max;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel

    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id + 1; i < s1 - 1; i+=numThreads) {
            results[i] = powerShiftedGS(A, v0, min + i * step, tol, maxIter, s1, &fakeTime);
        }
    }
    *time = omp_get_wtime() - startTime;
    return results;
}