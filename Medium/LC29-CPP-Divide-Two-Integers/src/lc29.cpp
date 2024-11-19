#include <iostream>
#include <climits>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 91.52% of C++ submissions
 * 
 */

class Solution {
public:

    /*
     * Determines the minimum number of bits needed to represent the given integer.
     *
     * @param num the integer being measured
     * 
     * @return The minimum number of bits needed to represent the given integer.
     */
    int numBits(int num) {

        int retVal = 0;

        while (num > 0)
        {
            num >>= 1;
            retVal++;
        }

        return retVal;

    }

    /*
     * Divides two integers without using multiplication, division, and mod operator.
     *
     * @param dividend the number to be divided by the divisor
     * @param divisor the number to divide the dividend by
     * 
     * @return The quotient obtained by dividing the dividend by the divisor.
     */
    int divide(int dividend, int divisor) {
        
        int quotient = 0; 
        int sign = (dividend < 0) ^ (divisor < 0); // get the sign of the result
        int addBack = 0; // an integer used to add 1 back to the result if INT_MIN needs to be flipped

        // avoid overflow errors caused by finding absolute value of INT_MIN
        if (divisor == INT_MIN && dividend != INT_MIN)
        {
            return 0;
        }

        // handle overflows that may be caused by finding an absolute value of the given numbers
        if (dividend == INT_MIN)
        {
            dividend = INT_MAX;
            addBack = 1;
        }
        if (divisor == INT_MIN)
        {
            divisor = INT_MAX;
            addBack = 1;
        }
        
        // make both numbers positive by finding their absolute values
        dividend = abs(dividend);
        divisor = abs(divisor);

        // if the numbers are equal
        if (dividend == divisor)
        {

            if (sign)
            {
                return -1;
            }
            else
            {
                return 1;
            }

        }
        else if (divisor == 1) // if the dividend is being divided by 1, the result is the dividend
        {

            if (sign)
            {

                if (addBack) // indicates the dividend was originally INT_MIN
                {
                    return INT_MIN;
                }
                else
                {
                    return -dividend;
                }

            }
            else
            {
                return dividend;
            }

        }

        int dividendBits = numBits(dividend);   // the number of bits needed to represent the dividend
        int divisorBits = numBits(divisor);     // the number of bits needed to represent the divisor
        int grabWindow = 0;                     // sliding window used to help with binary long division
        int currentDividend = dividend;         // the current remaining dividend

        // create a grab window to use on the dividend that has the same number of bits as the divisor
        for (int i = 0; i < divisorBits; i++)
        {
            grabWindow <<= 1;
            grabWindow |= 1;
        }

        // perform binary long division
        for (int i = dividendBits - divisorBits; i >= 0; i--)
        {

            // if the divisor is less than the current minuend
            if (divisor <= (currentDividend & (grabWindow << i)) >> i)
            {
                currentDividend -= (divisor << i);
                quotient |= (1 << i);
            }
            else
            {
                // increase window size as the subtraction was not possible
                grabWindow <<= 1;
                grabWindow |= 1;
            }

        }

        // if there was an avoided overflow and the current quotient is slightly off, correct it
        if (addBack && currentDividend == divisor-1)
        {
            quotient += 1;
        }

        if (sign)
        {
            return -quotient;
        }
        else
        {
            return quotient;
        }

    }

};

int main() {

    Solution s;

    int dividend = 10;
    int divisor = 3;

    int output = s.divide(dividend, divisor);

    cout << "Output: " << output << endl;

    return 0;

}
