#include <omp.h>
#include <math.h>

#define NUM_THREADS 4
float * vectorHadamardOMP(float* vector1, float* vector2, float size, double* time) {
    float* result =  (float*)malloc(size *  sizeof(float));
    double startTime = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel
    { 

        
    
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        for (int i = id; i < size; i+=numThreads) {
            result[i] = vector1[i] * vector2[i];
        }
    }

    *time = omp_get_wtime() - startTime;
    return result;
}