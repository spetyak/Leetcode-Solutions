
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 81.02% of Java submissions
 */
public class lc74 {

    /**
     * Given an m x n integer matrix where each row is sorted in increasing order
     * and the first integer of each row is greater than the last integer of the previous row,
     * returns {@code true} if the given target value is present within the matrix and {@code false}
     * if not.
     * 
     * @param matrix the m x n matrix to be searched for the target value
     * @param target the value to search for within the given matrix
     * 
     * @return {@code true} if the target value exists within the matrix, {@code false} if not
     */
    public static boolean searchMatrix(int[][] matrix, int target) {

        // perform binary search on row heads
        // then, perform binary search on the row that may contain the target

        int leftPtr = 0;                    // the left boundary of the binary search window
        int midPtr = 0;                     // pointer to the middle value of the binary search window
        int rightPtr = matrix.length - 1;   // the right boundary of the binary search window

        // search through rows, seeing if a row could possibly contain the target value in its range
        while (leftPtr <= rightPtr)
        {

            midPtr = leftPtr + ((rightPtr - leftPtr) / 2); // determine mid point of the search window

            if (target > matrix[midPtr][matrix[midPtr].length-1]) // if the target is larger than the largest value in the current row
            {
                leftPtr = midPtr + 1;
            }
            else if (target < matrix[midPtr][0]) // if the target is less than the current rows head value
            {
                rightPtr = midPtr - 1;
            }
            else // the target is within the bounds of the current row
            {
                break;
            }

        }

        // the search was unsuccessful, it is impossible for the target value to exist in the given matrix
        if (leftPtr > rightPtr)
        {
            return false;
        }

        int innerMidPtr = 0;                    // pointer to the middle value of the current row being searched
        leftPtr = 0;                            // reset left pointer for row search window
        rightPtr = matrix[midPtr].length - 1;   // reset right pointer for row search window

        // search through the row for the target value
        while (leftPtr <= rightPtr)
        {

            innerMidPtr = leftPtr + ((rightPtr - leftPtr) / 2); // determine mid point of the search window

            if (target < matrix[midPtr][innerMidPtr]) // if the target is less than the middle value, shift window left
            {
                rightPtr = innerMidPtr - 1;
            }
            else if (target > matrix[midPtr][innerMidPtr]) // if the target is greater than the middle value, shift window right
            {
                leftPtr = innerMidPtr + 1;
            }
            else // target value found
            {
                return true;
            }

        }

        return false; // target value does not exist in matrix
        
    }



    public static void main(String[] args) {
        
        int[][] matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
        int target = 11;

        boolean output = searchMatrix(matrix, target);

        System.out.println("Output: " + output);

    }

}