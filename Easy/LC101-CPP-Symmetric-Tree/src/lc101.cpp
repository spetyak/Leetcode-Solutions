#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 88.52% of C++ submissions
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    /*
     * Traverse two given trees in a mirrored fashion, 
     * checking if the nodes of the trees mirror each other
     *
     * @param root1 the left tree
     * @param root2 the right tree
     */
    bool symmetricDFSTraversal(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr and root2 == nullptr) // both nodes are null
        {
            return true;
        }
        else if ((root1 == nullptr and root2 != nullptr) or (root1 != nullptr and root2 == nullptr)) // one node is null
        {
            return false;
        }
        else // both nodes are not null
        {

            bool out1 = symmetricDFSTraversal(root1->left, root2->right);

            // check current nodes values, return false if not equal
            if (root1->val != root2->val)
            {
                return false;
            }

            bool out2 = symmetricDFSTraversal(root1->right, root2->left);

            return (out1 and out2); // return whether the current two subtrees match

        }

    }

    /*
     * Given the root of a binary tree, check whether it is a mirror of itself 
     * (i.e., symmetric around its center).
     *
     * @param root the root of the given binary tree
     */
    bool isSymmetric(TreeNode* root) {
        
        // if there is just a single root node
        if (root->left == nullptr and root->right == nullptr)
        {
            return true;
        }

        return symmetricDFSTraversal(root->left, root->right);

    }

};

int main() {

    Solution s;

    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    bool output = s.isSymmetric(root);

    cout << "Output: ";
    if (output)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << endl;

    return 0;

}