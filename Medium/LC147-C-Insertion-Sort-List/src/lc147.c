
#include <stdio.h>
#include <stdlib.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 96.17% of C submissions
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
 * Given the head of a singly linked list, sorts the list using insertion sort,
 * and returns the sorted list's head.
 *
 * @param head the head of the singly linked list that is to be sorted
 * 
 * @return The sorted linked list's head.
 */
struct ListNode* insertionSortList(struct ListNode* head) {

    if (!head) // if the list is empty
    {
        return NULL;
    }
    else if (!head->next) // if there is a single element in the list
    {
        return head;
    }

    struct ListNode* current = head->next;  // the current node being removed and sorted
    struct ListNode* prev = head;           // the node BEFORE the current node being sorted

    while (current)
    {

        /*
         * Simply continue down the list if the two nodes being compared are already in order.
         */
        if (prev->val <= current->val)
        {
            current = current->next;
            prev = prev->next;
            continue;
        }

        /*
         * Remove the current node from the list and hold on to it so that you may determine
         * where in the list to put it.
         */
        struct ListNode* removedNode = current;
        prev->next = current->next;
        current = prev->next;
        removedNode->next = NULL;

        /*
         * If the removed node is less than the head of the list, make it the new head.
         * Otherwise, keep searching throught the list for a larger number.
         */
        if (removedNode->val < head->val)
        {
            removedNode->next = head;
            head = removedNode;
        }
        else
        {

            struct ListNode* current2 = head;   // start from the beginning of the list
            char placed = 0;                    // a flag noting if the not has been placed or not

            while (current2->next)
            {

                /*
                 * If the removed node is smaller than the current pointer's next node,
                 * place it between the current pointer and it's next node.
                 */
                if (removedNode->val < current2->next->val) 
                {

                    removedNode->next = current2->next;
                    current2->next = removedNode;

                    placed = 1;

                    break;

                }

                current2 = current2->next;

            }

            if (!placed) // if the node was not placed yet, add it to the end of the list
            {
                current2->next = removedNode;
            }

            

        }

        /*
         * If the previous pointer and the current pointer are not next to each other anymore
         * (meaning a node was placed between them), advance the previous pointer to continue
         * without getting stuck in a trap.
         */
        if (prev->next != current)
        {
            prev = prev->next;
        }

    }

    return head;

}

int main() {

    struct ListNode* ln1 = malloc(sizeof(struct ListNode));
    struct ListNode* ln2 = malloc(sizeof(struct ListNode));
    struct ListNode* ln3 = malloc(sizeof(struct ListNode));
    struct ListNode* ln4 = malloc(sizeof(struct ListNode));
    struct ListNode* ln5 = malloc(sizeof(struct ListNode));

    ln1->val = -1;
    ln1->next = ln2;

    ln2->val = 5;
    ln2->next = ln3;

    ln3->val = 3;
    ln3->next = ln4;

    ln4->val = 4;
    ln4->next = ln5;

    ln5->val = 0;
    ln5->next = NULL;

    struct ListNode* current = insertionSortList(ln1);
    struct ListNode* temp = NULL;

    printf("Output: [");
    while (current)
    {
        printf("%d ", current->val);
        temp = current;
        current = current->next;
        free(temp);
    }
    printf("]\n");

    return 0;

}