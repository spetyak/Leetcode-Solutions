#include <iostream>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 79.96% of C++ submissions
 */

class Solution {
public:

    /*
     * Given an array of stock prices for different consecutive days, returns
     * the maximum profit that could be made by buying stock one of the days and
     * selling on a different following day.
     *
     * @param prices the array of stock prices on each day
     * 
     * @return The maximum profit that can be generated. If no profit can be made, 0 is returned.
     */
    int maxProfit(vector<int>& prices) {
        
        int maxPrice = prices[prices.size()-1]; //
        int maxProfit = 0;                      //
        int profit = 0;                         //

        // base case, can't buy AND sell in a single day
        if (prices.size() == 1)
        {
            return 0;
        }

        // loop from the end to the front of the array calculating profits compared to the largest
        // prices found in the array so far. 
        for (int i = prices.size()-2; i >= 0; i--)
        {

            if (prices[i] > maxPrice) // if the current price is larger than the current max
            {
                maxPrice = prices[i];
            }
            else // calculate the profit generated from selling maxPrice and buying prices[i]
            {

                profit = maxPrice - prices[i];

                if (profit > maxProfit) // update max profit
                {
                    maxProfit = profit;
                }

            }

        }

        return maxProfit;

    }

};

int main() {

    Solution s;

    vector<int> v = {7, 1, 5, 3, 6, 4};

    int output = s.maxProfit(v);

    cout << "Output: " << output << endl;

    return 0;

}