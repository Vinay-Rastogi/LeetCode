#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};

        vector<int> res;

        function<void(Node*)> dfs = [&](Node* node) {
            for (Node* child : node->children) {
                dfs(child);
            }
            res.push_back(node->val);
        };

        dfs(root);

        return res;
    }
};

int main() {
    // Creating an example tree
    Node* child1 = new Node(5);
    Node* child2 = new Node(6);
    Node* root = new Node(3, {child1, child2});
    Node* child3 = new Node(2);
    Node* child4 = new Node(4);
    root = new Node(1, {root, child3, child4});

    // Creating an instance of Solution and calling the postorder function
    Solution sol;
    vector<int> result = sol.postorder(root);

    // Printing the postorder traversal
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Freeing the allocated memory
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete root;

    return 0;
}
