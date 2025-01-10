#include <iostream>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 98.89% of C++ submissions
 * Memory: Beats 79.79% of C++ submissions
 */

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next) : val(x), left(left), right(right), next(next) {}
};

class Solution {
public:

    /*
     * Given a binary tree, populates each node's next pointer to its next right node.
     * If there is no next right node, the next pointer should be set to NULL.
     * Initially, all next pointers are set to NULL.
     *
     * @param root the root of the given binary tree
     * 
     * @return A binary tree with level/row nodes connected in a linked list fashion.
     */
    Node* connect(Node* root) {

        // base case
        if (root == nullptr)
        {
            return root;
        }

        Node* currRowHead = root;       // initialize pointer to current row head
        Node* nextRowHead = nullptr;    // initialize pointer that will point to next rows head

        // iterate through each level/row of the tree
        while (currRowHead != nullptr)
        {

            Node* curr = currRowHead;
            Node* hold = nullptr;       // pointer used to help bridge gaps between level nodes

            // iterate through nodes in level/row
            while (curr != nullptr)
            {

                // if the head of the next row has not been found yet
                if (nextRowHead == nullptr)
                {

                    if (curr->left)
                    {
                        nextRowHead = curr->left;
                    }
                    else if (curr->right)
                    {
                        nextRowHead = curr->right;
                    }
                    
                }



                // if there is a node that needs help bridging the gap between itself 
                // and the next node in that level
                if (hold)
                {

                    if (curr->left)
                    {
                        hold->next = curr->left;
                        hold = curr->left;
                    }
                    else if (curr->right)
                    {
                        hold->next = curr->right;
                        hold = curr->right;
                    }

                }

                if (curr->left and curr->right)
                {
                    curr->left->next = curr->right;
                    hold = curr->right;
                }
                else if (curr->left)
                {
                    hold = curr->left;
                }
                else if (curr->right)
                {
                    hold = curr->right;
                }

                curr = curr->next; // advance pointer in level/row

            }

            currRowHead = nextRowHead;  // advance to next level/row
            nextRowHead = nullptr;      // reset row head pointer to find new one
            hold = nullptr;             // reset hold pointer to avoid connecting different rows

        }

        return root;

    }

};

int main() {

    Solution s;

    Node* root = new Node(1, new Node(2, new Node(4), new Node(5), nullptr), new Node(3, nullptr, new Node(7), nullptr), nullptr);

    root = s.connect(root);

    // searching for row heads could be kinda annoying so may come back to make it print later 
    // but it is accepted on LeetCode so :D

    return 0;

}