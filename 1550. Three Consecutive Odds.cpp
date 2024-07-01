#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {

        if (arr.size() < 3)
            return false;

        for (int i = 1; i < arr.size() - 1; i++)
            if (arr[i - 1] % 2 && arr[i] % 2 && arr[i + 1] % 2)
                return true;

        return false;
    }
};

int main()
{

    Solution sl;
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};

    cout << sl.threeConsecutiveOdds(arr) << endl;

    return 0;
}