#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double powerOptimized(double** A,  double* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;

    double* z;
    double* w = action(A, v0, s1, s1);;
    double lambda0 = 0; 
    double lambda1;

    while (iter < maxIter && error > tol) {
        z = vectorScalar(w, 1 / norm(w, s1), s1);
        w = action(A, z, s1, s1);

        lambda1 = vectorDot(z, w, s1);

        error = fabs(lambda1 - lambda0);
        iter += 1;
        lambda0 = lambda1;
    }
    

    *time = omp_get_wtime() - startTime;
    return lambda1;
}