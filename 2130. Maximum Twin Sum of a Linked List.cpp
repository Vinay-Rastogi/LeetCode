/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int pairSum(ListNode *head)
    {

        ListNode *tmp = head;
        vector<int> v;

        while (tmp)
        {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }

        int n = v.size() - 1;
        int ans = 0;

        for (int i = 0; i < n; i++, n--)
        {
            ans = max(ans, v[i] + v[n]);
        }

        return ans;
    }
};