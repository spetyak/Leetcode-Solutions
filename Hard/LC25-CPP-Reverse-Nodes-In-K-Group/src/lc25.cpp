#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 58.17% of C++ submissions
 * Memory: Beats 96.47% of C++ submissions
 * 
 */

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    /*
     * Create a linked list using the given array.
     *
     * @param arr the array to be converted to a linked list
     * @param arrSize the size of the given array
     * 
     * @return A linked list containing the elements of the given array
     */
    ListNode* createList(int* arr, int arrSize) {

        ListNode* head = nullptr;
        ListNode* current = nullptr;

        for (int i = 0; i < arrSize; i++)
        {

            if (head == nullptr)
            {
                head = new ListNode(arr[i]);
                current = head;
            }
            else
            {
                ListNode* newNode = new ListNode(arr[i]);
                current->next = newNode;
                current = newNode;
            }

        }

        return head;

    }

    /*
     * Delete the memory of the nodes of the given list.
     *
     * @param head the head of the given list
     */
    void cleanup(ListNode* head) {

        if (head == nullptr)
        {
            return;
        }
        else
        {
            cleanup(head->next);
            head->next = nullptr;
            head->val = 0;
        }

        delete head;

    }

    /*
     * Reverses the given portion of a linked list.
     *
     * @param tail the end of the portion to be reversed, will become start
     * @param lead the start of the portion to be revered, will become end
     * @param k the number of nodes to reverse
     * @param depth the recursive depth and how many steps back have been taken
     * 
     * @return The tail (was once front) of the reversed portion
     */
    ListNode* reverse(ListNode* tail, ListNode* lead, int k, int depth) {

        // if the end of the reverse window has been reached
        if (k == depth)
        {
            lead->next = tail; // reverse direction
        }
        else
        {
            ListNode* nextNode = reverse(tail->next, lead, k, depth+1);
            nextNode->next = tail; // reverse direction
        }

        return tail;

    }

    /*
     * Given the head of a linked list, 
     * reverses the nodes of the list k at a time, and returns the modified list. 
     * If the number of nodes is not a multiple of k, 
     * then left-out nodes should have their order unchanged.
     *
     * @param head the head of the given linked list
     * @param k the size of groups that will be reversed
     * 
     * @return The modified linked list.
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // create a dummy node to help make swapping node pointers easier
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        // swap pointers
        ListNode* current = dummyNode;
        ListNode* start = nullptr;
        ListNode* next = nullptr;

        // while there are still nodes to possibly reverse
        while (current != nullptr)
        {

            start = current; // get pointer BEFORE window being reversed

            // walk to end of window
            for (int i = 0; i < k; i++)
            {

                current = current->next;

                if (current == nullptr)
                {
                    break;
                }

            } 

            // if end of list has not been reach yet
            if (current != nullptr)
            {

                next = current->next; // get pointer AFTER window being reversed
                ListNode* nextNode = reverse(start->next, start, k-1, 0); // reverse window
                nextNode->next = next; // put new end pointer to the next pointer
                current = nextNode; // sit BEFORE next window to hold start pointer later

            }

        }

        // remove dummy node
        head = dummyNode->next;
        dummyNode->next = nullptr;
        delete dummyNode;

        return head;

    }

};

int main() {

    Solution s;

    int a1[] = {1,2,3,4,5};

    struct Solution::ListNode* list1 = s.createList(a1, 5);

    Solution::ListNode* output = s.reverseKGroup(list1, 2);

    cout << "Output:" << endl;
    Solution::ListNode* current = output;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    s.cleanup(output);

    return 0;

}
