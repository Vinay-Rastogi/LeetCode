#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {

        int n = buckets;
        int t = minutesToTest / minutesToDie;
        int x = 0;

        while (pow(t + 1, x) < n)
            x++;

        return x;
    }
};

int main()
{

    Solution sl;
    int buckets = 4;
    int minutesToDie = 15;
    int minutesToTest = 15;

    cout << sl.poorPigs(buckets, minutesToDie, minutesToTest);

    return 0;
}