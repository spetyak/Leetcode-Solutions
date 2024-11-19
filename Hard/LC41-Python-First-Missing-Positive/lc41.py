
"""
Author: spetyak

Runtime: Beats 28.11% of Python submissions
Memory: Beats 53.74% of Python submissions

"""

class Solution(object):
    
    def firstMissingPositive(self, nums):
        """
        Finds the smallest positive integer not present in the given list of integers.

        Args:
            nums (List[int]): the unsorted list of integers to be examined

        Returns:
            int: the smallest positive integer not present in the given list of integers
        """
        
        # change any negative numbers in the list to 0 
        # as they are not needed and defining our own 
        # negative numbers to help with indexing will be necessary
        for i in range(len(nums)):
            
            if nums[i] < 0:
                
                nums[i] = 0
                
        # loop through the integer list and mark integers that are present as present
        for i in range(len(nums)):
            
            val = abs(nums[i])
            
            # if the current value being examined exists 
            # within the bounds of the length of the given array
            if 1 <= val and val <= len(nums):
                
                # if the given number is positive, mark it as being present 
                # in the array by making the hashed position negative
                if nums[val - 1] > 0:
                    
                    nums[val - 1] *= -1 
                    
                # if the given number is 0, mark the hashed position as 
                # negative by multiplying the length of the array by -1
                elif nums[val - 1] == 0:
                    
                    nums[val - 1] = -1 * (len(nums) + 1)
                    
        # check if all numbers within the bounds of the length of the list
        # exist in the list or not
        for i in range(1, len(nums) + 1):
            
            # if the current number does not exist in the list
            if nums[i - 1] >= 0:
                
                return i
        
        # if all positive numbers are present in the list,
        # the first missing positive integer is the next integer
        # not present in the list
        return len(nums) + 1

def main():
    
    sol = Solution()
    
    nums = [1,2,3,4,5]
    print(f"Output: {sol.firstMissingPositive(nums)}")

    return

if __name__ == "__main__":
    main()