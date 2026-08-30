// problem: https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
  typedef struct ListNode Node;

  if (!head || !head->next) return head;

  Node *odd = head;
  Node *even = head->next;
  Node *even_head = head->next;  // used for merging

  while (even && even->next) {
    odd->next = odd->next->next;   // get addr of next odd node & update next 
    even->next = even->next->next; // get addr of next even node & update next

    odd = odd->next;       // move to next odd and even node
    even = even->next;
  }

  // merge two odd/even
  odd->next = even_head;

  return head;
    
}