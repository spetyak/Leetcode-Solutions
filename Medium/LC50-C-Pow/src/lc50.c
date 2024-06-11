#include <stdio.h>
#include <math.h>

/**
 * Author:
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 95.81% of C submissions
 */

double myPow(double x, int n) {

    if (n == 0) // anything to the power of 0 is 1
    {
        return 1;
    }
    else if (x == 0 || x == 1 || x == INFINITY || x == -INFINITY) // special values that result in themselves
    {
        return x;
    }
    else if (n > 0) // if n is positive
    {

        if (n % 2 == 0) // if exponent is even
        {
            return myPow(x * x, n / 2);  
        }
        else // if exponent is odd
        {
            return x * myPow(x * x, (n - 1) / 2);
        }

    }
    else // n is negative
    {
        return myPow(1 / x, -(n+1)) / x;
    }

}

int main() {

    double x = 2.0;
    int n = -2;

    printf("Output: %lf\n", myPow(x, n));

    return 0;

}