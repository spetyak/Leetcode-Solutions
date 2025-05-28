#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 39.88% of C++ submissions
 * Memory: Beats 52.44% of C++ submissions
 */

class Solution {
public:

    /*
     * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
     * returns the maximum number of points that lie on the same straight line.
     *
     * @param points an array of x, y point coordinates
     * 
     * @return The maximum number of points the lie on the same straight line in the X-Y plane.
     */
    int maxPoints(vector<vector<int>>& points) {

        if (points.size() == 1) // if there is only a single point given
        {
            return 1;
        }

        double slope = 0.0;                     // the slope between two points ((y2-y1)/(x2-x1))
        unordered_map<double, int> slopeMap;    // a map of slopes and the order they were found

        /*
         * Construct a table that determines the slopes between any two points in the given array.
         * The slope between identical points (x1 == x2, y1 == y2) will be marked with -inf.
         * The slope between points on the same vertical line will be marked inf for undefined.
         */
        double** table = new double*[points.size()];
        for (int i = 0; i < points.size(); i++)
        {
            table[i] = new double[points.size()];
        }

        double x1 = 0;
        double y1 = 0;
        double x2 = 0;
        double y2 = 0;
        int k = 0;  // the current number of unique slopes found between all points in the graph

        for (int i = 0; i < points.size(); i++)
        {

            x1 = points[i][0];
            y1 = points[i][1];

            for (int j = 0; j < points.size(); j++)
            {

                x2 = points[j][0];
                y2 = points[j][1];

                if (x2 - x1 == 0) // if the denominator is undefined
                {

                    if (x1 == x2 && y1 == y2) // if the two points are the same, denote with -inf
                    {
                        slope = -INFINITY;
                    }
                    else // if the denominator is 0 but the numerator is not, denote with inf
                    {
                        slope = INFINITY;
                    }
                    
                }
                else
                {
                    slope = (y2-y1)/(x2-x1);
                }

                // if the slope has not been found, add it to the map
                if (slopeMap.find(slope) == slopeMap.end())
                {
                    slopeMap.insert({slope, k});
                    k++;
                }

                table[i][j] = slope; // update slope table

            }

        }



        vector<int> count(k);       // a counter of the slopes found in a row of the slope table
        int slopeCurrentCount = 0;  // the current number of times a given slope appears in a row
        int maxMatch = 0;           // the maximum number of matching slopes found so far

        for (int i = 0; i < points.size(); i++)
        {

            fill(count.begin(), count.end(), 1); // reset all counts in the count vector to 1

            for (int j = 0; j < points.size(); j++)
            {

                slopeCurrentCount = count[slopeMap[table[i][j]]] + 1;
                
                if (slopeCurrentCount > maxMatch)
                {
                    maxMatch = slopeCurrentCount;
                }

                count[slopeMap[table[i][j]]] = slopeCurrentCount;

            }

        }
        


        return maxMatch;
        
    }

};

int main() {

    Solution s;

    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};

    int output = s.maxPoints(points);

    cout << "Output: " << output << endl;

    return 0;

}