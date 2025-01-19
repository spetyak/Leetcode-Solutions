
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 62.81% of Python submissions

"""

class Solution:

    def minimumTotal(self, triangle):
        """
        Given a triangle array, returns the minimum path sum from top to bottom.
        For each step, you may move to an adjacent number of the row below. 
        More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

        Args:
            triangle (List[List[int]]): a 2D array representing a triangle of integers

        Returns:
            int: The minimum path sum from the top of the triangle to the bottom.
        """

        # base case
        if len(triangle) == 1:

            return triangle[0][0]
        
        # starting at the second-to-last row, add the minimum child to the current triangle node.
        # continue up the triangle until the minimum path is present at the top node.
        for i in range(len(triangle)-2, -1, -1):

            for j in range(len(triangle[i])):

                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])

        return triangle[0][0]
                
                
    
def main():

    sol = Solution()

    triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    
    output = sol.minimumTotal(triangle)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()