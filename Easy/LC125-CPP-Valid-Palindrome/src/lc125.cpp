#include <iostream>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 33.17% of C++ submissions
 */

class Solution {
public:

    /*
     * Given a string s, returns true if it is a palindrome, or false otherwise.
     *
     * @param s the given string
     * 
     * @return True if the given string is a palindrome, false if it is not.
     */
    bool isPalindrome(string s) {

        string cleaned = ""; // 

        // walk through string adding alphanumeric characters to a cleaned string
        for (int i = 0; i < s.size(); i++)
        {

            if (isalnum(s[i]))
            {

                if (isalpha(s[i]))
                {
                    cleaned.push_back(tolower(s[i])); // add lowercase letter to cleaned string
                }
                else
                {
                    cleaned.push_back(s[i]); // add number to cleaned string
                }

            }
            

        }

        // work to center from boths ends of string checking if cleaned string is a palindrome
        for (int i = 0; i < cleaned.size() / 2; i++)
        {

            if (cleaned[i] != cleaned[cleaned.size() - i - 1])
            {
                return false;
            }

        }

        return true;
        
    }

};

int main() {

    Solution s;

    string str = "A man, a plan, a canal: Panama";

    bool output = s.isPalindrome(str);

    cout << "Output: " << output << endl;

    return 0;

}