class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {

        int l = 1;
        int h = 1000000009;
        int ans = -1;

        while (l < h)
        {

            int mid = l + (h - l) / 2;
            double time = 0;

            for (int x : dist)
            {
                if (time > (int)time)
                    time = (double)((int)time + 1);

                time += ((double(x)) / (double(mid)));
            }

            if (time > hour)
                l = mid + 1;

            else
                h = mid;
        }

        return l > 100000000 ? -1 : l;
    }
};