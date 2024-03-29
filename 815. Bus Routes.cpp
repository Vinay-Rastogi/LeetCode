#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
    {

        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        queue<pair<int, int>> bfs;
        bfs.push({S, 0});
        unordered_set<int> seen = {S};
        while (!bfs.empty())
        {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if (stop == T)
                return bus;
            for (int i : to_routes[stop])
            {
                for (int j : routes[i])
                {
                    if (seen.find(j) == seen.end())
                    {
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};

int main()
{

    Solution sl;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int S = 1;
    int T = 6;

    cout << sl.numBusesToDestination(routes, S, T);

    return 0;
}