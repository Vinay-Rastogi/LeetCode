#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
        {
            return 0; // Base case: the first row is always '0'.
        }

        int mid = (1 << (n - 1)) / 2; // Calculate the middle index of the current row.

        if (k <= mid)
        {
            // The element is in the first half, which is the same as the previous row.
            return kthGrammar(n - 1, k);
        }
        else
        {
            // The element is in the second half, which is the complement of the previous row.
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};

int main()
{

    Solution sl;
    int n = 3;
    int k = 3;

    cout << sl.kthGrammar(n, k);

    return 0;
}