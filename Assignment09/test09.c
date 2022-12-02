





   
void testPower1(double (*f)()) {
    int s1 = 5;
    int s2 = 5;
    double matrix1Template[5][5] = 
                    {{50, 4, 3, 4, 6},
                    {9, 50, 5, 8, 3},
                    {1, 3, 50, 4, 1},
                    {8, 9, 7, 50, 1},
                    {0, 3, 3, 3, 50}};
    
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

void testPower2(double (*f)()) {
    int s1 = 12;
    int s2 = 12;
    double matrix1Template[12][12] = 
                    {{1000, 4, 5, 9, 9, 8, 4, 3, 9, 6, 6, 7},
                    {0, 1000, 5, 2, 9, 6, 3, 1, 8, 6, 4, 1},
                    {8, 9, 1000, 5, 6, 7, 3, 5, 6, 0, 3, 9},
                    {1, 2, 4, 1000, 3, 3, 6, 3, 1, 8, 8, 4},
                    {8, 8, 9, 3, 1000, 3, 2, 3, 5, 2, 4, 8},
                    {3, 2, 9, 9, 4, 1000, 5, 6, 9, 2, 5, 3},
                    {6, 7, 0, 2, 2, 9, 1000, 3, 9, 9, 0, 9},
                    {7, 4, 9, 2, 9, 7, 2, 1000, 7, 9, 3, 0},
                    {9, 5, 1, 3, 5, 0, 7, 8, 1000, 9, 0, 5},
                    {2, 0, 3, 8, 0, 1, 6, 8, 8, 1000, 3, 1},
                    {2, 3, 4, 8, 8, 8, 7, 3, 8, 8, 1000, 4},
                    {1, 6, 7, 8, 3, 4, 5, 5, 0, 3, 1, 1000}}
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
    double result = f(matrix1, vector, 0.0000001, 1000, s1, &time);

    printf("Result: %f\n", result);
    printf("In %f Seconds\n", time);
    
}

void testPowerShifted(double lambda) {
    int s1 = 5;
    int s2 = 5;
    double matrix1Template[5][5] = 
                    {{50, 4, 3, 4, 6},
                    {9, 50, 5, 8, 3},
                    {1, 3, 50, 4, 1},
                    {8, 9, 7, 50, 1},
                    {0, 3, 3, 3, 50}};
    
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
    double result = powerShifted(matrix1, vector, lambda, 0.000000000001, 1000, s1, &time);

    printf("Result: %f\n", result);
    printf("In %f Seconds\n", time);

}

void testPowerShifted2(double lambda) {
    int s1 = 12;
    int s2 = 12;
    double matrix1Template[12][12] = 
                    {{1000, 4, 5, 9, 9, 8, 4, 3, 9, 6, 6, 7},
                    {0, 1000, 5, 2, 9, 6, 3, 1, 8, 6, 4, 1},
                    {8, 9, 1000, 5, 6, 7, 3, 5, 6, 0, 3, 9},
                    {1, 2, 4, 1000, 3, 3, 6, 3, 1, 8, 8, 4},
                    {8, 8, 9, 3, 1000, 3, 2, 3, 5, 2, 4, 8},
                    {3, 2, 9, 9, 4, 1000, 5, 6, 9, 2, 5, 3},
                    {6, 7, 0, 2, 2, 9, 1000, 3, 9, 9, 0, 9},
                    {7, 4, 9, 2, 9, 7, 2, 1000, 7, 9, 3, 0},
                    {9, 5, 1, 3, 5, 0, 7, 8, 1000, 9, 0, 5},
                    {2, 0, 3, 8, 0, 1, 6, 8, 8, 1000, 3, 1},
                    {2, 3, 4, 8, 8, 8, 7, 3, 8, 8, 1000, 4},
                    {1, 6, 7, 8, 3, 4, 5, 5, 0, 3, 1, 1000}}
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
    double result = powerShifted(matrix1, vector, lambda, 0.0000001, 1000, s1, &time);

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





int main() {
    printf("Results for Power Iteration:");
    testPower1(powerOMP);
    testPower2(powerOMP);
    printf("Results for Inverse Power Iteration:\n");
    testPower1(powerInverse);
    testPower2(powerInverse);
    printf("Results for Shifted power Iteration:\n");
    testPowerShifted(10);
    testPowerShifted2(10);
}