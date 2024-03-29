#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> parents(n, -1);

        // Step 1: Check if each child has a unique parent
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                if (parents[leftChild[i]] == -1)
                    parents[leftChild[i]] = i; // Assign parent
                else
                    return false; // Duplicate parent, not a valid binary tree
            }
            if (rightChild[i] != -1)
            {
                if (parents[rightChild[i]] == -1)
                    parents[rightChild[i]] = i; // Assign parent
                else
                    return false; // Duplicate parent, not a valid binary tree
            }
        }

        // Step 2: Find the root node
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == -1)
            {
                if (root == -1)
                    root = i; // Assign root
                else
                    return false; // Multiple roots, not a valid binary tree
            }
        }
        if (root == -1)
            return false; // No root found, not a valid binary tree

        // Step 3: Detect cycles
        unordered_set<int> visited;
        queue<int> toVisit;
        toVisit.push(root);
        while (!toVisit.empty())
        {
            int node = toVisit.front();
            toVisit.pop();
            if (visited.find(node) != visited.end())
                return false; // Cycle detected, not a valid binary tree
            visited.insert(node);
            if (rightChild[node] != -1)
                toVisit.push(rightChild[node]);
            if (leftChild[node] != -1)
                toVisit.push(leftChild[node]);
        }

        // Step 4: Detect disconnected nodes
        return visited.size() == n;
    }
};

int main()
{

    Solution sl;
    int n = 4;
    vector<int> leftChild = {1, -1, 3, -1};
    vector<int> rightChild = {2, -1, -1, -1};

    cout << sl.validateBinaryTreeNodes(n, leftChild, rightChild);

    return 0;
}