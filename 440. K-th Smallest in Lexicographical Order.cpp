#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int Count(long curr, long next, int n)
    {
        int cntNum = 0;
        while (curr <= n)
        {
            cntNum += next - curr;
            curr *= 10;
            next *= 10;
            next = min(next, long(n + 1));
        }
        return cntNum;
    }
    int findKthNumber(int n, int k)
    {
        int curr = 1;
        k -= 1;
        while (k > 0)
        {
            int cnt = Count(curr, curr + 1, n);
            if (cnt <= k)
            {
                curr++;
                k -= cnt;
            }
            else
            {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};

int main()
{
    Solution sl;
    int n = 13;
    int k = 2;

    cout << sl.findKthNumber(n, k);

    return 0;
}