float * vectorScalar(float* v, float scalar, int s1) {
    float* result = (float*)malloc(s1 * sizeof(float));
    for (int i = 0; i < s1; i++) {
        result[i] = scalar * v[i];
    }

    return result;
}