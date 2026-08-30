// problem: 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(N), space - O(1)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  typedef struct ListNode Node;

  Node *left = head;
  Node *right = head;

  // move right ptr by n nodes
  for (int i = 0; i < n; i++) {
    right = right->next;
  }

  // if right is null, then node to be removed is the first node
  if (!right) return head->next;  

  // move left and right point by one node until right reachs last node
  while (right->next) {
    left = left->next;
    right = right->next;
  }

  // Now left will be previous to the Node to be removed
  if (left && left->next)
    left->next = left->next->next;

  return head;
}