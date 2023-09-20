#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Sliding Window Approach
// TC - O(N)
// SC - O(1)

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size();

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int count = -1;
        int start = 0;
        int end = 0;
        int sum = 0;

        while (end < n)
        {

            sum += nums[end];

            while (sum > target)
            {
                sum -= nums[start];
                start++;
            }

            if (sum == target)
                count = max(count, end - start + 1);

            end++;
        }

        return count == -1 ? -1 : n - count;
    }
};

//  memoization approach
//  TC - O(N^2)
//  SC - O(N^2)

class Solution2
{
public:
    int helper(vector<int> &nums, int i, int j, int x, vector<vector<int>> &dp)
    {

        if (x == 0)
            return 0;

        if (i > j || x < 0)
            return 1e9;

        if (dp[i][j] != 0)
            return dp[i][j];

        int ans1 = 1 + helper(nums, i + 1, j, x - nums[i], dp);
        int ans2 = 1 + helper(nums, i, j - 1, x - nums[j], dp);

        return dp[i][j] = min(ans1, ans2);
    }

    int minOperations(vector<int> &nums, int x)
    {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

        int ans = helper(nums, 0, nums.size() - 1, x, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;

    cout << sl.minOperations(nums, x);

    return 0;
}