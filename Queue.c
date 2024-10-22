#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int isEmpty() {
  return (front == -1);
}
int isFull() {
  return (rear == SIZE - 1);
}
void insert(int x) {
  if (isFull()) {
    printf("Queue Overflow\n");
  } else {
    if (isEmpty()) {
      front = 0;
    }
    rear++;
    queue[rear] = x;
  }
}
void delete() {
  if (isEmpty()) {
    printf("Queue Empty\n");
  } else if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
}
void display() {
  if (isEmpty()) {
    printf("Queue Empty\n");
  } else {
    printf("Queue:\n");
    for (int i = front; i <= rear; i++) {
      printf("%d\n", queue[i]);
    }
  }
}
int main() {
  int x, c;
  do {
    printf("Enter Your Choice:\n");
    printf("1. Insert\n2. Display\n3. Delete\n4. Exit\n");
    scanf("%d", & c);
    switch (c) {
    case 1:
      printf("Enter The Element To Be Inserted:\n");
      scanf("%d", & x);
      insert(x);
      break;
    case 2:
      display();
      break;
    case 3:
      delete();
      break;
    }
  } while (c != 4);
  return 0;
}