
/**
 * @author spetyak
 * 
 * Runtime: Beats 98.83% of Java submissions
 * Memory: Beats 69.93% of Java submissions
 */
public class lc45 {

    /**
     * Determines the fewest number of jumps necessary to reach the end of the array.
     * A given indexes number can jump as many spaces ahead as the number it contains 
     * (ie. an index with 2 allows for jumping at most 2 spaces ahead).
     * 
     * @param nums the array of numbers
     * 
     * @return the fewest number of jumps required to reach the end of the array
     */
    public static int jump(int[] nums) {

        int currentReach = 0; // the farthest position the current array number can reach
        int farthest = 0; // the farthest position reached so far
        int searchBoundary = 0; // the end of the current search area, which is updated to be the farthest spot reached so far
        
        int jumps = 0;

        if (nums.length == 1) // if there is only one number, no jumps are needed
        {
            return 0;
        }

        for (int i = 0; i < nums.length; i++) 
        {

            currentReach = nums[i] + i; // get the farthest position the current number can reach

            if (currentReach >= farthest) // if the reach is greater than the current farthest reach, update
            {
                farthest = currentReach;
            }

            if (currentReach >= nums.length-1) // if the reach touches or goes beyond the final element, end
            {
                jumps++;
                break;
            }
            
            if (i == searchBoundary) // if we've reached the end of the search area, some advancement must have been made, so add a jump and increase the area to the farthest reach seen so far
            {
                searchBoundary = farthest;
                jumps++;
            }

        }

        return jumps;

    }

    public static void main(String[] args) {

        int[] nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};

        System.out.println("Output: " + jump(nums));

        int[] nums2 = {2, 3, 1, 1, 4};

        System.out.println("Output: " + jump(nums2));

    }

}
