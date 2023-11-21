#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reverse(int num)
    {
        int rev = 0;
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int> &nums)
    {

        const int mod = 1000000007;

        int n = nums.size();

        for (int i = 0; i < n; ++i)
            nums[i] = nums[i] - reverse(nums[i]);

        sort(nums.begin(), nums.end());

        long res = 0;
        for (int i = 0; i < n - 1; ++i)
        {

            long count = 1;
            while (i < n - 1 && nums[i] == nums[i + 1])
            {
                count++;
                i++;
            }

            res = (res % mod + (count * (count - 1)) / 2) % mod;
        }

        return static_cast<int>(res % mod);
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {42, 11, 1, 97};

    cout << sl.countNicePairs(nums);

    return 0;
}