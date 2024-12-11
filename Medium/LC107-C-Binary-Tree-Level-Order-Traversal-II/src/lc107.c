
#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 95.29% of C submissions
 */

#define DEFAULT_CAPACITY 8

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct myArrayList {
    int* nums;
    int size;
    int capacity;
};

struct myLevelsList {
    struct myArrayList** levels;
    int size;
    int capacity;
};

struct myLevelsList* levelLists;

/*
 * Traverses the given binary tree and adds the nodes to a list in a top-down level order traversal.
 *
 * @param root the root of the given binary tree
 * @param level the level of the current root in the larger binary tree
 * 
 * @return A list of nodes found performing a top-down level order traversal of the binary tree.
 */
void levelTraversal(struct TreeNode* root, int level) {

    if (root == NULL) // base case
    {
        return;
    }

    if (levelLists->size >= level+1) // if there already exists a list for the current level
    {

        // add the current node to the appropriate level list
        struct myArrayList* currentLevelList = levelLists->levels[level];
        currentLevelList->nums[currentLevelList->size] = root->val;
        currentLevelList->size++;

        if (currentLevelList->size == currentLevelList->capacity) // if the list of nodes in the current level is at capacity, double its capacity
        {
            currentLevelList->capacity *= 2;
            currentLevelList->nums = realloc(currentLevelList->nums, currentLevelList->capacity * sizeof(int));
        }

    }
    else // there is no list currently for the current level, create it
    {

        // create new level list and add the current node to it
        struct myArrayList* newLevelList = malloc(sizeof(struct myArrayList));
        newLevelList->nums = malloc(DEFAULT_CAPACITY * sizeof(int));
        newLevelList->size = 0;
        newLevelList->capacity = DEFAULT_CAPACITY;

        newLevelList->nums[newLevelList->size] = root->val;
        newLevelList->size++;

        levelLists->levels[levelLists->size] = newLevelList;
        levelLists->size++;

        if (levelLists->size == levelLists->capacity) // if the list of levels is at capacity, double its capacity
        {
            levelLists->capacity *= 2;
            levelLists->levels = realloc(levelLists->levels, levelLists->capacity * sizeof(struct myArrayList*));
        }

    }

    levelTraversal(root->left, level+1);    // traverse left subtree
    levelTraversal(root->right, level+1);   // traverse right subtree

    return;

}

/*
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
 * (i.e., from left to right, level by level from leaf to root).
 *
 * @param root the root of the binary tree
 * @param returnSize the number of levels in the binary tree
 * @param returnColumnSizes the number of elements in each level of the binary tree
 * 
 * @return A bottom-up level order traversal of the given binary tree
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    // initialize the list of tree levels
    levelLists = malloc(sizeof(struct myLevelsList));
    levelLists->levels = malloc(DEFAULT_CAPACITY * sizeof(struct myArrayList*));
    levelLists->size = 0;
    levelLists->capacity = DEFAULT_CAPACITY;

    levelTraversal(root, 0); // traverse the tree in a level-order fashion (top-down)

    // reverse level list order so that the levels are now bottom-up
    for (int i = 0; i < levelLists->size / 2; i++)
    {

        int swapIndex = levelLists->size - i - 1;

        struct myArrayList* temp = levelLists->levels[i];
        levelLists->levels[i] = levelLists->levels[swapIndex];
        levelLists->levels[swapIndex] = temp;

    }

    // convert levelList struct to regular 2D int array

    int** output = malloc(levelLists->size * sizeof(int*));
    *returnSize = levelLists->size;
    *returnColumnSizes = malloc(levelLists->size * sizeof(int));

    for (int i = 0; i < levelLists->size; i++)
    {

        struct myArrayList* currentLevel = levelLists->levels[i];
        int* levelNums = currentLevel->nums;

        (*returnColumnSizes)[i] = currentLevel->size;

        output[i] = malloc(currentLevel->size * sizeof(int));

        for (int j = 0; j < currentLevel->size; j++)
        {
            output[i][j] = levelNums[j];
        }

    }

    return output;

}



int main() {

    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    node2->val = 9;
    node2->left = NULL;
    node2->right = NULL;

    struct TreeNode* node4 = malloc(sizeof(struct TreeNode));
    node4->val = 15;
    node4->left = NULL;
    node4->right = NULL;

    struct TreeNode* node5 = malloc(sizeof(struct TreeNode));
    node5->val = 7;
    node5->left = NULL;
    node5->right = NULL;

    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));
    node3->val = 20;
    node3->left = node4;
    node3->right = node5;

    struct TreeNode* node1 = malloc(sizeof(struct TreeNode));
    node1->val = 3;
    node1->left = node2;
    node1->right = node3;

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** output = levelOrderBottom(node1, &returnSize, &returnColumnSizes);

    // free output list
    for (int i = 0; i < returnSize; i++)
    {
        free(output[i]);
    }
    free(output);

    // free returnColumnSizes array
    free(returnColumnSizes);

    // free myLevelsList object and inner arraylist(s)
    for (int i = 0; i < levelLists->size; i++)
    {
        struct myArrayList* currentList = levelLists->levels[i];
        free(currentList->nums);
        free(currentList);
    }
    free(levelLists->levels);
    free(levelLists);

    // free tree nodes
    free(node2);
    free(node4);
    free(node5);
    free(node3);
    free(node1);

    return 0;

}