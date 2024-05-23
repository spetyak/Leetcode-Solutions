import java.util.List;
import java.util.ArrayList;

/**
 * @author spetyak
 * 
 * Runtime: Beats 99.50% of Java submissions
 * Memory: Beats 79.37% of Java submissions
 */
public class lc40 {

    /**
     * The list of combinations whose sum equals the target
     */
    public static List<List<Integer>> comboList = new ArrayList<>(); 

    /**
     * Sorts the given array using a counting sort method.
     * 
     * @param nums the array to be sorted
     */
    public static void countingSort(int[] nums) {

        int currentNum = 0;
        int max = -1;

        for (int i = 0; i < nums.length; i++) // find the max value
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        int[] countArray = new int[max+1];
        int[] copyNums = new int[nums.length];

        for (int i = 0; i < nums.length; i++) // populate the count array
        {
            countArray[nums[i]]++;
        }

        for (int i = 0; i < max; i++) // update the count array
        {
            countArray[i+1] = countArray[i] + countArray[i+1];
        }

        for (int i = nums.length-1; i >= 0; i--) // perform the sorting
        {
            currentNum = nums[i];
            copyNums[countArray[currentNum]-1] = currentNum;
            countArray[currentNum]--;
        }

        for (int i = 0; i < nums.length; i++) // copy from the copy array to the original
        {
            nums[i] = copyNums[i];
        }

    }

    /**
     * A helper function which checks the given array for element combinations whose sum is equal to the target.
     * 
     * @param nums the numbers who are candidates for combinations
     * @param currentGuess the current working guess for a combination
     * @param start the index of where to begin in the candidate array
     * @param currentSum the current working sum for a combination
     * @param target the value the combinations should sum to
     */
    public static void combinationTester2(int[] nums, ArrayList<Integer> currentGuess, int start, int currentSum, int target) {

        if (currentSum == target) 
        {
            comboList.add(new ArrayList<>(currentGuess));
        }
        else
        {

            for (int i = start; i < nums.length; i++)
            {

                if (i > start && nums[i] == nums[i-1]) // avoid repeating same steps
                {
                    continue;
                }

                if (currentSum + nums[i] > target) // don't advance if new sum will be larger than target
                {
                    return;
                }

                currentGuess.add(nums[i]); // add the current number to the working combination
                currentSum += nums[i]; // add the current number to the working sum

                combinationTester2(nums, currentGuess, i+1, currentSum, target); // go to the next level of the combination tree

                int last = currentGuess.removeLast(); // remove the current number from the working combination
                currentSum -= last; // remove the current number from the sum

            }

        }

    }

    /**
     * Searches the given array for combinations whose sum matches the target value.
     * 
     * @param candidates the array of values to be considered for combinations
     * @param target the value that the combination's sum should equal
     * 
     * @return a list of combinations of elements from the candidate array whose sum equals the target value
     */
    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {

        ArrayList<Integer> currentGuess = new ArrayList<>();
        int currentSum = 0;

        countingSort(candidates); // sort the array

        combinationTester2(candidates, currentGuess, 0, currentSum, target);

        return comboList;

    }

    public static void main(String[] args) {

        // int[] candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        // int target = 30;

        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;

        // int[] candidates = {2, 5, 2, 1, 2};
        // int target = 5;

        combinationSum2(candidates, target);

        System.out.println("Combo list:");
        for (List<Integer> currentList : comboList)
        {
            System.out.println(currentList);
        }

    }

}
