#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int helper(vector<int> &cost, int idx, vector<int> &memo)
    {

        if (idx == cost.size() - 1 || idx == cost.size() - 2)
            return cost[idx];

        if (memo[idx] != -1)
            return memo[idx];

        int x = helper(cost, idx + 1, memo);
        int y = helper(cost, idx + 2, memo);

        return memo[idx] = min(x, y) + cost[idx];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {

        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        vector<int> memo(1001, -1);

        int ans1 = helper(cost, 0, memo);
        int ans2 = helper(cost, 1, memo);

        return min(ans1, ans2);
    }
};

int main()
{

    Solution sl;
    vector<int> cost = {10, 15, 20};

    cout << sl.minCostClimbingStairs(cost);

    return 0;
}