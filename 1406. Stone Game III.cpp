class Solution
{
public:
    int helper(vector<int> &stoneValue, int i, vector<int> &dp)
    {

        if (i >= stoneValue.size())
            return 0;

        if (dp[i] != INT_MAX)
            return dp[i];

        int takingOne = stoneValue[i] - helper(stoneValue, i + 1, dp);

        int takingTwo = INT_MIN;

        if (i + 1 < stoneValue.size())
            takingTwo = (stoneValue[i] + stoneValue[i + 1]) - helper(stoneValue, i + 2, dp);

        int takingThree = INT_MIN;

        if (i + 2 < stoneValue.size())
            takingThree = (stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]) - helper(stoneValue, i + 3, dp);

        return dp[i] = max(takingOne, max(takingTwo, takingThree));
    }

    string stoneGameIII(vector<int> &stoneValue)
    {

        vector<int> dp(stoneValue.size(), INT_MAX);

        int ans = helper(stoneValue, 0, dp);

        if (ans > 0)
            return "Alice";

        else if (ans < 0)
            return "Bob";

        return "Tie";
    }
};