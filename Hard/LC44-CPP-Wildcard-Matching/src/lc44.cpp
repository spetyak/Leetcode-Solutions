#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 92.91% of C++ submissions
 * Memory: Beats 94.25% of C++ submission
 * 
 */

class Solution {
public:

    bool isMatch(string s, string p) {

        bool dpTable[s.size()+1][p.size()+1]; // initialize the DP table

        memset(dpTable, false, sizeof(bool) * (s.size()+1) * (p.size()+1)); // set all indices of the DP table to false

        dpTable[0][0] = true; // set the first index to true

        for (int i = 0; i < s.size()+1; i++)
        {

            for (int j = 0; j < p.size()+1; j++)
            {

                if (i > 0 && j > 0) // disregarding null strings
                {

                    if (s.at(i-1) == p.at(j-1) && dpTable[i-1][j-1] == true) // if the current characters match each other
                    {
                        dpTable[i][j] = true;
                    }
                    else if (p.at(j-1) == '?' && dpTable[i-1][j-1] == true) // if the current rule character is ?
                    {
                        dpTable[i][j] = true;
                    }
                    else if (p.at(j-1) == '*' && (dpTable[i-1][j] == true || dpTable[i][j-1] == true)) // if the current rule character is *
                    {
                        dpTable[i][j] = true;
                    }

                }
                else
                {

                    if (j > 0) // considering a null string
                    {

                        if (p.at(j-1) == '*' && dpTable[i][j-1] == true) // if the current rule character is *
                        {
                            dpTable[i][j] = true;
                        }

                    }

                }


            }

        }
        
        return dpTable[s.size()][p.size()]; // return the final index of the DP table

    }

};



int main() {

    string str = "";
    string rules = "******";

    Solution s;
    bool output = s.isMatch(str, rules);

    cout << "Output: " << output << endl;

    return 0;

}
