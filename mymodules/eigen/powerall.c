#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "powerOMP.c"
#include "powerinverse.c"
#include "powershifted.c"


double * powerAll(double** A,  double* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();

    double fakeTime;
    double max = powerOMP(A, v0, tol, maxIter, s1, &fakeTime);
    double min = powerInverse(A, v0, tol, maxIter, s1, &fakeTime);

    double step = (max - min) / (s1 - 1);

    double * results = (double*)malloc(s1 * sizeof(double));
    results[0] = min;
    results[s1 - 1] = max;
    double current = min + step;
    for (int i = 1; i < s1 - 1; i++) {
        results[i] = powerShifted(A, v0, current, tol, maxIter, s1, &fakeTime);
        current += step; 
    }

    *time = omp_get_wtime() - startTime;
    return results;
}