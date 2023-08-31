#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int helper(int i, int prev, vector<vector<int>> &intervals)
    {

        if (prev >= intervals.size() - 1)
            return 0;

        if (i == intervals.size())
            return 1e9;

        if (dp.count(i) && dp[i].count(prev))
            return dp[i][prev];

        if (intervals[i][0] <= prev)
        {

            int include = 1 + helper(i + 1, intervals[i][1], intervals);
            int exclude = helper(i + 1, prev, intervals);

            return dp[i][prev] = min(include, exclude);
        }

        return dp[i][prev] = 1e9;
    }

    int minTaps(int n, vector<int> &ranges)
    {

        vector<vector<int>> intervals;

        for (int i = 0; i < ranges.size(); i++)
            intervals.push_back({(i - ranges[i]), (i + ranges[i])});

        sort(intervals.begin(), intervals.end());

        int ans = helper(0, 0, intervals);

        if (ans == 1e9)
            return -1;

        return ans;
    }

    int minTapsTabulation(int n, vector<int> &ranges)
    {
        vector<int> maxReach(n + 1, 0);

        for (int i = 0; i < ranges.size(); ++i)
        {
            int s = max(0, i - ranges[i]);
            int e = i + ranges[i];
            maxReach[s] = e;
        }

        int tap = 0;
        int currEnd = 0;
        int nextEnd = 0;

        for (int i = 0; i <= n; ++i)
        {
            if (i > nextEnd)
            {
                return -1;
            }
            if (i > currEnd)
            {
                tap++;
                currEnd = nextEnd;
            }
            nextEnd = max(nextEnd, maxReach[i]);
        }

        return tap;
    }
};

int main()
{

    Solution sl;

    int n = 5;
    vector<int> ranges = {3, 4, 1, 1, 0, 0};

    cout << sl.minTaps(n, ranges);

    return 0;
}