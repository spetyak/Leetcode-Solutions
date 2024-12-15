#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 28.42% of C++ submissions
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    /*
     * Finds the minimum depth of the given tree.
     *
     * @param root the current subtree root of the larger tree
     * @param depth the depth of the current root
     * 
     * @return The minimum depth of the given tree.
     */
    int checkDepth(TreeNode* root, int depth) {

        if (root == nullptr) // base case
        {
            return depth;
        }

        if (root->left == nullptr && root->right == nullptr) // current root is a leaf node
        {
            return depth+1;
        }
        else if (root->left == nullptr) // only right subtree exists for current root
        {
            return checkDepth(root->right, depth+1);
        }
        else if (root->right == nullptr) // only left subtree exists for current root
        {
            return checkDepth(root->left, depth+1);
        }
        else // determine minimum depth of left and right subtrees
        {
            return min(checkDepth(root->left, depth+1), checkDepth(root->right, depth+1));
        }

    }

    /*
     * Given a binary tree, finds its minimum depth.
     *
     * @param root the root of the given binary tree
     * 
     * @return The minimum depth of the given tree.
     */
    int minDepth(TreeNode* root) {

        return checkDepth(root, 0);

    }

};

int main() {

    Solution s;

    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    int output = s.minDepth(root);

    cout << "Output: " << output << endl;

    return 0;

}