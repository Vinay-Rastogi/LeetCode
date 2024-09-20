#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        string copy=s;
        string ref=s;
        reverse(copy.begin(),copy.end());
        string ans="";
        while(s.size()>0){
            if(s==copy){
                break;
            }else{
                ans+=copy[0];
                s.pop_back();
                copy.erase(0,1);
            }
        }
        string res=ans+ref;
        return res;
    }
};


int main()
{
                Solution sl;
                string s = "aacecaaa";

                cout << sl.shortestPalindrome(s);



     return 0;
}