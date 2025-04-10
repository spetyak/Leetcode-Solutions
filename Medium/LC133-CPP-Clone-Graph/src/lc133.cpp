#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C++ submissions
 * Memory: Beats 89.08% of C++ submissions
 */

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    /*
     * Given a reference of a node in a connected undirected graph, 
     * returns a deep copy (clone) of the graph.
     *
     * @param node the given starting node for the given graph
     * 
     * @return A deep copy (clone) of the given graph.
     */
    Node* cloneGraph(Node* node) {

        unordered_map<Node*, Node*> origToCopyMap;  // map of original graph nodes to copy nodes
        unordered_map<Node*, int> visited;          // map of visited nodes
        queue<Node*> nodeQueue;                     // queue of nodes used to perform a BFT

        if (node == nullptr) // if there is no graph to clone
        {
            return node;
        }

        Node* copyOrig = new Node(node->val);   // make a copy of the given node

        origToCopyMap.insert({node, copyOrig}); // map the original to the copy in the map
        visited.insert({node, 1});              // mark the given node as visited
        nodeQueue.push(node);                   // push the node to the queue to begin BFT

        while (!nodeQueue.empty())
        {

            // remove the first node from the queue
            Node* popped = nodeQueue.front();
            nodeQueue.pop();

            Node* copyPopped = origToCopyMap.at(popped); // make a copy of the popped node

            vector<Node*> copyNeighbors; // a list of neighbors (copies of them) of the popped node

            // iterate through the popped node's neighbors
            for (int i = 0; i < popped->neighbors.size(); i++)
            {

                Node* currentNeighbor = popped->neighbors.at(i);

                if (visited.contains(currentNeighbor)) // if neighbor was visited, just add to list
                {

                    copyNeighbors.push_back(origToCopyMap.at(currentNeighbor));

                }
                else 
                {

                    Node* copyCurrent = new Node(currentNeighbor->val); // make a copy

                    origToCopyMap.insert({currentNeighbor, copyCurrent});   // map original to copy
                    visited.insert({currentNeighbor, 1});                   // mark node as visited

                    copyNeighbors.push_back(copyCurrent); // add copy of the neighbor to the list

                    nodeQueue.push(currentNeighbor); // push the original neighbor to the queue

                }

            }

            copyPopped->neighbors = copyNeighbors; // update popped copy's neighbors

        }



        return copyOrig;

    }

};

int main() {

    Solution s;

    // I don't feel like writing the code necessary to demonstrate this, just put it in leetcode.
    // It works.

    return 0;

}
