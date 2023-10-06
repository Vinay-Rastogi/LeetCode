#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dp[60];

    int helper(int n)
    {

        if (n <= 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int res = INT_MIN;

        for (int i = 1; i < n; i++)
        {

            res = max(res, max(i * helper(n - i), i * (n - i)));
        }

        return dp[n] = res;
    }

    int integerBreak(int n)
    {

        memset(dp, -1, sizeof(dp));

        return helper(n);
    }
};

int main()
{

    Solution sl;
    int n = 10;

    cout << sl.integerBreak(n);

    return 0;
}