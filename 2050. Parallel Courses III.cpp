#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> graph(n);

        for (const vector<int> &relation : relations)
        {
            int prev = relation[0] - 1;
            int next = relation[1] - 1;
            graph[prev].push_back(next);
        }

        vector<int> memo(n, -1);

        function<int(int)> calculateTime = [&](int course)
        {
            if (memo[course] != -1)
            {
                return memo[course];
            }

            if (graph[course].empty())
            {
                memo[course] = time[course];
                return memo[course];
            }

            int maxPrerequisiteTime = 0;
            for (int prereq : graph[course])
            {
                maxPrerequisiteTime = max(maxPrerequisiteTime, calculateTime(prereq));
            }

            memo[course] = maxPrerequisiteTime + time[course];
            return memo[course];
        };

        int overallMinTime = 0;
        for (int course = 0; course < n; course++)
        {
            overallMinTime = max(overallMinTime, calculateTime(course));
        }

        return overallMinTime;
    }
};

int main()
{

    Solution sl;
    int n = 3;
    vector<vector<int>> relations = {{1, 3}, {2, 3}};
    vector<int> time = {3, 2, 5};

    cout << sl.minimumTime(n, relations, time);

    return 0;
}