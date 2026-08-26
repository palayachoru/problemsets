// problem: https://leetcode.com/problems/valid-parentheses/description/

typedef struct Stack {
  int top;
  int capacity;
  char arr[];
} Stack;

// top start at index 0
// add value & increment top
// decrement top & remove the value
// stack full: top == capacity
// stack empty: top == 0
Stack* sinit(int capacity) {
  Stack *s = malloc(sizeof(Stack) + capacity * sizeof(char));
  s->top = 0;
  s->capacity = capacity;

  return s;
}

bool is_empty(Stack *s) {
  return s->top == 0;
}

bool is_full(Stack *s) {
  return s->top >= s->capacity;
}

void push(Stack *s, char val) {
  if (is_full(s)) return;
  s->arr[s->top] = val;
  s->top++;
}

char pop(Stack *s) {
  if (is_empty(s)) return 0;

  return s->arr[--s->top];
}

char peek(Stack *s) {
  if (is_empty(s)) return 0;

  return s->arr[s->top - 1];
}


char get_open_pair(char close_pair) {
  switch (close_pair) {
    case ')': return '(';
    case ']': return '[';
    case '}': return '{';
  }
  return 0;
}



// time - O(N), space - O(N)
bool isValid(char* s) {
  Stack *st = sinit(strlen(s) + 1);

  while (*s) {
    // if open parentheses, push it to stack
    if (*s == '(' || *s == '{' || *s == '[') push(st, *s);
    else {
      if (is_empty(st)) return false;

      char open_pair = pop(st);
      if (open_pair != get_open_pair(*s)) return false;
    }

    s++;
  }

  return is_empty(st);    
}