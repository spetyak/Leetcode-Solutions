#include <iostream>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 87.45% of C++ submissions
 */

class Solution {
public:

    /*
     * Given a non-negative integer x, returns the square root of x 
     * rounded down to the nearest integer.
     *
     * @param x the number to do the square root operation on
     * 
     * @return the square root of the given number, rounded to the nearest integer
     */
    int mySqrt(int x) {

        int leftPtr = 1;    // the left boundary of the binary search window
        int rightPtr = x/2; // the right boundary of the binary search window, sqrt(x) can be no bigger than x/2
        int midVal = -1;    // the middle value of the binary search window

        // base case
        if (x <= 1)
        {
            return x;
        }

        // perform binary search until square root is found
        while (true)
        {

            // instead of checking using multiplication, check using division
            // if the given number x divided by the midval equals itself, you found the square root
            // yippee :y

            midVal = (leftPtr + rightPtr) / 2; // determine the middle value of the binary search window

            if (midVal <= (x / midVal) && (midVal+1) > (x / (midVal+1))) // if midVal is too small BUT midVal+1 is too large, the square root has been found
            {
                return midVal;
            }
            else if (midVal < (x / midVal)) // midVal is too small, increase
            {
                leftPtr = midVal + 1;
            }
            else // miVal > (x / midVal) // midVal is too large, decrease
            {
                rightPtr = midVal - 1;
            }

        }

        return -1;
        
    }

};

int main() {

    Solution s;

    int x = 4;

    int output = s.mySqrt(x);

    printf("Output: %d\n", output);

    return 0;

}