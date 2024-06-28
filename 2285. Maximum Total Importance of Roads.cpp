#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int> inDegree(n,0);
        vector<pair<int,int>> imp;
        unordered_map<int,int> mp;

        for(vector<int> road:roads){
            inDegree[road[0]]++;
            inDegree[road[1]]++;
        }

        for(int i=0;i<n;i++)
            imp.push_back({inDegree[i],i});
        
        sort(imp.begin(),imp.end());


          for(int i=0;i<n;i++)
            mp[imp[i].second] = i+1;    


           long long ans = 0;

           for(vector<int> road:roads)
            ans += 1LL*mp[road[0]] + 1LL*mp[road[1]];
           

        return ans; 
    }

    long long betterApproach(int n, vector<vector<int>>& roads) {
       

        vector<long long> deg(n, 0);
        for (auto &a : roads) {
            deg[a[0]]++;
            deg[a[1]]++;
        }
        sort(deg.begin(), deg.end());
        long long ans = 0;
        for (long long i=0;i<n;i++) {
            ans += ( (i+1)*deg[i] );
        }
        return ans;
    }
};

int main(){

        Solution sl;
        vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
        int n = 5;
        long long ans = sl.maximumImportance(n,roads);

        cout << ans << endl;
        
    return 0;
}