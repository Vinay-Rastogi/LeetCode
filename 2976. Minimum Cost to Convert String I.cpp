#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        long long dist[26][26];
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
                dist[i][j] = 1e18;
            dist[i][i] = 0;
        }

        // Formulating graph
        int m = original.size();
        for (int i = 0; i < m; i++)
        {
            int u = original[i] - 'a', v = changed[i] - 'a';
            long long wt = cost[i];
            dist[u][v] = min(wt, dist[u][v]);
        }

        // Floyd Warshall
        for (int k = 0; k <= 25; k++)
            for (int i = 0; i <= 25; i++)
                for (int j = 0; j <= 25; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int n = source.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dist[u][v] == 1e18)
                return -1;
            sum += dist[u][v];
        }
        return sum;
    }
};

int main()
{

    Solution sl;

    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};

    cout << sl.minimumCost(source, target, original, changed, cost);

    return 0;
}