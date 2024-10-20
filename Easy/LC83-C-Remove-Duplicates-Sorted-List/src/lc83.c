#include <stdlib.h>
#include <stdio.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 38.23% of C submissions
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createLinkedList(int*, int);
void cleanup(struct ListNode*);

/*
 * Convert an array into a linked list.
 *
 * @param nums the array to be transformed into a linked list
 * @param numsSize the size of the given array
 * 
 * @return a linked list created using the values of the given array
 */
struct ListNode* createLinkedList(int* nums, int numsSize) {

    struct ListNode* head = NULL;
    struct ListNode* current = NULL;

    for (int i = 0; i < numsSize; i++)
    {

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        if (!newNode)
        {
            printf("Unable to allocate new node!\n");
            cleanup(head);
            exit(-1);
        }

        newNode->val = nums[i];
        newNode->next = NULL;

        if (!head)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }

    }

    return head;

}

/*
 * Free linked list nodes.
 *
 * @param head the head of the linked list
 */
void cleanup(struct ListNode* head) {

    if (!head)
    {
        return;
    }

    if (head->next != NULL)
    {
        cleanup(head->next);
        head->next = NULL;
    }

    free(head);

}

/*
 * Given the head of a sorted linked list, 
 * deletes all duplicates such that each element only appears once. 
 * The returned list should still be in sorted order.
 *
 * @param head the head of the sorted linked list to remove duplicates from
 * 
 * @return the head of the sorted linked list with duplicate elements removed
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    if (!head)
    {
        return head;
    }
    else if (!head->next)
    {
        return head;
    }

    // walk linked list
    struct ListNode* current = head;
    while (current->next)
    {

        if (current->val == current->next->val) // if the current and next value match
        {
            // remove next value
            struct ListNode* removedNode = current->next;
            current->next = current->next->next;
            free(removedNode);
        }
        else // advance
        {
            current = current->next;
        }

    }

    return head;

}

int main() {

    int nums[] = {1,1,2,3,3};
    int numsSize = 5;
    
    struct ListNode* head = createLinkedList(nums, numsSize);

    head = deleteDuplicates(head);

    struct ListNode* current = head;
    printf("Output: ");
    while (current)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    cleanup(head);

    return 0;

}