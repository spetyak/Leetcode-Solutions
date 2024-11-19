#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 88.85% of C submissions
 * Memory: Beats 14.58% of C submissions
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct Heap {
    int size;
    struct ListNode** data;
};

struct ListNode* createLinkedList(int*, int);
void cleanup(struct ListNode*);
void swap(struct ListNode**, struct ListNode**);
void heapify(struct Heap*, int);
void heapInsert(struct Heap*, struct ListNode*);
int extractMin(struct Heap*);
struct ListNode* mergeKLists(struct ListNode**, int);

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
 * Swap the two given list nodes.
 *
 * @param l1 the first list node to be swapped
 * @param l2 the second list node to be swapped
 */
void swap(struct ListNode** l1, struct ListNode** l2) {

    struct ListNode* temp = *l1;
    *l1 = *l2;
    *l2 = temp;

}

/*
 * Rearrange the binary tree to maintain the minHeap structure.
 *
 * @param heap the altered minHeap that needs to be corrected
 * @param i the node currently being examined
 */
void heapify(struct Heap* heap, int i) {

    // parent = arr[i]
    // left child of parent = arr[(2 * i) + 1]
    // right child of parent = arr[(2 * i) + 2]
    // parent of child = (i - 1) / 2

    int min = i;                // the current node being examined
    int left = (2 * i) + 1;     // the current node's left child
    int right = (2 * i) + 2;    // the current node's right child

    // if the current node's left child is less than the current node
    if (left < heap->size && heap->data[left]->val < heap->data[min]->val)
    {
        min = left;
    }
    
    // if the current node's right child is less than the current node
    if (right < heap->size && heap->data[right]->val < heap->data[min]->val)
    {
        min = right;
    }

    // if either of the current node's children are less than the current node
    if (min != i)
    {
        swap(&(heap->data[i]), &(heap->data[min]));
        heapify(heap, min);
    }

}

/*
 * Insert the given node into the minHeap.
 *
 * @param heap the minHeap being added to
 * @param node the node being added to the minHeap
 */
void heapInsert(struct Heap* heap, struct ListNode* node) {

    int currentPos = heap->size; // the position of the node being added at the bottom of the heap

    heap->data[currentPos] = node; // add node to heap
    heap->size++; // increase size of heap

    // while the current node's value being examined is less than it's parent's value
    while (currentPos > 0 && heap->data[currentPos]->val < heap->data[(currentPos-1)/2]->val)
    {
        swap(&(heap->data[currentPos]), &(heap->data[(currentPos-1)/2])); // swap
        currentPos = (currentPos - 1) / 2; // move to parent
    }

}

/*
 * Remove the mimimum value from the minHeap.
 *
 * @param heap the minHeap from which the minimum value is being extracted
 * 
 * @return The minimum value in the heap
 */
int extractMin(struct Heap* heap) {

    // get the minimum value from the heap of lists
    int min = heap->data[0]->val;

    // move to next value in the list
    heap->data[0] = heap->data[0]->next;

    if (heap->data[0] == NULL)
    {
        // remove node from heap
        heap->data[0] = heap->data[heap->size-1];
        heap->size--;
    }
    
    // ensure min heap is correctly ordered
    heapify(heap, 0);

    return min;

}

/*
 * Given an array of k sorted linked-lists, 
 * merge all the linked-lists into one sorted linked-list.
 *
 * @param lists the sorted linked-lists to be merged together
 * @param listsSize the number of linked-lists to be merged
 * 
 * @return A single linked-list containing the values from all the given linked-lists
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    // if there are no lists being merged
    if (listsSize == 0)
    {
        return NULL;
    }

    struct ListNode* outputList = NULL; // the merged list of all other list elements
    struct ListNode* current = NULL;    // the current node being added to the output list

    // create min heap
    struct Heap* minHeap = malloc(sizeof(struct Heap));
    minHeap->size = 0;
    minHeap->data = malloc((listsSize) * sizeof(struct ListNode*));
    if (!(minHeap->data))
    {
        printf("Failed to allocated heap data array!\n");
        exit(-1);
    }

    for (int i = 0; i < listsSize; i++)
    {
        if (lists[i] != NULL)
        {
            heapInsert(minHeap, lists[i]); // add list heads to heap based of head->val value
        }
    }

    // while the min heap is not empty
    while (minHeap->size != 0)
    {

        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        if (!newNode)
        {
            printf("Unable to allocate new output list node!\n");
            exit(-1);
        }

        // extract the minimum value from the heap of lists and assign it to a new output list node
        newNode->next = NULL;
        newNode->val = extractMin(minHeap);

        if (outputList == NULL)
        {
            outputList = newNode;
            current = outputList;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }

    }
    
    free(minHeap->data);
    free(minHeap);

    return outputList;
    
}

int main() {

    int nums1[] = {1,4,5};
    int nums1Size = 3;
    int nums2[] = {1,3,4};
    int nums2Size = 3;
    int nums3[] = {2,6};
    int nums3Size = 2;

    struct ListNode* list1 = createLinkedList(nums1, nums1Size);
    struct ListNode* list2 = createLinkedList(nums2, nums2Size);
    struct ListNode* list3 = createLinkedList(nums3, nums3Size);

    int listsSize = 3;

    struct ListNode** lists = malloc(listsSize * sizeof(struct ListNode*));
    if (!lists)
    {
        printf("Unable to allocate input lists!\n");
        exit(-1);
    }
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;

    for (int i = 0; i < listsSize; i++)
    {
        printf("List %d: ", i);
        struct ListNode* current = lists[i];
        while (current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }

    // CALL FUNCTION
    struct ListNode* output = mergeKLists(lists, listsSize);
    struct ListNode* current = output;

    // print merged list
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    for (int i = 0; i < listsSize; i++)
    {
        cleanup(lists[i]);
    }
    free(lists);

    return 0;

}