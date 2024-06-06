#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 42.24% of C submissions
 * Memory: Beats 83.03% of C submissions
 */

int factorial(int);
void computePermutations(int*, int*, int*, int, int, int***, int*);
int** permute(int*, int, int*, int**);

int factorial(int num) {

    int output = 1;
    for (int i = num; i > 0; i--)
    {
        output *= i;
    }

    return output;
    
}

void computePermutations(int* nums, int* tracker, int* currentPerm, int numsSize, int currentSize, int*** output, int* answerIndex) {

    if (currentSize == numsSize) // if the current permutation is complete
    {

        for(int i = 0; i < currentSize; i++)
        {
            (*output)[(*answerIndex)][i] = currentPerm[i]; // update the output array with the current permutation
        }

        (*answerIndex)++; // increment answer index for next permutation to be added to output array

        return;

    }
    else
    {

        for (int i = 0; i < numsSize; i++)
        {

            if (tracker[i] != 0) // if this number in nums has not already been used yet
            {
                // add the current number to the current permutation
                tracker[i] = 0;
                currentPerm[currentSize] = nums[i];
                currentSize++;

                // continue down the tree of permutations with the current permutation
                computePermutations(nums, tracker, currentPerm, numsSize, currentSize, output, answerIndex);

                // remove the number that was added from the current permutation
                currentSize--;
                currentPerm[currentSize] = -1;
                tracker[i] = 1;

            }

        }

    }

}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int outputSize = factorial(numsSize);

    // set return sizes
    *returnColumnSizes = malloc(outputSize * sizeof(int));
    memset(*returnColumnSizes, 0, (outputSize * sizeof(int)));
    for (int i = 0; i < outputSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = outputSize;

    // initialize output array
    int** output = malloc(outputSize * sizeof(int*));
    for (int i = 0; i < outputSize; i++)
    {
        output[i] = malloc(numsSize * sizeof(int));
        memset(output[i], 0, (numsSize * sizeof(int)));
    }

    // initialize array to hold the current permutation
    int* currentPerm = malloc(numsSize * sizeof(int));
    memset(currentPerm, -1, (numsSize * sizeof(int)));

    // initialize array to track which indices have already been added to the current permutation
    int* tracker = malloc(numsSize * sizeof(int));
    memset(tracker, 1, (numsSize * sizeof(int)));

    int currentSize = 0; // the size of the permutation currently being built
    int answerIndex = 0; // the index where the next permutation should be placed in the output array

    computePermutations(nums, tracker, currentPerm, numsSize, currentSize, &output, &answerIndex);

    free(tracker);
    free(currentPerm);

    return output;
    
}

int main() {

    int nums[] = {1, 2, 3};
    int numsSize = 3;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** output = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {

        for (int j = 0; j < numsSize; j++)
        {
            printf("%d ", output[i][j]);
        }

        printf("\n");

    }

    free(returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        free(output[i]);
    }
    free(output);

    return 0;

}