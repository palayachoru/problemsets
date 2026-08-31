// problem: https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// time - O(M+ N), space - O(1)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  typedef struct ListNode Node;

  Node *head = l1;
  Node *tail = NULL;   // to keep track of last node
  int carry = 0, sum = 0;

  while (l1 && l2) {
    sum = l1->val + l2->val + carry;

    l1->val = sum % 10;
    carry = sum / 10;

    tail = l1;
    l1 = l1->next;
    l2 = l2->next;    
  }

  // if l1 is exhaused, attach the remaining l2 nodes to l1
  if (l2) {
    tail->next = l2;
    l1 = l2;
  }

  while (l1) {
    sum = l1->val + carry;

    l1->val = sum % 10;
    carry = sum / 10;

    tail = l1;
    l1 = l1->next;
  }

  if (carry) {
    tail->next = malloc(sizeof(Node));
    tail->next->val = carry;
    tail->next->next = NULL;
  } 

  return head;
}
