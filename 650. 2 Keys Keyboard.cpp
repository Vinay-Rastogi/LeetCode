#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int targetLength;

    int findMinSteps(int currentLength, int clipboardLength)
    {
        if (currentLength == targetLength)
            return 0;
        if (currentLength > targetLength)
            return INT_MAX / 2;

        int copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength);
        int pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength);

        return min(copyAndPaste, pasteOnly);
    }

public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        targetLength = n;
        return 1 + findMinSteps(1, 1);
    }
};

int main()
{
    Solution sl;
    int n = 3;

    cout << sl.minSteps(n);

    return 0;
}