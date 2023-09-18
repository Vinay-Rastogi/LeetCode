#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        priority_queue<pair<int, int>> pq;
        int len = mat.size();

        for (int i = 0; i < len; i++)
        {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            pq.push({cnt, i});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    Solution sl;
    vector<vector<int>> mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    int k = 3;

    vector<int> ans = sl.kWeakestRows(mat, k);

    return 0;
}