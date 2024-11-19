
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 67.73% of Java submissions
 */

public class lc70 {

    /**
     * Returns the number of distinct ways to climb a staircase
     * with n steps where you are only able to climb 1 or 2 steps at a time.
     * 
     * @param n the number of steps in the staircase
     * 
     * @return the number of distiinct ways to climb a staircase 1 or 2 steps at a time
     */
    public static int climbStairs(int n) {

        if (n == 1) // base case #1
        {
            return 1;
        }
        else if (n == 2) // base case #2
        {
            return 2;
        }

        // initialize dynamic programming table
        int[] dpTable = new int[n];
        dpTable[0] = 1;
        dpTable[1] = 2;

        // the number of possible steps to get to the current step is simply
        // the possibilities for the previous two steps summed together
        // (it is essentially the fibonacci sequence)
        for (int i = 2; i < n; i++)
        {
            dpTable[i] = dpTable[i-1] + dpTable[i-2];
        }

        return dpTable[n-1]; // return the number of possible steps to get to get to the given step

    }

    public static void main(String[] args) {

        int numSteps = 4;

        int output = climbStairs(numSteps);

        System.out.println("Output: " + output);

    }

}
