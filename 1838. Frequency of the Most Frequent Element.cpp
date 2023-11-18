#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int mid, int k)
    {

        long long int sum = 0;
        long long int total = 0;

        for (int i = 0; i < mid; i++)
            sum += nums[i];

        total = 1LL * nums[mid - 1] * mid;

        if (total - sum <= k)
            return true;

        int j = 0;

        for (int i = mid; i < nums.size(); ++i)
        {
            sum -= nums[j];
            sum += nums[i];
            total = 1LL * nums[i] * mid;

            if (total - sum <= k)
                return true;
            j++;
        }

        return false;
    }
    int maxFrequency(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int l = 1;
        int r = nums.size();
        int ans = 0;

        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (possible(nums, mid, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 2, 4};
    int k = 5;

    cout << sl.maxFrequency(nums, k);

    return 0;
}