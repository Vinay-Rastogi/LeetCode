#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<int> arr;
    void inOrder(TreeNode *root)
    {
        vector<TreeNode *> stack;
        TreeNode *node = root;
        while (node || !stack.empty())
        {
            while (node)
            {
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();

            arr.push_back(node->val);

            node = node->right;
        }
    }

    TreeNode *insertNode(int l, int r)
    {

        if (l > r)
            return NULL;

        int m = l + (r - l) / 2;

        TreeNode *left = (l > m - 1) ? NULL : insertNode(l, m - 1);
        TreeNode *right = (m + 1 > r) ? NULL : insertNode(m + 1, r);

        return new TreeNode(arr[m], left, right);
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {

        inOrder(root);

        return insertNode(0, arr.size() - 1);
    }
};