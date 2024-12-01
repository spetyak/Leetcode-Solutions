
#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 90.77% of C submissions
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct myListNode {
    struct TreeNode* t;
    struct myListNode* next;
    int level;
};

struct myQueue {
    struct myListNode* head;
    struct myListNode* tail;
    int size;
};



/*
 * Removes the first element of the given queue and returns it.
 *
 * @param q the queue whose head should be removed
 *
 * @return The popped head node.
 */
struct myListNode* popQueueHead(struct myQueue* q) {

    if (q->head) // if there is a head of the queue
    {
        struct myListNode* head = q->head;
        q->head = q->head->next;
        q->size--;

        return head;

    }
    else
    {
        return NULL;
    }

}

/*
 * Add the given node at level nodeLevel to the front of the given queue.
 *
 * @param q the queue to add the node to
 * @param node the node being added to the queue
 * @param nodeLevel the level the node exists at in the tree
 */
void addToFront(struct myQueue* q, struct TreeNode* node, int nodeLevel) {

    // if given queue or node are null
    if (!q || !node)
    {
        return;
    }

    // initialize new node for queue
    struct myListNode* newNode = malloc(sizeof(struct myListNode));
    newNode->t = node;
    newNode->level = nodeLevel;

    if (!q->head) // if the queue is empty
    {

        newNode->next = NULL;

        q->head = newNode;
        q->tail = q->head;
        
    }
    else
    {

        newNode->next = q->head;
        q->head = newNode;

    }

    q->size++;

}

/*
 * Add the given node at level nodeLevel to the end of the given queue.
 *
 * @param q the queue to add the node to
 * @param node the node being added to the queue
 * @param nodeLevel the level the node exists at in the tree
 */
void addToRear(struct myQueue* q, struct TreeNode* node, int nodeLevel) {

    // if given queue or node are null
    if (!q || !node)
    {
        return;
    }

    // initialize new node for queue
    struct myListNode* newNode = malloc(sizeof(struct myListNode));
    newNode->t = node;
    newNode->next = NULL;
    newNode->level = nodeLevel;

    if (!q->head) // if the queue is empty
    {

        q->head = newNode;
        q->tail = q->head;
        
    }
    else
    { 

        q->tail->next = newNode;
        q->tail = q->tail->next;

    }

    q->size++;

}



/*
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
 * (i.e., from left to right, then right to left for the next level and alternate between).
 *
 * @param root the root node of the given binary tree
 * @param returnSize the size of the outer array of the output
 * @param returnColumnSizes the sizes of the inner arrays of the output
 *
 * @return A 2D array resulting from the zigzag level order traversal of the given binary tree.
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    int** output = malloc(10 * sizeof(int*));   // the output array (duh)
    int outputSize = 0;                         // the current size of the output array
    int outputCapacity = 10;                    // the current capacity of the output array

    *returnSize = outputSize; // initially update the return size pointer to 0

    // if the given root is null
    if (!root)
    {
        return output;
    }

    *returnColumnSizes = malloc(10 * sizeof(int)); // initialize return column sizes array

    int lastLevel = -1; // track the last level observed to use aid in knowing when to swap directions

    // initialize the queue used to perform a breadth-first traversal
    struct myQueue* traversalQueue = malloc(sizeof(struct myQueue));
    traversalQueue->head = NULL;
    traversalQueue->tail = NULL;
    traversalQueue->size = 0;

    // initialize the queue used to help organize the current tree level
    struct myQueue* levelDeque = malloc(sizeof(struct myQueue));
    levelDeque->head = NULL;
    levelDeque->tail = NULL;
    levelDeque->size = 0;

    int i = 0; // counter used to update output array and return column size array

    // add root node to both queues to start
    addToRear(traversalQueue, root, 0);
    addToRear(levelDeque, root, 0);

    // while more nodes have yet to be traversed
    while (traversalQueue->size) {

        struct myListNode* current = popQueueHead(traversalQueue); // grab the next node from the queue

        // add the left and right children of the current node to the traversal queue
        addToRear(traversalQueue, current->t->left, current->level+1);
        addToRear(traversalQueue, current->t->right, current->level+1);

        // if the current node is a deeper level than the last node examined
        if (current->level != lastLevel)
        {

            int* levelList = malloc(levelDeque->size * sizeof(int));    // initialize array for level elements
            struct myListNode* removeNode = NULL;                       // pointer used to pop elements from level deque
            int j = 0;                                                  // counter used to help populate level array

            (*returnColumnSizes)[i] = levelDeque->size; //

            // unload level deque into output array list
            while (levelDeque->head)
            {

                struct myListNode* removedNode = popQueueHead(levelDeque); // pop head from deque

                levelList[j] = removedNode->t->val; // update level array element

                free(removedNode); // free popped deque element

                j++;

            }

            levelDeque->tail = NULL; // reset deque tail to null since head is now null

            output[i] = levelList;  // update output array with current level
            outputSize++;           // update output size
            i++;
            
            // if output array is at capacity, double it's size (and the return column sizes array)
            if (outputSize == outputCapacity)
            {

                outputCapacity *= 2;
                output = realloc(output, outputCapacity * sizeof(int*));
                *returnColumnSizes = realloc(*returnColumnSizes, outputCapacity * sizeof(int));

            }

        }

        

        if ((current->level+1) % 2 == 0) // add level elements to end of deque 
        {

            addToRear(levelDeque, current->t->left, current->level+1);
            addToRear(levelDeque, current->t->right, current->level+1);

        }
        else // add level elements to front of deque
        {

            addToFront(levelDeque, current->t->left, current->level+1);
            addToFront(levelDeque, current->t->right, current->level+1);

        }

        

        lastLevel = current->level; // update last level observed

    }

    *returnSize = outputSize; // update return size

    return output;

}

int main() {

    struct TreeNode* node5 = malloc(sizeof(struct TreeNode));
    node5->val = 7;
    node5->left = NULL;
    node5->right = NULL;

    struct TreeNode* node4 = malloc(sizeof(struct TreeNode));
    node4->val = 15;
    node4->left = NULL;
    node4->right = NULL;

    struct TreeNode* node3 = malloc(sizeof(struct TreeNode));
    node3->val = 20;
    node3->left = node4;
    node3->right = node5;

    struct TreeNode* node2 = malloc(sizeof(struct TreeNode));
    node2->val = 9;
    node2->left = NULL;
    node2->right = NULL;

    struct TreeNode* node1 = malloc(sizeof(struct TreeNode));
    node1->val = 3;
    node1->left = node2;
    node1->right = node3;

    struct TreeNode* root = node1;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** output = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);



    for (int i = 0; i < returnSize; i++)
    {

        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", output[i][j]);
        }
        printf("]\n");

    }

    return 0;

}