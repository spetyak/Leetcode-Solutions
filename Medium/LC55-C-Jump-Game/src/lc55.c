#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 70.60% of C submissions
 * Memory: Beats 98.16% of C submissions
 */



/*
 * Determines if the last position of the given array can be reached
 * by jumping from index to index based of their values (ie. an index
 * with a value of 3 can jump at most 3 spots to the right of the 
 * current index).
 *
 * @param nums the array of integers that define how far each spot can jump to
 * @param numsSize the size of the given array
 * 
 * @return True if the end can be reached, False if not.
 */
bool canJump(int* nums, int numsSize) {
    
    int energy = 0; // the energy available to continue traversing through the array

    // attempt to reach end of array
    for (int i = 0; i < numsSize; i++)
    {

        if (energy < 0) // if there is an energy deficit, the end cannot be reached
        {
            return false;
        }
        else if (nums[i] > energy) // if the current number is larger than energy, use current num
        {
            energy = nums[i];
        }

        energy--; // use one energy to get to next index

    }

    return true;

}

int main() {

    int nums[] = {2,3,1,1,4};
    int numsSize = 5;

    bool output = canJump(nums, numsSize);
    printf("Output: %d\n", output);

    return 0;

}