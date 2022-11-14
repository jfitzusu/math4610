# Math 4610 Tasksheet 2
### Jacob Fitzgerald (A02261889)

## Docs
https://jfitzusu.github.io/math4610/

## Code
https://github.com/jfitzusu/math4610/tree/main/Assignment06
https://github.com/jfitzusu/math4610/tree/main/Assignment06/mymodules/approximation
https://github.com/jfitzusu/math4610/tree/main/Assignment06/mymodules/operations

All test code can be found in the *tests06.py* and *test06.c* files in the Assignment06 directory, while code for specific functions can be found under the python/c files named after them in the approximation and operations directories.  

## Task 1

For this task we need to derive a method for the approximation of $\pi$. A classic example of this is the integral:
$$
\int_{0}^{\frac{\sqrt{3}}{2}} \frac{1}{\sqrt{(1 - x ^ 2)}} = arcsin(\frac{\sqrt{3}}{2}) - arcsin(0) = \frac{\pi}{3}
$$

This is very similar to the method used in class, however, arcsin is used this time instead of arctan. This method will be much less efficient as it involves both a square and a square root, so the method discussed in class should involve much less work. Either way, most integral approximations of $\pi$ will involve some sort of trigometric function, so this one will do well enough. Additionally, as the expression we're integrating would be undefined at 1, we have to use a slightly different interval. 

For approximating integrals, we have several methods available. Because we're doing an approximation, we don't want to actually integrate and evaluate, because then we'd just be using whatever math libraries our chosen language uses. We also probably don't want to do the work of integrating anything at all, so polynomial interpolation is off the table as well. In this case, we just want to approximate the integral, and since it is somewhat curvy, the Simpson's method should provide pretty decent results here. 

As we've seen before, the greater the iterations, the greater the accuracy of our results. Since we're only interested in calculating $\pi$ using this exact method, our function should need only one input, and should look almost identical to our code for simpson's method. The pseudocode should look something like the following.

**Pseudocode**:

```
approximatePi(steps): // Steps Must be Even
	total4 = 0
	total2 = 0
	x = 0
	h = sqrt(3) / 2 / steps
	for i in range(1, steps // 2 - 1):
		x = x + h
		total4 = total4 + (1 / sqrt(1 - x * x))
		x = x + h
		total2 = total2 + (1 / sqrt(1 - x * x))
	total4 = total4 + (1 / sqrt(1 - (x + h) * (x + h)))
	
	total4 = total4 * 4
	total2 = total2 * 2
    total = (total4 + total2 + 3) * (h / 3)
    return total * 3
```

As you can see, this method relies on the languages built in sqrt() method. This means that we'll be relying on yet another approximation, as computer hardware doesn't recognize such an operation. Our results should still be significantly accurate though. 

## Task 2

 **Implementation Code (C):**

