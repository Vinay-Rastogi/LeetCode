#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum)
    {

        const int r = rowSum.size(), c = colSum.size();
        vector<vector<int>> arr(r, vector<int>(c, 0));

        for (int i = 0, j = 0; i < r && j < c;
             i += (rowSum[i] == 0), j += (colSum[j] == 0))
        {
            int x = min(rowSum[i], colSum[j]);
            arr[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
        return arr;
    }
};

int main()
{
    Solution sl;
    vector<int> rowSum = {5, 7, 10};
    vector<int> colSum = {8, 6, 8};
    vector<vector<int>> res = sl.restoreMatrix(rowSum, colSum);

    return 0;
}