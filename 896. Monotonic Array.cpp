#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {

        if (nums.size() <= 2)
            return true;

        int n = nums.size();
        int i = 1;

        for (; i < n && (nums[i] == nums[i - 1]); i++)
        {
        }

        if (i == n)
            return true;

        bool flag = nums[i - 1] <= nums[i] ? true : false;

        i++;

        for (; i < n; i++)
        {

            if (flag)
            {
                if (nums[i] < nums[i - 1])
                    return false;
            }
            else
            {
                if (nums[i] > nums[i - 1])
                    return false;
            }
        }

        return true;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 2, 2, 3};

    cout << sl.isMonotonic(nums);

    return 0;
}