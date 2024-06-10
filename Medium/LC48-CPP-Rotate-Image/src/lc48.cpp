#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 61.01% of C++ submissions
 * 
 */

class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {

        int matrixSize = matrix.size(); // get size of matrix side, better than recalculating later
        
        int levels = (matrixSize / 2) + 1; // determine the number of levels/rings in the matrix

        for (int i = 0; i < levels; i++)
        {

            int numRotations = (matrixSize - 1) - (2 * i); // determine the number of rotations to do on this level

            if (numRotations >= 0)
            {

                for (int j = 0; j < numRotations; j++)
                {

                    // determine the matrix indices ONCE before rotating to save some time
                    int dist1 = i;
                    int dist2 = j + i;
                    int dist3 = (matrixSize-1) - i;
                    int dist4 = ((matrixSize-1) - j) - i;

                    // rotate the values clockwise
                    int temp = matrix.at(dist4).at(dist1);
                    matrix.at(dist4).at(dist1) = matrix.at(dist3).at(dist4); // num3 -> num4
                    matrix.at(dist3).at(dist4) = matrix.at(dist2).at(dist3); // num2 -> num3
                    matrix.at(dist2).at(dist3) = matrix.at(dist1).at(dist2); // num1 -> num2
                    matrix.at(dist1).at(dist2) = temp; // num4 -> num1

                }
                
            }  

        }

    }

};

int main() {

    Solution s;

    vector<vector<int>> nums {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    cout << "Before:" << endl;

    // print matrix
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            cout << nums.at(i).at(j) << " ";
        }
        cout << endl;
    }

    s.rotate(nums); // rotate the matrix

    cout << "After:" << endl;

    // print matrix
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            cout << nums.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;

}
