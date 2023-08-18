#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {

        vector<int> degree(n, 0);
        set<pair<int, int>> connections;

        for (auto &road : roads)
        {

            degree[road[0]]++;
            degree[road[1]]++;
            connections.insert({road[0], road[1]});
            connections.insert({road[1], road[0]});
        }

        int max_rank = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int rank = degree[i] + degree[j];
                if (connections.find({i, j}) != connections.end())
                {
                    rank--;
                }
                max_rank = max(max_rank, rank);
            }
        }

        return max_rank;
    }
};

int main()
{

    Solution sl;

    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    int n = 4;

    cout << sl.maximalNetworkRank(n, roads);

    return 0;
}