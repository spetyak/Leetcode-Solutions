#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 97.78% of C submissions
 * Memory: Beats 100% of C submissions
 */

#define MAX_LEN 1000

/*
 * Given two strings s and t, returns the number of distinct subsequences of s which equal t.
 *
 * @param s the haystack string
 * @param t the needle subsequence string
 * 
 * @return The number of distinct subquences of s which equal t.
 */
int numDistinct(char* s, char* t) {

    int output = 0; // the number of distinct subquences of s which equal t

    int sLen = strnlen(s, MAX_LEN); // the length of the haystack string
    int tLen = strnlen(t, MAX_LEN); // the length of the needle subsequence string
    
    // initialize the one-dimensional dynamic programming table
    // initialized with an extra index for a preceding null character
    int* dpTable = malloc((tLen + 1) * sizeof(int));
    memset(dpTable, 0, (tLen + 1) * sizeof(int));
    dpTable[0] = 1;

    char currS = 'a';   // the current s character being examined
    char currT = 'a';   // the current t character being examined

    int preceding = 0;  // the number of distinct subsequences up to the character before the current character
    int current = 0;    // the number of distinct subsequences up to the current character

    for (int i = 0; i < sLen; i++)
    {

        currS = s[i];

        // loop backwards throught the needle subsequence string, summing occurrences when characters match
        for (int j = tLen; j >= 1; j--)
        {

            currT = t[j-1];

            if (currS == currT)
            {

                preceding = dpTable[j-1];
                current = dpTable[j];

                // avoid unnecessarily large additions as problem description said result will be within 32-bit range
                if (preceding <= INT_MAX - current)
                {
                    dpTable[j] += dpTable[j-1];
                }

            }

        }

    }

    output = dpTable[tLen]; // grab the total number of distinct subsequences of t in s

    free(dpTable);

    return output;

}

int main() {

    int output = numDistinct("rabbbit", "rabbit");

    printf("Output: %d\n", output);

    return 0;

}
