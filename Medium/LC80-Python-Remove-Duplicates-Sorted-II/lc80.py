
"""
Author: spetyak

Runtime: Beats 77.72% of Python submissions
Memory: Beats 88.79% of Python submissions

"""

class Solution(object):

    def removeDuplicates(self, nums):
        """
        Given an integer array nums sorted in non-decreasing order, 
        removes duplicates in-place such that each unique element appears at most twice. 
        The relative order of the elements should be kept the same.

        Args:
            nums (List[int]): the sorted array of integers to remove duplicates from

        Returns:
            int: the size of the legal section of the modified array
        """

        numDict = {}            # dictionary to track the number of times each number is present
        actualUpdateIndex = 0   # the index of the update pointer for the legal section of the array

        for i in range(len(nums)):

            currentOcc = numDict.get(nums[i], 0) # check number of occurrences of current number
            
            if (currentOcc < 2): # if the current number has occurred less than 2 times so far

                if (currentOcc == 0): # if this is the first occurrence seen of the current number

                    numDict[nums[i]] = 1 # add the current number to the dictionary
                    
                else: # not the first occurrence seen of the current number
                    
                    numDict[nums[i]] += 1 # increment number count in dictionary
                    
                nums[actualUpdateIndex] = nums[i]   # update the legal section of the array
                actualUpdateIndex += 1              # increment the update pointer



        return actualUpdateIndex # return the size of the legal section of the modified array

def main():

    sol = Solution()
    
    nums = [0,0,1,1,1,1,2,3,3]
    
    print(f"Output: {sol.removeDuplicates(nums)}")

    return

if __name__ == "__main__":
    main()