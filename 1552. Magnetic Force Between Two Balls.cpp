#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool check(int x,vector<int>& position,int m){

        int mPlaced = 1;
        int lastPos = position[0];

        for(int i=0;i<position.size();i++){

            if(position[i]-lastPos >= x){

                if(++mPlaced == m)
                return true;

                lastPos = position[i];
            }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());

        long long low = 1;
        long long high = position[position.size()-1];
        int ans = 0;

        while(high >= low){

            int mid = (high+low)/2;

            if(check(mid,position,m)){
                low = mid+1;
                ans = mid;
            }
             else
              high = mid-1;
        }
        
        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> positions = {5,4,3,2,1,1000000000};
    int m = 2;

    cout << sl.maxDistance(positions,m);

    return 0;
}