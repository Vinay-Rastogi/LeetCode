class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

          if(head == NULL || head->next == NULL)
          return head;

        
          ListNode* temp = head;
            int len = 0;
            while (temp) {
                len++;        
                temp = temp->next;
            }
        
            if (k > len) {
                return head;
            }

            ListNode* first = head;
            for (int i = 1; i < k; i++) {
                first = first->next;
            }

            ListNode* second = head;
            for (int i = 1; i <= len - k; i++) {
                second = second->next;
            }

            int t = first->val;
            first->val = second->val;
            second->val = t;

            return head;
    }
};