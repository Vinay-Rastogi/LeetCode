#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, int target, vector<int> &dp)
    {

        if (dp[target] != -1)
            return dp[target];

        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] <= target)
                count += helper(nums, target - nums[i], dp);
        }

        return dp[target] = count;
    }
    int combinationSum4(vector<int> &nums, int target)
    {

        vector<int> dp(target + 1, -1);
        dp[0] = 1;

        return helper(nums, target, dp);
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 2, 3};
    int target = 4;

    cout << sl.combinationSum4(nums, target);

    return 0;
}