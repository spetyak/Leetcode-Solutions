
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Author: spetyak
 *
 * Referenced: https://www.youtube.com/watch?v=Sx9NNgInc3A
 *
 * Runtime: Beats 42.55% of C submissions
 * Memory: Beats 21.81% of C submissions
 */

/*
 * Returns the substring of the given string s starting at index start and ending at index end.
 *
 * @param s the given string
 * @param start the start index of the desired substring
 * @param end the end index of the desired substring
 * 
 * @return The specified substring.
 */
char* getSubstring(char* s, int start, int end) {

    int strLength = strnlen(s, 300); // determine the length of the given string

    // copy the specified section of string s into the new substring and null terminate it
    char* substring = malloc(((end-start) + 1)* sizeof(char));
    strncpy(substring, s+start, end-start);
    substring[end-start] = '\0';

    return substring;

}

/*
 * Given a string s and a dictionary of strings wordDict, return true if s can be segmented 
 * into a space-separated sequence of one or more dictionary words.
 *
 * @param s the given string
 * @param wordDict the dictionary of words that the string can be split into
 * @param wordDictSize the size of the dictionary of words
 * 
 * @return True if all of s can be segmented using dictionary words, False if not.
 */
bool wordBreak(char* s, char** wordDict, int wordDictSize) {

    int sSize = strnlen(s, 300); //

    // initialize a dynamic programming array and set all positions to false
    bool* dp = malloc((sSize+1) * sizeof(bool));
    memset(dp, false, (sSize+1) * sizeof(bool));

    dp[sSize] = true; // set the last position to true (signifying a null string)

    char* substring = NULL; // a string used to hold the current substring of s being considered
    int wordSize = 0;       // the size of the current word being considered

    for (int i = sSize-1; i >= 0; i--) // loop backwards through s letters
    {

        for (int j = 0; j < wordDictSize; j++) // loop through dictionary words
        {

            wordSize = strnlen(wordDict[j], 20); // determine the length of the current word

            if (i + wordSize <= sSize) // if the current dictionary word could fit starting from i
            {

                substring = getSubstring(s, i, i+wordSize); // get the substring starting at i

                if (strncmp(substring, wordDict[j], 20) == 0) // if the substring and word match
                {
                    dp[i] = dp[i + wordSize]; // update the dynamic programming array
                }

                free(substring); // free the substring memory

            }

            if (dp[i]) // if a word could be used here there is no need to do more work
            {
                break;
            }

        }

    }

    bool output = dp[0]; // note if all of s can be broken into the dictionary words

    free(dp); // free the DP array memory
    
    return output;
    
}

int main() {

    char* s = "cbca";
    char* wordDict[] = {"bc", "ca"};
    int wordDictSize = 2;

    bool output = wordBreak(s, wordDict, wordDictSize);

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