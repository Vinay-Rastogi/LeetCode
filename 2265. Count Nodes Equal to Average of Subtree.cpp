#include <iostream>
#include <bits/stdc++.h>

using namespace std ; 

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

    pair<int,int> sumOfSubtrees(TreeNode* root,int& ans){

        if(root == NULL)
        return {0,0};

        pair<int,int> lSubTree = sumOfSubtrees(root->left,ans);
        pair<int,int> rSubTree = sumOfSubtrees(root->right,ans);

        int totalSum = lSubTree.first + rSubTree.first + root->val;
        int totalNodes = lSubTree.second + rSubTree.second + 1;

        int avg = totalSum/totalNodes;


        if(totalNodes && avg == root->val)
         ans++ ;

        return {totalSum,totalNodes};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;
        sumOfSubtrees(root,ans);
        
        return ans;
    }
};
