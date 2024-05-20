#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 54.76% of C++ submission
 * 
 */

class Solution {
public:

    vector<vector<int>> comboList = {}; // the list of combinations that add up to the target sum

    void combinationTester(vector<int>& nums, vector<int>& currentGuess, int start, int currentSum, int target) {

        for (int i = start; i < nums.size(); i++) // loop through the remaining candidates
        {

            currentGuess.push_back(nums.at(i)); // add the candidate to the current guess
            currentSum += nums.at(i); // add the candidate to the current sum

            if (currentSum <= target)
            {

                if (currentSum == target) // a valid combination was found
                {
                    comboList.push_back(currentGuess); 
                }

                combinationTester(nums, currentGuess, i, currentSum, target); // continue looking (even if equal)

            }

            // these lines are only reached after all possibilities are exhausted or a sum was greater than the target
            // in that case, the next possible candidate for the selection of candidates will be chosen

            int lastOffending = currentGuess.at(currentGuess.size()-1); // get the last added candidate
            currentGuess.pop_back(); // remove the offending candidate from the list
            currentSum -= lastOffending; // remove the offending candidate from the sum

        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> currentGuess = {}; // initialize an empty vector to pass
        
        combinationTester(candidates, currentGuess, 0, 0, target); // call the helper function which will update the combo list

        return comboList;

    }

};

int main() {

    vector<int> candidates{7, 6, 3, 2};
    int target = 7;

    Solution s;
    vector<vector<int>> output = s.combinationSum(candidates, target);

    return 0;

}