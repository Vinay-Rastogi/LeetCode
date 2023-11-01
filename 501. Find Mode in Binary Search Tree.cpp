#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {

    vector<int> result;
    int maxFreq = 0;

    void helper(TreeNode* cur, int & curval, int & reps) 
    {
        if (cur == NULL)
            return;

        helper(cur->left, curval, reps);

        if (cur->val == curval)
            reps ++;

        else{
            if (reps > maxFreq)
            {
                result.clear();
                result.push_back(curval);
                maxFreq = reps;
            }else if (reps > 0 && reps == maxFreq)
                result.push_back(curval);
            curval = cur->val, reps = 1;
        }
        helper(cur->right, curval, reps);
    }

public:
    vector<int> findMode(TreeNode* root) {
        int curval = 0, reps = 0;
        helper(root, curval, reps);
        if (reps > maxFreq)
        {
            result.clear();
            result.push_back(curval);
            maxFreq = reps;
        }
        else if (reps > 0 && reps == maxFreq)
            result.push_back(curval);

        return result;
    }
};