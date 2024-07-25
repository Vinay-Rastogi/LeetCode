#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = nums[l + i];

        for (j = 0; j < n2; j++)
            R[j] = nums[m + 1 + j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                nums[k] = L[i];
                i++;
            }
            else
            {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
        are any */
        while (i < n1)
        {
            nums[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
        are any */
        while (j < n2)
        {
            nums[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {

            int m = l + (r - l) / 2;

            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);

            merge(nums, l, m, r);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {

        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{

    Solution sl;

    vector<int> nums = {5, 1, 1, 2, 0, 0};

    vector<int> ans = sl.sortArray(nums);

    return 0;
}