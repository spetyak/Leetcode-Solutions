import java.util.HashMap;

/**
 * @author spetyak
 * 
 * Runtime: Beats 97.94% of Java submissions
 * Memory: Beats 48.16% of Java submissions
 */
public class lc106 {

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

    public static HashMap<Integer, Integer> map;
    public static int currentIndex;

    /**
     * Recursively build a binary tree given the inorder and postorder traversal lists of said tree.
     * 
     * @param inorder the inorder traversal list of the tree to be built
     * @param postorder the postorder traversal list of the tree to be built
     * @param leftBound the left bound of the current subtree window of the inorder traversal list
     * @param rightBound the right bound of the current subtree window of the inorder traversal list
     * 
     * @return The binary tree which produces the inorder and postorder traversal lists given
     */
    public static TreeNode recursiveBuildTree(int[] inorder, int[] postorder, int leftBound, int rightBound) {

        if (rightBound <= leftBound) // base case
        {
            return null;
        }

        int currentRoot = postorder[currentIndex]; // get the current root from the postorder traversal list
        int rootPosInOrder = map.get(currentRoot); // find the index of the root in the inorder tra

        TreeNode root = new TreeNode(currentRoot); // create new tree node using current root node
        currentIndex--; // move pointer to point to next root node of postorder list

        root.right = recursiveBuildTree(inorder, postorder, rootPosInOrder+1, rightBound); // build right subtree
        root.left = recursiveBuildTree(inorder, postorder, leftBound, rootPosInOrder); // build left subtree

        return root;

    }

    /**
     * Given two integer arrays inorder and postorder where inorder is the 
     * inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
     * construct and return the binary tree.
     * 
     * @param inorder the inorder traversal list of the tree to be built
     * @param postorder the postorder traversal list of the tree to be built
     * 
     * @return The binary tree which produces the inorder and postorder traversal lists given.
     */
    public static TreeNode buildTree(int[] inorder, int[] postorder) {

        currentIndex = postorder.length-1; // set the current root index to the last node in the postorder list, as it is the root of the whole tree

        // create a map of what index each node appears at in the inorder traversal list
        map = new HashMap<>();
        for (int i = 0; i < inorder.length; i++)
        {
            map.put(inorder[i], i);
        }

        TreeNode t = recursiveBuildTree(inorder, postorder, 0, inorder.length);

        return t;

    }

    public static void main(String[] args) {
        
        int[] inorder = {9, 3, 15, 20, 7};
        int[] postorder = {9, 15, 7, 20, 3};
        
        TreeNode tree = buildTree(inorder, postorder);

    }

}