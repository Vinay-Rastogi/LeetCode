#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> help(TreeNode* root, vector<int> &v) {
        if (root == nullptr) {
            return v;
        }
        help(root->left, v);
        help(root->right, v);
        v.push_back(root->val);
        return v;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> Res;
        return help(root, Res);
    }
};

int main() {
    // Constructing a sample tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    Solution sol;
    vector<int> result = sol.postorderTraversal(root);
    
    // Print the postorder traversal result
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // Cleaning up the dynamically allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
