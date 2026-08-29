// problem: https://leetcode.com/problems/linked-list-cycle-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(N), space - O(1)
struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *tortoise = head;
  struct ListNode *hare = head;

  // identify the collison node (if cycle is present)
  while (hare && hare->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;

    if (tortoise == hare) break;
  }

  // no node, single node & cyclic check
  if (!head || !head->next || hare != tortoise) return NULL;

  // identify the cyclic entry point
  tortoise = head;    // reset tortoise to head node
  while (tortoise != hare) {
    tortoise = tortoise->next;
    hare = hare->next;
  }

  return hare;    
}