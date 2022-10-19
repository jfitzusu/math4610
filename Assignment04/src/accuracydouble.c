
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Caclulates the Accuracy of A Double (in Bits)
* Returns: The Number of Digits of Accuracy a Double is Capable of Displaying
*/
int accuracyDouble(int maxLoops) {
        double one = 1.0f;
        double modifier = 1.0f;

        for (int i=0; i < maxLoops; i++) {
            if (one - (one + modifier) == 0) {
                return i;
            }
            modifier /= 2.0f;
        }

        return -1;
    }

