#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 99.43% of C++ submissions
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
     * Free linked list nodes.
     *
     * @param head the head of the linked list
     */
    void cleanup(ListNode* head) {

        if (!head) // head is null
        {
            return;
        }

        if (head->next) // if there is something following this node
        {
            cleanup(head->next);
            head->next = nullptr;
        }
        
        delete[] head; // delete head pointer memory

    }

    /*
     * Convert a vector into a linked list.
     *
     * @param nums the vector to be transformed into a linked list
     * 
     * @return a linked list created using the values in the given vector
     */
    ListNode* createLinkedList(vector<int>& nums) {

        ListNode* head = nullptr;
        ListNode* current = nullptr;

        for (int i = 0; i < nums.size(); i++)
        {

            ListNode* newNode = new ListNode();
            if (!newNode)
            {
                printf("Unable to allocate new node!\n");
                cleanup(head);
                exit(-1);
            }

            // initialize ListNode fields
            newNode->val = nums.at(i);
            newNode->next = nullptr;

            if (!head) // if there is currently no node in the list
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
     * Given the head of a linked list, rotates the list to the right by k places.
     *
     * @param head the head of the given linked list
     * @param k the number of times the list should be rotated right
     * 
     * @return The head of the rotated list
     */
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next)
        {
            return head;
        }

        // get size of list
        int size = 0;
        ListNode* current = head;
        while (current->next)
        {
            size++;
            current = current->next;
        }
        size++;

        k %= size; // determine how many rotations would actually need to be done

        if (k == 0) // if the rotation would result in the list being unchanged
        {
            return head;
        }
        else
        {
            
            current->next = head; // loop end of list to make shifting easier

            // move to the node before what will be the new head
            current = head;
            k = size - k - 1;
            while (k > 0)
            {
                current = current->next;
                k--;
            }

            head = current->next;       // update head pointer
            current->next = nullptr;    // break loop and make current pointer tail

            return head;

        }
        
    }

};

int main() {

    Solution s;

    // v {1,2,3,4,5} k = 7
    // v {0, 1, 2} k = 4
    // v {1, 2} k = 1
    vector<int> v {1,2,3,4,5};
    int k = 3;

    Solution::ListNode* head = s.createLinkedList(v);

    head = s.rotateRight(head, k);

    Solution::ListNode* current = head;
    cout << "Output:" << endl;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    s.cleanup(head);

    return 0;

}