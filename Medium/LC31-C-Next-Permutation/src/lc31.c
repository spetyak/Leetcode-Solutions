#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
 * Author: spetyak
 *
 * Runtime: Beat 28.21% of C submissions
 * Memory: Beat 62.39% of C submissions
 */

void countingSort(int*, int, int, int, int);
void nextPermutation(int*, int);

void countingSort(int* nums, int numSize, int startIndex, int endIndex, int max) {

    int currentNum = 0;

    // initialize count array to all 0's 
    int counts[max+1];
    memset(counts, 0, (max+1)*sizeof(int));

    // initialize nums copy array to all 0's
    int copyNums[numSize];
    memset(copyNums, 0, (numSize)*sizeof(int));

    // count num occurences in nums array
    for (int i = startIndex; i < endIndex; i++)
    {
        counts[nums[i]]++;
    }

    // update count array
    for (int i = 0; i < max; i++)
    {
        counts[i+1] = counts[i] + counts[i+1];
    }

    // unpack information from count array to populate copy array
    for (int i = endIndex-1; i >= startIndex; i--)
    {

        currentNum = nums[i]; 

        copyNums[(counts[currentNum] - 1) + startIndex] = currentNum; 

        counts[currentNum]--;

    }

    // copy relevant data to original array
    for (int i = startIndex; i < endIndex; i++)
    {
        nums[i] = copyNums[i];
    }

}

void nextPermutation(int* nums, int numsSize) {

    int temp = 0;
    int check = 1;

    if (numsSize < 2)
    {
        return;
    }
    else if (numsSize == 2)
    {

        temp = nums[1];
        nums[1] = nums[0];
        nums[0] = temp;

        return;

    }

    int totalMax = -1;

    int closestMax = -1;
    int closestMaxIndex = -1;

    // find max value
    for (int i = 0; i < numsSize; i++)
    {

        if (nums[i] > totalMax)
        {
            totalMax = nums[i];
            closestMax = nums[i];
            closestMaxIndex = i;
        }

    }

    

    // walk backwards through nums array
    for (int i = numsSize-2; i >= 0; i--)
    {

        // if the left number is smaller than the right number it can be increased
        if (nums[i] < nums[i+1])
        {
            
            check = 0; // failed final permutation check

            // find closest max
            for (int j = i; j < numsSize; j++)
            {

                if (nums[j] > nums[i])
                {

                    if (nums[j] <= closestMax)
                    {
                        closestMax = nums[j];
                        closestMaxIndex = j;
                    }

                }

            }

            // swap offending number with max
            temp = nums[i];
            nums[i] = nums[closestMaxIndex];
            nums[closestMaxIndex] = temp;

            // sort remaining numbers on the right
            countingSort(nums, numsSize, i+1, numsSize, totalMax);

            break;

        }

    }

    // if the num array was in its final permutation (can not be increased), reset it
    if (check)
    {
        countingSort(nums, numsSize, 0, numsSize, totalMax);
    }

}

int main() {

    int nums[] = {2, 1, 3}; 
    int numsSize = 3;

    nextPermutation(nums, numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;

}
