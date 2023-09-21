#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {

        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans(m + n);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                ans[k] = arr1[i++];
                k++;
            }

            else
            {
                ans[k] = arr2[j++];
                k++;
            }
        }

        while (i < n)
        {
            ans[k] = arr1[i++];
            k++;
        }

        while (j < m)
        {
            ans[k] = arr2[j++];
            k++;
        }

        return ans;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans = mergeSortedArrays(nums1, nums2);
        float median = 0;
        int n = ans.size() - 1;

        if (n % 2 != 0)
            median = (ans[n / 2] + ans[(n / 2) + 1]) / 2.0;
        else
            median = ans[n / 2];

        return median;
    }
};

int main()
{

    Solution sl;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << sl.findMedianSortedArrays(nums1, nums2);

    return 0;
}