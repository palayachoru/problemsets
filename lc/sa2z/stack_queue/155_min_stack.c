// problem: https://leetcode.com/problems/min-stack/

typedef struct Node{
  int min;
  int val;
  struct Node *nxt;
} Node;


typedef struct {
  Node *head;    
} MinStack;


MinStack* minStackCreate() {
  MinStack *ms = malloc(sizeof(MinStack));
  ms->head = NULL;

  return ms;    
} 


void minStackPush(MinStack* obj, int value) {
  Node *n = malloc(sizeof(Node));
  n->val = value;
  n->nxt = NULL;

  if (obj->head ==  NULL) {
    n->min = value;
    obj->head = n;
  }
  else {
    n->min = value < obj->head->min ? value : obj->head->min;
    n->nxt = obj->head;
    obj->head = n;
  }   
}


void minStackPop(MinStack* obj) {
  if (obj->head == NULL) return;
  obj->head = obj->head->nxt;    
}


int minStackTop(MinStack* obj) {
  return obj->head->val;    
}


int minStackGetMin(MinStack* obj) {
  return obj->head->min;    
}


void minStackFree(MinStack* obj) {
  Node *curr = obj->head;

  while (curr) {
    Node *nxt = curr->nxt;
    free(curr);
    curr = nxt;
  }

  free(obj);    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/