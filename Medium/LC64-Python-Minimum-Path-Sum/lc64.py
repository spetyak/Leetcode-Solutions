"""
Author: spetyak

Runtime: Beats 72.65% of Python submissions
Memory: Beats 32.95% of Python submissions

"""

class Solution(object):

    def minPathSum(self, grid):
        """
        Given a m x n grid filled with non-negative numbers, 
        returns the sum of the path with the minimum cost from the top left to bottom right
        with the restriction of only being able to move right or down.

        Args:
            grid (List[List[int]]): the grid of values between which paths can be created

        Returns:
            int: the sum of the path from top left to bottom right with the minimum sum
        """
        
        # add infinity to the end of each row
        for i in range(len(grid)):
            grid[i] += [float('inf')]
            
        # add a new row of infinities
        grid += [[float('inf') for i in range(len(grid[0]))]]
        
        grid[len(grid)-1][len(grid[0])-2] = 0 # set the position below the destination to 0
        
        
        # follow the minimum path from the destination to the start, summing cost at each step
        for i in range(len(grid)-2, -1, -1):
            
            for j in range(len(grid[i])-2, -1, -1):
                
                grid[i][j] = grid[i][j] + min(grid[i+1][j], grid[i][j+1])
            
                
        
        return grid[0][0] # return minimum path cost

def main():

    sol = Solution()
    
    grid = [[1,3,1],[1,5,1],[4,2,1]]
    
    print(f"Output: {sol.minPathSum(grid)}")

    return

if __name__ == "__main__":
    main()