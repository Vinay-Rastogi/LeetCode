class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {

        stack<int> st;

        for (int ele : asteroids)
        {
            if (ele > 0)
            {
                st.push(ele);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() < abs(ele))
                {
                    st.pop();
                }

                if (!st.empty() && st.top() == abs(ele))
                {
                    st.pop();
                }
                else if (st.empty() || st.top() < 0)
                {
                    st.push(ele);
                }
            }
        }

        vector<int> arr(st.size());

        for (int i = st.size() - 1; i >= 0; i--)
        {
            arr[i] = st.top();
            st.pop();
        }

        return arr;
    }
};