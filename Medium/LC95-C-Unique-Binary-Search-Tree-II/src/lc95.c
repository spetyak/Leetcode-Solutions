#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 70.59% of C submissions
 * Memory: Beats 63.46% of C submissions
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    };

/*
 * Helper function to print the given binary search tree.
 *
 * @param root the root of the given binary search tree
 */
void printBinaryTree(struct TreeNode* root) {

    if (root == NULL)
    {
        printf("- ");
        return;
    }
    else
    {

        printf("%d ", root->val);
        printBinaryTree(root->left);
        printBinaryTree(root->right);

    }

}

/*
 * Generates all possible unique binary search trees by recursively building subtrees
 * around the current root node and combining the subtrees to form full trees.
 *
 * @param left the left boundary for the current window of values to consider
 * @param right the right boundary for the current window of values to consider
 * @param outputSize the number of binary search trees generated
 * 
 * @return An array of all unique binary search trees with n nodes and unique values in the range [1,n]
 */
struct TreeNode** generate(int left, int right, int* outputSize) {

    struct TreeNode** output;
    int count = 0;

    // if the window has overflowed, the result is a null pointer for a leaf of the tree
    if (left > right)
    {
        output = malloc(sizeof(struct TreeNode*));
        output[0] = NULL;
        *outputSize = 1;
        return output;
    }

    int currentSize = 0;                        // the current size of the output array of combined subtrees
    output = malloc(sizeof(struct TreeNode*));  // initially allocate a small empty array for combining subtrees into full trees

    // given the current range, treat each value as a root and generate 
    // the resulting possible binary search trees for each root
    for (int i = left; i <= right; i++)
    {

        int leftSubTreeSize = 0;
        int rightSubTreeSize = 0;
        struct TreeNode** leftSubTree = generate(left, i-1, &leftSubTreeSize);      // generate all subtrees to the left of the current node
        struct TreeNode** rightSubTree = generate(i+1, right, &rightSubTreeSize);   // generate all subtrees to the right of the current node

        currentSize += (leftSubTreeSize * rightSubTreeSize); // update size

        output = realloc(output, currentSize * sizeof(struct TreeNode*)); // grow array of combined subtrees

        // combine left and right subtrees to form full trees with the current root i
        for (int j = 0; j < leftSubTreeSize; j++)
        {

            for (int k = 0; k < rightSubTreeSize; k++)
            {

                struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftSubTree[j];    // add current left subtree to root
                root->right = rightSubTree[k];  // add current right subtree to root
                output[count++] = root;         // add current tree to output

            }

        }       

    }

    (*outputSize) = count; // update size

    return output;

}

/*
 * Given an integer n, returns all the structurally unique binary search trees 
 * which have exactly n nodes of unique values from 1 to n.
 *
 * @param n the number of nodes and upper limit of values in the binary search tree
 * @param returnSize the number of unique binary search trees created
 * 
 * @return An array of all unique binary search trees with n nodes and unique values in the range [1,n]
 */
struct TreeNode** generateTrees(int n, int* returnSize) {
    
    *returnSize = 0;

    return generate(1, n, returnSize);

}

int main() {

    int n = 4;
    int returnSize = 0;
    
    struct TreeNode** output = generateTrees(n, &returnSize);

    printf("Final output:\n");
    for (int i = 0; i < (returnSize); i++)
    {
        printf("Tree %d: ", i+1);
        printBinaryTree(output[i]);
        printf("\n");
    }

    // to whomever wrote this question, I wish you a very segmentation fault
    // you can deal with the memory cleanup jagoff

    return 0;

}
