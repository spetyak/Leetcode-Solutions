#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 89.28% of C++ submissions
 */

class Solution {
public:

    /*
     * Given a non-decreasing sorted integer array rotated around some pivot and an integer target, 
     * returns true if target is in nums, or false if it is not in nums.
     *
     * @param nums the array to be searched
     * @param target the target to search for in the given array
     * 
     * @return True if target is in the given array, false if not
     */
    bool search(vector<int>& nums, int target) {

        int left = 0;               // the position of the left window boundary
        int right = nums.size()-1;  // the position of the right window boundary
        int middle = 0;             // the position of the windows middle value

        int leftVal = 0;    // the value of the current left window boundary position
        int rightVal = 0;   // the value of the current right window boundary position
        int midVal = 0;     // the value of the current middle position

        // while the search window has not reduced to nothing
        while (left <= right)
        {

            middle = left + (right - left) / 2; // update the windows middle

            // get values from current left, right, and middle positions
            leftVal = nums.at(left);
            rightVal = nums.at(right);
            midVal = nums.at(middle);

            if (midVal == target) // if the current middle value is the target
            {
                return true;
            }

            if (leftVal < midVal) // if the current left value is less than the current middle value
            {

                if (leftVal <= target && target < midVal) // focus search left of middle
                {
                    right = middle - 1;
                }
                else // focus search right of middle
                {
                    left = middle + 1;
                }

            }
            else if (leftVal > midVal) // if the current left value is greater than the current middle value
            {

                if (midVal < target && target <= rightVal) // focus search right of middle
                {
                    left = middle + 1;
                }
                else // focus search left of middle
                {
                    right = middle - 1;
                }

            }
            else // increment left window boundary
            {
                left++;
            }

        }

        return false; // target value was not found in the array

    }

};

int main() {

    Solution s;

    vector<int> v = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;

    s.search(v, target);

    return 0;

}