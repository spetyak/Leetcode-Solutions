#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Runtime: Beats 88.89% of C submissions
 * Memory: Beats 77.78% of C submissions
 */

#define MAX_STRING_LENGTH 30

/*
 * Determines if the string s1 can be scrambled into the string s2
 * using the algorithm described in the LeetCode 87 problem description.
 *
 * @param s1 the string to scramble
 * @param s2 the target string
 * 
 * @return True if the string s1 can be scrambled into s2 using the algorithm, False if not
 */
bool isScramble(char* s1, char* s2) {

    int stringsSize = strnlen(s1, MAX_STRING_LENGTH);

    bool dpTable[stringsSize+1][stringsSize+1][stringsSize+1];
    memset(dpTable, false, sizeof(dpTable));

    // length of substring
    for (int length = 1; length <= stringsSize; length++)
    {

        // s1 substring start
        for (int i = 0; i+length <= stringsSize; i++)
        {

            // s2 substring start
            for (int j = 0; j+length <= stringsSize; j++)
            {

                // base case, check if the strings match each other at their current positions
                if (length == 1)
                {
                    dpTable[i][j][length] = (s1[i] == s2[j]);
                    continue;
                }

                // loop through possible splits of s1
                for (int split = 1; split < length; split++)
                {

                    if (dpTable[i][j][split] && dpTable[i+split][j+split][length-split])
                    {
                        dpTable[i][j][length] = true;
                        break;
                    }

                    if (dpTable[i][j+split][length-split] && dpTable[i+length-split][j][split])
                    {
                        dpTable[i][j][length] = true;
                        break;
                    }

                }

            }

        }

    }

    

    return dpTable[0][0][stringsSize];
    
}

int main() {

    char* str1 = "great";
    char* str2 = "rgeat";
    
    bool output = isScramble(str1, str2);

    if (output)
    {
        printf("Output: TRUE\n");
    }
    else
    {
        printf("Output: FALSE\n");
    }

    return 0;

}
