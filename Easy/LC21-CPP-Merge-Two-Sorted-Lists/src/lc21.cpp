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
     * Merges two sorted lists into one sorted list.
     *
     * @param list1 the first sorted list to be merged with
     * @param list2 the second sorted list to be merged with
     *
     * @return A sorted list containing all of the values in the two given lists.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* outputList = nullptr; // the merged output list
        ListNode* tail = nullptr;    // the last element of the output list

        // attempt to walk through both lists values
        while (list1 != nullptr && list2 != nullptr)
        {

            // if the output list is currently empty
            if (outputList == nullptr)
            {

                if (list1->val < list2->val)
                {
                    outputList = new ListNode(list1->val);
                    tail = outputList;
                    list1 = list1->next;
                }
                else
                {
                    outputList = new ListNode(list2->val);
                    tail = outputList;
                    list2 = list2->next;
                }

            }
            else
            {

                if (list1->val < list2->val)
                {
                    ListNode* newNode = new ListNode(list1->val);
                    tail->next = newNode;
                    tail = newNode;
                    list1 = list1->next;
                }
                else
                {
                    ListNode* newNode = new ListNode(list2->val);
                    tail->next = newNode;
                    tail = newNode;
                    list2 = list2->next;
                }

            }
            
        }

        // if list 2 is done but there are still elements in list 1 that need merged
        while (list1 != nullptr)
        {
            ListNode* newNode = new ListNode(list1->val);
            if (outputList == nullptr)
            {
                outputList = newNode;
                tail = outputList;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
        }

        // if list 1 is done but there are still elements in list 2 that need merged
        while (list2 != nullptr)
        {
            ListNode* newNode = new ListNode(list2->val);
            if (outputList == nullptr)
            {
                outputList = newNode;
                tail = outputList;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            list2 = list2->next;
        }

        return outputList;

    }

};

int main() {

    Solution s;

    struct Solution::ListNode* list1 = nullptr;
    struct Solution::ListNode* list2 = nullptr;

    Solution::ListNode* output = s.mergeTwoLists(list1, list2);

    cout << "Output:" << endl;
    while (output != nullptr)
    {
        cout << output->val << " " << endl;
    }
    cout << endl;

    return 0;

}
