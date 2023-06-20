// Approach 1
// SC - O(N)
// TC  (N)

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<long long int> pre(n), suff(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i];

        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {

            if (i - k < 0 || i + k >= n)
                ans.push_back(-1);

            else
            {

                long long int sum = (long long int)((suff[i - k] - suff[i]) + (pre[i + k] - pre[i]) + nums[i]);
                sum = sum / (2 * k + 1);
                ans.push_back(sum);
            }
        }

        return ans;
    }
};

// Approach 2
// SC - O(1)
// TC  (N)

// class Solution {
// public:
//     vector<int> getAverages(vector<int>& nums, int k) {

//         vector<int> ans(nums.size(),-1);
//         int left = 0;
//         int div = 2*k+1;
//         int sum = 0;

//         for(int right=0;right<nums.size();right++){

//             sum += nums[right];

//             if(right-left+1 >= 2*k+1){
//                 ans[k+left] = sum/div;
//                 sum -= nums[left];
//                 left++;
//             }
//         }

//         return ans;
//     }
// };
