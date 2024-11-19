
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 61.70% of Java submissions
 * Memory: Beats 37.86% of Java submissions
 */
public class lc18 {

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
     * Given an array of integers, returns an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
     * <ul>
     *  <li> 0 <= a, b, c, d < n
     *  <li> a, b, c, and d are distinct
     *  <li> nums[a] + nums[b] + nums[c] + nums[d] == target
     * </ul>
     * 
     * @param nums the array of numbers to be searched for valid 4sums
     * @param target the sum that the four integers being considered should sum to
     * 
     * @return An array of valid 4sum arrays.
     */
    public static List<List<Integer>> fourSum(int[] nums, int target) {

        List<List<Integer>> output = new ArrayList<>(); // the list of all valid 4sum arrays
        int leftPtr = 0;                // a pointer to a number on the left hand of the remaining portion of the array
        int rightPtr = 0;               // a pointer to a number on the right hand of the remaining portion of the array
        long sumVal = 0;                // the sum of the current three numbers being examined

        mergeSort(nums); // sort the numbers

        // examine values in sorted array
        for (int i = 0; i < nums.length; i++)
        {

            // do not repeat using a value as the initial number in the sum
            if (i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            for (int j = i+1; j < nums.length; j++)
            {

                // do not repeat using a value as the second number in the sum
                if ((i != (j-1)) && (nums[j] == nums[j-1]))
                {
                    continue;
                }

                leftPtr = j+1;
                rightPtr = nums.length-1;

                while (leftPtr < rightPtr)
                {

                    // do not repeat using a value as the third number in the sum
                    if ((j != (leftPtr - 1)) && (nums[leftPtr] == nums[leftPtr-1]))
                    {
                        leftPtr++;
                        continue;
                    }

                    sumVal = (long) nums[i] + (long) nums[j] + (long) nums[leftPtr] + (long) nums[rightPtr];

                    if (sumVal == target)
                    {

                        // add new quadruple to output list
                        ArrayList<Integer> newMatch = new ArrayList<>();
                        newMatch.add(nums[i]);
                        newMatch.add(nums[j]);
                        newMatch.add(nums[leftPtr]);
                        newMatch.add(nums[rightPtr]);

                        output.add(newMatch);

                        leftPtr++;

                    }
                    else if (sumVal > target) // sum is too large, use smaller values in sum
                    {
                        rightPtr--;
                    }
                    else // sum is too large, use larger values in sum
                    {
                        leftPtr++;
                    }

                }

            }

        }



        return output;

    }

    public static void main(String[] args) {

        int[] nums = {1000000000,1000000000,1000000000,1000000000};
        int target = -294967296;

        List<List<Integer>> l = fourSum(nums, target);

        System.out.println("Output (" + l.size() + "):");
        Iterator<List<Integer>> iter = l.iterator();
        while (iter.hasNext())
        {
            Iterator<Integer> innerIter = iter.next().iterator();
            while (innerIter.hasNext())
            {
                System.out.print(innerIter.next() + " ");
            }
            System.out.println();
        }

    }

}
