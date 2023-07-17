class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;

        while (head)
        {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode *Helper(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *ans = Helper(l1, l2);
        return reverseList(ans);
    }
};

/// Approach 2

class Solution
{
public:
    ListNode *Helper(ListNode *l1, ListNode *l2)
    {
        stack<int> stack1, stack2;

        while (l1 != nullptr)
        {
            stack1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            stack2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *result = nullptr;
        int carry = 0;

        while (!stack1.empty() || !stack2.empty() || carry != 0)
        {
            int digit1 = !stack1.empty() ? stack1.top() : 0;
            int digit2 = !stack2.empty() ? stack2.top() : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;

            if (!stack1.empty())
                stack1.pop();
            if (!stack2.empty())
                stack2.pop();
        }

        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = Helper(l1, l2);
        return ans;
    }
};