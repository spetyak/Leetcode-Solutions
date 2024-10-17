#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 75.54% of C++ submissions
 * Memory: Beats 77.84% of C++ submissions
 */

class Solution {
public:

    /*
     * Generates all combinations of k numbers chosen from the range [1, upper]
     *
     * @param output the list of all combinations
     * @param current the combination currently being built
     * @param lower the lower bound for new numbers added to the current combination
     * @param upper the upper bound for new numbers added to the current combination
     * @param k the size of each combination of numbers
     */
    void combinationHelper(vector<vector<int>>& output, vector<int>& current, int lower, int upper, int k) {

        // if a combination has been made of the appropriate size
        if (current.size() == k)
        {
            output.push_back(current);
            return;
        }

        // add increasingly larger values to the combinations
        for (int i = lower; i <= upper; i++)
        {
            current.push_back(i);
            combinationHelper(output, current, i+1, upper, k);
            current.pop_back();
        }

        return;

    }

    /*
     * Given two integers n and k, returns all possible combinations of k numbers chosen from the range [1, n].
     *
     * @param n the upper bound of the range of integers present in each combination
     * @param k the number of integers in each combination
     * 
     * @return
     */
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> output; // initialize vector of combinations
        vector<int> current;        // initialize current combination vector

        combinationHelper(output, current, 1, n, k); // call recursive function

        return output;

    }

};

int main() {

    Solution s;

    int n = 1;
    int k = 1;

    vector<vector<int>> output = s.combine(n, k);

    cout << "Output:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output.at(0).size(); j++)
        {
            cout << output.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;

}
