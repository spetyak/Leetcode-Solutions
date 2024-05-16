#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SUDOKU_SIZE 9
#define SQUARE_ROW_COL_SIZE 3

/*
 * Author: spetyak
 *
 * Runtime: Beats 89.55% of C submissions
 * Memory: Beats 46.40% of C submissions
 */



/*
 * Struct used to house the current row, column, or square values being examined.
 */
typedef struct sudoku_hashtable {

    char values[SUDOKU_SIZE];

} sudoku_hashtable_t;

/*
 * Checks if the given sudoku board is valid or not.
 *
 * board - the sudoku board to be examined
 * boardSize - the number of rows in the board
 * boardColSize - the number of columns in the board
 * 
 * Returns - a boolean TRUE if the board is valid, FALSE if not
 * */
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int rowSize = boardSize; 
    int colSize = boardColSize[0];

    int squareRowBase = 0; // variable used to track the starting row of sudoku squares
    int squareColBase = 0; // variable used to track the starting columns of sudoku squares

    int val = 0; // the value of a given spot on the sudoku board

    sudoku_hashtable_t* sht = malloc(sizeof(sudoku_hashtable_t)); // hashtable used to keep track of numbers used in rows, columns, and squares

    // CHECK ROWS
    for (int i = 0; i < rowSize; i++)
    {

        memset(sht->values, 0, SUDOKU_SIZE*sizeof(char)); // reset hash table to all 0's

        for (int j = 0; j < colSize; j++)
        {

            if (board[i][j] != '.') // if current space is not empty
            {

                val = board[i][j] - '0';

                if (sht->values[val % SUDOKU_SIZE] == 0) // if the value does not exist in the hashtable yet
                {
                    sht->values[val % SUDOKU_SIZE] = 1;
                }
                else
                {

                    printf("Failed at row %d\n", i);
                    free(sht);
                    return false;

                }

            }

        }

    }

    // CHECK COLUMNS
    for (int j = 0; j < colSize; j++)
    {

        memset(sht->values, 0, SUDOKU_SIZE*sizeof(char)); // reset hash table to all 0's

        for (int i = 0; i < rowSize; i++)
        {

            if (board[i][j] != '.') // if current space is not empty
            {

                val = board[i][j] - '0';

                if (sht->values[val % SUDOKU_SIZE] == 0) // if the value does not exist in the hashtable yet
                {
                    sht->values[val % SUDOKU_SIZE] = 1;
                }
                else
                {

                    printf("FAILED at column %d\n", j);
                    free(sht);
                    return false;

                }

            }

        }

    }

    // CHECK SQUARES
    for (int i = 0; i < SUDOKU_SIZE; i++) // loop through sqaures
    {

        squareRowBase = (i / SQUARE_ROW_COL_SIZE) * SQUARE_ROW_COL_SIZE;
        squareColBase = (i % SQUARE_ROW_COL_SIZE) * SQUARE_ROW_COL_SIZE;

        memset(sht->values, 0, SUDOKU_SIZE*sizeof(char)); // reset hash table to all 0's

        for (int j = 0; j < SQUARE_ROW_COL_SIZE; j++) // loop inside squares
        {

            for (int k = 0; k < SQUARE_ROW_COL_SIZE; k++)
            {

                if (board[(squareRowBase)+j][(squareColBase)+k] != '.') // if current space is not empty
                {

                    val = board[(squareRowBase)+j][(squareColBase)+k] - '0';

                    if (sht->values[val % SUDOKU_SIZE] == 0) // if the value does not exist in the hashtable yet
                    {
                        sht->values[val % SUDOKU_SIZE] = 1;
                    }
                    else
                    {

                        printf("FAILED at square %d\n", i);
                        free(sht);
                        return false;

                    }

                }

            }

        }

    }



    free(sht); 

    return true;

}

int main() {

    int rowSize = SUDOKU_SIZE;
    int colSize = SUDOKU_SIZE;

    char** board = malloc(rowSize*colSize*sizeof(char));

    // board[0] = "53..7....";
    // board[1] = "6..195...";
    // board[2] = ".98....6.";
    // board[3] = "8...6...3";
    // board[4] = "4..8.3..1";
    // board[5] = "7...2...6";
    // board[6] = ".6....28.";
    // board[7] = "...419..5";
    // board[8] = "....8..79";

    board[0] = "83..7....";
    board[1] = "6..195...";
    board[2] = ".98....6.";
    board[3] = "8...6...3";
    board[4] = "4..8.3..1";
    board[5] = "7...2...6";
    board[6] = ".6....28.";
    board[7] = "...419..5";
    board[8] = "....8..79";

    printf("Output: %d\n", isValidSudoku(board, rowSize, &colSize));

    free(board);

}
