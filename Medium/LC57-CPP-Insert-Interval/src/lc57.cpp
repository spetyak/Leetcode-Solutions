#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 61.42% of C++ submissions
 * Memory: Beats 76.84% of C++ submissions
 * 
 */

class Solution {
public:

    /*
     * Helper function to print intervals.
     *
     * @param interval the interval to be printed
     */
    void printInterval(vector<int>& interval) {

        for (int i = 0; i < interval.size()-1; i++)
        {
            cout << interval.at(i) << ", ";
        }
        cout << interval.at(interval.size()-1) << endl;

    }

    /*
     * Inserts a new interval into a list of intervals sorted by start time.
     * Intervals are merged if there is overlap when inserting new interval.
     *
     * @param intervals the list of non-overlapping sorted intervals
     * @param newInterval the new interval to be inserted/merged in the list
     * 
     * @return The new list of non-overlapping sorted intervals
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> output;

        // if list empty
        if (intervals.size() == 0)
        {
            output.push_back(newInterval);
            return output;
        }

        if (newInterval.at(1) < intervals.at(0).at(0)) // put new interval first
        {
            output.push_back(newInterval); // add to front
            for (int i = 0; i < intervals.size(); i++)
            {
                output.push_back(intervals.at(i));
            }
            return output;
        }
        else if (newInterval.at(0) > intervals.at(intervals.size()-1).at(1)) // put new interval last
        {
            for (int i = 0; i < intervals.size(); i++)
            {
                output.push_back(intervals.at(i));
            }
            output.push_back(newInterval); // add to end
            return output;
        }
        else // new interval is between other intervals, possibly overlapping
        {

            for (int i = 0; i < intervals.size(); i++)
            {

                // if the new interval does not overlap with the current interval
                if (intervals.at(i).at(1) < newInterval.at(0) || newInterval.at(1) < intervals.at(i).at(0))
                {

                    // if the new interval is less than the current interval, add it before
                    if (newInterval.at(1) < intervals.at(i).at(0))
                    {
                        output.push_back(newInterval);
                        for (int j = i; j < intervals.size(); j++)
                        {
                            output.push_back(intervals.at(j));
                        }
                        return output;
                    }
                    else
                    {
                        output.push_back(intervals.at(i));
                    }

                }
                else // overlap, current interval and newInterval should be merged
                {

                    int minStart = newInterval.at(0);     // the smallest start in the overlapping interval found so far
                    int maxEnd = newInterval.at(1);    // the largest end in the overlapping interval found so far

                    while (i < intervals.size() && !((intervals.at(i).at(1) < newInterval.at(0) || newInterval.at(1) < intervals.at(i).at(0))))
                    {

                        minStart = min(intervals.at(i).at(0), minStart);    // update min start
                        maxEnd = max(intervals.at(i).at(1), maxEnd);  // update max end
                        i++;

                    }

                    newInterval.at(0) = minStart;   // update newInterval with min start found
                    newInterval.at(1) = maxEnd;     // update newInterval with max end found

                    output.push_back(newInterval);  // add merged interval to output list

                    // add the remaining unmerged intervals
                    for (int j = i; j < intervals.size(); j++)
                    {
                        output.push_back(intervals.at(j));
                    }

                    return output;

                }

            }

        }

        

        return output;
        
    }

};

int main() {

    Solution s;

    vector<vector<int>> intervals {{1,3},{6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> output = s.insert(intervals, newInterval);

    cout << "Output:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        s.printInterval(output.at(i));
    }

    return 0;

}