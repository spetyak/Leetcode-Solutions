import java.util.ArrayList;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 46.66% of Java submissions
 */
public class lc94 {

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
     * Performs a inorder traversal from the given node and 
     * adds the nodes value to the given list.
     * 
     * @param root the current node of the binary tree being examined
     * @param l the list to add the node values to when traversed inorder
     */
    public static void traverse(TreeNode root, List<Integer> l) {

        if (root == null) // if the current node is null, return
        {
            return;
        }
        else // perform inorder traversal
        {

            traverse(root.left, l);     // continue left
            l.add(root.val);            // perform action (add to list)
            traverse(root.right, l);    // continue right

        }

    }

    /**
     * Given the root of a binary tree, returns the inorder traversal of its nodes' values.
     * 
     * @param root the root of a binary tree structure
     * 
     * @return A list of the binary tree nodes' values obtained by traversing the tree in order
     */
    public static List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> l = new ArrayList<>(); // initialize inorder traversal node output list

        traverse(root, l); // perform traversal on given binary tree

        return l;
        
    }

    public static void main(String[] args) {
        
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(3);
        TreeNode n3 = new TreeNode(2);

        n1.right = n2;
        n2.left = n3;

        List<Integer> output = inorderTraversal(n1);

        System.out.println("Output: " + output.toString());

    }

}