#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int start = 0;
        double sum = 0;

        for(auto it:customers){
            int a = it[0];
            int t = it[1];

            start = max(start,a) + t;
            sum += start-a;
        }

       
        return sum/customers.size();
    }
};

int main()
{

    Solution sl;
    vector<vector<int>> customers = {{1,2},{2,5},{4,3}}; 
  
    cout << sl.averageWaitingTime(customers);
    
    return 0;
}