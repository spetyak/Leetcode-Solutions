#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 44.00% of C++ submissions
 */

class Solution {
public:

    /*
     * Given a string s, returns whether s is a valid number.
     * The string can contain alphanumeric characters, +/- signs, and a decimal point.
     *
     * @param s the given string to be checked
     * 
     * @return True if the given string is a valid number, False if not
     */
    bool isNumber(string s)
    {

        bool decimalPointPresent = false;   //
        bool exponentPresent = false;       //

        for (int i = 0; i < s.size(); i++)
        {

            char currentChar = s.at(i); //

            if (isalnum(currentChar)) //
            {

                if (isalpha(currentChar)) // alphabetic
                {

                    currentChar = toupper(currentChar); // convert to upper to do one less check

                    // ensure E is not the first or last character and no other exponents are present
                    if (currentChar == 'E' and i != 0 and i < s.size()-1 and !exponentPresent) 
                    {
                        exponentPresent = true; // update flag so that the current exponent is the only legal one
                        continue;
                    }
                    else
                    {
                        return false;
                    }

                }
                else // numeric
                {
                    continue;
                }

            }
            else // symbolic character
            {

                if (currentChar == '-' or currentChar == '+') // only allow +/- signs
                {

                    if (i == 0) // if signing leading integer
                    {

                        // check if followed by digit or decimal point
                        if (i+1 < s.size() and (isdigit(s.at(i+1)) or s.at(i+1) == '.'))
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }

                    }
                    else if (toupper(s.at(i-1)) == 'E') // if following an E
                    {
                        
                        // check if followed by digit (not legal for decimal point following E)
                        if (i+1 < s.size() and isdigit(s.at(i+1)))
                        {
                            continue;
                        }
                        else
                        {
                            return false;
                        }

                    }
                    else
                    {
                        return false;
                    }

                }
                else if (currentChar == '.') // decimal point
                {

                    // if no exponent or other decimal point has been encountered yet
                    if (!exponentPresent and !decimalPointPresent) 
                    {

                        // check before and after for a digit

                        if (i-1 >= 0 and isdigit(s.at(i-1)))
                        {
                            decimalPointPresent = true;
                            continue;
                        }
                        
                        if (i+1 < s.size() and isdigit(s.at(i+1)))
                        {
                            decimalPointPresent = true;
                            continue;
                        }

                        return false;
                        
                    }
                    else
                    {
                        return false;
                    }

                }
                else
                {
                    return false;
                }

            }

        }

        // . cannot come after e or E
        // - or + can only come very first and/or right after an e or E
        // e or E MUST be followed by a number

        return true;

    }

};

int main() {

    Solution s;

    string input = "1e";

    cout << "Output: " << s.isNumber(input) << endl;

    return 0;

}