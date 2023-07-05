class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int head = 0;
        int tail = 0;
        int cnt = 0;
        int ans = INT_MIN;

        for (; head < nums.size(); head++)
        {

            if (nums[head] == 0)
                cnt++;

            while (cnt > 1)
            {

                if (nums[tail] == 0)
                    cnt--;

                tail++;
            }

            ans = max(ans, head - tail);
        }

        return ans;
    }
};