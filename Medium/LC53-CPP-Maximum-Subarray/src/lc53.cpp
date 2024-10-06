#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 46.68% of C++ submissions
 * Memory: Beats 98.66% of C++ submissions
 * 
 */

class Solution {
public:

    /*
     * Given an integer array, finds the subarray with the largest sum.
     *
     * @param nums the array of integers to consider
     * 
     * @return the sum of the subarray with the largest sum
     */
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;     // the sum of the current subarray being considered
        int maxSum = INT_MIN;   // the maximum sum found so far
        
        for (int i = 0; i < nums.size(); i++)
        {

            // if the current number is larger than the current sum
            // and the resulting sum will be less than the current number
            if (nums.at(i) > currentSum && (currentSum + nums.at(i)) < nums.at(i))
            {
                currentSum = nums.at(i); // consider a new subarray starting at this position
            }
            else
            {
                currentSum += nums.at(i); // add to the current subarray sum
            }

            // update max sum
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }

        }



        return maxSum;

    }

};

int main() {

    Solution s;

    vector<int> vect{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> vect2{-2,-1,-3,-4,-1,-2,-1,-5,-4};
    vector<int> vect3{2, 3};

    cout << "Output 1: " << s.maxSubArray(vect) << endl;
    cout << "Output 2: " << s.maxSubArray(vect2) << endl;
    cout << "Output 3: " << s.maxSubArray(vect3) << endl;

    return 0;

}