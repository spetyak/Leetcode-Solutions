
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 79.43% of Java submissions
 */
public class lc110 {

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

    /**
     * Determines the height of the given tree and returns -1 if the tree is not height-balanced.
     * 
     * @param root the current subtree root
     * @param height the height of the current subtree root in the larger tree
     * 
     * @return the maximum height of the left and right subtree if their max heights do not differ by more than 1, -1 otherwise.
     */
    public static int checkHeight(TreeNode root, int height) {

        if (root == null) // base case
        {
            return height;
        }

        int height1 = checkHeight(root.left, height+1);     // get left subtree height
        int height2 = checkHeight(root.right, height+1);    // get right subtree height

        if (Math.abs(height1 - height2) > 1) // if the subtree heights differ by more than 1 level
        {
            return -1;
        }
        else
        {
            return Math.max(height1, height2);
        }

    }

    /**
     * Given a binary tree, determines if it is height-balanced.
     * 
     * @param root the root of the given binary tree
     * 
     * @return {@code true} if the given binary tree is heigh-balanced, {@code false} if not
     */
    public static boolean isBalanced(TreeNode root) {

        if (root == null) // base case
        {
            return true;
        }

        if (checkHeight(root, 0) >= 0) // if a valid tree height is returned, the tree is balanced
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    public static void main(String[] args) {
        
        TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        
        boolean output = isBalanced(root);

        System.out.println("Output: " + output);

    }

}