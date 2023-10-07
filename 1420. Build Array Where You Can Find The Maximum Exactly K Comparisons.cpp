#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    long dp[51][101][101];

    int solve(int prev, int k, int n, int m)
    {
        if (n == 0 && k == 0)
            return 1;
        if (k < 0 || n < 0)
            return 0;
        if (dp[n][k][prev] != -1)
            return dp[n][k][prev];
        long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (i > prev)
                ans += solve(i, k - 1, n - 1, m) % mod;
            else
                ans += solve(prev, k, n - 1, m) % mod;
        }
        return dp[n][k][prev] = ans % mod;
    }

    int numOfArrays(int n, int m, int k)
    {
        if (k > m)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, k, n, m);
    }
};

int main()
{

    Solution sl;
    int n = 2;
    int m = 3;
    int k = 1;

    cout << sl.numOfArrays(n, m, k);

    return 0;
}