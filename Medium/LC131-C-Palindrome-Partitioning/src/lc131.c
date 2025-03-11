
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 69.56% of C submissions
 * Memory: Beats 86.96% of C submissions
 */

#define MAX_STRING_LENGTH 16

char*** outputList;         // the list containing all palindromic partitions of the given string 
int outputIndex;            // the new index of the output list to populate, also the list's size
int* outputPartitionSizes;  // the number of splits in each partition in the output list

/*
 * Determines if the given string is a palindrome.
 *
 * @param s the string to be checked
 * 
 * @return 1 if the given string is a palindrome, 0 if it is not.
 */
int checkPalindrome(char* s) {

    int sLength = strnlen(s, MAX_STRING_LENGTH);

    for (int i = 0; i < sLength/2; i++)
    {
        if (s[i] != s[sLength - i - 1])
        {
            return 0;
        }
    }

    return 1;

}

/*
 * Partitions the given source string into palindromic substrings by performing a DFT where
 * palindromic substrings allow for further traversal if possible.
 * Adds the resulting palindromic partition to the list of all possible palindromic 
 * partitions of the source string.
 *
 * @param currentPartition the current palindromic partitioning being built from the source string
 * @param numPartitions the number of partitions in the current partition
 * @param partitionSizes the number of characters in each partition 
 * @param sourceStr the string to be partitioned into different palindromes
 * @param sourceStrLen the length of the given string to be partitioned
 * @param sourceIndex the start index of the remaining substring
 */
void helper(char** currentPartition, int numPartitions, int* partitionSizes, char* sourceStr, int sourceStrLen, int sourceIndex) {

    if (sourceIndex >= sourceStrLen) // check if all characters of the source string have been used
    {

        // add to output list
        char** partitionCopy = malloc(numPartitions * sizeof(char*));
        for (int i = 0; i < numPartitions; i++)
        {
            partitionCopy[i] = malloc((partitionSizes[i]+1) * sizeof(char));
            memset(partitionCopy[i], '\0', (partitionSizes[i]+1) * sizeof(char));
            strncpy(partitionCopy[i], currentPartition[i], partitionSizes[i]);
        }
        outputList[outputIndex] = partitionCopy;
        outputPartitionSizes[outputIndex] = numPartitions;
        outputIndex++;

        return;
    }

    // build substrings using the remaining characters of the source string
    // if a substring is a palindrome, go deeper into the DFT and repeat this process
    for (int i = 0; i < sourceStrLen-sourceIndex; i++)
    {

        // build the substring
        char sub[MAX_STRING_LENGTH+1]; // why did this up the time/space efficiency so much?
        memset(sub, '\0', (MAX_STRING_LENGTH+1) * sizeof(char));
        strncpy(sub, sourceStr+sourceIndex, i+1);

        if (checkPalindrome(sub))
        {

            currentPartition[numPartitions] = sub; // add the substring to the current partition
            partitionSizes[numPartitions] = strnlen(sub, MAX_STRING_LENGTH); // update the size in the size array
            helper(currentPartition, numPartitions+1, partitionSizes, sourceStr, sourceStrLen, sourceIndex+strnlen(sub, MAX_STRING_LENGTH)); // go deeper into dfs

        }

    }

}

/*
 * Given a string s, partitions s such that every substring of the partition is a palindrome. 
 * Returns all possible palindrome partitionings of s.
 *
 * @param s the string to be partitioned into palindromes
 * @param returnSize the number of ways s can be partitioned into palindromes
 * @param returnColumnSizes the number of palindromes in each partition of s
 * 
 * @return A list containing all possible palindrome partitioning of s.
 */
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    
    /*
     * The current partition being created.
     * Will eventually be copied to output list when a valid partition is finished.
     */
    char** currentPartition = malloc(MAX_STRING_LENGTH * sizeof(char*));
    for (int i = 0; i < MAX_STRING_LENGTH; i++)
    {
        currentPartition[i] = malloc((MAX_STRING_LENGTH+1) * sizeof(char));
        memset(currentPartition[i], '\0', (MAX_STRING_LENGTH+1) * sizeof(char));
    }

    /* 
     * Keeps track of the sizes of the current partitions.
     */
    int* partitionSizes = malloc(MAX_STRING_LENGTH * sizeof(int));
    memset(partitionSizes, 0, MAX_STRING_LENGTH * sizeof(int));

    int sLen = strnlen(s, MAX_STRING_LENGTH); // the length of the given string

    int numPossiblePartitions = pow(2, sLen-1); // the upper bound of possibilites is 2^(sLen-1)

    /*
     * Allocate the upper bound of space that may be needed for the given string.
     */
    outputList = malloc(numPossiblePartitions * sizeof(char**));
    outputPartitionSizes = malloc(numPossiblePartitions * sizeof(int));
    memset(outputPartitionSizes, 0, numPossiblePartitions * sizeof(int));

    outputIndex = 0;

    helper(currentPartition, 0, partitionSizes, s, sLen, 0);

    *returnSize = outputIndex;
    *returnColumnSizes = outputPartitionSizes;

    return outputList;

}

int main() {

    // it works for me so screw leetcode if their stuff doesn't wanna run it for god-knows-why

    char* str = "aaaaaaaaaaaaaaaa";
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    char*** output = partition(str, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {

        printf("partition %d: [", i+1);
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {

            printf("%s ", output[i][j]);

        }
        printf("]\n");

    }

    // free the output list
    // free the returnColumnSizes array

    return 0;

}