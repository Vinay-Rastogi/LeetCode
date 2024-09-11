#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        int ans = 0;

        while (start || goal)
        {
            int s = start & 1;
            int g = goal & 1;

            ans += s == g ? 0 : 1;

            start = start >> 1;
            goal = goal >> 1;
        }

        return ans;
    }
};

int main()
{
    Solution sl;

    int start = 10;
    int goal = 7;

    cout << sl.minBitFlips(start, goal);

    return 0;
}