
/**
 * @author spetyak
 * 
 * Runtime: Beats 33.85% of Java submissions
 * Memory: Beats 59.15% of Java submissions
 */
public class lc130 {

    public static char globalBoard[][];     // a global copy of the given board to make function calls simpler
    public static boolean[][] safeSpots;    // a identically-sized board that tracks 'O' spots that are safe
    public static int[][] directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // array of possible directions a space can travel to

    /**
     * Determines if the given index exists on the border of the given board.
     * 
     * @param x the x-coordinate of the given space
     * @param y the y-coordinate of the given space
     * 
     * @return {@code true} if the index does exist on the border of the board, {@code false} if not.
     */
    public static boolean checkBorder(int x, int y) {

        if (x == 0 || x == globalBoard.length-1 || y == 0 || y == globalBoard[0].length-1)
        {
            return true;
        }

        return false;

    }

    /**
     * Determines if the given index is a valid position on the given board.
     * 
     * @param x the x-coordinate of the given space
     * @param y the y-coordinate of the given space
     * 
     * @return {@code true} if the index is a valid position on the board, {@code false} if not.
     */
    public static boolean checkBounds(int x, int y) {

        if (x >= 0 && x < globalBoard.length)
        {

            if (y >= 0 && y < globalBoard[0].length)
            {
                return true;
            }

        }
        return false;
    }

    /**
     * Performs a depth-first search on the given board for 'O' spaces connected vertically
     * and horizontally to the current 'O' space. Connected spaces found containing 'O's are marked 
     * as safe. 
     * 
     * @param x the x-coordinate of the current 'O' space
     * @param y the y-coordinate of the current 'O' space
     */
    public static void dfs(int x, int y) {

        int newX = 0;
        int newY = 0;

        // check spaces directly above, below, to the left, and to the right of the given space
        for (int[] dir : directions)
        {

            newX = x + dir[0];
            newY = y + dir[1];

            /*
             * Check that the new space:
             * - exists on the board
             * - contains an 'O'
             * - has not already been marked as safe (no need to check again)
             */
            if (checkBounds(newX, newY) && globalBoard[newX][newY] == 'O' && !safeSpots[newX][newY])
            {

                safeSpots[newX][newY] = true;
                dfs(newX, newY);

            }

        }

    }
    
    /**
     * Given an m x n matrix of 'X's and 'O's, alters the matrix such that regions of 'O's 
     * that are fully surrounded (in vertical and horizontal directions) are "captured" and
     * converted to 'X's. The way an 'O' region is safe from being captured by 'X's is if the
     * 'O' region touches a boundary of the matrix.
     *
     * @param board the m x n matrix of 'X's and 'O's given
     */
    public static void solve(char[][] board) {

        // initialize global variables
        globalBoard = board;
        safeSpots = new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++)
        {

            for (int j = 0; j < board[0].length; j++)
            {

                /*
                 * Look for places along the borders of the board that are O's 
                 * that have not already been visited.
                 */
                if (checkBorder(i, j) && board[i][j] == 'O' && !safeSpots[i][j])
                {

                    // do dfs and mark safe spots as it goes
                    safeSpots[i][j] = true;
                    dfs(i, j);

                }

            }

        }

        /*
         * Mark all 'O' spots on the board that were not marked as being in a "safe" region to 
         * become 'X's.
         */
        for (int i = 0; i < board.length; i++)
        {

            for (int j = 0; j < board[0].length; j++)
            {

                if (board[i][j] == 'O' && !safeSpots[i][j])
                {
                    board[i][j] = 'X';
                }

            }

        }

    }

    public static void main(String[] args) {
        
        char[][] board = {
                            {'X', 'X', 'X', 'X'}, 
                            {'X', 'O', 'O', 'X'}, 
                            {'X', 'X', 'O', 'X'}, 
                            {'X', 'O', 'X', 'X'}};

        solve(board);

        System.out.println("Output:");
        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board[0].length; j++)
            {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }

    }

}