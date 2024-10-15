#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 78.12% of C++ submissions
 * Memory: Beats 84.43% of C++ submissions
 */

class Solution {
public:

    /*
     * Given an m x n integer matrix, if an element is 0, sets its entire row and column to 0's.
     *
     * @param matrix the m x n matrix to modify
     */
    void setZeroes(vector<vector<int>>& matrix) {

        vector<int> matrixRows(matrix.size());          // vector to flag rows containing zeroes
        vector<int> matrixCols(matrix.at(0).size());    // vector to flag columns containing zeroes

        for (int i = 0; i < matrixRows.size(); i++)
        {
            for (int j = 0; j < matrixCols.size(); j++)
            {
                if (matrix.at(i).at(j) == 0) // if the current position is zero
                {
                    matrixRows.at(i) = 1; // mark current row to be zeroed out
                    matrixCols.at(j) = 1; // mark current column to be zeroed out
                }
            }
        }


        // change rows marked as containing zeroes to zero
        for (int i = 0; i < matrixRows.size(); i++)
        {
            if (matrixRows.at(i) == 1)
            {
                for (int j = 0; j < matrixCols.size(); j++)
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }

        // change columns marked as containing zeroes to zero
        for (int i = 0; i < matrixCols.size(); i++)
        {
            if (matrixCols.at(i) == 1)
            {
                for (int j = 0; j < matrixRows.size(); j++)
                {
                    matrix.at(j).at(i) = 0;
                }
            }
        }
        
    }

};

int main() {

    Solution s;

    vector<vector<int>> matrix = {{}};

    s.setZeroes(matrix);

    cout << "Output:" << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(0).size(); j++)
        {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;

}


