"""
Author: spetyak

Runtime: Beats 28.40% of Python submissions
Memory: Beats 78.45% of Python submissions

"""

class Solution(object):

    def threeSumClosest(self, nums, target):
        """
        Given an integer array nums of length n and an integer target, 
        find three integers in nums such that the sum is closest to target.
        Return the sum of the three integers.

        Args:
            nums (List[int]): the list of numbers to consider for possible three sum combos
            target (int): the target value for the three sum to sum to

        Returns:
            int: the closest sum to the given target value using the given integers in nums
        """
        
        closestSum = float('inf')   # the current closest sum to the target, initialized as a very large value
        currentSum = 0              # the current three sum being considered
        
        nums.sort() # sort the given array from least to greatest
        
        for i in range(len(nums)):
            
            # do not repeat using a value as the initial number in the sum
            if ((i != 0) and (nums[i] == nums[i-1])):
                
                continue
            
            # do threesum stuff
            left = i+1
            right = len(nums)-1
            while (left < right):
                
                currentSum = nums[i] + nums[left] + nums[right]
                
                # if the distance from the current sum to the target is less than 
                # the distance from the current closest sum to the target, 
                # mark the current sum as the new closest sum
                if (abs(currentSum - target) < abs(closestSum - target)):
                    
                    closestSum = currentSum
                

                # move the left pointer to a larger value to increase the sum
                if (currentSum < target):
                    
                    left += 1
                    
                # move the right pointer to a smaller value to decrease the sum
                elif (currentSum > target):
                    
                    right -= 1
                    
                else: # if currentSum == target:
                    
                    return currentSum
                
                

        return closestSum

def main():
    
    nums = [0, 0, 0]
    target = 10000

    sol = Solution()

    print(f'Output: {sol.threeSumClosest(nums, target)}')

    return

if __name__ == "__main__":
    main()
