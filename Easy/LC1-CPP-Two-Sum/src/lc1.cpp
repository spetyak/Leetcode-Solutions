#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Author:
 *
 * Runtime: Beats 98.53% of C++ submissions
 * Memory: Beats 49.16% of C++ submissions
 */
class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> m; // map which contains the remainder of the target minus the current number
        vector<int> output; // the two values which summed together equal the target value

        for (int i = 0; i < nums.size(); i++)
        {

            map<int, int>::iterator iter = m.find(nums[i]); // search map for current number

            if (iter != m.end()) // if the map contains this number then we have found the two values
            {

                output.push_back(iter->second);
                output.push_back(i);
                break; // no need to continue

            }
            else
            {

                m[target - nums[i]] = i; // add remainder to map in hopes of finding later

            }

        }

        return output;
        
    }

};

int main() {

    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> output = s.twoSum(nums, target);

    cout << "Output:";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;

}
