
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 5.90% of Python submissions

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):

    def maxDepth(self, root):
        """
        Given the root of a binary tree, return its maximum depth.
        A binary tree's maximum depth is the number of nodes along the longest path 
        from the root node down to the farthest leaf node.

        Args:
            root (TreeNode): the root of the given binary tree

        Returns:
            int: the maximum depth of the given tree
        """

        maxDepth = 0 # the current maximum depth of the given tree

        if root is None: # if the given root is null, the tree has no depth
            return 0

        queue = [(root, 1)] # initialize BFS queue

        # while there are more nodes to traverse
        while len(queue):

            node, depth = queue.pop(0) # pop the head of the queue

            if depth > maxDepth: # if the popped depth is deeper than the current max depth
                maxDepth = depth

            if node.left is not None: # if there is a left child
                queue.append((node.left, depth+1))

            if node.right is not None: # if there is a right child
                queue.append((node.right, depth+1))

        return maxDepth
                
                
    
def main():

    sol = Solution()
    
    root = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    
    output = sol.maxDepth(root)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()