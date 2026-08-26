// PROBLEM: https://leetcode.com/problems/implement-stack-using-queues/description/

typedef struct Queue {
  int front;
  int rear;
  int capacity;
  int arr[];
} Queue;

// front and rear starts at index 0
// Empty Queue: front == rear
// Full Queue: rear + 1 == front
// one element is sacrificed to distungish b/w empty and full
Queue* qinit(int capacity) {
  Queue *q = malloc(sizeof(Queue) + capacity * sizeof(int));
  if (!q) return NULL;

  q->front = 0;
  q->rear = 0;
  q->capacity = capacity;

  return q;
}

bool qis_empty(Queue *q) {
  return q->front == q->rear;
}

bool qis_full(Queue *q) {
  return ((q->rear + 1) % q->capacity == q->front);
}

void enqueue(Queue *q, int value) {
  if (qis_full(q)) return;
  q->arr[q->rear] = value;
  q->rear = (q->rear + 1) % q->capacity;
}

int dequeue(Queue *q) {
  if (qis_empty(q)) return -1;

  int pop = q->arr[q->front];
  q->front = (q->front + 1) % q->capacity;
  return pop;
}

int qpeek(Queue *q) {
  if (qis_empty(q)) return -1;

  return q->arr[q->front];
}





typedef struct {
  Queue *q1;
  Queue *q2;    
} MyStack;


MyStack* myStackCreate() {
  MyStack *s = malloc(sizeof(MyStack));

  s->q1 = qinit(101);
  s->q2 = qinit(101);

  return s;    
}

// time - O(N)
void myStackPush(MyStack* obj, int x) {
  enqueue(obj->q2, x);

  while (!qis_empty(obj->q1)) {
    enqueue(obj->q2, dequeue(obj->q1));
  }

  // swap the references
  Queue *tmp = obj->q2;
  obj->q2 = obj->q1;
  obj->q1 = tmp;    
}

// time - O(1)
int myStackPop(MyStack* obj) {
  return dequeue(obj->q1);    
}

int myStackTop(MyStack* obj) {
  return qpeek(obj->q1);    
}

bool myStackEmpty(MyStack* obj) {
  return qis_empty(obj->q1);    
}

void myStackFree(MyStack* obj) {
  free(obj->q1);
  free(obj->q2);
  free(obj);    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/