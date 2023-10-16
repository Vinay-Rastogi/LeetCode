#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
           vector<int> p, prev;
        
        prev.push_back(1);
        
        if(rowIndex == 0)
            return prev;
   
    
        
        for(int i = 1; i <= rowIndex; i++)
        {
            int n = i - 1;
            
            int sum = 0;
            p.push_back(1);
            
            for(int j = 0;  j <= n-1; j++)
            {
                sum = 0;
                sum += prev[j] + prev[j+1];
                p.push_back(sum);
            }
            
            p.push_back(1);
            prev = p;
            
            if(i != rowIndex)
                p.clear();
            
        }
          
        
        return p;
    }
};

int main(){

        Solution sl;
        int rowIndex = 3;
        vector<int> res = sl.getRow(rowIndex);


    return 0;
}