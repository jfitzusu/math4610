#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Caclulates the Absolute Error Given a Value and It's Approximation
* u: True Value
* v: Approximation
* Returns: Absolute Error of Approximation
*/
double absError(double u, double v) {
        return fabs(v - u);
    }