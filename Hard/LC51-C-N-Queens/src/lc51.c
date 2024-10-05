#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 5.17% of C submissions
 * Memory: Beats 71.55% of C submissions
 */



/*
 * Checks the diagonal of the given position by following the given directional vectors.
 *
 * @param board the current chess board
 * @param boardSize the size of the chess board
 * @param x the x-coordinate of the given position
 * @param y the y-coordinate of the given position
 * @param dirX the direction the x-coordinate should travel in the next step
 * @param dirY the direction the y-coordinate should travel in the next step
 * 
 * @return 1 if there are no queens present in the diagonal, 0 if there are.
 */
int checkDiagonal(char** board, int boardSize, int x, int y, int dirX, int dirY) {

    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) // if current position is outside of board
    {
        return 1;
    }
    else if (board[x][y] == 'Q') // if current position contains a queen
    {
        return 0;
    }
    else
    {
        return checkDiagonal(board, boardSize, x+dirX, y+dirY, dirX, dirY);
    }

}

/*
 * Check the row, column, and diagonals of the given position for other queens.
 *
 * @param board the current chess board 
 * @param boardSize the size of the chess board
 * @param x the x-coordinate of the given position
 * @param y the y-coordinate of the given position
 * 
 * @return 1 if there are no queens able to attack the current position, 0 if there are.
 */
int checkSafety(char** board, int boardSize, int x, int y) {

    // check row
    for (int j = 0; j < boardSize; j++)
    {
        if (j != y && board[x][j] == 'Q')
        {
            return 0;
        }
    }

    // check column
    for (int i = 0; i < boardSize; i++)
    {
        if (i != x && board[i][y] == 'Q')
        {
            return 0;
        }
    }

    // check diagonals
    if (!checkDiagonal(board, boardSize, x, y, -1, -1)
        || !checkDiagonal(board, boardSize, x, y, -1, 1)
        || !checkDiagonal(board, boardSize, x, y, 1, -1)
        || !checkDiagonal(board, boardSize, x, y, 1, 1))
    {
        return 0;
    }

    return 1;

}

/*
 * Adds the current board configuration with N queens safely placed to a list of solutions.
 *
 * @param output the list of valid N-Queen solution boards found so far
 * @param outputSize the size of the solution list
 * @param outputCapacity the capacity of the solution list, doubled if capacity is reached
 * @param board the current chess board
 * @param boardSize the size of the chess board
 * 
 */
void addToOutput(char**** output, int* outputSize, int* outputCapacity, char** board, int boardSize) {

    //
    char** newOutput = malloc(boardSize * sizeof(char*));
    if (!newOutput)
    {
        printf("Failed to allocate new output array!\n");
        exit(-1);
    }

    //
    for (int i = 0; i < boardSize; i++)
    {
        newOutput[i] = malloc((boardSize+1) * sizeof(char));
        if (!newOutput[i])
        {
            printf("Failed to allocate new output array row!\n");
            exit(-1);
        }
        memcpy(newOutput[i], board[i], boardSize * sizeof(char));
        newOutput[i][boardSize] = '\0';
    }

    //
    (*output)[(*outputSize)] = newOutput;
    (*outputSize)++;

    //
    if ((*outputSize) == (*outputCapacity))
    {
        (*outputCapacity) *= 2; // double capacity
        (*output) = realloc((*output), (*outputCapacity) * sizeof(char**));
    }

}

/*
 * Determines all possible N Queen arrangements on the N x N board.
 *
 * @param numQueens the remaining number of queens to place on the chess board
 * @param startX the starting x-coordinate (prevents overwriting data)
 * @param startY the starting y-coordinate (prevents overwriting data)
 * @param board the current chess board
 * @param boardSize the length/width of the chess board
 * @param output the list of valid N-Queen solution boards found so far
 * @param outputSize the size of the solution list
 * @param outputCapacity the capacity of the solution list, doubled if capacity is reached
 */
void validSolution(char**** output, int* outputSize, int* outputCapacity, char** board, int boardSize, int numQueens, int startX, int startY) {

    // 
    if (numQueens == 0)
    {
        addToOutput(output, outputSize, outputCapacity, board, boardSize); // add board to return array
        return;
    }

    for (int i = startX; i < boardSize; i++)
    {

        for (int j = startY; j < boardSize; j++)
        {

            //
            if (board[i][j] != 'Q')
            {

                // 
                if (checkSafety(board, boardSize, i, j))
                {
                    board[i][j] = 'Q';
                    numQueens--;
                    validSolution(output, outputSize, outputCapacity, board, boardSize, numQueens, i, j);
                    board[i][j] = '.';
                    numQueens++;
                }

            }

        }

        startY = 0; // prevent getting stuck/overwriting

    }

    return;

}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 
 * @param n
 * @param returnSize
 * @param returnColumnSizes
 * 
 * @return the list of all possible safe positionings of queens on the N x N chess board
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;
    int outputCapacity = 1;

    char*** output = malloc(sizeof(char**));
    if (!output)
    {
        printf("Unable to allcoate output array!\n");
        exit(-1);
    }

    // create empty chess board
    char** board = malloc(n * sizeof(char*));
    if (!board)
    {
        printf("Unable to allocate chess board!\n");
        exit(-1);
    }

    for (int i = 0; i < n; i++)
    {

        board[i] = malloc(n * sizeof(char));
        if (!board[i])
        {
            printf("Unable to allocate inner grid array!\n");
            exit(-1);
        }

        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }

    }

    

    validSolution(&output, returnSize, &outputCapacity, board, n, n, 0, 0); // find all valid solutions



    // allocate returnColumnSizes array and populate
    (*returnColumnSizes) = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    // free board memory
    for (int i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);
    
    

    return output;

}

    

int main() {

    int n = 5;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    char*** solutions = solveNQueens(n, &returnSize, &returnColumnSizes);

    // print solution(s) (if they exist)
    if (returnSize == 0)
    {
        printf("No solutions for size %d!\n", n);
    }
    else
    {
        for (int i = 0; i < returnSize; i++)
        {
            printf("Solution %d:\n", i+1);
            for (int j = 0; j < returnColumnSizes[i]; j++)
            {
                for (int k = 0; k < returnColumnSizes[i]; k++)
                {
                    printf("%c ", solutions[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    
    

    // free solutions array
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            free(solutions[i][j]); // free solution row
        }
        free(solutions[i]); // free solution board
    }
    free(solutions);

    // free returnColumnSizes array
    free(returnColumnSizes);

    return 0;

}