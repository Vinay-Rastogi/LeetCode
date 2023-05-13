class Solution {
public:

    int mod = 1e9+7;

    int helper(int length, int zero,int one,vector<int>& memo){

            if(length== 0)
            return 1;

            if(length < 0)
            return 0;

            if(memo[length] != -1)
            return memo[length];

            int case1 = helper(length-zero,zero,one,memo)%mod;
            int case2 = helper(length-one,zero,one,memo)%mod;
           

           return memo[length]=(case1+case2)%mod; 
    }

    int countGoodStrings(int low, int high, int zero, int one) {

            int ans = 0;
            vector<int> memo(high+1,-1);        

            for(int i = low;i<=high;i++)
                ans = (ans%mod + helper(i,zero,one,memo))%mod;
            
          

        return ans;        
    }
};