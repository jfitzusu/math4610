float vectorDot(float* v1, float* v2, int size) {
    float result = 0;
    for (int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }

    return result;
}