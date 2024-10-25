#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 39.51% of C submissions
 */

#define MAX_STRING_LENGTH 100

/*
 * Determines the number of possible decodings from numbers to letters where
 * "1" is mapped to 'A', "2" is mapped to 'B', ..., and "26" is mapped to 'Z'. 
 * Leading zeroes are invalid as and should not be translated as parts of a code.
 *
 * @param s the coded string of numbers
 * 
 * @return The number of possible letter decodings of the given string of numbers
 */
int numDecodings(char* s) {

    int returnVal = 0; // the total number of possible decodings of the given string of numbers

    int stringSize = strnlen(s, MAX_STRING_LENGTH); // determine the size of the given string

    // create a dynamic programming table to track the number of possible combinations
    int* dpTable = malloc((stringSize + 1) * sizeof(int));
    if (!dpTable)
    {
        printf("Unable to allocate dynamic programming table!\n");
        exit(-1);
    }

    // initialize dp table values
    for (int i = 0; i < stringSize; i++)
    {
        dpTable[i] = 0;
    }
    dpTable[stringSize] = 1;

    // go through string numbers from end to front and update possible combinations found
    for (int i = stringSize-1; i >= 0; i--)
    {
        
        if (s[i] == '0') // standalone zero or leading zero cannot count as a code
        {
            dpTable[i] = 0;
        }
        else
        {

            dpTable[i] = dpTable[i+1]; // inherit number of combinations from previous (next) number

            // if the current number can be part of a two-digit number, update the dp table accordingly
            if (i < stringSize-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
            {
                dpTable[i] += dpTable[i+2];
            }

        }

    }

    returnVal = dpTable[0]; // grab number of combinations before freeing table

    free(dpTable);

    return returnVal;

}

int main() {
    
    char* s = "06";

    int output = numDecodings(s);

    printf("Output: %d\n", output);

    return 0;

}