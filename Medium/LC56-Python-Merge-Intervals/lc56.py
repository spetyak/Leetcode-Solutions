"""
Author: spetyak

Runtime: Beats 69.86% of Python submissions
Memory: Beats 10.17% of Python submissions

"""

class Solution(object):
    
    def merge(self, intervals):
        """
        Given an array of intervals where intervals[i] = [starti, endi], 
        merges all overlapping intervals and returns an array of the non-overlapping 
        intervals that cover all the intervals in the input.

        Args:
            intervals (List[List[int]]): the list of intervals to be merged if possible
        """
        
        intervals.sort(key = lambda i : i[0]) # sort the intervals by start
        output = [intervals[0]] # add the first interval to the output list
        
        for start, end in intervals[1:]:
            
            lastEndVal = output[-1][1] # the interval end of the last interval added to the output
            
            if start <= lastEndVal:
                
                output[-1][1] = max(lastEndVal, end) # update the interval end of the last output interval
                
            else:
                
                output.append([start, end]) # add interval to the end of the output list
        
        return output

def main():

    sol = Solution()
    
    intervals = [[15,18],[2,6],[1,3],[8,10]]
    
    newIntervals = sol.merge(intervals)
    
    print(f"Output: {newIntervals}")

    return

if __name__ == "__main__":
    main()