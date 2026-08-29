// problem: https://leetcode.com/problems/reverse-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// ITERATIVE APPROACH //
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode *prev = NULL;
  struct ListNode *curr = head;
  struct ListNode *nxt;

  while (curr) {
    nxt = curr->next;

    curr->next = prev;
    prev = curr;

    curr = nxt;
  }

  return prev;    
}


// RECURSIVE APPROCH //
struct ListNode* reverseList(struct ListNode* head) {
  if (!head || head->next == NULL) return head;

  // recursive call, always track the reversed head
  struct ListNode *rev_head = reverseList(head->next);

  // as the logic is placed below the recursive call, this
  // will be executed after we hit the boundry condition

  // add the curr node to the end of the reversed chain 
  // and update the next ref to NULL
  head->next->next = head;
  head->next = NULL;

  return rev_head;
}