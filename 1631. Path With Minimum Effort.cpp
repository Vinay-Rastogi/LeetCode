#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int effort[105][105];

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

public:
    int dijkstra(vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty())
        {

            auto curr = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            int r = curr.first;
            int c = curr.second;

            if (cost > effort[r][c])
                continue;

            if (r == n - 1 && c == m - 1)
                return cost;

            for (int i = 0; i < 4; i++)
            {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int newEffort = max(effort[r][c], abs(heights[r][c] - heights[nr][nc]));

                if (newEffort < effort[nr][nc])
                {
                    effort[nr][nc] = newEffort;
                    pq.push({-newEffort, {nr, nc}});
                }
            }
        }
        return effort[n - 1][m - 1];
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {

        for (int i = 0; i < heights.size(); i++)
            for (int j = 0; j < heights[0].size(); j++)
                effort[i][j] = INT_MAX;

        return dijkstra(heights);
    }
};

int main()
{

    Solution sl;
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    cout << sl.dijkstra(heights);

    return 0;
}