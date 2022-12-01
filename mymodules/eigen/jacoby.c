#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#include "../operations/vectoradd.c"
#include "../operations/vectorsub.c"
#include "../operations/daction.c"

float * jacoby(float** A,  float* x0, float* b, double tol, int maxIter, int s1, double* time) {
    double startTime = omp_get_wtime();


    int iter = 0;
    double error = tol * 10;
    float** D = (float**)malloc(s1 * sizeof(float*));
    for (int i = 0; i < s1; i++) {
        D[i] = (float*)malloc(s1 * sizeof(float));
    }

    for (int i = 0; i < s1; i++) {
        D[i][i] = 1 / A[i][i];
    }

    float* r0 = vectorSub(b, actionOMP(A, x0, s1, s1), s1);
    float* x1;
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