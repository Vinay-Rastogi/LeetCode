#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {

        vector<double> curr(1, poured);

        for (int r = 0; r < query_row; r++)
        {

            vector<double> next(r + 2, 0.0);

            for (int glass = 0; glass < curr.size(); glass++)
            {

                double extra = (curr[glass] - 1) / 2.0;

                if (extra > 0.0)
                {

                    next[glass] += extra;
                    next[glass + 1] += extra;
                }
            }

            curr = next;
        }

        return min(1.0, curr[query_glass]);
    }
};

int main()
{

    Solution sl;
    int poured = 2;
    int query_row = 1;
    int query_glass = 1;

    cout << sl.champagneTower(poured, query_row, query_glass);

    return 0;
}