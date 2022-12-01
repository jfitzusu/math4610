#include <math.h>

float norm(float* v, int size) {
    float result = 0;
    for (int i = 0; i < size; i++) {
        result += v[i] * v[i];
    }

    return sqrt(result);
}