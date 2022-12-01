float * vectorAdd(float* v1, float* v2, int s1) {
    float* result = (float*)malloc(s1 * sizeof(float));
    for (int i = 0; i < s1; i++) {
        result[i] =  v1[i] + v2[i];
    }

    return result;
}