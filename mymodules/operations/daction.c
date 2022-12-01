float * dAction(float** matrix, float* vector, int s1, int s2) {
    float* result = (float*)malloc(s1 * sizeof(float));
    for (int i = 0; i < s1; i++) {
        result[i] = matrix[i][i] * vector[i];
    }

    return result;
}