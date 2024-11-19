#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 80.60% of C submissions
 */



/*
 * Given a positive integer n, generates an n x n matrix filled with elements 
 * from 1 to n^2 in spiral order.
 *
 * @param n the length, width, and sqaure root of the amount of numbers that should be present in the array
 * @param returnSize the size of the output array (# of rows)
 * @param returnColumnSizes the number of columns in the output arrays
 * 
 * @return the spiral matrix of integers 1 to n^2
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    // allocate output array
    int** outputArray = malloc(n * sizeof(int*));
    if (!outputArray)
    {
        printf("Unable to allocate outer output array!\n");
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        outputArray[i] = malloc(n * sizeof(int));
        if (!(outputArray[i]))
        {
            printf("Unable to allocate inner output array!\n");
            exit(-1);
        }
    }

    *returnSize = n;

    // allocate and populate returnColumnSizes array
    (*returnColumnSizes) = malloc(n * sizeof(int));
    if (!(*returnColumnSizes))
    {
        printf("Unable to allocate returnColumnSizes array!\n");
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    int number = 0; // the current number being added to the 
    int i = 0;      // the current x position in the matrix
    int j = 0;      // the current y position in the matrix

    int colLower = -1;  // the lower bound of the columns
    int colUpper = n;   // the upper bound of the columns
    int rowLower = 0;   // the lower bound of the rows
    int rowUpper = n;   // the upper bound of the rows

    // loop until all numbers added
    while (number < (n * n))
    {

        // go right
        colLower++;
        for (int i = colLower; i < colUpper; i++)
        {
            outputArray[rowLower][i] = number+1;
            number++;
        }

        // go down
        rowLower++;
        for (int i = rowLower; i < rowUpper; i++)
        {
            outputArray[i][colUpper-1] = number+1;
            number++;
        }

        // go left
        colUpper--;
        for (int i = colUpper-1; i >= colLower; i--)
        {
            outputArray[rowUpper-1][i] = number+1;
            number++;
        }

        // go up
        rowUpper--;
        for (int i = rowUpper-1; i >= rowLower; i--)
        {
            outputArray[i][colLower] = number+1;
            number++;
        }

    }

    return outputArray;
    
}

int main() {

    int n = 5;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** outputArray = generateMatrix(n, &returnSize, &returnColumnSizes);

    printf("Output:\n");
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", outputArray[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++)
    {
        free(outputArray[i]);
    }
    free(outputArray);
    free(returnColumnSizes);

    return 0;

}
