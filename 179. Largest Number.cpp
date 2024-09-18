#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyComparator
{
public:
    bool operator()(string a, string b) const
    {

        string s1 = a + b;
        string s2 = b + a;

        return s1 > s2;
    }
};

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        vector<string> str(nums.size());

        for (int i = 0; i < nums.size(); i++)
            str[i] = to_string(nums[i]);

        sort(str.begin(), str.end(), MyComparator());

        string ans = "";

        for (string s : str)
            ans += s;

        if (ans[0] == '0')
            return "0";

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {3, 30, 34, 5, 9};

    cout << sl.largestNumber(nums);

    return 0;
}