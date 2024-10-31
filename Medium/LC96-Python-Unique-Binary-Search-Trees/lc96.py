
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 41.13% of Python submissions

"""

class Solution(object):

    def numTrees(self, n):
        """
        Given an integer n, returns the number of structurally unique binary search trees 
        which have exactly n nodes of unique values from 1 to n.

        Args:
            n (int): the number of nodes in the generated binary trees and the upper limit to nodes' values

        Returns:
            int: The number of structurally unique binary search trees that can be generated n nodes of values [1,n]
        """
        
        dpTable = [1 for i in range(n+1)] # initialize the dynamic programming table to contain all 1's
        
        # determine the number of trees that can be generated for each number up to (and including) n
        for i in range(2, n+1):
            
            output = 0 # the number of trees that can be generated with i nodes
            
            # consider each node as a possible root and aggregate the number of subtrees
            for j in range(1, i+1):
                
                left = j - 1    # the size of the left subtree
                right = i - j   # the size of the right subtree
                output += (dpTable[left] * dpTable[right]) # combine left and right subtree counts
                
            dpTable[i] = output # update the dp table
                
        return dpTable[n] 
                
                
    
def main():

    sol = Solution()
    
    n = 3
    
    print(f"Output: {sol.numTrees(n)}")

    return

if __name__ == "__main__":
    main()