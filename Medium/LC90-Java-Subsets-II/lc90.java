import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 99.91% of Java submissions
 * Memory: Beats 79.20% of Java submissions
 */
public class lc90 {

    /**
     * Sorts the given array using the merge sort algorithm.
     * 
     * @param nums the array to be sorted
     */
    public static void mergeSort(int[] nums) {

        // base case
        if (nums.length == 1)
        {
            return;
        }

        int leftSize = nums.length / 2;
        int rightSize =  nums.length - (nums.length / 2);

        int[] numsLeft = new int[leftSize];
        int[] numsRight = new int[rightSize];

        // populate left array
        for (int i = 0; i < leftSize; i++)
        {
            numsLeft[i] = nums[i];
        }

        // populate right array
        for (int i = 0; i < rightSize; i++)
        {
            numsRight[i] = nums[leftSize+i];
        }

        // perform merge sort on array halves
        mergeSort(numsLeft);
        mergeSort(numsRight);

        // merge left and right array back into input array
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < leftSize && j < rightSize)
        {

            if (numsLeft[i] <= numsRight[j])
            {
                nums[k] = numsLeft[i];
                i++;
            }
            else
            {
                nums[k] = numsRight[j];
                j++;
            }

            k++;

        }

        // if numsRight is fully merged but numsLeft is not yet
        while (i < leftSize)
        {
            nums[k] = numsLeft[i];
            i++;
            k++;
        }

        // if numsLeft is fully merged but numsRight is not yet
        while (j < rightSize)
        {
            nums[k] = numsRight[j];
            j++;
            k++;
        }

    }

    /**
     * Generates all possible subsets of the given set nums while avoiding duplicates.
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

            if (i > lower && nums[i] == nums[i-1]) // if the current number is a repeat
            {
                continue;
            }

            current.add(nums[i]);                       // add new number to subset
            subsetHelper(output, current, nums, i+1);   // add to power set / build on current subset
            current.remove(current.size()-1);           // remove last added int from subset for next combo

        }

    }

    /**
     * Given an integer array nums that may contain duplicates, returns all possible subsets 
     * (the power set) while avoiding duplicates.
     * 
     * @param nums the set to determine the power set of
     * 
     * @return all possible subsets of the given set of integers (the power set) with no duplicates
     */
    public static List<List<Integer>> subsetsWithDup(int[] nums) {
        
        List<List<Integer>> output = new ArrayList<>(); // the power set of the given set nums
        List<Integer> current = new ArrayList<>();      // the subset currently being added/built
        int lower = 0;                                  // the lower bound for new integers added to the current subset

        mergeSort(nums); // sort the input array

        subsetHelper(output, current, nums, lower); // call helper function to generate subsets

        return output;

    }

    public static void main(String[] args) {
        
        int[] nums = {1, 2, 2};

        List<List<Integer>> output = subsetsWithDup(nums);

        Iterator<List<Integer>> outerIter = output.iterator();
        while (outerIter.hasNext())
        {
            System.out.println("Combination: " + outerIter.next().toString());
        }

    }

}