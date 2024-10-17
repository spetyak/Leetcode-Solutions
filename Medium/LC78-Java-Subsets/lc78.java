import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 96.16% of Java submissions
 */
public class lc78 {

    /**
     * Generates all possible subsets of the given set nums.
     * 
     * @param output the power set of the set nums
     * @param current the subset currently being added/built
     * @param nums the set to determine the power set of
     * @param lower the lower bound for new integers added to the current subset
     */
    public static void subsetHelper(List<List<Integer>> output, List<Integer> current, int[] nums, int lower) {

        output.add(new ArrayList<>(current)); // add current subset to power set

        // all numbers in set have been used
        if (lower == nums.length)
        {
            return;
        }

        for (int i = lower; i < nums.length; i++)
        {
            current.add(nums[i]);                       // add new number to subset
            subsetHelper(output, current, nums, i+1);   // add to power set / build on current subset
            current.remove(current.size()-1);           // remove last added int from subset for next combo
        }

    }

    /**
     * Given an integer array nums of unique elements, returns all possible subsets (the power set).
     * 
     * @param nums the set to determine the power set of
     * 
     * @return all possible subsets of the given set of integers (the power set)
     */
    public static List<List<Integer>> subsets(int[] nums) {
        
        List<List<Integer>> output = new ArrayList<>(); // the power set of the given set nums
        List<Integer> current = new ArrayList<>();      // the subset currently being added/built
        int lower = 0;                                  // the lower bound for new integers added to the current subset

        subsetHelper(output, current, nums, lower); // call helper function to generate subsets

        return output;

    }

    public static void main(String[] args) {
        
        int[] nums = {1, 2, 3};

        List<List<Integer>> output = subsets(nums);

        Iterator<List<Integer>> outerIter = output.iterator();
        while (outerIter.hasNext())
        {
            System.out.println("Combination: " + outerIter.next().toString());
        }

    }

}