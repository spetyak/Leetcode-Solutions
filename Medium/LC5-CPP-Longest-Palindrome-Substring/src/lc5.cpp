#include <iostream> 
#include <vector>
#include <string>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 46.38%
 * Memory: Beats 13.32%
 */

class Solution {
public:

    string longestPalindrome(string s) {

        vector<vector<int>> dpTable (s.size(), vector<int> (s.size()));

        int maxLen = 0; // the length of the longest palindromic substring found
        int maxStart = 0; // the start index of the longest palindromix substring
        int maxEnd = 0; // the end index of the longest palindromic substring found

        int len = 0; // the length of the current palindromic substring being examined
        int m = 0; // the dynamic programming table x index
        int n = 0; // the dynamic programming table y index
        int startIndex = 0; // the start index of the current palindromic substring
        int endIndex = 0; // the end index of the current palindromic substring
        int climbed = 0; // integer used to check / prevent going laterally after going diagonally

        // populate dynamic programming table, marking matching letters with 1
        for (int i = 0; i < s.size(); i++)
        {

            for (int j = i; j < s.size(); j++)
            {

                if (i == j)
                {
                    dpTable[i][j] = 1;
                }
                
                if (s.at(i) == s.at(j))
                {
                    dpTable[i][j] = 1;
                }

            }

        }

        

        for (int i = 0; i < s.size(); i++) // travel along diagonal
        {

            len = 1; // a string has a palindrome of at least size 1
            m = i; // diagonal x position
            n = i; // diagonal y position
            startIndex = i; // start index of current palindrome
            endIndex = i; // end index of current palindrome
            climbed = 0; // set to 0 to represent false

            while (m >= 0 && n < s.size()-1) 
            {

                if (m != 0 && dpTable[m-1][n+1] == 1) // if the diagonal right from the current position is 1, meaning a letter repeats
                {

                    len += 2; // increase length by two since palindrome will have same letter on both sides
                    startIndex -= 1;
                    endIndex += 1;
                    climbed = 1;
                    m--;
                    n++;
                    
                }
                else if (climbed == 0 && dpTable[m][n+1] == 1)
                {

                    len += 1; // increase length by one since the same letter repeated
                    endIndex += 1;
                    n++;

                }
                else
                {
                    break;
                }

            }
            
            // update max length palindrome as necessary
            if (len > maxLen)
            {
                maxLen = len;
                maxStart = startIndex;
                maxEnd = endIndex;
            }

        }



        // build the longest palindrome substring found
        string outputStr = "";

        for (int i = maxStart; i < maxEnd+1; i++)
        {
            outputStr += s.at(i);
        }

        return outputStr;

    }

};