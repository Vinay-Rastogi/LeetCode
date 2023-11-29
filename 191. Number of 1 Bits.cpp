#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {

        int count = 0;

        while (n)
        {
            if (n & 1)
                count++;

            n = n >> 1;
        }

        return count;
    }
};

int main()
{

    Solution sl;
    uint32_t n = 00000000000000000000000000001011;

    cout << sl.hammingWeight(n);

    return 0;
}