#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 75.16% of C++ submissions
 */

class Solution {
public:

    /*
     * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
     *
     * @param s1 a string to be interleaved with string s2
     * @param s2 a string to be interleaved with string s1
     * @param s3 a string which is the possible result of interleaving strings s1 and s2
     * 
     * @return True if s3 is a possilbe result of interleaving s1 and s2, False if not.
     */
    bool isInterleave(string s1, string s2, string s3) {

        // if the interleaved string s3 is not the same length as s1 and s2 combined
        // it cannot possibly be the result of interleaving s1 and s2
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        // initialize dynamic programming table
        vector<vector<bool>> dpTable(s1.size()+1, vector<bool>(s2.size()+1));
        dpTable[s1.size()][s2.size()] = true;

        // working from the end of string s3 and the end of strings s1 and s2,
        // consider possible uses of the letters from s1 and s2 to build s3
        for (int i = s1.size(); i >= 0; i--)
        {

            for (int j = s2.size(); j >= 0; j--)
            {

                // if the current s1 character matches the current s3 character and later s1 characters have already been used
                if (i < s1.size() and s1[i] == s3[i + j] and dpTable[i+1][j])
                {
                    dpTable[i][j] = true;
                }

                // if the current s2 character matches the current s3 character and later s2 characters have already been used
                if (j < s2.size() and s2[j] == s3[i + j] and dpTable[i][j+1])
                {
                    dpTable[i][j] = true;
                }

            }

        }



        return dpTable[0][0];
        
    }

};

int main() {

    Solution s;

    

    return 0;

}