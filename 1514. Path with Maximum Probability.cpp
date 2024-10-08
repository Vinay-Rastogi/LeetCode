#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {

        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;

        queue<int> q;
        q.push(start);

        while (!q.empty())
        {

            int curr = q.front();
            q.pop();

            for (auto it : adj[curr])
            {

                int nextNode = it.first;
                double prob = it.second;

                double newProb = dist[curr] * prob;

                if (newProb > dist[nextNode])
                {
                    dist[nextNode] = newProb;
                    q.push(nextNode);
                }
            }
        }

        return dist[end];
    }
};

int main()
{
    Solution sl;
    int n = 3;
    vector<vector<int>> edges = {{0, 1}};
    vector<double> succProb = {0.5};
    int start = 0;
    int end = 2;

    cout << sl.maxProbability(n, edges, succProb, start, end);

    return 0;
}