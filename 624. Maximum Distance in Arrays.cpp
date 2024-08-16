#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {

        int mn = arrays[0][0];
        int mx = arrays[0].back();
        int ans = 0;

        for (int i = 1; i < arrays.size(); i++)
        {

            int s = arrays[i][0];
            int e = arrays[i].back();

            ans = max(ans, abs(e - mn));
            ans = max(ans, abs(mx - s));

            mn = min(mn, s);
            mx = max(mx, e);
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};

    cout << sl.maxDistance(array);

    return 0;
}