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



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // time - O(N), space - O(1)
bool isPalindrome(struct ListNode* head) {
  typedef struct ListNode Node;

  Node *tortoise = head;
  Node *hare = head;

  // identify the mid of the linked list
  while (hare->next && hare->next->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  // reverse the second half
  Node *rev_head = reverseList(tortoise->next);

  // compare for match
  while (rev_head) {
    if (head->val != rev_head->val) return false;

    head = head->next;
    rev_head = rev_head->next;
  }

  return true;    
}