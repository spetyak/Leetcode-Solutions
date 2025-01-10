
"""
Author: spetyak

Runtime: Beats 96.00% of Python submissions
Memory: Beats 32.98% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:

    def connect(self, root):
        """
        Given a perfect binary tree, populates each node's next pointer to point to its next right node. 
        If there is no next right node, the next pointer should be set to NULL.
        Initially, all next pointers are set to NULL.

        Args:
            root (Optional[Node]): the root of the given perfect binary tree

        Returns:
            Optional[Node]: A binary tree with level/row nodes connected in a linked list fashion.
        """

        # base case
        if root is None:

            return root

        currRowHead = root # initialize row head variable

        # iterate through each level/row of the tree
        while currRowHead is not None:

            curr = currRowHead

            # iterate through nodes in level/row
            while curr is not None:

                if curr.left is not None:

                    curr.left.next = curr.right

                # connect gaps between subtrees
                if curr.right is not None and curr.next is not None:

                    curr.right.next = curr.next.left

                curr = curr.next # advance pointer in level/row

            currRowHead = currRowHead.left # advance to next level/row

        return root
                
                
    
def main():

    sol = Solution()

    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3, TreeNode(6), TreeNode(7)))

    root = sol.connect(root)

    print("Output: [", end="")
    while root is not None:
        rowHead = root
        while rowHead is not None:
            print(f"{rowHead.val} ", end="")
            rowHead = rowHead.next
        print("# ", end="")
        root = root.left
    print("]")

    return

if __name__ == "__main__":
    main()