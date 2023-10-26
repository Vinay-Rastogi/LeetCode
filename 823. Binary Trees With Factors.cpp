#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;

    int numFactoredBinaryTrees(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        long totalTrees = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1;

            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int factor = arr[i] / arr[j];
                    if (dp.count(factor))
                    {
                        dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[factor]) % MOD) % MOD;
                    }
                }
            }

            totalTrees = (totalTrees + dp[arr[i]]) % MOD;
        }

        return totalTrees;
    }
};

int main()
{

    Solution sl;
    vector<int> arr = {2, 4};

    cout << sl.numFactoredBinaryTrees(arr);

    return 0;
}