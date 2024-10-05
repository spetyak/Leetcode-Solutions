
"""
Author: spetyak

Runtime: Beats 5% of Python submissions
Memory: Beats 22.90% of Python submissions

"""

class Solution(object):
    
    numSolutions = 0 # the current number of solutions found
    
    def totalNQueens(self, n):
        """
        Finds the total number of possible n x n board arrangements
        where n queens are unable to attack each other.

        Args:
            n (int): the number of queens that need to be present on the board and the length and width of the board

        Returns:
            int: the number of possible arrangements the queens can be placed peacefully on the board
        """
        
        board = [[]]
        
        def checkDiagonal(x, y, dirX, dirY):
            """
            Checks the diagonal of the given position by following the given directional vectors.

            Args:
                x (int): the x-coordinate of the origin position for the diagonal
                y (int): the y-coordinate of the origin position for the diagonal
                dirX (int): the x direction to advance in for the next step
                dirY (int): the y direction to advance in for the next step

            Returns:
                bool: True if the diagonal does not have any queens, False if it does
            """
            
            if (x < 0 or x >= n or y < 0 or y >= n):
                return 1
            elif (board[x][y] == 'Q'):
                return 0;
            else:
                return checkDiagonal(x+dirX, y+dirY, dirX, dirY)
            
        
        def checkSafety(x, y):
            """
            Check the row, column, and diagonals of the given position for other queens.

            Args:
                x (int): the x-coordinate of the given position
                y (int): the y-coordinate of the given position

            Returns:
                bool: True if there are no queens able to attack the given position, False if there are
            """
            
            # check row
            for j in range(n):
                if (j != y and board[x][j] == "Q"):
                    return False
                
            # check column
            for i in range(n):
                if (i != x and board[i][y] == "Q"):
                    return False
                
            # check diagonals
            if (not checkDiagonal(x, y, -1, -1) or
                not checkDiagonal(x, y, -1, 1) or
                not checkDiagonal(x, y, 1, -1) or
                not checkDiagonal(x, y, 1, 1)):
                
                return False
            
            return True
            
        
        def validSolution(numQueens, startX, startY):
            """
            Determines all possible N Queen arrangements on the N x N board.

            Args:
                numQueens (int): the remaining number of queens that must be placed on the board
                startX (int): the starting x-coordinate (prevents overwriting data)
                startY (int): the starting y-coordinate (prevents overwriting data)
            """
            
            # if all queens have been placed on the board
            if (numQueens == 0):
                self.numSolutions += 1
                return
            
            for i in range(startX, n):
                
                for j in range(startY, n):
                    
                    # if the current position does not contain a queen
                    if board[i][j] != "Q":
                        
                        # if a queen can safely be placed at the current position
                        if checkSafety(i, j) == True:
                            
                            board[i][j] = "Q"
                            numQueens -= 1
                            validSolution(numQueens, i, j) # attempt to place more queens
                            board[i][j] = "."
                            numQueens += 1
                            
                
                startY = 0
                
            return 
            
        board = [["." for i in range(n)] for j in range(n)] # initialize board to be blank (all "."s)
    
        validSolution(n, 0, 0) # determine all possible arrangements of n-queens on the board
        
        return self.numSolutions

def main():
    
    sol = Solution()
    
    numQueens = 3
    
    print(f"Output: {sol.totalNQueens(numQueens)}")

    return

if __name__ == "__main__":
    main()
