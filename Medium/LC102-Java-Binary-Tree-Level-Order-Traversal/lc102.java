import java.util.ArrayList;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 7.47% of Java submissions
 */
public class lc102 {

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

    public static List<List<Integer>> levels; // the list of lists of nodes grouped by tree level

    /**
     * Traverse the tree using a pre-order traversal and add the current node value to the level list.
     * 
     * @param root the current node being added to the level list
     * @param level the current level in the tree
     */
    public static void levelTraversal(TreeNode root, int level) {

        if (root == null) // base case
        {
            return;
        }

        if (levels.size() >= level+1) // if there is already a list for the current level this node is a part of
        {
            levels.get(level).add(root.val);
        }
        else // there is not a list yet for the current level, make one and add the current node to it
        {
            List<Integer> l = new ArrayList<>();
            l.add(root.val);
            levels.add(l);
        }

        levelTraversal(root.left, level+1);     // traverse left subtree
        levelTraversal(root.right, level+1);    // traverse right subtree

        return;

    }

    /**
     * Given the root of a binary tree, return the level order traversal of its nodes' values. 
     * (i.e., from left to right, level by level).
     * 
     * @param root the root of the given binary tree
     * 
     * @return a list of lists containing the values at each level of the binary tree grouped by their level
     */
    public static List<List<Integer>> levelOrder(TreeNode root) {

        levels = new ArrayList<>();

        levelTraversal(root, 0);

        return levels;
        
    }

    public static void main(String[] args) {
        
        TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        
        levels = levelOrder(root);

        System.out.print("[");
        for (int i = 0; i < levels.size(); i++)
        {
            System.out.print(levels.get(i).toString());
        }
        System.out.println("]");

    }

}