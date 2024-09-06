#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 25.82% of C++ submission
 * 
 */

class Solution {
public:

    bool isPalindrome(int x) {

        if (x < 0) // if negative, not considered a palindrome due to the '-'
        {
            return false;
        }
        else if (x / 10 == 0) // if input number is less than 10
        {
            return true;
        }

        int temp = x;                       // temp variable used to determine number of digit places
        int numPlaces = 0;                  // the number of digit places in the input number
        int lowDigitIndex = 0;              // the index of the current low digit being examined
        int upperDigitIndex = numPlaces-1;  // the index of the current high digit being examined
        int lowerDigit = 0;                 // the low digit being examined
        int upperDigit = 0;                 // the high digit being examined

        // determine number of digit places in input number
        while (temp != 0) 
        {
            numPlaces++;
            temp /= 10;
        }



        if (numPlaces % 2 == 0) // even length number
        {

            while (lowDigitIndex != upperDigitIndex-1) // while not at the center two digits
            {

                if (lowDigitIndex == 0)
                {
                    lowerDigit = x % 10;
                }
                else
                {
                    lowerDigit = (x / ((int) pow(10, lowDigitIndex))) % 10;
                }
                
                upperDigit = (x / ((int) pow(10, upperDigitIndex))) % 10;

                if (lowerDigit != upperDigit) // if digits don't match, not a palindrome
                {
                    return false;
                }

                lowDigitIndex++;
                upperDigitIndex--;

            }

            // check the two center digits
            lowerDigit = (x / ((int) pow(10, lowDigitIndex))) % 10;
            upperDigit = (x / ((int) pow(10, upperDigitIndex))) % 10;

            if (lowerDigit != upperDigit)
            {
                return false;
            }
            else
            {
                return true;
            }

        }
        else // odd length number
        {

            while (lowDigitIndex != upperDigitIndex) // while not at the center digit
            {

                if (lowDigitIndex == 0)
                {
                    lowerDigit = x % 10;
                }
                else
                {
                    lowerDigit = (x / ((int) pow(10, lowDigitIndex))) % 10;
                }

                upperDigit = (x / ((int) pow(10, upperDigitIndex))) % 10;

                if (lowerDigit != upperDigit) // if digits don't match, not a palindrome
                {
                    return false;
                }

                lowDigitIndex++;
                upperDigitIndex--;

            }

            return true;

        }

    }

};

int main() {

    Solution s;

    int x = 1234554321;

    bool output = s.isPalindrome(x);

    cout << "Output: " << output << endl;

    return 0;

}
