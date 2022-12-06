#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "../operations/vectorscalar.c"
#include "../operations/laction.c"
#include "../operations/vectordot.c"
#include "../operations/norm.c"
#include "../operations/daction.c"
#include "../operations/vectoradd.c"
#include "../operations/vectorsub.c"
#include "../operations/backsubs.c"


double * gauss(double** A,  double* x0, double* b, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;

    double* x1; 
    while (iter < maxIter && error > tol) {
        x1 = backSubs(A, vectorSub(b, laction(A, x0, s1, s1), s1) ,s1, s1); 
        error = norm(vectorSub(b, x1, s1), s1);
        x0 = x1;
        iter += 1;
    }
    

    *time = omp_get_wtime() - startTime;
    return x0;
}