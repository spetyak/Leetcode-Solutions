
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 77.64% of Python submissions

"""

class Solution:

    def singleNumber(self, nums):
        """
        Given an array of integers where every element appears twice EXCEPT FOR ONE, 
        finds that single non-repeated element and returns it.

        Args:
            nums (List[int]): the given array of integers

        Returns:
            int: The only element in the given array that is not repeated
        """

        num = 0 # an integer used to track bit appearances

        # iterate through the array, flipping the bits of the current number in the num variable
        # numbers that appear twice will essentially leave no trace while the single element will
        # have its bits marked after the loop has completed regardless of its position in the array
        for i in range(1, len(nums)):

            num ^= nums[i]

        return num
                
                
    
def main():

    sol = Solution()

    nums = [4, 1, 2, 1, 2]
    
    output = sol.singleNumber(nums)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()