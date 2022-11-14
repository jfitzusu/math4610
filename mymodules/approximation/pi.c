#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double arcSinPrime(double x) {
    return (1 / (sqrt(1 - x * x)));
}

double pi(int steps, double* time) {
    double startTime = omp_get_wtime();
    double total4 = 0;
    double total2 = 0;
    double x = 0;
    double h = sqrt(3) / (2 * steps);


    for (int i = 0; i < floor(steps / 2) - 1; i++) {
        x += h;
        total4 += arcSinPrime(x);
        x += h;
        total2 += arcSinPrime(x);
    }

    x += h;
    total4 += arcSinPrime(x);

    total4 *= 4;
    total2 *= 2;

    double total = (total4 + total2 + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}

