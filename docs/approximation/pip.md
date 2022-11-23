# PI Approximation Algorithm (Parellel)

**Routine Name:** piParellel

**Author:** Jacob Fitzgerald

**Language:** C. This function can be used by including the include statment in your C file:
```
#include "piparellel.c"
```

Your code can then be compiled using gcc with library linking to produce an executable:
```
gcc -o my_exe my_code.c -lm
```
It can be used as part of a shared library for convience, but that goes beyond the scope of this document.

**Description/Purpose:** This function will calculate pi using a certain number of steps. The more steps used, the more accurate the result. This approximation is done exclusivley with parellel code, making it much faster compared to serial methods. It also includes the ability to time itself. Pi is approximated by using simpson's rule to approximate the integral of 1 / sqrt(1 - x ^ 2) from 0 to sqrt(3) / 2, which should give us Pi/4. As we're using the simpson's rule, this should give us extremley fast convergence.

**Input:**
### *steps:* 
  * Data Type: int
  * Valid Input: (0, int.max]
  * Description: The number of steps to use for the approximation

  ### *time:* 
  * Data Type: double*
  * Valid Input: Any
  * Description: A pointer to a variable to store timing results in, the current value will be destroyed

**Output:** 
### *pi:*
  * Data Type: double
  * Possible Values: A small range around PI
  * Description: An approximation of PI

**Usage/Example:**

After Importing the Function, You Can Call it In Your Code Like So:

```
void testPiPar() {
        double time = 0;
    
    for (int i = 1; i <=  1000000; i *= 10) {
        double approx = piParellel(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }
}
```

This code tests our pi approximations over several step values, and reports both the approximation and the time it took.


Console Output:
```
Pi With 1 Iterations: 2.5980762114 (0.0001551000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000020000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000015000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000074000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000192000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0001595000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0018391000 Seconds)
```

As we can see, our code rapidly converges to PI, due to the usage of simpson's rule, and is incredibly fast.  

**Implementation/Code:** The Following is the Code for piParellel()
```
double arcSinPrime(double x) {
    return (1 / (sqrt(1 - x * x)));
}

#define NUM_THREADS 4
#define PAD 8
double piParellel(int steps, double* time) {
    int threadsUsed = NUM_THREADS;
    double startTime = omp_get_wtime();
    double total4[NUM_THREADS][PAD];
    double total2[NUM_THREADS][PAD];

    double h = sqrt(3) / (2 * steps);
    int iterations = floor(steps / 2) - 1;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        if (id == 0) {
            threadsUsed = numThreads;
        }


        double x;
        total4[id][0] = 0.0;
        total2[id][0] = 0.0;

        for (int i = id; i < iterations; i+=numThreads) {
            x = (2 * i + 1) * h;
            total4[id][0] += arcSinPrime(x);
            x += h;
            total2[id][0] += arcSinPrime(x);
        }
    }

    if (iterations > 0) {
            total4[0][0] += arcSinPrime(sqrt(3) / 2 - h);
    }

    double total4Sum = 0;
    double total2Sum = 0;
    for (int i = 0; i < threadsUsed; i++) {
        total4Sum += total4[i][0];
        total2Sum += total2[i][0];
    }

    total4Sum *= 4;
    total2Sum *= 2;

    double total = (total4Sum + total2Sum + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}
```
**Last Modified:** November/2022