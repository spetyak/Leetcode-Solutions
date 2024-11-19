import math

"""
Author: spetyak

Runtime: Beats 99.09% of Python submissions
Memory: Beats 40.58% of Python submissions

"""

class Solution(object):
    
    def getPermutation(self, n, k):
        """
        Given n and k, returns the kth permutation sequence of the n! permutations.

        Args:
            n (int): the number of integers included in each permutation [1, n]
            k (int): the target permutation 

        Returns:
            str: the kth permutation sequence of the n! permutations
        """

        output = ""

        # get number that will be part of permutation sequence
        sourceStr = ""
        for i in range(1, n+1):
            sourceStr += str(i)
            
        k -= 1 # decrease to match with 0-indexing

        # loop until source string is empty
        while len(sourceStr) > 0:
            
            # determine how many permutations exist with any given element being 
            # the first element in an array of n elements (n-1 other elements)
            factFactor = math.factorial(n-1) 
            
            # determine which number would appear in which position based off of
            # the number of permutations it would take to reach that element at
            # that given position
            elementIndex = k // factFactor

            # add the given integer character to the output string
            output += str(sourceStr[elementIndex])
            
            # remove the used character from the source string
            sourceStr = sourceStr[:elementIndex] + sourceStr[elementIndex+1:]
                    
            n -= 1          # decrease the number of spaces to consider
            k %= factFactor # update the number of permutations needed to reach the next value

       

        return output

def main():

    sol = Solution()
    
    n = 3
    k = 2
    
    print("Output: " + sol.getPermutation(n, k))

    return

if __name__ == "__main__":
    main()
    