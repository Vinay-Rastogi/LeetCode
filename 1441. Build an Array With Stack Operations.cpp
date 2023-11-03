#include <iostream>
#include <bits/stdc++.h>

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> st;
        int num = 1;

        for(int i=0;i<target.size();i++){

             while(num < target[i]){
                 st.push_back("Push");
                 st.push_back("Pop");
                 num++;
             }

             if(num == target[i]){
                st.push_back("Push");
                num++;
             }
             
        }

        return st;
    }
};

using namespace std ; 

int main() {

             Solution sl;
             int n = 4;
             vector<int> target = {1,2};
             vector<string> res = sl.buildArray(target,n);

    return 0;
}