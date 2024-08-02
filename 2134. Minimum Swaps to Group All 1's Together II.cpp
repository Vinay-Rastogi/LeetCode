#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {

        vector<int> nums1;
        int n = 2 * nums.size();

        for (int i = 0; i < nums.size(); i++)
            nums1.push_back(nums[i]);

        for (int i = 0; i < nums.size(); i++)
            nums1.push_back(nums[i]);

        int s = 0, e = 0;
        int cnt1 = 0;

        for (int x : nums)
        {
            if (x == 1)
                cnt1++;
        }

        int cnt = 0, ans = n;

        while (e < n)
        {
            if (nums1[e] == 1)
                cnt++;

            if (e - s + 1 > cnt1)
            {
                if (nums1[s] == 1)
                    cnt--;
                s++;
            }

            if (e - s + 1 == cnt1)
                ans = min(ans, cnt1 - cnt);

            e++;
        }

        return ans;
    }
};

int main()
{
    Solution sl;

    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};

    cout << sl.minSwaps(nums);

    return 0;
}