class Solution {
public:
    int minDepth(TreeNode* root) {

              
        if (root == NULL)
        return 0;
        
    else {
       
        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);
 
        
        if(root->left == NULL || root->right == NULL)
				return max(lDepth,rDepth)+1;
			
			else
                return min(lDepth,rDepth)+1;
    }
             
       return -1;      
    }
};
