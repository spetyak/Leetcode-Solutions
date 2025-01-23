
#include <stdio.h>

/*
 * Author: spetyak
 * Credit to: https://algo.monster/liteproblems/123
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 99.13% of C submissions
 */

/*
 * Returns the maximum value of the two given integers.
 *
 * @param a the first integer being considered
 * @param b the second integer being considered
 * 
 * @return The maximum value of the two given integers.
 */
int max(int a, int b) {
    return a > b ? a : b;
}

/*
 * Given an array of prices where prices[i] is the price of a given stock on the i-th day,
 * finds the maximum profit that can be achieved by completing at most two transactions.
 * A single transaction is considered a buy and a subsequent sell. Stocks can only be bought
 * after selling the current stock.
 *
 * @param prices the array of prices for each day
 * @param pricesSize the size of the array of prices
 * 
 * @return The maximum profit that can be achieved by completing at most two transactions.
 */
int maxProfit(int* prices, int pricesSize) {

    /*
     * Initialize transaction state variables.
     * The buys will both be initialized to the first price as it is initially assumed
     * that price is the most advantageous to buy. The purchases are made negative to 
     * denote the expense.
     */
    int bought1 = -prices[0];
    int sold1   = 0;
    int bought2 = -prices[0];
    int sold2   = 0;

    // iterate through all prices given
    for (int i = 1; i < pricesSize; i++)
    {

        /*
         * determine the LEAST expensive purchase so far
         */
        bought1 = max(bought1, -prices[i]);

        /*
         * determine if this current price yields a greater profit than the greatest
         * first sell so far
         */
        sold1   = max(sold1, bought1 + prices[i]);

        /*
         * attempt to buy another stock, determining the least expensive purchase so 
         * far keeping the profits from the first sale in mind
         */
        bought2 = max(bought2, sold1 - prices[i]);

        /*
         * determine if this current price yields a greater profit than the greatest
         * second sell so far
         */
        sold2   = max(sold2, bought2 + prices[i]);

    }

    return sold2; // the final second sell will be the maximum profit possible

}



int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int pricesSize = 8;

    int output = maxProfit(prices, pricesSize);

    printf("Output: %d\n", output);

    return 0;

}