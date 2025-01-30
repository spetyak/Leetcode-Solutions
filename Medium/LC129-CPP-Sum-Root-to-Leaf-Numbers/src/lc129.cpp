#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 69.96% of C++ submissions
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

    int totalSum; // the total sum of all root-to-leaf numbers

    /*
     * Performs a depth-first traversal on a binary tree, 
     * adding the node's integer value to a string that will eventually represent a larger integer.
     * This larger integer is then added to the total sum of all root-to-leaf numbers.
     *
     * @param root the current subtree root of the given binary tree
     * @param s the current number string
     */
    void dft(TreeNode* root, string &s) {

        // if the current node has no children
        if (root->left == nullptr and root->right == nullptr)
        {

            s.push_back('0' + root->val);

            // convert string to integer and add it to total sum
            int sum = stoi(s);
            totalSum += sum;

            s.pop_back();

            return;

        }

        if (root->left) // work on left subtree
        {
            s.push_back('0' + root->val);
            dft(root->left, s);
            s.pop_back();
        }

        if (root->right) // work on right subtree
        {
            s.push_back('0' + root->val);
            dft(root->right, s);
            s.pop_back();
        }

    }

    /*
     * Given a binary tree containing digits from [0, 9], 
     * returns the total sum of all root-to-leaf numbers.
     *
     * @param root the root of the given binary tree
     * 
     * @return The total sum of all root-to-leaf numbers.
     */
    int sumNumbers(TreeNode* root) {

        /*
         * A string of the numbers found along the current path, 
         * will eventually be converted to an integer.
         */
        string s;

        totalSum = 0;

        dft(root, s); // perform a depth-first traversal on the tree, building numbers along the way

        return totalSum;

    }

};

int main() {

    Solution s;

    TreeNode* root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));

    int output = s.sumNumbers(root);

    cout << "Output: " << output << endl;

    return 0;

}