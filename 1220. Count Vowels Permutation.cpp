#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int mod = 1000000007;

    int helper(int prev, int len, int n, vector<vector<int>> &dp)
    {

        if (len == n)
            return 1;

        if (dp[len][prev] != -1)
            return dp[len][prev];

        int ans = 0;

        for (int i = 1; i <= 5; i++)
        {

            if (prev == 1 && i == 2)
                ans = (ans % mod + helper(i, len + 1, n, dp) % mod) % mod;

            else if (prev == 2 && (i == 1 || i == 3))
                ans = (ans % mod + helper(i, len + 1, n, dp) % mod) % mod;

            else if (prev == 3 && (i != 3))
                ans = (ans % mod + helper(i, len + 1, n, dp) % mod) % mod;

            else if (prev == 4 && (i == 3 || i == 5))
                ans = (ans % mod + helper(i, len + 1, n, dp) % mod) % mod;

            else if (prev == 5 && i == 1)
                ans = (ans % mod + helper(i, len + 1, n, dp) % mod) % mod;
        }

        return dp[len][prev] = ans % mod;
    }

    int countVowelPermutation(int n)
    {

        vector<vector<int>> dp(n + 1, vector<int>(6, -1));
        int ans = 0;

        for (int i = 1; i <= 5; i++)
            ans = (ans % mod + helper(i, 1, n, dp) % mod) % mod;

        return ans % mod;
    }
};

int main()
{

    Solution sl;
    int n = 2;

    cout << sl.countVowelPermutation(n);

    return 0;
}