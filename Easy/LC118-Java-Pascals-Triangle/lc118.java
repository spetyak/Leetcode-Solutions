import java.util.ArrayList;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 85.76% of Java submissions
 * Memory: Beats 91.75% of Java submissions
 */
public class lc118 {

    /**
     * Given an integer {@code numRows}, returns the first {@code numRows} of Pascal's triangle.
     * In Pascal's triangle, each number is the sum of the two numbers directly above it
     * 
     * @param numRows the number of rows/levels in the generated triangle
     * 
     * @return The first {@code numRows} of Pascal's triangle.
     */
    public static List<List<Integer>> generate(int numRows) {

        // initialize the triangle with a single 1 at the top (the smallest a triangle can be is 1 row)
        List<List<Integer>> triangle = new ArrayList<>();
        List<Integer> row = new ArrayList<Integer>();
        row.add(1);
        triangle.add(row);

        // base case
        if (numRows == 1)
        {
            return triangle;
        }

        int rowIndex = 0; // the index of the previous row in the triangle

        while (rowIndex < numRows-1)
        {

            row = new ArrayList<Integer>();

            row.add(1);

            if (rowIndex + 1 > 1)
            {

                // for all middle values of the row, add the values of the two numbers above it
                for (int i = 1; i < rowIndex+1; i++)
                {
                    row.add(triangle.get(rowIndex).get(i-1) + triangle.get(rowIndex).get(i));
                }

            }
            
            row.add(1);

            triangle.add(row); // add the row to the triangle
            rowIndex++;

        }
        
        return triangle;

    }

    public static void main(String[] args) {

        int numRows = 5;

        List<List<Integer>> triangle = generate(numRows);

        System.out.print("Output triangle: [");
        for (int i = 0; i < triangle.size(); i++)
        {
            System.out.print("[");
            for (int j = 0; j < triangle.get(i).size(); j++)
            {
                System.out.print(triangle.get(i).get(j) + " ");
            }
            System.out.print("] ");
        }
        System.out.println("]");

    }

}