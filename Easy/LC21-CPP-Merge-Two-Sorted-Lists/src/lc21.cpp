#include <iostream>
#include <vector>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 57.79% of C++ submissions
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
     * Merges two sorted lists into one sorted list.
     *
     * @param list1 the first sorted list to be merged with
     * @param list2 the second sorted list to be merged with
     *
     * @return A sorted list containing all of the values in the two given lists.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) // if list 1 is empty
        {
            return list2;
        }

        if (list2 == nullptr) // if list 2 is empty
        {
            return list1;
        }
        
        ListNode* outputList = nullptr; // the merged output list
        ListNode* current = outputList;  // the current element pointed to in the output list

        // while neither of the lists are empty
        while (list1 != nullptr and list2 != nullptr)
        {

            ListNode* movedNode = nullptr; // the node being moved from one of the original lists

            if (list1->val < list2->val)
            {
                movedNode = list1;
                list1 = list1->next;
            }
            else
            {
                movedNode = list2;
                list2 = list2->next;
            }

            if (outputList == nullptr) // output list has no head yet
            {
                outputList = movedNode;
                current = outputList;
            }
            else
            {
                movedNode->next = nullptr;
                current->next = movedNode;
                current = current->next;
            }

        }

        if (list1 != nullptr) // add rest of list 1 to output
        {
            current->next = list1;
        }

        if (list2 != nullptr) // add rest of list 2 to output
        {
            current->next = list2;
        }

        return outputList;

    }

};

int main() {

    Solution s;

    int a1[] = {1,2,4};
    int a2[] = {1,3,4};

    struct Solution::ListNode* list1 = s.createList(a1, 3);
    struct Solution::ListNode* list2 = s.createList(a2, 3);

    Solution::ListNode* output = s.mergeTwoLists(list1, list2);

    cout << "Output:" << endl;
    Solution::ListNode* current = output;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    s.cleanup(list1);
    s.cleanup(list2);
    s.cleanup(output);

    return 0;

}
