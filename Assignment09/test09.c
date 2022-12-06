
#include <stdio.h>
#include <stdlib.h>

#include "../mymodules/eigen/powerOMP.c"
#include "../mymodules/eigen/powerinverse.c"
#include "../mymodules/eigen/powershifted.c"
#include "../mymodules/eigen/powerall.c"
#include "../mymodules/eigen/powerallomp.c"
#include "../mymodules/eigen/powerallgs.c"
#include "../mymodules/operations/backsubs.c"
#include "../mymodules/eigen/powerallgsomp.c"



   
void testPower(double (*f)()) {
    int s1 = 6;
    int s2 = 6;
    double matrix1Template[6][6] = 
                    {{18,0,1,0,1,1},
                    {0,24,0,1,0,1},
                    {1,0,18,0,1,1},
                    {0,1,1,12,1,0},
                    {1,0,0,1,24,0},
                    {0,1,1,1,0,6}};
    
    double * vector = (double*)malloc(s1 * sizeof(double));

    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
        vector[i] = 0.1;
    }

    double time;
    double result = f(matrix1, vector, 0.000000000001, 1000, s1, &time);

    printf("Result: %f\n", result);
    printf("In %f Seconds\n", time);

}

   
void testPowerShifted() {
    int s1 = 6;
    int s2 = 6;
    double matrix1Template[6][6] = 
                    {{18,0,1,0,1,1},
                    {0,24,0,1,0,1},
                    {1,0,18,0,1,1},
                    {0,1,1,12,1,0},
                    {1,0,0,1,24,0},
                    {0,1,1,1,0,6}};
    
    double * vector = (double*)malloc(s1 * sizeof(double));

    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
        vector[i] = 0.1;
    }

    double time;
    double result = powerShifted(matrix1, vector, 10, 0.000000000001, 1000, s1, &time);

    printf("Result: %f\n", result);
    printf("In %f Seconds\n", time);

}

void testPowerAll(double* (*f)()) {
    int s1 = 6;
    int s2 = 6;
    double matrix1Template[6][6] = 
                    {{18,0,1,0,1,1},
                    {0,24,0,1,0,1},
                    {1,0,18,0,1,1},
                    {0,1,1,12,1,0},
                    {1,0,0,1,24,0},
                    {0,1,1,1,0,6}};
    
    double * vector = (double*)malloc(s1 * sizeof(double));

    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
        vector[i] = 0.1;
    }

    double time;
    double* results = f(matrix1, vector, 0.000000000000001, 1000, s1, &time);
    printf("Results:\n");
    for (int i = 0; i < s1; i++) {
        printf("Lambda%i: %f\n", s1 - i, results[i]);
    }
    printf("In %f Seconds\n", time);

}


void timeFunctions() {
    srand(1);

    for (int k = 10; k < 2000; k*=2) {
        int s1 = k;
        int s2 = k;

        double** matrix1 = (double**)malloc(s1 * sizeof(double*));
        double * vector = (double*)malloc(s1 * sizeof(double));
        for (int i = 0; i < s1; i++) {
            matrix1[i] = (double*)malloc(s2 * sizeof(double));
        }

        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                matrix1[i][j] = rand() % 10;
            }
            vector[i] = 0.01;
        }

        double time1;
        double time2;
        double time3;
        // double result1 = powerSimple(matrix1, vector, 0.0001, 1000, s1, &time1);
        // double result2 = powerOptimized(matrix1, vector, 0.0001, 1000, s1, &time2);
        // double result3 = powerOMP(matrix1, vector, 0.0001, 1000, s1, &time3);

        printf("Size %i\n", k);
        printf("SIMPLE: %f\n", time1);
        printf("OPTIMIZED: %f\n", time2);
        printf("PARALLEL: %f\n", time3);
        printf("\n");
    }
}

void testBackSubs() {
        int s1 = 6;
    int s2 = 6;
    double matrix1Template[6][6] = 
                    {{1,1,1,1,1,1},
                    {0,1,1,1,1,1},
                    {0,0,1,1,1,1},
                    {0,0,0,1,1,1},
                    {0,0,0,0,1,1},
                    {0,0,0,0,0,1}};
    
    double * vector = (double*)malloc(s1 * sizeof(double));

    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

        for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
        vector[i] = s1 - i;
    }

    double* results = backSubs(matrix1, vector, s1, s2);
        printf("Results:\n");
    for (int i = 0; i < s1; i++) {
        printf("X%i: %f\n", i, results[i]);
    }
}
void testGauss() {
    int s1 = 3;
    int s2 = 3;

    double matrix1Template[3][3] = 
        {{3, -2, 1},
        {1, -3, 2},
        {-1, 2, 4}};

    double vector1Template[4] = {2, 1, 3};

    double * vector1 = (double*)malloc(s1 * sizeof(double));
    double * vector2 = (double*)malloc(s1 * sizeof(double));
    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
        vector1[i] = vector1Template[i];
        vector2[i] = 0;
    }

    double time;
    double time2;
    double* result = jacoby(matrix1, vector2, vector1, 0.001, 1000, s1, &time);
    double* result2 = gauss(matrix1, vector2, vector1, 0.001, 1000, s1, &time2);

    printf("Results:\n");
    for (int i = 0; i < s1; i++) {
        printf("x%i (Jacoby) = %f\n", i, result[i]);
        printf("x%i (Gauss) = %f\n", i, result2[i]);
    }
    printf("In %f Seconds\n", time);
    printf("In %f Seconds\n", time2);
    printf("\n");
}





int main() {
    printf("Results for Power Iteration:\n");
    testPower(powerOMP);
    printf("Results for Inverse Power Iteration:\n");
    testPower(powerInverse);
    printf("Results for Shifted power Iteration:\n");
    testPowerShifted();
    printf("Results for Comprehensive power Iteration:\n");
    testPowerAll(powerAll);
    printf("Results for Parallel Comprehensive power Iteration:\n");
    testPowerAll(powerAllOMP);
    printf("Results for Gauss Seidel Power Iteration:\n");
    testPowerAll(powerAllGS);
    printf("Results for Gauss Seidel Power Iteration (OMP):\n");
    testPowerAll(powerAllGSOMP);
    printf("Testing BACKSUBS:\n");
    testBackSubs();
    printf("Testing Gauss:\n");
    testGauss();

    

}