```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

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

This function accepts the following parameters:

* Steps: Integer. Number of steps to approximate pi with.

* Time: Double. Return variable used to keep track of timing data.

  

It returns the approximation of pi, as a double.



This code follows our pseudocode pretty closely. We've factored out the derivative of arcsin into it's own fucniton, that way we can just call it for a quick evaluation. This code also includes timing functionality. C isn't very flexible when it comes to returns, so we have to use an external variable pasesd by reference to get the timing information out. 

**Testing Code:**

```
void testPiSeq() {
    double time = 0;
    
    for (int i = 1; i <= 1000000; i *= 10) {
        double approx = pi(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }

}
```

In this case, we simply run a sequence of approximations for pi using our function. We print the result as well as how long it took to the conosle, so we can test the gcc optimzation flags. 

**Test Output (Unoptimized):**

```
Pi With 1 Iterations: 9.5262794416 (0.0000013000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000002000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000007000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000056000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000547000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0005586000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0058283000 Seconds)
```

**Test Output (o1):**

```
Pi With 1 Iterations: 9.5262794416 (0.0000013000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000001000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000003000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000029000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000293000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0002926000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0030220000 Seconds)
```

In this case, our method experiences a pretty decent performance boost. Our final call is about twice as fast.

**Test Output (o2):**

```
Pi With 1 Iterations: 9.5262794416 (0.0000012000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000001000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000003000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000030000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000416000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0003039000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0029896000 Seconds)
```

In this case, we experience basically no gain over the previous optimization.

**Test Output (o3):**

```
Pi With 1 Iterations: 9.5262794416 (0.0000011000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000001000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000004000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000030000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000292000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0002917000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0029704000 Seconds)
```

In this case, there is no difference in performance over the pervious optimization.



It shoudl be noted that every optimization level still returned the same results for our approximation, so using the optimization flags shouldn't affect our accuracy. In this example, only 10 digits of precision were used, but the results seem to match for up to full length double precision, but the results were a little too verbose to fit into this report. 





## Task 3

**Parallel Implementation Code (C):**

```

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "pi.c"

#define NUM_THREADS 2
double piParellel(int steps, double* time) {
    int threadsUsed = NUM_THREADS;
    double startTime = omp_get_wtime();
    double total4[NUM_THREADS];
    double total2[NUM_THREADS];

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
        total4[id] = 0.0;
        total2[id] = 0.0;

        for (int i = id; i < iterations; i+=numThreads) {
            x = (2 * i + 1) * h;
            total4[id] += arcSinPrime(x);
            x += h;
            total2[id] += arcSinPrime(x);
        }
    }

    if (iterations > 0) {
            total4[0] += arcSinPrime(sqrt(3) / 2 - h);
    }


    double total4Sum = 0;
    double total2Sum = 0;
    for (int i = 0; i < threadsUsed; i++) {
        total4Sum += total4[i];
        total2Sum += total2[i];
    }

    total4Sum *= 4;
    total2Sum *= 2;

    double total = (total4Sum + total2Sum + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "pi.c"

#define NUM_THREADS 2
double piParellel(int steps, double* time) {
    int threadsUsed = NUM_THREADS;
    double startTime = omp_get_wtime();
    double total4[NUM_THREADS];
    double total2[NUM_THREADS];
    double x = 0;

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

        total4[id] = 0.0;
        total2[id] = 0.0;

        for (int i = id; i < iterations; i+=numThreads) {
            x = (i + 1) * h;
            total4[id] += arcSinPrime(x);
            x += h;
            total2[id] += arcSinPrime(x);
        }
    }

    total4[0] += arcSinPrime(x + h);

    double total4Sum = 0;
    double total2Sum = 0;
    for (int i = 0; i < threadsUsed; i++) {
        total4Sum += total4[i];
        total2Sum += total2[i];
    }

    total4Sum *= 4;
    total2Sum *= 2;

    double total = (total4Sum + total2Sum + 3.0) * (3.0 * h / 3.0);
    *time = omp_get_wtime() - startTime;
    return total;
}


```

This function accepts the following parameters:

* Steps: Integer. Number of steps to approximate pi with.

* Time: Double. Return variable used to keep track of timing data.

  

It returns the approximation of pi, as a double.

This code uses the same method as before, but this time we've included omp, and use it to perform parts of the calculation in parrelel. As each iteration over the loop can be performed independant of the others, we can calculate these values by assigning each thread a non-sequential "slice" of of the problem, and combining the results from our subproblems. The number of threads used is currently hardcoded, but as far as I'm aware, it's entirley possible to determine it programatically at run time. 

**Testing Code:**

```
void testPiPar() {
        double time = 0;
    
    for (int i = 1; i <= 1000000; i *= 10) {
        double approx = piParellel(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }
}
```

This is exactly the same code for our sequential method, it just calls our parellel method instead.

**Testing Output (1 Threads):**

```
Pi With 1 Iterations: 2.5980762114 (0.0000050000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000022000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000040000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000068000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000626000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0006420000 Seconds)

Pi With 1000000 Iterations: 3.1415926536 (0.0063371000 Seconds)
```

As we can see, our function is a little slower when only using one thread. This is to be expected, due to the overhead of omp as well as combining results.

**Testing Output (2 Threads):**

```
Pi With 1 Iterations: 2.5980762114 (0.0000617000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000020000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000015000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000091000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000895000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0008360000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0081875000 Seconds)
```

Now this is where things get a little weird. Not only do we not get any improvment, things got worse. This is due to the whole false sharing thing talked about in the openMP videos. After padding the arrays, we begin to see the improvments from multithreading.

**Updated Code:**

```

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include "pi.c"

#define NUM_THREADS 2
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

In this case, we simply "padded" each cell of our array by using a two dimensional array, to ensure that cache tomfoolery won't impact our performance.

**Test Output (2 Threads):**

```
Pi With 1 Iterations: 2.5980762114 (0.0000938000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000023000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000017000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000050000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000460000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0003286000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0031665000 Seconds)
```

**Test Output (4 Threads):**

```
Pi With 1 Iterations: 2.5980762114 (0.0001495000 Seconds)
Pi With 10 Iterations: 3.1424775218 (0.0000024000 Seconds)
Pi With 100 Iterations: 3.1415927928 (0.0000014000 Seconds)
Pi With 1000 Iterations: 3.1415926536 (0.0000073000 Seconds)
Pi With 10000 Iterations: 3.1415926536 (0.0000673000 Seconds)
Pi With 100000 Iterations: 3.1415926536 (0.0001666000 Seconds)
Pi With 1000000 Iterations: 3.1415926536 (0.0015788000 Seconds)
```

As we can see, we get a massive increase in performance by increasing the number of threads in this case. The timing is still kind of unstable, and I'm guessing that's because there's a lot going on with my while I'm testing this, so the threads might have to wait for cpu time. 


## Task 4




## Task 5

