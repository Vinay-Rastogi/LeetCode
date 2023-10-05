#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        vector<int> Res;

        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }

            else if (nums[i] == num2)
            {
                count2++;
            }

            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }

            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }

            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }

            else if (nums[i] == num2)
            {
                count2++;
            }
        }

        if (count1 > nums.size() / 3)
            Res.push_back(num1);

        if (count2 > nums.size() / 3)
            Res.push_back(num2);

        return Res;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {3, 2, 3};
    vector<int> res = sl.majorityElement(nums);

    return 0;
}