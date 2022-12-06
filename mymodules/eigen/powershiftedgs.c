#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "powerinversegs.c"


double powerShiftedGS(double** A,  double* v0, double lambda, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;

    double** B = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        B[i] = (double*)malloc(s1 * sizeof(double));
        for (int j = 0; j < s1; j++) {
            B[i][j] = A[i][j];
        }
        B[i][i] -= lambda;
    }

    double result = powerInverseGS(B, v0, tol, maxIter, s1, time);
    *time = omp_get_wtime() - startTime;
    return result + lambda;
}