
#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 65.14% of C submissions
 */

/*
 * Given an integer rowIndex, returns the rowIndexth (0-indexed) row of a Pascal triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * @param rowIndex the desired row of the Pascal triangle
 * @param returnSize the number of elements in the returned row
 * 
 * @return The rowIndexth row of a Pascal triangle.
 */
int* getRow(int rowIndex, int* returnSize) {

    int prevSize = 1;                   // the size of the previous row in the Pascal triangle
    int* oldRow = malloc(sizeof(int));  // initialize the previous row, initially just a single 1
    int* newRow = NULL;                 // the new row being created using the old row

    oldRow[0] = 1; // initialize the first value of the row to 1

    // base case
    if (rowIndex == 0)
    {
        *returnSize = 1;
        return oldRow;
    }

    int currRow = 0; // the index of the previous row the new one is being built upon

    while (currRow != rowIndex)
    {

        newRow = malloc((prevSize + 1) * sizeof(int)); // allocate space for the next row of the triangle

        newRow[0] = 1;

        if (currRow > 0)
        {

            // for all middle values of the row, add the values of the two numbers above it
            for (int i = 1; i < prevSize; i++)
            {
                newRow[i] = oldRow[i-1] + oldRow[i];
            }

        }

        newRow[prevSize] = 1;

        free(oldRow);       // free the current old row as it is no longer needed
        oldRow = newRow;    // make the row that has been created the new old row
        prevSize++;         // note the increase in the size of the previous row

        currRow++;

    }

    *returnSize = prevSize; // note the final size of the targeted row

    return newRow;
    
}

int main() {

    int rowIndex = 3;
    int returnSize = 0;

    int* output = getRow(rowIndex, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", output[i]);
    }
    printf("]\n");

    free(output);

    return 0;

}