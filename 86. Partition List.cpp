#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {

        ListNode *LStart = NULL;
        ListNode *LEnd = NULL;
        ListNode *GStart = NULL;
        ListNode *GEnd = NULL;

        ListNode *temp = head;

        while (temp)
        {
            if (temp->val < x)
            {
                if (LStart == NULL)
                {
                    LStart = temp;
                    LEnd = temp;
                }
                else
                {
                    LEnd->next = temp;
                    LEnd = LEnd->next;
                }
            }
            else
            {

                if (GStart == NULL)
                {
                    GStart = temp;
                    GEnd = temp;
                }
                else
                {
                    GEnd->next = temp;
                    GEnd = GEnd->next;
                }
            }

            temp = temp->next;
        }

        if (LStart == NULL || GStart == NULL)
            return head;

        LEnd->next = GStart;
        GEnd->next = NULL;

        return LStart;
    }
};

int main()
{

    Solution sl;

    return 0;
}