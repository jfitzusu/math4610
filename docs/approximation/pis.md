# PI Approximation Algorithm (Serial)

**Routine Name:** pi

**Author:** Jacob Fitzgerald

**Language:** C. This function can be used by including the include statment in your C file:
```
#include "pi.c"
```

Your code can then be compiled using gcc with library linking to produce an executable:
```
gcc -o my_exe my_code.c -lm
```
It can be used as part of a shared library for convience, but that goes beyond the scope of this document.

**Description/Purpose:** This function will calculate pi using a certain number of steps. The more steps used, the more accurate the result. This approximation is done exclusivley with serial code, making it slower compared to parrallel methods. It also includes the ability to time itself. Pi is approximated by using simpson's rule to approximate the integral of 1 / sqrt(1 - x ^ 2) from 0 to sqrt(3) / 2, which should give us Pi/4. As we're using the simpson's rule, this should give us extremley fast convergence.

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
void testPiSeq() {
    double time = 0;
    
    for (int i = 1; i <= 1000000; i *= 10) {
        double approx = pi(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }

}
```

This code tests our pi approximations over several step values, and reports both the approximation and the time it took.


Console Output:
```
Pi With 1 Iterations: 9.5262794416 (0.0000013000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000002000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000007000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000055000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000547000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0005606000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0055591000 Seconds)
```

As we can see, our code rapidly converges to PI, due to the usage of simpson's rule. 

**Implementation/Code:** The Following is the Code for pi()
```
double arcSinPrime(double x) {
    return (1 / (sqrt(1 - x * x)));
}

double pi(int steps, double* time) {
    double startTime = omp_get_wtime();
    double total4 = 0;
    double total2 = 0;
    double x = 0;
    double h = sqrt(3) / (2 * steps);


    for (int i = 0; i < floor(steps / 2) - 1; i++) {
        x += h;
        total4 += arcSinPrime(x);
        x += h;
        total2 += arcSinPrime(x);
    }

    x += h;
    total4 += arcSinPrime(x);

    total4 *= 4;
    total2 *= 2;

    double total = (total4 + total2 + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}
```
**Last Modified:** November/2022