
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 83.18% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def preorderTraversal(self, root):
        """
        Given the root of a binary tree, returns the preorder traversal of its nodes' values.

        Args:
            root (Optional[TreeNode]): the given binary tree

        Returns:
            List[int]: A list containing the preorder traversal of the binary tree nodes' values.
        """
        
        outputList = [] # a list with the binary tree nodes' values from a preorder traversal

        def POT(root):
            """
            Performs a preorder traversal on the given binary tree.

            Args:
                root (Optional[TreeNode]): the given binary tree
            """

            if root is None:
                return
            else:
                outputList.append(root.val)
                POT(root.left)
                POT(root.right)

        POT(root) # perform preorder traversal

        return outputList
                
    
def main():

    sol = Solution()

    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)

    node1.right = node2
    node2.left = node3

    output = sol.preorderTraversal(node1)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()