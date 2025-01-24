from math import inf

"""
Author: spetyak

Runtime: Beats 94.09% of Python submissions
Memory: Beats 52.10% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

maxSplitSum = 0

class Solution:

    def maxPathSum(self, root):
        """
        Given the root of a binary tree, returns the maximum path sum of any non-empty path.

        Args:
            root (Optional[TreeNode]): the root of the given binary tree

        Returns:
            int: The maximum path sum of any non-empty path in the tree.
        """

        global maxSplitSum
        maxSplitSum = -inf # initialize the maximum sum of a split path to be negative infinity

        def maxPathNoSplit(root):
            """
            Given the root of a binary tree, returns the maximum path sum of any non-empty path in 
            the tree where the path does not follow the left AND right children of any node in the
            tree.

            Args:
                root (Optional[TreeNode]): the root of the given binary tree

            Returns:
                int: The maximum path sum of any non-empty path in the tree.
            """

            global maxSplitSum

            # base case
            if root is None:
                return 0

            leftSum  = maxPathNoSplit(root.left)    # determine max path sum of the left subtree
            rightSum = maxPathNoSplit(root.right)   # determine max path sum of the right subtree

            # determine the maximum path sum to the current node from its left and/or right subtrees
            # the maximum may be:
            # - just the root itself
            # - a subtree that has a larger sum,
            # - the left subtree including the root
            # - the right subtree including the root
            # - or the left and right subtree including the root
            maxSplitSum = max(root.val, 
                              maxSplitSum, 
                              leftSum + root.val, 
                              rightSum + root.val, 
                              leftSum + root.val + rightSum)

            # disregarding a path that splits travels along both a left and right subtree,
            # determine the maximum path sum of the left and right subtrees and add it to the 
            # root value
            # if both are negative, opt for just considering this current root value going forward
            return root.val + max(leftSum, rightSum, 0)

        # return the maximum sum of a path that DOES NOT follow the left AND right subtree of a node
        # OR the maximum sum of a path which DOES follow the left AND right subtree of a node,
        # whichever is larger
        return max(maxPathNoSplit(root), maxSplitSum)
                
                
    
def main():

    sol = Solution()

    root = TreeNode(-10, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))

    output = sol.maxPathSum(root)

    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()