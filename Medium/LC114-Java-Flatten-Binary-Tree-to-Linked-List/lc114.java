
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 64.53% of Java submissions
 */
public class lc114 {

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

    private static TreeNode prev;

    /**
     * Given the root of a binary tree, flatten the tree into a "linked list" (a degenerate tree).
     * 
     * @param root the root of the binary tree to be flattened
     */
    public static void flatten(TreeNode root) {

        if (root == null) // base case
        {
            return;
        }

        flatten(root.right);    // process right subtree
        flatten(root.left);     // process left subtree

        root.right = prev;      // set current nodes right pointer to last left node encountered
        root.left = null;       // set current nodes left pointer to null

        prev = root;            // update previous pointer to be current node

    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, null, new TreeNode(6)));
        
        flatten(root);

        while (root != null)
        {
            System.out.println(root.val);
            root = root.right;
        }

    }

}