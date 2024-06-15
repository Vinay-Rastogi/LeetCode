#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {

        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for (int i = 0; i < n; i++)
            projects[i] = {capital[i], profits[i]};

        sort(projects.begin(), projects.end());

        int i = 0;
        priority_queue<int> maxCapital;

        while (k--)
        {

            while (i < n && projects[i].first <= w)
            {
                maxCapital.push(projects[i].second);
                i++;
            }

            if (maxCapital.empty())
                break;

            w += maxCapital.top();

            maxCapital.pop();
        }

        return w;
    }
};

int main()
{

    Solution sl;
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    int ans = sl.findMaximizedCapital(k, w, profits, capital);

    cout << ans << endl;

    return 0;
}