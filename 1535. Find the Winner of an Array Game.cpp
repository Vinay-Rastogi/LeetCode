#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {

        if (k == 1)
            return max(arr[0], arr[1]);

        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());

        int count = 0;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {

            if (ans > arr[i])
            {
                count++;
            }
            else
            {
                ans = arr[i];
                count = 1;
            }

            if (count == k)
                break;
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    int k = 2;
    vector<int> arr = {2, 1, 3, 5, 4, 6, 7};

    cout << sl.getWinner(arr, k);

    return 0;
}