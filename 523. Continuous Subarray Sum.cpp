#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        int Sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            Sum += nums[i];
            Sum %= k;

            if (Sum == 0 && i)
                return true;

            if (mp.find(Sum) != mp.end())
            {
                if (i - mp[Sum] > 1)
                    return true;
            }

            else
                mp[Sum] = i;
        }

        return false;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {23, 2, 6, 4, 7};
    int k = 13;

    cout << sl.checkSubarraySum(nums, k);   

    return 0;
}