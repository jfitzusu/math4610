#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include "../operations/norm.c"
#include "../operations/vectorscalar.c"
#include "../operations/action.c"

float powerSimple(float** A,  float* v0, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;
    float* y;
    float* z;
    float lambda0 = 0; 
    float lambda1;

    while (iter < maxIter && error > tol) {
        y = action(A, v0, s1, s1);

        z = vectorScalar(y, 1 / norm(y, s1), s1);

        lambda1 = vectorDot(z, action(A, z, s1, s1), s1);

        error = fabs(lambda1 - lambda0);
        iter += 1;
        lambda0 = lambda1;
        v0 = z;
    }
    

    *time = omp_get_wtime() - startTime;
    return lambda1;
}