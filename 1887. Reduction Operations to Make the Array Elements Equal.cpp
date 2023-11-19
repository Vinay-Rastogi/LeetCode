#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> freq(50001, 0);

        for (int i = 0; i < n; i++)
            freq[nums[i]]++;

        int res = 0;
        int oper = 0;

        for (int i = 50000; i >= 1; i--)
        {
            if (freq[i] > 0)
            {
                oper += freq[i];
                res += oper - freq[i];
            }
        }

        return res;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {};

    cout << sl.reductionOperations(nums);
    return 0;
}