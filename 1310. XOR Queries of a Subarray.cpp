#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> res;
        for (int i = 1; i < A.size(); ++i)
            A[i] ^= A[i - 1];
        for (auto &q : queries)
            res.push_back(q[0] > 0 ? A[q[0] - 1] ^ A[q[1]] : A[q[1]]);
        return res;
    }
};

int main()
{
    Solution sl;

    vector<int> A = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> ans = sl.xorQueries(A, queries);

    return 0;
}