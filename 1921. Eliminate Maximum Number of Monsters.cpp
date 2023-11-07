#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {

        vector<double> time(dist.size());

        for (int i = 0; i < dist.size(); i++)
            time[i] = static_cast<double>(dist[i]) / speed[i];

        sort(time.begin(), time.end());

        for (int i = 0; i < dist.size(); i++)
            if (time[i] <= i)
                return i;

        return dist.size();
    }
};

int main()
{

    Solution sl;
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};

    cout << sl.eliminateMaximum(dist, speed);

    return 0;
}