
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "pi.c"

#define NUM_THREADS 4
#define PAD 8
double piParellel(int steps, double* time) {
    int threadsUsed = NUM_THREADS;
    double startTime = omp_get_wtime();
    double total4[NUM_THREADS][PAD];
    double total2[NUM_THREADS][PAD];

    double h = sqrt(3) / (2 * steps);
    int iterations = floor(steps / 2) - 1;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        if (id == 0) {
            threadsUsed = numThreads;
        }


        double x;
        total4[id][0] = 0.0;
        total2[id][0] = 0.0;

        for (int i = id; i < iterations; i+=numThreads) {
            x = (2 * i + 1) * h;
            total4[id][0] += arcSinPrime(x);
            x += h;
            total2[id][0] += arcSinPrime(x);
        }
    }

    if (iterations > 0) {
            total4[0][0] += arcSinPrime(sqrt(3) / 2 - h);
    }

    double total4Sum = 0;
    double total2Sum = 0;
    for (int i = 0; i < threadsUsed; i++) {
        total4Sum += total4[i][0];
        total2Sum += total2[i][0];
    }

    total4Sum *= 4;
    total2Sum *= 2;

    double total = (total4Sum + total2Sum + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}

