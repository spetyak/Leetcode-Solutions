#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 76.94% of C submissions
 * Memory: Beats 92.08% of C submissions
 */
int lengthOfLongestSubstring(char* s) {
    
    int sLen = strnlen(s, 50000);

    int hashTable[256] = {0}; // table of characters in window
    int size = 0; // the current size of the window
    int maxSize = 0; // the size of the maximum valid substring

    int left = 0; // left boundary of window
    int right = 0; // right boundary of window

    while (right < sLen) // no need to continue once right boundary has reached end
    {

        if (hashTable[s[right]] == 0) // if character is not in window
        {

            hashTable[s[right]]++; // increment character count
            right++; // advance right boundary
            size++; // increase window size

        }
        else
        {

            if (left == right) // boundaries are pointing at same character
            {
                right++; // advance right boundary
                size++; // increase window size
            }
            else
            {
                hashTable[s[left]]--; // decrement character count
                left++; // advance left boundary
                size--; // decrease window size
            }

        }

        // update max substring size if necessary
        if (size > maxSize)
        {
            maxSize = size;
        }

    }



    return maxSize;

}

int main() {

    int output = lengthOfLongestSubstring("abcabcbb");
    printf("Output: %d\n", output);

    return 0;

}