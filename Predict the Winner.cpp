class Solution
{
public:
    vector<vector<int>> player;
    int n;

    int game(int l, int r, int score, vector<int> &nums)
    {

        int sgn = ((r - l - n) & 1) ? 1 : -1;

        if (l == r)
            return player[l][r] = score + sgn * nums[l];

        if (player[l][r] != INT_MAX)
        {
            return player[l][r];
        }

        int ans;

        if (sgn == 1) // player 1
            ans = max(game(l + 1, r, nums[l] + score, nums),
                      game(l, r - 1, nums[r] + score, nums));

        else
            ans = min(game(l + 1, r, -nums[l] + score, nums),
                      game(l, r - 1, -nums[r] + score, nums));

        return ans;
    }

    bool PredictTheWinner(vector<int> &nums)
    {

        n = nums.size();
        player.assign(n, vector<int>(n, INT_MAX));

        return game(0, n - 1, 0, nums) >= 0;
    }
};