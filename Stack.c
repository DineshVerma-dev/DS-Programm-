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