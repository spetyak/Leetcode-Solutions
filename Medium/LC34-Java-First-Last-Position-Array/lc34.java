
import java.util.Arrays;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 41.08% of Java submissions
 */
public class lc34 {

    /**
     * Helper method for searchRange() method which splits the array and searches it for the earliest and 
     * latest occurence of the target number.
     * 
     * @param nums the array of numbers to be searched through
     * @param pos the current earliest and latest position of target found in the nums array
     * @param low the leftmost position of the current window
     * @param mid the middle position of the current window
     * @param high the rightmost position of the current window
     * @param target the number whose occurences we are searching for
     * 
     * @return the current known start/end positions of target in nums, if it exists
     * 
     * @see #searchRange(int[] nums, int target)
     */
    public static int[] binarySearchRange(int[] nums, int[] pos, int low, int mid, int high, int target) {

        int lowNum = nums[low];
        int midNum = nums[mid];
        int highNum = nums[high];

        

        if (lowNum == target)
        {
            if (pos[0] == -1) // if positions have not been updated yet
            {
                pos[0] = low;
                pos[1] = low;
            }
            else if (low < pos[0])
            {
                pos[0] = low;
            }
        }

        if (midNum == target)
        {
            if (pos[0] == -1) // if positions have not been updated yet
            {
                pos[0] = mid;
                pos[1] = mid;
            }
            else if (mid < pos[0])
            {
                pos[0] = mid;
            }
            else if (mid > pos[1])
            {
                pos[1] = mid;
            }
        }

        if (highNum == target) // if positions have not been updated yet
        {
            if (pos[0] == -1)
            {
                pos[0] = high;
                pos[1] = high;
            }
            else if (high > pos[1])
            {
                pos[1] = high;
            }
        }



        if (low != high) // if the window is not a single number
        {
            
            if (lowNum <= target && midNum >= target && lowNum != midNum) // go left
            {
                binarySearchRange(nums, pos, low, (low+mid)/2, mid-1, target);
            }

            if (midNum <= target && highNum >= target && midNum != highNum) // go right
            {
                binarySearchRange(nums, pos, mid+1, (mid+high)/2, high, target);
            }

        }

        return pos;

    }

    /**
     * Searches for first and last occurence of target number in array.
     * 
     * @param nums the array to be searched
     * @param target the number whose first and last positions we are looking for in the nums array
     * 
     * @return the first and last position of target in nums, if it exists
     * 
     * @see #binarySearchRange(int[] nums, int[] pos, int low, int mid, int high, int target)
     */
    public static int[] searchRange(int[] nums, int target) {

        int[] pos = {-1, -1};

        if (nums.length == 0) // if the nums array is empty
        {
            return pos;
        }

        return binarySearchRange(nums, pos, 0, nums.length/2, nums.length-1, target);

    }



    public static void main(String[] args) {

        int[] nums = {1, 2, 2, 3, 4, 4, 4};

        int target = 4;

        System.out.println("Output: " + Arrays.toString(searchRange(nums, target)));

    }

}
