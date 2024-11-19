
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 77.33% of Java submissions
 */
public class lc62 {

    /**
     * Given the two integers m and n, returns the number of possible unique paths that 
     * a robot which can only move right or down can take to reach the bottom-right 
     * corner starting from the top-left corner.
     * 
     * @param m the number of board rows
     * @param n the number of board columns
     * 
     * @return the number of possible unique paths the robot can take
     */
    public static int uniquePaths(int m, int n) {

        int[][] board = new int[m][n];

        // initialize first row and column with 1's as there is only 1 path the
        // robot can take to reach those board positions
        for (int i = 0; i < m; i++)
        {
            board[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            board[0][j] = 1;
        }

        // at each remaining board position, combine the number of paths it took to 
        // get to the spot above the current position and the spot to the left of
        // the current position
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }

        return board[m-1][n-1]; 
        
    }



    public static void main(String[] args) {
        
        int m = 7;
        int n = 3;

        int output = uniquePaths(m, n);

        System.out.println("Output: " + output);

    }

}
