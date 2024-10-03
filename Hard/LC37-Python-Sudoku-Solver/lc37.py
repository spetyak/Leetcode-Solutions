
"""
Author: spetyak

Runtime: Beats 29.48% of Python submissions
Memory: Beats 94.70% of Python submissions

"""

class Solution(object):
    
    solved = False # flag used to end recursive solution attempts early if a solution is found

    def solveSudoku(self, board):
        """
        Solves the given sudoku board.

        Args:
            board (List[List[str]]): the sudoku board to be solved
        """
        
        def possible(x, y, num):
            """
            Determines if the given number is possible at position x,y 
            on the board given the current configuration of the board. 

            Args:
                x (int): the row of the position in question
                y (int): the column of the position in question
                num (str): the number being checked for being unique in the current row/column/square

            Returns:
                bool: True if the given number is a possible solution at the given position, False if not 
            """
        
            # check row and column
            for i in range(len(board)):
                if (board[x][i] == num or board[i][y] == num):
                    return False
            
            # check square
            rowStart = (x // 3) * 3
            colStart = (y // 3) * 3
            for i in range(rowStart, rowStart+3):
                for j in range(colStart, colStart+3):
                    if (board[i][j] == num):
                        return False
            
            return True
        
        def attempt(board):
            """
            Recursively attempt to solve the given board.

            Args:
                board (List[List[str]]): the partially filled sudoku board to be solved
            """
        
            for i in range(len(board)):
                
                for j in range(len(board[i])):
                    
                    # if the current spot on the board has not yet been assigned a value
                    if (board[i][j] == '.'):
                        
                        # test all possible values to see if any of them might work
                        for k in range(1, 10):
                            
                            # check if the value is possible with the current board configuration
                            if (possible(i, j, str(k)) == True):
                                
                                board[i][j] = str(k)    # set the current position to the value
                                attempt(board)            # go deeper into recursion to continue
                                
                                # if the board has already been solved, break out of recursion
                                if (self.solved == True):
                                    return
                                else:
                                    board[i][j] = '.'
                                
                        return # all possibilities have been considered for this position, so return
                    
            # this can only be reached if board is complete, meaning it is solved
            self.solved = True 
            return
        
        # CLASS FUNCTIONS END
        
        
        
        attempt(board) # attempt to solve the given sudoku board
        
        return

def main():
    
    sol = Solution()
    
    board = [["5","3",".",".","7",".",".",".","."],
             ["6",".",".","1","9","5",".",".","."],
             [".","9","8",".",".",".",".","6","."],
             ["8",".",".",".","6",".",".",".","3"],
             ["4",".",".","8",".","3",".",".","1"],
             ["7",".",".",".","2",".",".",".","6"],
             [".","6",".",".",".",".","2","8","."],
             [".",".",".","4","1","9",".",".","5"],
             [".",".",".",".","8",".",".","7","9"]]

    sol.solveSudoku(board)
    
    print("Solution:")
    print(board)   

    return

if __name__ == "__main__":
    main()
