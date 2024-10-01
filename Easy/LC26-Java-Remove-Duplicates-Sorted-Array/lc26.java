
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 63.49% of Java submissions
 */

public class lc26 {

    /**
     * Given an integer array sorted in increasing order, 
     * sorts unique numbers to the front of the array and 
     * returns the size of the sub array of distinct numbers.
     * 
     * @param nums the sorted integer array
     * 
     * @return the sized of the unique sub array
     */
    public static int removeDuplicates(int[] nums) {

        int current = 1;        // the current index of the array
        int lastNonRepeat = 1;  // the index of the end of the unique sub array

        // loop through nums array
        while (current < nums.length)
        {

            // if the current number is not a repeat
            if (current != 0 && nums[current] != nums[current-1])
            {
                nums[lastNonRepeat] = nums[current]; // add it to the unique sub array
                lastNonRepeat++;
            }

            current++;

        }

        return lastNonRepeat; // return the size of the unique sub array
        
    }

    public static void main(String[] args) {

        int nums[] = {0,0,1,1,1,2,2,3,3,4};

        int output = removeDuplicates(nums);

        System.out.println("Output: " + output);
        
    }

}