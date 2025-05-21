
#include <stdio.h>
#include <stdlib.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 5.49% of C submissions
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct stackNode {
    struct ListNode* node;
    struct stackNode* next;
};

/*
 * Pushes the given listNode node onto the given stack structure.
 *
 * @param top a pointer to the top element of the given stack
 * @param listNode the listNode element to be added to the stack
 */
void pushToStack(struct stackNode** top, struct ListNode* listNode) {

    struct stackNode* newNode = malloc(sizeof(struct stackNode));
    newNode->node = listNode;
    newNode->next = NULL;

    if (!(*top)) // if the stack is empty
    {
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }

}

/*
 * Pops the top element from the given stack and returns it.
 *
 * @param top a pointer to the top element of the given stack
 * 
 * @return The top stack listNode node.
 */
struct ListNode* popFromStack(struct stackNode** top) {

    if (!(*top)) // if the stack is empty
    {
        return NULL;
    }
    else
    {

        struct stackNode* oldTop = *top;            // grab the current top stack element
        struct ListNode* poppedNode = oldTop->node; // grab the listNode from that stack element
        *top = (*top)->next;                        // update the stack top pointer
        free(oldTop);                               // free the popped stack node
        return poppedNode;

    }

}

/*
 * Given the head of a singly linked-list, reorders the nodes such that they are
 * in the following order:
 * 
 * L[0] -> L[n] -> L[1] -> L[n-1] -> L[2] -> L[n-2] -> ... 
 *
 * @param head the head of the singly linked-list
 */
void reorderList(struct ListNode* head) {

    if (!head)
    {
        return;
    }
    else if (!head->next)
    {
        return;
    }


    /*
     * Determine where the list divides in half (or the first node on the right half if there are
     * an even number of nodes). 
     * When the fast pointer reaches the end of the list the slow pointer will have found the 
     * dividing node.
     */
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* current = slow;

    /*
     * Add the latter half of the list to a stack.
     */
    struct stackNode* stack = NULL;

    while (current && current->next)
    {
        struct ListNode* removedNode = current->next;
        pushToStack(&stack, removedNode);
        current->next = current->next->next;
    }

    current = head;

    while (stack)
    {

        struct ListNode* poppedNode = popFromStack(&stack);

        // place popped node between first-half nodes
        poppedNode->next = current->next;
        current->next = poppedNode;
        current = current->next->next;

    }
    
}

int main() {

    // I don't feel like going through the trouble of making the test cases right now.
    // It passed all the test cases on LeetCode so test it ya self ya filthy animals.

    return 0;

}