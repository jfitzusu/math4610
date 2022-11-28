#include "../mymodules/operations/matrixmultiply.c"
#include "../mymodules/operations/vectorhadamard.c"
#include "../mymodules/operations/vectorhadamardomp.c"
#include "../mymodules/operations/matrixhadamard.c"
#include "../mymodules/operations/outerproduct.c"



void testMatrixMultiply() {
    int s1 = 10;
    int s2 = 30;
    int s3 = 20;
    float matrix1Template[10][30] = 
        {{4, 4, 6, 1, 7, 3, 7, 7, 2, 9, 1, 0, 6, 8, 7, 6, 0, 9, 3, 3, 0, 1, 9, 1, 2, 4, 1, 6, 8, 7},
        {1, 6, 0, 5, 6, 0, 0, 8, 5, 6, 0, 7, 0, 6, 4, 4, 5, 4, 4, 5, 9, 1, 0, 8, 8, 1, 8, 6, 7, 1},
        {6, 7, 6, 2, 9, 3, 9, 4, 9, 5, 3, 6, 5, 1, 5, 0, 5, 0, 9, 7, 8, 7, 5, 9, 6, 9, 2, 1, 2, 2},
        {6, 7, 6, 9, 8, 6, 5, 1, 5, 7, 6, 2, 8, 4, 9, 1, 9, 2, 5, 8, 8, 1, 4, 0, 3, 6, 2, 1, 1, 3},
        {4, 4, 3, 0, 6, 4, 8, 4, 9, 2, 4, 8, 7, 8, 1, 1, 1, 6, 1, 1, 2, 2, 1, 3, 5, 2, 6, 2, 6, 5},
        {5, 4, 0, 1, 2, 5, 9, 3, 7, 7, 6, 3, 4, 3, 5, 3, 0, 0, 4, 8, 6, 3, 9, 6, 0, 4, 9, 9, 0, 3},
        {0, 2, 4, 9, 7, 1, 7, 4, 3, 9, 8, 4, 7, 9, 5, 9, 9, 0, 3, 3, 4, 0, 0, 8, 1, 1, 9, 5, 0, 7},
        {7, 2, 0, 4, 1, 0, 9, 6, 1, 8, 7, 4, 2, 8, 1, 1, 7, 3, 8, 1, 7, 0, 6, 6, 9, 7, 6, 7, 4, 6},
        {5, 0, 0, 9, 5, 2, 3, 6, 0, 2, 8, 5, 0, 5, 1, 2, 2, 6, 6, 2, 8, 4, 2, 4, 6, 0, 8, 0, 7, 9},
        {4, 4, 6, 5, 7, 8, 3, 2, 6, 8, 8, 0, 8, 7, 2, 6, 1, 0, 7, 0, 6, 9, 8, 7, 4, 3, 4, 2, 3, 0}};
    float matrix2Template[30][20] = 
        {{4, 3, 4, 4, 3, 9, 6, 4, 7, 5, 2, 9, 4, 4, 1, 8, 0, 5, 0, 1},
        {1, 2, 1, 7, 9, 0, 4, 5, 0, 2, 9, 2, 2, 7, 1, 5, 9, 8, 5, 0},
        {9, 3, 7, 0, 7, 9, 9, 6, 8, 2, 6, 1, 0, 8, 2, 8, 9, 1, 9, 7},
        {0, 5, 8, 0, 9, 8, 4, 5, 5, 4, 9, 2, 5, 4, 1, 8, 8, 0, 0, 7},
        {9, 7, 4, 7, 3, 2, 1, 3, 7, 0, 6, 4, 8, 7, 4, 9, 2, 9, 8, 4},
        {8, 5, 4, 1, 3, 0, 3, 7, 1, 6, 9, 5, 9, 4, 7, 0, 3, 9, 1, 5},
        {1, 0, 7, 0, 9, 9, 3, 9, 9, 7, 1, 7, 1, 6, 5, 2, 9, 8, 9, 8},
        {9, 2, 8, 5, 4, 3, 2, 3, 5, 9, 9, 5, 9, 3, 8, 9, 8, 2, 9, 1},
        {8, 6, 5, 2, 7, 9, 7, 4, 4, 2, 4, 8, 2, 6, 8, 8, 8, 6, 9, 8},
        {4, 7, 9, 3, 4, 1, 1, 3, 0, 7, 2, 1, 3, 1, 8, 0, 5, 6, 6, 7},
        {7, 2, 9, 6, 7, 6, 5, 3, 3, 2, 0, 4, 1, 2, 7, 7, 8, 6, 3, 0},
        {4, 0, 1, 6, 0, 3, 8, 6, 3, 9, 7, 2, 5, 1, 5, 8, 1, 8, 8, 5},
        {7, 4, 2, 8, 0, 4, 8, 9, 8, 6, 2, 7, 8, 4, 8, 8, 8, 1, 1, 0},
        {5, 5, 8, 2, 0, 7, 2, 9, 0, 1, 3, 4, 7, 1, 8, 3, 6, 9, 0, 7},
        {6, 5, 0, 1, 1, 8, 0, 3, 3, 2, 6, 9, 8, 5, 3, 6, 9, 3, 1, 0},
        {8, 9, 7, 7, 8, 8, 8, 1, 8, 3, 1, 8, 6, 7, 8, 3, 4, 1, 5, 9},
        {3, 5, 4, 2, 0, 4, 1, 2, 8, 1, 4, 5, 5, 7, 4, 5, 8, 8, 0, 1},
        {5, 1, 5, 7, 6, 0, 6, 4, 8, 4, 2, 5, 2, 2, 2, 7, 7, 0, 8, 5},
        {0, 5, 5, 7, 2, 8, 0, 7, 5, 1, 2, 8, 2, 3, 5, 6, 1, 4, 8, 0},
        {5, 4, 8, 4, 5, 5, 1, 1, 3, 1, 9, 2, 1, 5, 6, 2, 9, 5, 4, 8},
        {1, 1, 7, 4, 2, 1, 0, 7, 3, 8, 5, 9, 6, 9, 3, 9, 7, 7, 6, 8},
        {2, 4, 0, 8, 1, 6, 5, 7, 8, 8, 8, 6, 3, 0, 3, 8, 2, 0, 8, 5},
        {2, 4, 8, 5, 8, 0, 7, 2, 9, 6, 1, 4, 7, 3, 0, 9, 8, 5, 9, 2},
        {1, 0, 5, 2, 4, 8, 2, 6, 4, 9, 2, 9, 0, 2, 0, 3, 1, 3, 8, 5},
        {2, 3, 0, 6, 9, 4, 6, 3, 8, 7, 8, 8, 9, 0, 2, 6, 8, 2, 0, 4},
        {8, 5, 5, 7, 3, 4, 1, 6, 1, 5, 3, 5, 3, 5, 4, 8, 6, 7, 4, 0},
        {0, 3, 2, 9, 4, 7, 2, 6, 2, 8, 5, 3, 9, 4, 9, 6, 7, 8, 8, 4},
        {4, 7, 0, 0, 6, 9, 9, 1, 2, 1, 6, 6, 2, 1, 4, 8, 2, 0, 2, 6},
        {6, 7, 3, 2, 3, 8, 4, 4, 6, 5, 0, 7, 0, 2, 8, 9, 8, 3, 6, 9},
        {5, 0, 7, 9, 9, 9, 7, 6, 2, 4, 6, 0, 4, 5, 6, 6, 3, 3, 0, 2}};

    float** matrix1 = (float**)malloc(s1 * sizeof(float*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (float*)malloc(s2 * sizeof(float));
    }

    float** matrix2 = (float**)malloc(s2 * sizeof(float*));
    for (int i = 0; i < s2; i++) {
        matrix2[i] = (float*)malloc(s3 * sizeof(float));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {

            matrix1[i][j] = matrix1Template[i][j];
        }
    }

    for (int i = 0; i < s2; i++) {
        for (int j = 0; j < s3; j++) {
            matrix2[i][j] = matrix2Template[i][j];
        }
    }

    float** result = matrixMultiply(matrix1, matrix2, s1, s2, s3);

    printf("Result:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
        printf("%i ", (int) result[i][j]);

        }
        printf("\n");
    }



}

