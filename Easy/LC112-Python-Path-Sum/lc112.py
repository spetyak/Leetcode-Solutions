
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 25.84% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def hasPathSum(self, root, targetSum):
        """
        Given the root of a binary tree and an integer targetSum, returns true if the tree has a 
        root-to-leaf path such that adding up all the values along the path equals targetSum.

        Args:
            root (Optional[TreeNode]): the root of the given binary tree
            targetSum (int): the target path sum to search for

        Returns:
            bool: True if tree has root-to-leaf path whose sum equals target sum, False if not
        """

        def traverse(root, currentSum):
            """
            Traverses the given tree while determining the current path sum, checking if the 
            current sum equals the target path sum.

            Args:
                root (Optional[TreeNode]): the root of the current subtree
                currentSum (int): the sum of the current path traveled along the tree

            Returns:
                bool: True if tree has root-to-leaf path whose sum equals target sum, False if not
            """

            if (root is None): # base case, null node does not count towards sum

                return False

            currentSum += root.val # add node value to path sum

            if (root.left is None and root.right is None): # if the current node is a leaf node

                if (currentSum == targetSum): 

                    return True

                else:

                    return False

            return traverse(root.left, currentSum) or traverse(root.right, currentSum) # check left and right subtrees

        if (root is None): # base case

            return False

        else:

            return traverse(root, 0)
                
                
    
def main():

    sol = Solution()

    root = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, None, TreeNode(1))))
    targetSum = 22

    output = sol.hasPathSum(root, targetSum)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()