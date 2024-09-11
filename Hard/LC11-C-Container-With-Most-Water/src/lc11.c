#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 83.60% of C submissions
 * Memory: Beats 89.90% of C submissions
 */

/*
 * Determines the maximum amount of water that a container 
 * (the space between two lines of height height[i]) can store
 * given an array of integer height values.
 */
int maxArea(int* height, int heightSize) {

    int lowPtr = 0;                 // pointer used to track the current left wall of the container
    int highPtr = heightSize-1;     // pointer used to track the current right wall of the container
    int maxWater = 0;               // the maximum amount of water held by one of the container combinations

    int distance = 0;   // the horizontal distance between the two walls of the container
    int minHeight = 0;  // the minimum height of the two walls being considered
    int area = 0;       // the area contained between the walls of the containers
    
    while (1)
    {

        if (lowPtr == highPtr-1) // if the pointers are adjacent
        {

            // determine min height of current two pointer positions
            if (height[lowPtr] <= height[highPtr])
            {
                minHeight = height[lowPtr];
            }
            else
            {
                minHeight = height[highPtr];
            }

            area = minHeight; // 1 * minHeight

            // update max water
            if (area > maxWater)
            {
                maxWater = area;
            }

            break;

        }
        else
        {

            distance = highPtr - lowPtr;

            // determine min height of current two pointer positions
            if (height[lowPtr] <= height[highPtr])
            {
                minHeight = height[lowPtr];
                lowPtr++;
            }
            else
            {
                minHeight = height[highPtr];
                highPtr--;
            }

            area = distance * minHeight;

            // update max water
            if (area > maxWater)
            {
                maxWater = area;
            }

        }

    }

    return maxWater;

}

int main() {

    int arr[] = {1, 1};
    int arrLength = 2;

    printf("Output: %d\n", maxArea(arr, arrLength));

    return 0;

}