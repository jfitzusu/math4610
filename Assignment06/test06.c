#include "../mymodules/approximation/pi.c"
#include "../mymodules/approximation/piparallel.c"

void testPiSeq() {
    double time = 0;
    
    for (int i = 1; i <= 1000000; i *= 10) {
        double approx = pi(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }

}

void testPiPar() {
        double time = 0;
    
    for (int i = 1; i <=  1000000; i *= 10) {
        double approx = piParellel(i, &time);

        printf("Pi With %i Iterations: %.10f (%.10f Seconds)\n", i, approx, time);
    }
}

int main() {
    testPiSeq();
    testPiPar();
}

