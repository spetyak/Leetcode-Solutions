#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 95.76% of C++ submissions
 * Memory: Beats 12.90% of C++ submissions
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

    vector<int> nums; // the sorted vector to be used to create the binary search tree

    /*
     * Using a sorted vector, recursively divide the array into halves around a middle value
     * that will be treated as a subtree root node.
     *
     * @param leftBound the lower bound of the current window
     * @param rightBound the upper bound of the current window
     * 
     * @return A height-balanced binary search tree.
     */
    TreeNode* recursive(int leftBound, int rightBound) {

        if (rightBound <= leftBound) // base case
        {
            return nullptr;
        }

        int midIndex = (rightBound + leftBound) / 2;        // get middle value of current window

        TreeNode* newNode = new TreeNode(nums[midIndex]);   // create new node using middle value
        newNode->left = recursive(leftBound, midIndex);     // build left subtree
        newNode->right = recursive(midIndex+1, rightBound); // build right subtree

        return newNode;

    }

    /*
     * Given the head of a singly linked list where elements are sorted in ascending order,
     * converts it to a height-balanced binary search tree.
     *
     * @param head the head of the singly linked list
     * 
     * @return A height-balanced binary search tree made from the given linked list.
     */
    TreeNode* sortedListToBST(ListNode* head) {

        ListNode* current = head;
        while (current)
        {
            nums.push_back(current->val);
            current = current->next;
        }

        TreeNode* root = recursive(0, nums.size());

        return root;

    }

};

int main() {

    Solution s;

    // kinda pointless to go through trouble here to demonstrate output 

    return 0;

}