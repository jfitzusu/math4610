#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "../operations/vectorscalar.c"
#include "../operations/actionomp.c"
#include "../operations/vectordot.c"
#include "../operations/norm.c"
#include "../operations/daction.c"
#include "../operations/vectoradd.c"
#include "../operations/vectorsub.c"


double * jacoby(double** A,  double* x0, double* b, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;
    double** D = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        D[i] = (double*)malloc(s1 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        D[i][i] = 1 / A[i][i];
    }

    double* r0 = vectorSub(b, actionOMP(A, x0, s1, s1), s1);
    double* x1;
    while (iter < maxIter && error > tol) {
        error = norm(r0, s1);
        x1 = vectorAdd(x0, dAction(D, r0, s1, s1), s1);
        x0 = x1;
        r0 = vectorSub(b, actionOMP(A, x0, s1, s1), s1);
        iter += 1;
    }
    

    *time = omp_get_wtime() - startTime;
    return x0;
}