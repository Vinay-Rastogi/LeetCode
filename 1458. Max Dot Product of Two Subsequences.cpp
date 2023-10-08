#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {

        if (i == nums1.size() || j == nums2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeBoth = (nums1[i] * nums2[j]) + solve(i + 1, j + 1, nums1, nums2);
        int take1 = solve(i, j + 1, nums1, nums2);
        int take2 = solve(i + 1, j, nums1, nums2);
        int takeNone = solve(i + 1, j + 1, nums1, nums2);

        return dp[i][j] = max(max(takeBoth, takeNone), max(take1, take2));
    }

    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int num : nums1)
        {

            max1 = max(max1, num);
            min1 = min(min1, num);
        }

        for (int num : nums2)
        {

            max2 = max(max2, num);
            min2 = min(min2, num);
        }

        if (max1 < 0 && min2 > 0)
            return max1 * min2;

        if (min1 > 0 && max2 < 0)
            return min1 * max2;

        dp = vector<vector<int>>(nums1.size(), vector<int>(nums2.size(), -1));

        return solve(0, 0, nums1, nums2);
    }
};

int main()
{

    Solution sl;
    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    cout << sl.maxDotProduct(nums1, nums2);

    return 0;
}