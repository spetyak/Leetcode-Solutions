
"""
Author: spetyak

Referenced: https://www.youtube.com/watch?v=lXVy6YWFcRM

Runtime: Beats 69.62% of Python submissions
Memory: Beats 52.71% of Python submissions

"""

class Solution:

    def maxProduct(self, nums):
        """
        Given an integer array nums, finds a subarray that has the largest product, 
        and returns the product.

        Args:
            nums (List[int]): the given array of integer nums

        Returns:
            int: The product of the subarray with the largest product.
        """
        
        # i hate you leetcode

        output = max(nums) # determine the single maximum value of the given array

        maxProduct = nums[0] # initialize the maximum product to the first element
        minProduct = nums[0] # initialize the minimum product to the first element

        for i in range(1, len(nums)):

            # if the current number is 0, reset the max and min to 1 to allow
            # further computation of products past this 0
            if nums[i] == 0:
                maxProduct = 1
                minProduct = 1
                continue

            temp = maxProduct * nums[i] # store this product before manipulating the max product

            # update the max and min products
            maxProduct = max(nums[i] * maxProduct, nums[i] * minProduct, nums[i])
            minProduct = min(temp, nums[i] * minProduct, nums[i])

            output = max(output, maxProduct) # update the ultimate maximum product
                

        return output
        
                
                
    
def main():

    sol = Solution()

    nums = [2,3,-2,4]
    
    output = sol.maxProduct(nums)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()