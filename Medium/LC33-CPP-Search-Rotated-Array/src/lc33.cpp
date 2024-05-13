#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 35.03% of C++ submission
 * 
 */

class Solution {
public:

    int binarySearch(vector<int>& nums, int lowIndex, int medIndex, int highIndex, int target) {

        int num1 = nums[lowIndex]; // leftmost number in current window
        int num2 = nums[medIndex]; // middle number in current window
        int num3 = nums[highIndex]; // rightmost number in current window

        // check if target is any of the bounding numbers
        if (target == num1)
        {
            return lowIndex;
        }
        else if (target == num2)
        {
            return medIndex;
        }
        else if (target == num3)
        {
            return highIndex;
        }

        

        if (num1 < num2 && num2 > num3)
        {

            if (target > num1 || target < num2) // number will be to left of middle in window
            {

                highIndex = medIndex-1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }
            else if (target > num2 || target < num3) // number will be to right of middle in window
            {

                lowIndex = medIndex+1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }

        }
        else if (num1 < num2 && num2 < num3)
        {
            
            if (target > num1 && target < num2) // number will be to left of middle in window
            {

                highIndex = medIndex-1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }
            else if (target > num2 && target < num3) // number will be to right of middle in window
            {

                lowIndex = medIndex+1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }

        }
        else if (num1 > num2 && num2 < num3)
        {
            
            if (target > num1 || target < num2) // number will be to left of middle in window
            {

                highIndex = medIndex-1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }
            else if (target > num2 || target < num3) // number will be to right of middle in window
            {

                lowIndex = medIndex+1;
                medIndex = (highIndex+lowIndex)/2;

                return binarySearch(nums, lowIndex, medIndex, highIndex, target);

            }

        }

        return -1;

    }

    int search(vector<int>& nums, int target) {

        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
        }
        else if (nums.size() == 2)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else if (nums[1] == target)
            {
                return 1;
            }
        }
        else // nums.size() >= 3
        {
            return binarySearch(nums, 0, nums.size()/2, nums.size()-1, target);
        }

        return -1;

    }

};

int main() {

    // 7 0 1 <2> 4 5 6 

    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums{0, 1, 2, 4, 5, 6, 7};
    // vector<int> nums{6, 7, 0, 1, 2, 4, 5};
    int target = 4;

    cout << "Nums:" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i) << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;

    Solution s;
    int output = s.search(nums, target);

    cout << "Output: " << output << endl;

    return 0;

}
