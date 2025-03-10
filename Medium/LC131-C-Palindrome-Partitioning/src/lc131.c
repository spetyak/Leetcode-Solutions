
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 5.33% of C submissions
 * Memory: Beats 5.33% of C submissions
 */

#define MAX_STRING_LENGTH 16

char*** outputList;     // the list containing all substring partitions of the given string
int outputIndex;        // the current partition being added to the output list
int outputCapacity;     // the current capacity of the output list
int* listSizes;         // global pointer used to help update partition list sizes

/*
 * Checks if the given string is a palindrome.
 *
 * @param s the string to be checked
 * @param sLength the length of the given string
 * 
 * @return 1 if the given string is a palindrome, 0 if it is not.
 */
int checkPalindrome(char* s, int sLength) {

    if (sLength == 1)
    {
        return 1;
    }

    for (int i = 0; i < sLength / 2; i++)
    {

        if (s[i] != s[sLength - i - 1])
        {
            return 0;
        }

    }

    return 1;

}

/*
 * Description
 *
 * @param s
 * @param list
 * @param listIndex
 * @param low
 * @param high
 */
void helper(char* s, char** list, int listIndex, int low, int high) {

    if (high > strnlen(s, MAX_STRING_LENGTH))
    {
        return;
    }

    int length = high - low;
    char* substr = malloc((length+1) * sizeof(char));
    strncpy(substr, s + low, length);
    substr[length] = '\0';

    if (checkPalindrome(substr, length))
    {

        if (high + 1 > strnlen(s, MAX_STRING_LENGTH))
        {

            int currentListSize = listIndex + 1;

            list[listIndex] = substr;

            // add/copy to output list
            outputList[outputIndex] = malloc(currentListSize * sizeof(char**));
            for (int i = 0; i < currentListSize; i++)
            {
                int currentStrLength = strnlen(list[i], MAX_STRING_LENGTH);
                outputList[outputIndex][i] = malloc((currentStrLength + 1) * sizeof(char));
                strncpy(outputList[outputIndex][i], list[i], currentStrLength);
                outputList[outputIndex][i][currentStrLength] = '\0';
            }
            
            listSizes[outputIndex] = currentListSize;
            outputIndex++;

            if (outputIndex == outputCapacity) // up output capacity if it has been reached
            {

                outputCapacity *= 2;
                outputList = realloc(outputList, outputCapacity * sizeof(char**));
                listSizes = realloc(listSizes, outputCapacity * sizeof(int));

            }

            free(list[listIndex]);
            list[listIndex] = NULL;

            return;

        }
        else
        {

            list[listIndex] = substr;
            listIndex++;
            helper(s, list, listIndex, low+length, high+1); // DON'T attempt to add to the current palindrome 
            listIndex--;

            helper(s, list, listIndex, low, high+1); // DO attempt to add to the current palindrome 
            free(list[listIndex]);
            list[listIndex] = NULL;

        } 

    }
    else // if the current substring is not a palindrome, it can only be considered with other characters until a palindrome is formed or all letters have been used
    {

        list[listIndex] = substr;
        helper(s, list, listIndex, low, high+1); // DO attempt to add to the current palindrome 
        free(list[listIndex]);
        list[listIndex] = NULL;

    }

}

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome. 
 * Return all possible palindrome partitioning of s.
 *
 * @param s the string to be partitioned into palindromes
 * @param returnSize the number of ways s can be partitioned into palindromes
 * @param returnColumnSizes the number of palindromes in each partition of s
 * 
 * @return a list containing all possible palindrome partitioning of s
 */
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    
    outputList = malloc(100 * sizeof(char**));
    outputCapacity = 100;
    outputIndex = 0;

    char** list = malloc(MAX_STRING_LENGTH * sizeof(char*));
    listSizes = malloc(100 * sizeof(int));

    helper(s, list, 0, 0, 1);
    
    free(list);

    *returnSize = outputIndex;
    *returnColumnSizes = listSizes;

    return outputList;

}

int main() {

    char* str = "efe";
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    char*** output = partition(str, &returnSize, &returnColumnSizes);

    // print output list of 
    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%s ", output[i][j]);
        }
        printf("] ");
    }
    printf("]\n");

    // free output list and return column array
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            free(outputList[i][j]);
        }
        free(outputList[i]);
    }
    free(outputList);
    free(returnColumnSizes);

    return 0;

}