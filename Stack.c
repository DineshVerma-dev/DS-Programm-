#include <stdio.h>
#include<conio.h>
#define SIZE 5

struct stack {
  int item[SIZE];
  int top;
}s;

int isEmpty() {
  return (s.top == -1);
}

int isFull() {
  return (s.top == SIZE - 1);
}
void push(int x) {
  if (isFull()) {
    printf("Stack Overflow\n");
  } else {
    s.top++;
    s.item[s.top] = x;
  }
}
void pop() {
  if (isEmpty()) {
    printf("Stack Empty\n");
  } else {
    s.top--;
  }
}
void display() {
  if (isEmpty()) {
    printf("Stack Empty\n");
  } else {
    for (int i = 0; i <= s.top; i++) {
      printf("%d\n", s.item[i]);
    }
  }
}
int main() {
  int x, c;
  s.top = -1;

  do {
    printf("Enter your Choice:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    scanf("%d", & c);

    switch (c) {
    case 1:
      printf("Enter Element\n");
      scanf("%d", & x);
      push(x);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    }
  } while (c != 4);

  return 0;
}

/// Algorithm 
Algorithm for Stack using Array and Structure
Initialize Stack:

Set top = -1 to indicate the stack is initially empty.
Check if Stack is Empty (isEmpty):

If top == -1, return true (the stack is empty).
Otherwise, return false.
Check if Stack is Full (isFull):

If top == SIZE - 1, return true (the stack is full).
Otherwise, return false.
Push Operation (push):

If isFull() is true, print "Stack Overflow."
Otherwise:
Increment top by 1.
Set item[top] = x, where x is the element to be pushed.
Pop Operation (pop):

If isEmpty() is true, print "Stack Empty."
Otherwise:
Decrement top by 1 (remove the top element).
Display Stack (display):

If isEmpty() is true, print "Stack Empty."
Otherwise:
Iterate from index 0 to top.
Print item[i] for each i in the range [0, top].
Main Process:

Initialize stack with top = -1.
Continuously offer options to:
Push an element into the stack.
Pop an element from the stack.
Display the elements in the stack.
Exit the loop when the user chooses to exit.





