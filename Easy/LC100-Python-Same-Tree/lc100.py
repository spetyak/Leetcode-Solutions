
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 58.83% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    
    def isSameTree(self, p, q):
        """
        Given the roots of two binary trees p and q, write a function to check if they are the same or not.
        Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

        Args:
            p (Optional[TreeNode]): one of the binary trees to be compared
            q (Optional[TreeNode]): one of the binary trees to be compared

        Returns:
            bool: True if the binary trees are identical, False if not.
        """

        # if null pointers are reached for both binary trees
        if p is None and q is None:

            return True

        else:

            # if only one of the current nodes is null the trees are not matching
            if p is None or q is None:

                return False

            # if the current nodes match, continue traversing trees
            elif p.val == q.val:

                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

            # the current node values do not match
            else:

                return False
                
                
    
def main():

    sol = Solution()
    
    p = TreeNode(1, TreeNode(2), TreeNode(3))
    q = TreeNode(1, TreeNode(2), TreeNode(3))
    
    print(f"Output: {sol.isSameTree(p, q)}")

    return

if __name__ == "__main__":
    main()