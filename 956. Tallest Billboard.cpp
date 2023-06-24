class Solution
{
public:
    int helper(vector<int> &rods, int l, int r, int remain, vector<vector<int>> &memo)
    {
        // Base case: all rods have been considered
        if (l == r && l > 0)
            return l;

        // If the current state has been memoized, return the memoized result
        if (memo[l][rods.size() - remain - 1] != -1)
            return memo[l][rods.size() - remain - 1];

        int res = 0;

        // Try using the current rod on the left side
        if (l + rods[remain] <= r + remain)
        {
            res = max(res, helper(rods, l + rods[remain], r, remain - rods[remain], memo));
        }

        // Try using the current rod on the right side
        if (r + rods[remain] <= l + remain)
        {
            res = max(res, helper(rods, l, r + rods[remain], remain - rods[remain], memo));
        }

        // Skip using the current rod
        res = max(res, helper(rods, l, r, remain - rods[remain], memo));

        // Memoize the result
        memo[l][rods.size() - remain - 1] = res;

        return res;
    }

    int tallestBillboard(vector<int> &rods)
    {

        if (rods.size() <= 0)
            return 0;

        int sum = 0;

        for (int rod : rods)
            sum += rod;

        vector<vector<int>> memo(rods.size(), vector<int>(sum + 1, -1));

        return helper(rods, 0, 0, sum, memo);
    }
};