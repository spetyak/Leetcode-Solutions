import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 99.79% of Java submissions
 */
public class lc54 {

    /**
     * Given an m x n matrix, returns all elements of the matrix in spiral order.
     * 
     * @param matrix the m x n matrix that will be converted to a list in spiral order
     * 
     * @return a list of the matrix elements in spiral order
     */
    public static List<Integer> spiralOrder(int[][] matrix) {
        
        int numArrayElements = (matrix.length) * (matrix[0].length);   // the total number of elements in the array

        // spiral walk-through bounds
        int rowLower = 0;                   // the lower bound of the rows being considered
        int rowUpper = matrix.length;       // the upper bound of the rows being considered
        int colLower = -1;                  // the lower bound of the columns being considered
        int colUpper = matrix[0].length;    // the upper bound of the columns being considered

        int i = 0;  // the current row position in the array
        int j = 0;  // the current column position in the array
        List<Integer> output = new ArrayList<>();   // the return list of elements in spiral order

        // repeat spiral walk-through until all elements have been added to the output list
        while (output.size() < numArrayElements)
        {

            // go right
            colLower += 1; // increase column lower bound for next pass
            while (j < colUpper) // walk through row
            {
                output.add(matrix[i][j]);
                j++;
            }
            if (output.size() == numArrayElements) // if all matrix elements have been added
            {
                break;
            }
            j = colUpper-1; // reset column pointer to within bounds
            i++;            // avoid repeating last element added
            
            // go down
            rowLower += 1;
            while (i < rowUpper)
            {
                output.add(matrix[i][j]);
                i++;
            }
            if (output.size() == numArrayElements)
            {
                break;
            }
            i = rowUpper-1;
            j--;

            // go left
            colUpper -= 1;
            while (j >= colLower)
            {
                output.add(matrix[i][j]);
                j--;
            }
            if (output.size() == numArrayElements)
            {
                break;
            }
            j = colLower;
            i--;

            // go up
            rowUpper -= 1;
            while (i >= rowLower)
            {
                output.add(matrix[i][j]);
                i--;
            }
            if (output.size() == numArrayElements)
            {
                break;
            }
            i = rowLower;
            j++;

        }



        return output;
        
    }

    public static void main(String[] args) {
    
        int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

        List<Integer> l = spiralOrder(matrix);

        System.out.print("Output: ");
        if (l != null)
        {

            Iterator<Integer> iter = l.iterator();
            while (iter.hasNext())
            {
                System.out.print(iter.next() + " ");
            }
            
        }
        System.out.println();

    }

}
