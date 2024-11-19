#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 98.01% of C submissions
 */


/*
 * Given an array nums with n objects colored red, white, or blue, 
 * sorts them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue.
 * 
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 *
 * @param nums the given array of unsorted colors
 * @param numsSize the size of the given array
 */
void sortColors(int* nums, int numsSize) {

    int colorCount[3] = {0}; // the count of each color in the given array

    // count the number of each color in the given array
    for (int i = 0; i < numsSize; i++)
    {
        colorCount[nums[i]]++;
    }

    int j = 0; // the current number being added to the sorted array
    for (int i = 0; i < numsSize; i++)
    {

        // while the current color has been account for, advance to next color
        while (!colorCount[j])
        {
            j++;
        }

        nums[i] = j; // set the current position to the current color

        colorCount[j]--; // decrement the count of the current color
        
    }
    
}

int main() {
  
    int nums[] = {1};
    int numsSize = 1;

    sortColors(nums, numsSize);

    printf("Output:\n");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;

}