#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (m * n != original.size())
            return {};
        vector<vector<int>> vec(m, vector<int>(n));
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec[i][j] = original[k];
                k++;
            }
        }
        return vec;
    }
};

int main()
{
    Solution sl;
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    vector<vector<int>> res = sl.construct2DArray(original, m, n);

    return 0;
}