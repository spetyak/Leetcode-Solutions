#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 90.51% of C++ submissions
 */

class Solution {
public:

    /*
     * Given a m x n binary matrix filled with 0's and 1's, 
     * finds the largest rectangle containing only 1's and returns its area.
     *
     * @param matrix the binary matrix to examine
     * 
     * @return The area of the largest rectangle containing only 1's in the binary matrix
     */
    int maximalRectangle(vector<vector<char>>& matrix) {

        // if the matrix or its rows are empty
        if (matrix.empty() or matrix[0].empty())
        {
            return 0;
        }

        vector<int> heights(matrix[0].size() + 1, 0); // the heights of rectangles found so far
        int maxArea = 0;    // the maximum rectangle area found so far
        int height = 0;     // the height of the current rectangle
        int width = 0;      // the width of the current rectangle

        // for each row in the matrix
        for (const auto& row : matrix)
        {

            stack<int> monoStack; // reset monotonic stack

            // update heights based on current row values
            for (int i = 0; i < row.size(); i++)
            {
                heights[i] = (row[i] == '1') ? heights[i]+1 : 0;  
            }

            for (int i = 0; i < heights.size(); i++)
            {

                // if the current height is less than the stack top
                while (!monoStack.empty() and heights[i] < heights[monoStack.top()])
                {

                    // height may be 0, as the top of the stack points to a position, 
                    // but i will never be 0 as that implies an empty stack,
                    // and so when the 0 pushed to the stack is examined it will be used as a position in the heights array, 
                    // not solely for width

                    height = heights[monoStack.top()];                          // grab height from stack top
                    monoStack.pop();                                            // pop height from stack
                    width = (monoStack.empty()) ? i : i - monoStack.top() - 1;  // determine width of rectangle
                    maxArea = max(maxArea, height * width);                     // update max area

                }

                monoStack.push(i); // add current position to stack

            }

        }



        return maxArea;

    }

};

int main() {

    Solution s;

    vector<vector<char>> v = {{'1'}};

    int output = s.maximalRectangle(v);

    cout << "Output: " << output << endl;

    return 0;

}