#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
         vector<int> Res;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
         int i=0;
         int j=0;
        
        while(i<nums1.size() && j<nums2.size())
        {
    
              if(nums1[i] == nums2[j])
            {
                Res.push_back(nums1[i]);
                i++;
                j++;
            }
            
            else
            { 
                 if(nums1[i] < nums2[j]){
                     i++;
                 }
                
                else{
                      j++;
                }    
            }
           
            
        }
        
        return Res;
    }
};
int main()
{

    Solution sl;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = sl.intersect(nums1,nums2);

   

    return 0;
}