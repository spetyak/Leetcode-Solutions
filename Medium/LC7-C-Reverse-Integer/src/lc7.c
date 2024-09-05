#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 49.45% of C submissions
 * Memory: Beats 30.35% of C submissions
 */

/*
 * Reverses the digits of a given integer
 *
 * x - integer to be reversed
 */
int reverse(int x) {

    int temp = x;           // temporary value used to help determine number of places in input value
    int numPlaces = 0;      // the number of digit places in the input value
    int currentDigit = 0;   // the current digit being compared/swapped
    int output = 0;         // the reversed integer value

    // determine number of digit places in input value
    while (temp != 0) 
    {
        temp /= 10;
        numPlaces++;
    }

    // if the input value has 10 digit places, it is possible reversing it could cause an overflow
    if (numPlaces == 10) 
    {

        int limit = 0;              // the maximum/minimum integer value, based on input value's sign
        int currentLimitDigit = 0;  // the current digit of the limit value being compared/swapped with the input digit
        int keepChecking = 1;       // 0 if value cannot possibly overflow when reversed, 1 if it is possible

        // determine limit value
        if (x < 0) 
        {
            limit = INT_MIN;
        }
        else 
        {
            limit = INT_MAX;
        }

        // for safety, check each place of -2^31 and 2^31 - 1 to ensure no overflows
        // if current place is greater than max or min current place, end

        while (numPlaces >= 1) 
        {

            // compare limit and input digits to be swapped
            currentLimitDigit = (limit / ((int) pow((double) 10, (double) numPlaces-1))) % 10;
            currentDigit = x % 10;
            x /= 10;

            if (keepChecking) {

                if (abs(currentDigit) > abs(currentLimitDigit)) // swapping digits will cause overflow, end
                { 
                    return 0;
                }
                else if (currentDigit == currentLimitDigit) // swapping digits ok, but overflow still possible
                {
                    keepChecking = 1;
                }
                else // current digit less than current limit digit, impossible to overflow
                {
                    keepChecking = 0; 
                }

            }

            output += (currentDigit * ((int) pow((double) 10, (double) numPlaces-1))); // add digit to output at highest place

            numPlaces--;

        }

    }
    else
    {

        while (numPlaces >= 1) 
        {

            // grab digit in ones place and divide by 10
            currentDigit = x % 10;
            x /= 10;

            output += (currentDigit * ((int) pow((double) 10, (double) numPlaces-1))); // add digit to output at highest place

            numPlaces--;

        }
        
    }

    

    return output;

}

int main() {

    int x = -2147483412;

    printf("Output: %d\n", reverse(x));

    return 0;

}