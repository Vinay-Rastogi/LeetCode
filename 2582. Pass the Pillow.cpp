#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {

        int curr = 1;
        int d = 1;

        while (time--)
        {

            curr += d;
            if (curr == n || curr == 1)
            {
                d = -d;
            }
        }

        return curr;
    }
};

int main()
{

    Solution sl;

    int n = 4;
    int time = 5;

    cout << sl.passThePillow(n, time);

    return 0;
}