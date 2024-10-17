#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 24.30% of C submissions
 * Memory: Beats 94.86% of C submissions
 */

#define MAX_WORD_LENGTH 15

/*
 * Searches the given board attempting to build the given word.
 * Returns true if it is possible to build the word, false if not.
 *
 * @param board the m x n matrix of letters
 * @param word the target word to create using the letters on the board
 * @param row the current row position
 * @param col the current column position
 * @param letterIndex the current letter of the word
 * @param boardSize the number of rows in the board
 * @param boardColSize the number of columns in the board
 * 
 * @return True if the given word can be created using the letters in the board, false if not
 */
bool search(char** board, char* word, int row, int col, int letterIndex, int boardSize, int boardColSize) {

    // all of the given word was found, return true
    if (letterIndex >= strnlen(word, MAX_WORD_LENGTH))
    {
        return true;
    }

    // if position is out of bounds
    if (0 > row || row >= boardSize || 0 > col || col >= boardColSize)
    {
        return false;
    }

    // another letter of the word was found
    if (board[row][col] == word[letterIndex])
    {

        // hold onto old board value and mark position to avoid retracing steps
        char temp = board[row][col];
        board[row][col] = '0';

        // continue on trying to build the target word
        if (search(board, word, row+1, col, letterIndex+1, boardSize, boardColSize) 
            || search(board, word, row-1, col, letterIndex+1, boardSize, boardColSize) 
            || search(board, word, row, col+1, letterIndex+1, boardSize, boardColSize) 
            || search(board, word, row, col-1, letterIndex+1, boardSize, boardColSize))
        {
            return true;
        }

        board[row][col] = temp; // failed to make word, put old character back

        return false;

    }
    else
    {
        return false;
    }

}

/*
 * Given an m x n grid of characters board and a string word, returns true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells, 
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 *
 * @param board the m x n matrix of letters
 * @param boardSize the number of rows in the board
 * @param boardColSize the number of columns in the board
 * @param word the target word to create using the letters on the board
 * 
 * @return True if the given word can be created using the letters in the board, false if not
 */
bool exist(char** board, int boardSize, int* boardColSize, char* word) {

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardColSize[i]; j++)
        {

            // if current letter is the beginning of the target word
            if (board[i][j] == word[0])
            {

                // if the target word can be found starting from the current position
                if (search(board, word, i, j, 0, boardSize, boardColSize[0]))
                {
                    return true;
                }

            }

        }
    }

    return false;
    
}


int main() {
    char board0[4] = {'A', 'B', 'C', 'E'};
    char board1[4] = {'S', 'F', 'C', 'S'};
    char board2[4] = {'A', 'D', 'E', 'E'};
    char* board[3] = {board0, board1, board2};
    int boardSize = 3;
    int boardColSize[3] = {4, 4, 4};
    char* word = "SEE";

    bool output = exist(board, boardSize, boardColSize, word);

    if (output)
    {
        printf("Output: TRUE\n");
    }
    else
    {
        printf("Output: FALSE\n");
    }

    return 0;

}