#include "vectordot.c"
float * action(float** matrix, float* vector, int s1, int s2) {
    float* result = (float*)malloc(s1 * sizeof(float));
    for (int i = 0; i < s1; i++) {
        result[i] = vectorDot(matrix[i], vector, s1);
    }

    return result;
}