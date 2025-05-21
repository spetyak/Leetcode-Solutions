#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 43.85% of C++ submissions
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> output; // the list containing the postorder traversal values

    /*
     * Performs a postorder traversal on the given binary tree.
     *
     * @param root the root of the given binary tree
     */
    void POT(TreeNode* root) {

        if (root != nullptr)
        {

            POT(root->left);
            POT(root->right);
            output.push_back(root->val);

        }

    }

    /*
     * Given the root of a binary tree, returns the postorder traversal of its nodes' values.
     *
     * @param root the root of the given binary tree
     * 
     * @return A list containing the values of a postorder traversal of the given binary tree.
     */
    vector<int> postOrderTraversal(TreeNode* root) {

        output.clear(); // reset the global output list

        POT(root); // perform postorder traversal

        return output;

    }

};

int main() {

    Solution s;

    TreeNode* tn1 = new TreeNode(1);
    TreeNode* tn2 = new TreeNode(2);
    TreeNode* tn3 = new TreeNode(3);

    tn1->right = tn2;
    tn2->left = tn3;

    vector<int> output = s.postOrderTraversal(tn1);

    cout << "Output: [";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    } 
    cout << "]" << endl;

    return 0;

}