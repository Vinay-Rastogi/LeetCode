#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

        // 1.Approach : Recusrion
       // Issue : Time Limit Exceeded

    int helper(int steps,int arrLen,int pos){

            if(pos >= arrLen || pos<0)
            return 0;
            
            if(steps == 0){

                if(pos == 0)
                return 1;

                else
                return 0;
            }
            

            int left = helper(steps-1,arrLen,pos-1);
            int right = helper(steps-1,arrLen,pos+1);
            int stay = helper(steps-1,arrLen,pos);

        return (left+right+stay);    
    }

    int numWays(int steps, int arrLen) {
        
        return helper(steps,arrLen,0);
    }

        // 2.Approach : Recusrion with Memoization
       //  Issue : Memory Limit Exceeded
    int helperMemo(int steps,int arrLen,int pos,vector<vector<int>>& Memo){

            if(pos >= arrLen || pos<0)
            return 0;
            
            if(steps == 0){

                if(pos == 0)
                return 1;

                else
                return 0;
            }

            if(Memo[steps][pos] != -1)
            return Memo[steps][pos];
            

            int left = helperMemo(steps-1,arrLen,pos-1,Memo) % static_cast<int>(1e9+7);
            int right = helperMemo(steps-1,arrLen,pos+1,Memo) % static_cast<int>(1e9+7);
            int stay = helperMemo(steps-1,arrLen,pos,Memo) % static_cast<int>(1e9+7);

        return Memo[steps][pos] = ((left+right)%static_cast<int>(1e9+7)+stay)%static_cast<int>(1e9+7);    
    }
    
    int numWaysMemo(int steps, int arrLen) {
        
         vector<vector<int>> Memo(steps+1,vector<int>(arrLen,-1));

        return helperMemo(steps,arrLen,0,Memo);
    }


        // 1.Approach : Tabulation
        // Most Optimised

    int numWaysTabulation(int steps, int arrLen) {

        int m = steps;
        int n = min(steps / 2 + 1, arrLen);
        
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        dp[0][0] = 1;
        
        int mod = 1000000007; 
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < n - 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        
        return dp[m][0];
        
    }
};

int main(){

        Solution sl;
        int steps  = 3;
        int arrLen = 2;

        cout << sl.numWaysTabulation(steps,arrLen);
        
    return 0;
}

