/**
* Caclulates the Accuracy of A Single (in Bits)
* Returns: The Number of Digits of Accuracy a Single is Capable of Displaying
*/
int accuracySingle(int maxLoops) {
        float one = 1.0f;
        float modifier = 1.0f;

        for (int i=0; i < maxLoops; i++) {
            if (one - (one + modifier) == 0) {
                return i;
            }
            modifier /= 2.0f;
        }

        return -1;
    }