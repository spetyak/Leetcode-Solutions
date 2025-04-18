
/**
 * @author spetyak
 * 
 * Runtime: Beats 97.45% of Java submissions
 * Memory: Beats 78.81% of Java submissions
 */
public class lc134 {

    /**
     * Given arrays representing a circuit of gas stations and the associated fuel costs to travel
     * between them, returns the position from which a circuit can be completed in the clockwise
     * direction, or -1 if it is impossible.
     * 
     * @param gas the fuel available to take at each gas station
     * @param cost the fuel cost to travel to the next gas station
     * 
     * @return The position from which a circuit can be completed in the clockwise direction, or -1.
     */
    public static int canCompleteCircuit(int[] gas, int[] cost) {

        int gasSum = 0;     // the total sum of all gas in the circuit
        int costSum = 0;    // the total sum of all travel costs in the circuit

        // sum up the total gas and travel costs in the circuit
        for (int i = 0; i < gas.length; i++)
        {
            gasSum += gas[i];
            costSum += cost[i];
        }

        // if the circuit has a total travel cost greater than the total gas
        // it is impossible to loop
        if (costSum > gasSum) 
        {
            return -1;
        }

        int total = 0;          // the total gas accumulated in the trip since the marked start
        int startingPos = 0;    // the position from which a circuit can be completed

        for (int i = 0; i < gas.length; i++)
        {

            total += (gas[i] - cost[i]); // update the using the new gas and travel cost

            // if the current total is negative, the loop can't travel from here, reset and continue
            if (total < 0)
            {
                total = 0;
                startingPos = i + 1;
            }

        }

        return startingPos;

    }

    public static void main(String[] args) {

        int[] gas = {1,2,3,4,5};
        int[] cost = {3,4,5,1,2};

        System.out.println("Output: " + canCompleteCircuit(gas, cost));

    }

}