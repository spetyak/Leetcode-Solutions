#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 39.50% of C submissions
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createLinkedList(int*, int);
void cleanup(struct ListNode*);
struct ListNode* removeNthFromEnd(struct ListNode*, int);

/*
 * Convert an array into a linked list.
 *
 * @param nums the array to be transformed into a list
 * @param numsSize the size of the given array
 * 
 * @return a linked list created using the values in the given array
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

        if (head == NULL)
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

    if (head == NULL)
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
 * Given the head of a linked list, removes the nth node from the end of the list and return its head.
 *
 * @param head the head of the linked list
 * @param n the distance of the node to be removed from the end (1 is last element in list)
 * 
 * @return a linked list with the specified node removed
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {

        struct ListNode* dummyNode = malloc(sizeof(struct ListNode));
        if (!dummyNode)
        {
            printf("Unable to allocate dummyNode!\n");
            cleanup(head);
            exit(-1);
        }

        dummyNode->next = head;
        dummyNode->val = -1;
        head = dummyNode;

        struct ListNode* left = head;
        struct ListNode* right = head->next;

        while (n != 0)
        {
            right = right->next;
            n -= 1;
        }

        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }

        

        struct ListNode* nodeToRemove = left->next;
        left->next = left->next->next;

        free(nodeToRemove);
        head = head->next;
        free(dummyNode);

        return head;

    }
    
}

int main() {

    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = 5;
    int distFromEnd = 5;

    struct ListNode* head = createLinkedList(nums, numsSize);

    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    head = removeNthFromEnd(head, distFromEnd);

    

    current = head;
    printf("Out here: %d\n", current->val);
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    cleanup(head);

    return 0;

}