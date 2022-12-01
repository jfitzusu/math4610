#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include "../operations/actionomp.c"
float powerOMP(float** A,  float* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;
    float* y = actionOMP(A, v0, s1, s1);

    float* z;
    float* w;
    float lambda0 = 0; 
    float lambda1;

    while (iter < maxIter && error > tol) {
        z = vectorScalar(y, 1 / norm(y, s1), s1);
        w = actionOMP(A, z, s1, s1);

        lambda1 = vectorDot(z, w, s1);

        error = fabs(lambda1 - lambda0);
        iter += 1;
        lambda0 = lambda1;
        y = w;
    }
    

    *time = omp_get_wtime() - startTime;
    return lambda1;
}