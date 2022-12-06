#include "../mymodules/operations/matrixkronecker.c"
#include "../mymodules/eigen/powersimple.c"
#include "../mymodules/eigen/poweroptimized.c"
#include "../mymodules/eigen/poweromp.c"
#include "../mymodules/eigen/jacoby.c"




void testMatrixKronecker() {
    int s1 = 5;
    int s2 = 7;
    int s3 = 3;
    int s4 = 4;
    double matrix1Template[5][7] = 
        {{4, 4, 6, 1, 7, 3, 7},
        {1, 6, 0, 5, 6, 0, 0},
        {6, 7, 6, 2, 9, 3, 9},
        {6, 7, 6, 9, 8, 6, 5},
        {4, 4, 3, 0, 6, 4, 8}};
    double matrix2Template[3][4] = 
        {{4, 3, 4, 4},
        {1, 2, 1, 7},
        {9, 3, 7, 0}};

    double** matrix1 = (double**)malloc(s1 * sizeof(double*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (double*)malloc(s2 * sizeof(double));
    }

    double** matrix2 = (double**)malloc(s3 * sizeof(double*));
    for (int i = 0; i < s3; i++) {
        matrix2[i] = (double*)malloc(s4 * sizeof(double));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
        }
    }

    for (int i = 0; i < s3; i++) {
        for (int j = 0; j < s4; j++) {
            matrix2[i][j] = matrix2Template[i][j];
        }
    }

    double time;
    double** result = matrixKronecker(matrix1, matrix2, s1, s2, s3, s4, &time);

    printf("Result:\n");
    for (int i = 0; i < s1 * s3; i++) {
        for (int j = 0; j < s2 * s4; j++) {
        printf("%i ", (int) result[i][j]);

        }
        printf("\n");
    }

    printf("In %f Seconds\n", time);



}

void timeMatrixKronecker() {

    for (int k = 10; k < 200; k*=2) {
        int s1 = k;
        int s2 = k;

        double** matrix1 = (double**)malloc(s1 * sizeof(double*));
        for (int i = 0; i < s1; i++) {
            matrix1[i] = (double*)malloc(s2 * sizeof(double));
        }

        double** matrix2 = (double**)malloc(s1 * sizeof(double*));
        for (int i = 0; i < s2; i++) {
            matrix2[i] = (double*)malloc(s2 * sizeof(double));
        }

        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                matrix1[i][j] = 10;
                matrix2[i][j] = 10;
            }
        }

        double time;
        double** result = matrixKronecker(matrix1, matrix2, s1, s2, s1, s2, &time);

        printf("Size %i: (%f)\n", k, time);
    }
}

void testPower1(double (*f)()) {
    int s1 = 5;
    int s2 = 5;
    double matrix1Template[5][5] = 
                    {{8, 4, 3, 4, 6},
                    {9, 5, 5, 8, 3},
                    {1, 3, 3, 4, 1},
                    {8, 9, 7, 0, 1},
                    {0, 3, 3, 3, 3}};
    
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
    double result = f(matrix1, vector, 0.00001, 1000, s1, &time);

    printf("Result: %f\n", result);
    printf("In %f Seconds\n", time);

}

void testPower2(double (*f)()) {
    int s1 = 12;
    int s2 = 12;
    double matrix1Template[12][12] = 
                    {{8, 4, 5, 9, 9, 8, 4, 3, 9, 6, 6, 7},
                    {0, 6, 5, 2, 9, 6, 3, 1, 8, 6, 4, 1},
                    {8, 9, 9, 5, 6, 7, 3, 5, 6, 0, 3, 9},
                    {1, 2, 4, 2, 3, 3, 6, 3, 1, 8, 8, 4},
                    {8, 8, 9, 3, 6, 3, 2, 3, 5, 2, 4, 8},
                    {3, 2, 9, 9, 4, 7, 5, 6, 9, 2, 5, 3},
                    {6, 7, 0, 2, 2, 9, 8, 3, 9, 9, 0, 9},
                    {7, 4, 9, 2, 9, 7, 2, 0, 7, 9, 3, 0},
                    {9, 5, 1, 3, 5, 0, 7, 8, 4, 9, 0, 5},
                    {2, 0, 3, 8, 0, 1, 6, 8, 8, 1, 3, 1},
                    {2, 3, 4, 8, 8, 8, 7, 3, 8, 8, 9, 4},
                    {1, 6, 7, 8, 3, 4, 5, 5, 0, 3, 1, 0}}
;
    
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
    double result = f(matrix1, vector, 0.00001, 1000, s1, &time);

    printf("Result: %f\n", result);
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
        double result1 = powerSimple(matrix1, vector, 0.0001, 1000, s1, &time1);
        double result2 = powerOptimized(matrix1, vector, 0.0001, 1000, s1, &time2);
        double result3 = powerOMP(matrix1, vector, 0.0001, 1000, s1, &time3);

        printf("Size %i\n", k);
        printf("SIMPLE: %f\n", time1);
        printf("OPTIMIZED: %f\n", time2);
        printf("PARALLEL: %f\n", time3);
        printf("\n");
    }
}

void testJacoby() {
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
    double* result = jacoby(matrix1, vector2, vector1, 0.001, 1000, s1, &time);

    printf("Results:\n");
    for (int i = 0; i < s1; i++) {
        printf("x%i = %f\n", i, result[i]);
    }
    printf("In %f Seconds\n", time);
    printf("\n");
}





int main() {
    testMatrixKronecker();
    timeMatrixKronecker();
    printf("Results for Simple Power Iteration:\n");
    testPower1(powerSimple);
    testPower2(powerSimple);
    printf("Results for Optimized Power Iteration:\n");
    testPower1(powerOptimized);
    testPower2(powerOptimized);
    printf("Results for Parellel Power Iteration:\n");
    testPower1(powerOMP);
    testPower2(powerOMP);
    timeFunctions();
    testJacoby();
}