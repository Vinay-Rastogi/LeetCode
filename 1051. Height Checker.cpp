#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {

        vector<int> nums(heights.begin(), heights.end());

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != heights[i])
                ans++;

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int ans = sl.heightChecker(heights);

    cout << ans << endl;
}