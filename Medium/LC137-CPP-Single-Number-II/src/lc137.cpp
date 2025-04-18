#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 86.79% of C++ submissions
 */

class Solution {
public:

    /*
     * Given an integer array where every element appears three times except for one 
     * (which appears exactly once), finds the single element and return it.
     *
     * @param nums the given array of integer elements
     * 
     * @return The array element which appears only once.
     */
    int singleNumber(vector<int>& nums) {

        if (nums.size() == 1)
        {
            return nums[0];
        }

        int ones = 0; // an integer whos bits are used to keep track of the bits seen only once
        int twos = 0; // an integer whos bits are used to keep track of the bits seen twice
        int mask = 0; // an integer used as a bit mask to help update the ones and twos integer

        for (int i = 0; i < nums.size(); i++)
        {

            mask = nums[i];         // note what new bits are being recorded

            mask = twos & nums[i];  // make the mask only effect the matching bits in twos
            twos ^= mask;           // update the twos bits (meaning these bits were seen 3 times)

            nums[i] ^= mask;        // 0 the changed bits from the current number

            mask = ones & nums[i];  // make the mask only effect the matching bits in ones
            ones ^= mask;           // update the ones bits (meaning these bits were seen 2 times)
            twos |= mask;           // update the twos bits

            nums[i] ^= mask;        // 0 the changed bits from the current number

            ones |= nums[i];        // mark the remaining bits as this is the first time seeing them

        }

        return ones;

    }

};

int main() {

    Solution s;

    vector<int> nums = {30000,500,100,30000,100,30000,100};

    int output = s.singleNumber(nums);

    cout << "Output: " << output << endl;

    return 0;

}