#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 98.75% of C++ submission
 * 
 */

class Solution {
public:

    /**
     *  @brief  Converts a Roman numeral string to an integer.
     *  @param s The Roman numeral to be converted.
     *  @return  The integer value of the given Roman numeral.
     */
    int romanToInt(string s) {

        int output = 0; // the integer value represented by the Roman numerals

        // loop through characters in Roman numeral string
        for (int i = 0; i < s.length(); i++)
        {

            switch (s.at(i)) // check the current character
            {
                case 'M':
                    output += 1000;
                    break;

                case 'D':
                    output += 500;
                    break;

                case 'C':

                    // check if reductive form is present
                    if (i != s.length()-1 && s.at(i+1) == 'M')
                    {
                        output += 900;
                        i += 1;
                    }
                    else if (i != s.length()-1 && s.at(i+1) == 'D')
                    {
                        output += 400;
                        i += 1;
                    }
                    else
                    {
                        output += 100;
                    }

                    break;

                case 'L':

                    output += 50;
                    break;

                case 'X':

                    // check if reductive form is present
                    if (i != s.length()-1 && s.at(i+1) == 'C')
                    {
                        output += 90;
                        i += 1;
                    }
                    else if (i != s.length()-1 && s.at(i+1) == 'L')
                    {
                        output += 40;
                        i += 1;
                    }
                    else
                    {
                        output += 10;
                    }

                    break;

                case 'V':

                    output += 5;
                    break;

                case 'I':

                    // check if reductive form is present
                    if (i != s.length()-1 && s.at(i+1) == 'X')
                    {
                        output += 9;
                        i += 1;
                    }
                    else if (i != s.length()-1 && s.at(i+1) == 'V')
                    {
                        output += 4;
                        i += 1;
                    }
                    else
                    {
                        output += 1;
                    }

                    break;
            
                default:

                    return -1; // invalid character present

            }

        }

        return output;

    }

};

int main() {

    Solution s;

    string romanNumerals = "LVIII";

    int output = s.romanToInt(romanNumerals);

    cout << "Output: " << output << endl;

    return 0;

}
