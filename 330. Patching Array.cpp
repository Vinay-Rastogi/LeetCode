#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {

        long long max_sum = 0;
        int additions = 0;

        for (int coin : nums)
        {
            while (max_sum + 1 < coin)
            {
                max_sum += max_sum + 1;
                additions++;

                if (max_sum >= n)
                {
                    return additions;
                }
            }

            max_sum += coin;

            if (max_sum >= n)
            {
                return additions;
            }
        }

        while (max_sum < n)
        {
            max_sum += max_sum + 1;
            additions++;
        }

        return additions;
    }
};

int main()
{

    Solution sl;
    int n = 6;
    vector<int> nums = {1, 3};

    int ans = sl.minPatches(nums, n);

    cout << ans << endl;

    return 0;
}