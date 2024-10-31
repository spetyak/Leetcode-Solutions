
#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 92% of C submissions
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* firstNode;     // the first misplaced node encountered
struct TreeNode* secondNode;    // the second misplaced node encountered
struct TreeNode* previousNode;  // the last node acted on in the inorder traversal

/*
 * Traverse the binary search tree in order and find the two misplaced nodes.
 *
 * @param root the root of the binary search tree
 */
void traverse(struct TreeNode* root) {

    if (!root)
    {
        return;
    }

    traverse(root->left); // traverse left sub tree

    // if the inorder tree traversal is underway and the current node value is 
    // less than the previous node value
    if (previousNode && root->val < previousNode->val)
    {

        // if no node has been found out of order yet
        if (!firstNode)
        {
            firstNode = previousNode;
        }
        
        // if a node has already been found out of order
        if (firstNode)
        {
            secondNode = root;
        }

    }

    previousNode = root; // grab this node as the previous node for the next node visited

    traverse(root->right); // traverse right sub tree

}

/*
 * Given the root of a binary search tree where the values of exactly two nodes of the tree 
 * were swapped by mistake, recovers the tree without changing its structure.
 *
 * @param root the root of a slightly altered binary search tree
 */
void recoverTree(struct TreeNode* root) {

    firstNode = secondNode = previousNode = NULL; // initialize pointer nodes to null

    traverse(root); // find the two misplaced nodes

    // swap the misplaced nodes
    if (firstNode && secondNode)
    {
        int temp = secondNode->val;
        secondNode->val = firstNode->val;
        firstNode->val = temp;
    }

}

int main() {

    recoverTree(NULL);

    return 0;

}
