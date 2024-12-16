#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 54.37% of C++ submissions
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

    int target;
    vector<vector<int>> paths;

    /*
     * Performs a depth-first traversal on the given tree, summing node values and adding them to 
     * a path list along the traversal. If a leaf node is reached whose root-to-leaf path sum equals
     * the target value, that path is added to the global list of paths that sum to targetSum.
     *
     * @param root the current root of the given tree
     * @param currentSum the current sum of the nodes on the current path
     * @param pathNums the list of nodes on the current path
     */
    void traverse(TreeNode* root, int currentSum, vector<int>* pathNums) {

        if (root == nullptr) // base case
        {
            return;
        }

        // add current root to current sum and path list
        currentSum += root->val;
        pathNums->push_back(root->val);

        // if this node is a leaf node in the larger tree
        if (root->left == nullptr && root->right == nullptr)
        {

            if (currentSum == target)
            {
                paths.push_back(*pathNums);
            }

        }

        traverse(root->left, currentSum, pathNums);     // check left subtree
        traverse(root->right, currentSum, pathNums);    // check right subtree

        pathNums->pop_back(); // revert back up the tree

    }

    /*
     * Given the root of a binary tree and an integer targetSum, returns all root-to-leaf paths
     * where the sum of the node values in the path equals targetSum.
     *
     * @param root the root of the given binary tree
     * @param targetSum the target value that each tree path should sum to
     * 
     * @return A list of all root-to-leaf paths in the tree whose sum equals targetSum.
     */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        target = targetSum;         // set the global target variable
        vector<int> currentPath;    // the list of nodes on the path currently being traversed

        traverse(root, 0, &currentPath);

        return paths;

    }

};

int main() {

    Solution s;

    TreeNode* root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    int targetSum = 22;

    vector<vector<int>> output = s.pathSum(root, targetSum);

    cout << "Output: [";
    for (int i = 0; i < output.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < output[0].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;

}