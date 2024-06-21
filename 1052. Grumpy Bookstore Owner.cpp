#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {

        int n = grumpy.size();
        int i = 0;
        int currWin = 0;
        int maxWin = 0;

        for (int j = 0; j < n; j++)
        {

            currWin += customers[j] * grumpy[j];
            maxWin = max(currWin, maxWin);

            if (j >= minutes - 1)
                currWin -= customers[i] * grumpy[i++];
        }

        int res = maxWin;

        for (i = 0; i < n; i++)
            res += customers[i] * (1 - grumpy[i]);

        return res;
    }
};
int main()
{

    Solution sl;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    cout << sl.maxSatisfied(customers, grumpy, minutes);

    return 0;
}