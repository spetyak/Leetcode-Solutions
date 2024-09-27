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

        // initialize ListNode fields
        newNode->val = nums[i];
        newNode->next = NULL;

        // if there is currently no node in the list
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

    // if there is only a single element in the given list
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {

        // add dummy node to front of linked list
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

        // initialize ruler pointers
        struct ListNode* left = head;
        struct ListNode* right = head->next;

        // move right pointer so left pointer will be in correct position when right pointer 
        // is shifted (while also shifting left pointer) to end of list
        while (n != 0)
        {
            right = right->next;
            n -= 1;
        }

        // move left pointer to one node before target
        while (right != NULL)
        {
            left = left->next;
            right = right->next;
        }

        

        // remove the specified node from the list
        struct ListNode* nodeToRemove = left->next;
        left->next = left->next->next;
        free(nodeToRemove);

        // remove dummy node from front of list
        head = head->next;
        free(dummyNode);

        return head;

    }
    
}

int main() {

    int nums[] = {1};
    int numsSize = 1;
    int distFromEnd = 1;

    struct ListNode* head = createLinkedList(nums, numsSize);

    // print created list
    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    head = removeNthFromEnd(head, distFromEnd);

    // print altered list
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    cleanup(head);

    return 0;

}