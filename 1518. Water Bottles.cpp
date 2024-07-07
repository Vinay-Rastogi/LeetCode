#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles, count = 0, curBottles = 0;
        while (true)
        {
            if (numBottles - numExchange < 0)
            {
                numBottles += curBottles;
                ans += count;
                count = curBottles = 0;
            }
            if (numBottles - numExchange < 0)
                break;
            count++, curBottles++;
            numBottles -= numExchange;
        }
        return ans;
    }
};

int main()
{

    Solution sl;

    int numBottles = 15;
    int numExchange = 4;

    cout << sl.numWaterBottles(numBottles, numExchange);

    return 0;
}