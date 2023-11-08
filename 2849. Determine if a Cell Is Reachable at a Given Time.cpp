#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {

        // we go min( diff x , diff y) that is min(4, 2) = 2 step in digonal direction to (sx + 2, sy + 2) i.e. (5, 3).

        // Then move abs(diff x - diff y ) steps in horizontal or vertical direction to reach the destionation.

        int xdiff = abs(sx - fx);
        int ydiff = abs(sy - fy);

        if (xdiff == 0 && ydiff == 0 && t == 1)
            return false;

        return (min(xdiff, ydiff) + abs(xdiff - ydiff)) <= t;
    }
};

int main()
{

    Solution sl;
    int sx = 2;
    int sy = 4;
    int fx = 7;
    int fy = 7;
    int t = 6;

    cout << sl.isReachableAtTime(sx, sy, fx, fy, t);

    return 0;
}