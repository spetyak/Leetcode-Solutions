#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 95.45% of C submissions
 * Memory: Beats 85.08% of C submissions
 */
int trap(int* height, int heightSize) {

    int leftIndex = 0; // index of the current left mountain being examined
    int rightIndex = heightSize-1; // index of the current right mountain being examined
    int leftValue = 0; // value of the current left mountain being examined
    int rightValue = 0; // value of the current right mountain being examined
    int leftMax = height[leftIndex]; // maximum value found by the left pointer so far
    int rightMax = height[rightIndex]; // maximum value found by the right pointer so far

    int totalWater = 0; // the amount of water trapped in the mountain range

    while (leftIndex != rightIndex) // while all of the mountains have not been considered...
    {

        leftValue = height[leftIndex];
        rightValue = height[rightIndex];

        if (leftValue > leftMax)
        {
            leftMax = leftValue;
        }

        if (rightValue > rightMax)
        {
            rightMax = rightValue;
        }

        if (leftValue < rightValue) // if the left mountain is smaller than the right mountain
        {

            if (leftValue <= leftMax && leftValue <= rightMax) // if the left mountain is between the current maxes
            {

                // determine which max is smaller to determine how much water can be added
                if (leftMax < rightMax) 
                {
                    totalWater += (leftMax - leftValue);
                }
                else
                {
                    totalWater += (rightMax - leftValue);
                }

            }

            leftIndex++; // advance the left pointer

        }
        else
        {

            if (rightValue <= leftMax && rightValue <= rightMax) // if the right mountain is between the current maxes
            {

                // determine which max is smaller to determine how much water can be added
                if (leftMax < rightMax)
                {
                    totalWater += (leftMax - rightValue);
                }
                else
                {
                    totalWater += (rightMax - rightValue);
                }

            }

            rightIndex--; // advance the right pointer

        }

    }

    return totalWater;

}

int main() {

    int heights[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightsSize = 12;

    printf("totalWater: %d\n", trap(heights, heightsSize));

    return 0;

}
