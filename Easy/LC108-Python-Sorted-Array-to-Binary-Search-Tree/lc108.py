
"""
Author: spetyak

Runtime: Beats 85.18% of Python submissions
Memory: Beats 26.76% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def sortedArrayToBST(self, nums):
        """
        Given an integer array nums where the elements are sorted in ascending order, 
        convert it to a height-balanced binary search tree.

        Args:
            nums (List[int]): the sorted array to be used as the basis for the binary search tree order

        Returns:
            Optional[TreeNode]: A height-balanced binary search tree.
        """

        def recursive(leftBound, rightBound):
            """
            Using a sorted array, recursively divide the array into halves around a middle value
            that will be treated as a subtree root node.

            Args:
                leftBound (int): the lower bound of the current window
                rightBound (int): the upper bound of the current window

            Returns:
                Optional[TreeNode]: A height-balanced binary search tree.
            """

            if rightBound <= leftBound: # base case
                return None

            midIndex = (rightBound + leftBound) // 2            # get middle value of the current subset

            newNode = TreeNode(nums[midIndex])                  # create new node using middle value of subset
            newNode.left = recursive(leftBound, midIndex)       # build left subtree
            newNode.right = recursive(midIndex+1, rightBound)   # build right subtree

            return newNode



        root = recursive(0, len(nums)) # build tree recursively

        return root
                
                
    
def main():

    sol = Solution()
    
    testInput = [-10, -3, 0, 5, 9]

    return

if __name__ == "__main__":
    main()