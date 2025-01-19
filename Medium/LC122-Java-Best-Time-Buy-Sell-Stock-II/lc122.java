
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 54.95% of Java submissions
 */
public class lc122 {

    /**
     * Given an array of stock prices for different consecutive days, returns
     * the maximum profit that could be made by buying stocks and selling them.
     * 
     * @param prices the array of stock prices on each day
     * 
     * @return The maximum profit that can be generated.
     */
    public static int maxProfit(int[] prices) {

        int profit = 0;         // the profit generated between two consecutive days
        int totalProfit = 0;    // the total profit that can be generated over the course of all given days

        // look for all increasing periods and add their profit to the total profit generated
        for (int i = 0; i < prices.length-1; i++)
        {

            profit = prices[i+1] - prices[i];

            if (profit > 0) // if there is a profit
            {
                totalProfit += profit;
            }

        }

        return totalProfit;

    }

    public static void main(String[] args) {

        int[] prices = {7, 1, 5, 3, 6, 4};

        int output = maxProfit(prices);

        System.out.println("Output: " + output);

    }

}