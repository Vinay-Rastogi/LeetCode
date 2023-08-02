class Solution
{

private:
    void generatePermutation(vector<int> &nums, vector<int> &ds, vector<vector<int>> &Res, vector<bool> freq)
    {

        if (ds.size() == nums.size())
        {
            Res.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (!freq[i])
            {

                freq[i] = true;
                ds.push_back(nums[i]);
                generatePermutation(nums, ds, Res, freq);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> Res;
        vector<int> ds;
        vector<bool> freq(nums.size());

        generatePermutation(nums, ds, Res, freq);

        return Res;
    }
};