void timeVectorHadmardOMP() {


    for (int i = 10; i < 1000000000; i *= 10) {
        float* vector1 = (float*)malloc(i * sizeof(float));
        float* vector2 = (float*)malloc(i * sizeof(float));
        for (int j = 0; j < i; j++) {
            vector1[j] = 10;
            vector2[j] = 10;
        }

        double time;
        float* result = vectorHadamardOMP(vector1, vector2, i, &time);
        printf("Size %i: (%f)\n", i, time);
    }


}


void timeVectorHadmard() {


    for (int i = 10; i < 1000000000; i *= 10) {
        float* vector1 = (float*)malloc(i * sizeof(float));
        float* vector2 = (float*)malloc(i * sizeof(float));
        for (int j = 0; j < i; j++) {
            vector1[j] = 10;
            vector2[j] = 10;
        }

        double time;
        float* result = vectorHadamard(vector1, vector2, i, &time);
        printf("Size %i: (%f)\n", i, time);
    }


}

void testVectorHadmard() {
    int size = 10;
    float vector1Template[] = {2, 7, 8, 12, 89, 1, 0, 0, 2, 6};
    float vector2Template[] = {7, 23, 8, 1, 1, 27, 7, 2, 1, 0};
    float* vector1 = (float*)malloc(size * sizeof(float));
    float* vector2 = (float*)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        vector1[i] = vector1Template[i];
        vector2[i] = vector2Template[i];
    }
    double time;
    float* result = vectorHadamard(vector1, vector2, size, &time);

    printf("Results: ");
    for (int i = 0; i < size; i++) {
        printf("%i ", (int) result[i]);
    }
    printf("\n");
}


