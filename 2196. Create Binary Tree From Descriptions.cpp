#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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
    TreeNode* helper(unordered_map<int,pair<int,int>>& mp, int value){
        if(mp.count(value)==0){
            TreeNode* root=new TreeNode(value);
            return root;
        }
        TreeNode* root=new TreeNode(value);
        if(mp[value].first!=-1) root->left=helper(mp,mp[value].first);
        if(mp[value].second!=-1) root->right=helper(mp,mp[value].second);

        return root;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> parent;
        unordered_map<int,pair<int,int>> mp;

        for(int i=0;i<descriptions.size();i++){
            parent[descriptions[i][1]]=descriptions[i][0];

            if(mp.count(descriptions[i][0])==0) mp[descriptions[i][0]]={-1,-1};

            if(descriptions[i][2]==1){
                mp[descriptions[i][0]].first=descriptions[i][1];
            }
            else{
                mp[descriptions[i][0]].second=descriptions[i][1];
            }
        }
        int root=0;
        for(auto i : parent){
            if(parent.count(i.second)==0){
                root=i.second;
                break;
            }
        }

        return helper(mp,root);        
    }
};

int main()
{

   

    return 0;
}