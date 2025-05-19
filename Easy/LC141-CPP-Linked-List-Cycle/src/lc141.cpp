#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 81.37% of C++ submissions
 * Memory: Beats 79.78% of C++ submissions
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    /*
     * Given the head of a singly linked list, determines if the linked list has a cycle in it.
     *
     * @param head the head of the singly linked list
     * 
     * @return True if there is a cycle in the linked list, False if there is not.
     */
    bool hasCycle(ListNode* head) {

        /*
         * Initialize two pointers to the head of the linked list. 
         * One pointer, slow, will move one node at a time while the other pointer, 
         * fast, will move two at a time. 
         * If the two pointers end up pointing at the same node there must be a cycle in the list.
         */
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;          // take a step forward
            fast = fast->next->next;    // take two steps forward

            if (slow == fast) // if both pointers are pointing at the same node, there is a cycle
            {
                return true;
            }

        }

        return false;
        
    }

};

int main() {

    Solution s;

    ListNode* ln0 = new ListNode(3);
    ListNode* ln1 = new ListNode(2);
    ListNode* ln2 = new ListNode(0);
    ListNode* ln3 = new ListNode(-4);

    ln0->next = ln1;
    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln1;

    bool output = s.hasCycle(ln0);

    if (output)
    {
        cout << "Output: TRUE" << endl;
    }
    else
    {
        cout << "Output: FALSE" << endl;
    }

    return 0;

}