#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 98.04% of C submissions
 */



/*
 * Given a grid with an obstacle to avoid, returns the number of possible unique paths 
 * that a robot which can only move right or down can take to reach the bottom-right 
 * corner starting from the top-left corner.
 *
 * @param obstacleGrid the grid the robot is to traverse while avoiding the obstacle
 * @param obstacleGridSize the number of rows on the grid
 * @param obstacleGridColSize the number of columns on the grid
 * 
 * @return The number of unique paths the robot can take from start to end avoiding the obstacle
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {

    // mark obstacle with a negative to differentiate from 1's used for dynamic programming
    for (int i = 0; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < obstacleGridColSize[i]; j++)
        {
            obstacleGrid[i][j] *= -1;
        }
    }

    // attempt to initialize first row / column with 1's, break if obstacle encountered
    for (int i = 0; i < obstacleGridSize; i++)
    {
        if (obstacleGrid[i][0] == -1)
        {
            break;
        }
        obstacleGrid[i][0] = 1;
    }
    for (int j = 0; j < obstacleGridColSize[0]; j++)
    {
        if (obstacleGrid[0][j] == -1)
        {
            break;
        }
        obstacleGrid[0][j] = 1;
    }

    int up = 0;     // number of paths that lead to the position above the current position
    int left = 0;   // number of paths that lead to the position to the left of the current position

    for (int i = 1; i < obstacleGridSize; i++)
    {

        for (int j = 1; j < obstacleGridColSize[i]; j++)
        {

            if (obstacleGrid[i][j] != -1) // if the current position is NOT the obstacle
            {

                up = obstacleGrid[i-1][j];
                left = obstacleGrid[i][j-1];

                if (up <= 0) // if the obstacle is above the current position
                {
                    up = 0;
                }
                if (left <= 0) // if the obstacle is to the left of the current position
                {
                    left = 0;
                }

                obstacleGrid[i][j] = up + left; // combine number of steps needed to reach current position

            }

        }

    }

    if (obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1] <= 0) // if the obstacle is at the end
    {
        return 0;
    }
    else
    {
        return obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1];
    }

}

int main() {

    int rowSize = 2;
    int colSize = 2;

    int rockX = 0;
    int rockY = 1;

    // create obstacle grid
    int** obstacleGrid = malloc(rowSize * sizeof(int*));
    if (!obstacleGrid)
    {
        printf("Unable to allocate obstacleGrid outer array!\n");
        exit(-1);
    }
    for (int i = 0; i < rowSize; i++)
    {
        obstacleGrid[i] = malloc(colSize * sizeof(int));
        if (!obstacleGrid[i])
        {
            printf("Unable to allocate obstacleGrid inner array!\n");
            exit(-1);
        }
    }

    for (int i = 0; i < rowSize; i++)
    {

        for (int j = 0; j < colSize; j++)
        {

            if (i == rockX && j == rockY)
            {
                obstacleGrid[i][j] = 1;
            }
            else
            {
                obstacleGrid[i][j] = 0;
            }

        }

    }

    int* colSizes = malloc(rowSize * sizeof(int));
    if (!colSizes)
    {
        printf("Unable to allocate colSizes array!\n");
        exit(-1);
    }
    for (int i = 0; i < rowSize; i++)
    {
        colSizes[i] = colSize;
    }

    

    int output = uniquePathsWithObstacles(obstacleGrid, rowSize, colSizes);
    printf("Output: %d\n", output);



    free(colSizes);
    for (int i = 0; i < rowSize; i++)
    {
        free(obstacleGrid[i]);
    }
    free(obstacleGrid);

    return 0;

}