void testMatrixHadamard() {
    int s1 = 5;
    int s2 = 6;
    float matrix1Template[5][6] = {{0, 1, 2, 3, 4, 5}, {6, 7, 8, 9, 10, 11}, {12, 13, 14, 15, 16, 17}, {18, 19, 20, 21, 22, 23}, {24, 25, 26, 27, 28, 29}};
    float matrix2Template[5][6] = {{0, 1, 2, 3, 4, 5}, {6, 7, 8, 9, 10, 11}, {12, 13, 14, 15, 16, 17}, {18, 19, 20, 21, 22, 23}, {24, 25, 26, 27, 28, 29}};

    float** matrix1 = (float**)malloc(s1 * sizeof(float*));
    for (int i = 0; i < s1; i++) {
        matrix1[i] = (float*)malloc(s2 * sizeof(float));
    }

    float** matrix2 = (float**)malloc(s1 * sizeof(float*));
    for (int i = 0; i < s2; i++) {
        matrix2[i] = (float*)malloc(s2 * sizeof(float));
    }

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            matrix1[i][j] = matrix1Template[i][j];
            matrix2[i][j] = matrix2Template[i][j];
        }
    }

    double time;
    float** result = matrixHadamard(matrix1, matrix2, s1, s2, &time);

    printf("Result:\n");
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
        printf("%i ", (int) result[i][j]);

        }
        printf("\n");
    }

        printf("Time: %f\n", time);



}

void timeMatrixHadamard() {

    for (int k = 10; k < 100000; k*=10) {
        int s1 = k;
        int s2 = k;

        float** matrix1 = (float**)malloc(s1 * sizeof(float*));
        for (int i = 0; i < s1; i++) {
            matrix1[i] = (float*)malloc(s2 * sizeof(float));
        }

        float** matrix2 = (float**)malloc(s1 * sizeof(float*));
        for (int i = 0; i < s2; i++) {
            matrix2[i] = (float*)malloc(s2 * sizeof(float));
        }

        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                matrix1[i][j] = 10;
                matrix2[i][j] = 10;
            }
        }

        double time;
        float** result = matrixHadamard(matrix1, matrix2, s1, s2, &time);

        printf("Size %i: (%f)\n", k, time);
    }
    

}

void testOuterProduct() {
        int size = 10;
    float vector1Template[] = {2, 7, 8, 12, 89, 1, 0, 0, 2, 6};
    float vector2Template[] = {7, 23, 8, 1, 1, 27, 7, 2, 1, 0};
    float* vector1 = (float*)malloc(size * sizeof(float));
    float* vector2 = (float*)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        vector1[i] = vector1Template[i];
        vector2[i] = vector2Template[i];
    }
    double time;
    float** result = outerProduct(vector1, vector2, size, size, &time);

    printf("Results: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%i ", (int) result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    testMatrixMultiply();
    testVectorHadmard();
    timeVectorHadmard();
    timeVectorHadmardOMP();
    testMatrixHadamard();
    timeMatrixHadamard();
    testOuterProduct();

}