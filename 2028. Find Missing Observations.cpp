#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {

        int m = rolls.size();
        int total = (m + n) * mean;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int rem = total - sum;

        if (n * 6 < rem)
            return {};

        int i = n - 1;
        vector<int> ans;

        while (i--)
        {
            int num = rem / n;

            if (num < 1)
                return ans;

            ans.push_back(num);
            rem -= num;
            n--;
        }

        ans.push_back(rem);

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;
    vector<int> res = sl.missingRolls(rolls, mean, n);

    return 0;
}