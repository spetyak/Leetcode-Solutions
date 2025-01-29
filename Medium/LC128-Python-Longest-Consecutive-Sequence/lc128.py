
"""
Author: spetyak

Runtime: Beats 38.32% of Python submissions
Memory: Beats 13.55% of Python submissions

"""

class Solution:

    def longestConsecutive(self, nums):
        """
        Given an unsorted array of integers nums, 
        returns the length of the longest consecutive elements sequence.

        Args:
            nums (List[int]): the unsorted array of integers

        Returns:
            int: The length of the longest consecutive elements sequence.
        """

        sequenceLength = 0  # the current sequence's length
        maxLength = 0       # the maximum sequence length found so far

        myDict = {} # hash table used to help find consecutive elements

        # add the numbers from nums to a hash table
        for i in range(len(nums)):

            myDict[nums[i]] = nums[i]

        # loop through the numbers in the hash table
        for num in myDict:

            # if no preceding number exists in the hash table, this could be the start of a sequence
            if (num-1 not in myDict):

                foundNext = True
                sequenceLength = 1

                current = num

                # while subsequent numbers continue to be found
                while foundNext:

                    if (current+1 in myDict):

                        sequenceLength += 1
                        current += 1    # move to the next value

                    else:

                        maxLength = max(sequenceLength, maxLength)  # update the max length
                        foundNext = False   # flag that the next sequence element was not found
                        break

        return maxLength
                
                
    
def main():

    sol = Solution()

    nums = [100,4,200,1,3,2]
    
    output = sol.longestConsecutive(nums)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()