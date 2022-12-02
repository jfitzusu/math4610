#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

double powerInverse(double** A,  double* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;

    double* x0 = (double*)malloc(s1 * sizeof(double));
    for (int i = 0; i < s1; i++) {
        x0[i] = 0;
    }
    double* z;
    double timeTemp;
    double* w = jacoby(A, x0, v0, tol, maxIter, s1, &timeTemp);
    double lambda0 = 0; 
    double lambda1;

    while (iter < maxIter && error > tol) {
        z = vectorScalar(w, 1 / norm(w, s1), s1);

        w = jacoby(A, x0, z, tol, maxIter, s1, &timeTemp);
        

        lambda1 = vectorDot(z, w, s1);

        error = fabs(lambda1 - lambda0);
        iter += 1;
        lambda0 = lambda1;
    }
    

    *time = omp_get_wtime() - startTime;
    return 1 / lambda1;
}