
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 73.61% of Java submissions
 */
public class lc98 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public static long minValue = Long.MIN_VALUE;

    /**
     * Given the root of a binary tree, determines if it is a valid binary search tree.
     * 
     * @param root the root of a binary tree
     * 
     * @return {@code true} if the given tree is a valid binary search tree, {@code false} if it is not.
     */
    public static boolean isValidBST(TreeNode root) {

        // perform in order traversal
        // in an in order traversal, nodes are visited in ascending order

        // base case
        if (root == null)
        {
            return true;
        }

        boolean out1 = isValidBST(root.left); // check left subtree

        // check if current node value is less than the current minimum, if so this is not a BST
        if (root.val <= minValue)
        {
            return false;
        }
        else
        {
            minValue = root.val; // update minimum
        }

        boolean out2 = isValidBST(root.right); // check right subtree

        return out1 && out2; // return validity of current tree
        
    }

    public static void main(String[] args) {
        
        // [5,4,6,null,null,3,7]
        TreeNode t = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));

        boolean output = isValidBST(t);

        System.out.println("Output: " + output);

    }

}