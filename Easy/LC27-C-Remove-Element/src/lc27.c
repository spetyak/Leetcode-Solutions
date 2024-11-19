#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 86.84% of C submissions
 */

/*
 * Given an integer array and a target integer, 
 * removes all occurrences of the target value in the array.
 *
 * @param nums the integer array to be modified
 * @param numsSize the size of the given array
 * @param val the value to be removed from the integer array
 * 
 * @return The size of the modified array
 */
int removeElement(int* nums, int numsSize, int val) {
    
    int current = 0;        // the current index of the array
    int lastNonTarget = 0;  // the index of the end of the non-target sub array

    // loop through nums array
    while (current < numsSize)
    {

        // if the current number is not the target value
        if (nums[current] != val)
        {
            nums[lastNonTarget] = nums[current]; // add it to the non-target sub array
            lastNonTarget++;
        }

        current++;

    }

    return lastNonTarget; // return the size of the non-target sub array

}

int main() {

    int nums[] = {0,1,2,2,3,0,4,2};
    int numsSize = 8;
    int val = 2;

    int output = removeElement(nums, numsSize, val);

    for (int i = 0; i < output; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;

}