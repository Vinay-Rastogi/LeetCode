#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> newNum(nums.begin(), unique(nums.begin(), nums.end()));
        int ans = INT_MIN;
        int end = 0;

        for (int x : newNum)
            cout << x << " ";

        for (int start = 0; start < newNum.size(); start++)
        {

            while (end < newNum.size() && newNum[end] < (newNum[start] + n))
                end++;

            ans = max(ans, end - start);
        }

        return n - ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {4, 2, 5, 3};

    cout << sl.minOperations(nums);

    return 0;
}