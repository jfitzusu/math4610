#include <stdio.h>
#include <stdlib.h>
#include "../../mymodules/accuracy/accuracysingle.c"
#include "../../mymodules/accuracy/accuracydouble.c"
#include "../../mymodules/accuracy/abserror.c"
#include "../../mymodules/accuracy/relerror.c"


int main() {
        printf("Relative Error of %f to %f: %f \n", 10.1, 10.0, relError(10.0, 10.1));
        printf("Absolute Error of %f to %f: %f \n", 10.1, 10.0, absError(10.0, 10.1));
        printf("Accuracy of a Single: %i \n", accuracySingle(500));
        printf("Accuracy of a Double: %i \n", accuracyDouble(500));
    }