// problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(N), space - O(1)
struct ListNode* deleteMiddle(struct ListNode* head) {
  typedef struct ListNode Node;

  if (!head->next) return NULL;

  // start hare with 2 nodes advance
  // this will make the tortoise always to previous of middle node
  Node *tortoise = head;
  Node *hare = head->next->next;

  while (hare && hare->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  // now tortoise points to the previous of middle node
  tortoise->next = tortoise->next->next;

  return head;    
}