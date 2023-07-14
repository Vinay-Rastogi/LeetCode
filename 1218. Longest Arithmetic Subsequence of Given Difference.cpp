// Recursive Code (Time Limit Exceeded)

class Solution
{
public:
    int helper(int idx, vector<int> &arr, int diff, int prev)
    {

        if (idx >= arr.size())
            return 0;

        int include = 0;
        int exclude = 0;

        if (prev == -10000)
        {

            include = 1 + helper(idx + 1, arr, diff, arr[idx]);
            exclude = helper(idx + 1, arr, diff, prev);
        }

        else
        {

            if (arr[idx] == prev + diff)
                include = 1 + helper(idx + 1, arr, diff, arr[idx]);

            exclude = helper(idx + 1, arr, diff, prev);
        }

        return max(include, exclude);
    }

    int longestSubsequence(vector<int> &arr, int difference)
    {

        return helper(0, arr, difference, -10000);
    }
};

// Memoization (Memory limit Exceeded)

class Solution
{
public:
    int helper(int idx, vector<int> &arr, int diff, int prev, vector<vector<int>> &dp)
    {

        if (idx >= arr.size())
            return 0;

        if (dp[idx][prev + 10000] != -1)
            return dp[idx][prev + 10000];

        int include = 0;
        int exclude = 0;

        if (prev == -10000)
        {

            include = 1 + helper(idx + 1, arr, diff, arr[idx], dp);
            exclude = helper(idx + 1, arr, diff, prev, dp);
        }

        else
        {

            if (arr[idx] == prev + diff)
                include = 1 + helper(idx + 1, arr, diff, arr[idx], dp);

            exclude = helper(idx + 1, arr, diff, prev, dp);
        }

        return dp[idx][prev + 10000] = max(include, exclude);
    }

    int longestSubsequence(vector<int> &arr, int difference)
    {

        vector<vector<int>> dp(arr.size(), vector<int>(20001, -1));

        return helper(0, arr, difference, -10000, dp);
    }
};

// Tabulation

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
        unordered_map<int, int> dp; // Stores the maximum length at each index

        int ans = 1; // Initialize with the minimum length of 1

        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end())
            {
                dp[num] = dp[num - difference] + 1;
            }
            else
            {
                dp[num] = 1;
            }

            ans = max(ans, dp[num]);
        }

        return ans;
    }
};