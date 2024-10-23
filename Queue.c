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



Algorithm for Queue using Array
Initialize Queue:

Set front = -1 and rear = -1 to indicate the queue is empty.
Check if Queue is Empty (isEmpty):

If front == -1, return true (the queue is empty).
Otherwise, return false.
Check if Queue is Full (isFull):

If rear == SIZE - 1, return true (the queue is full).
Otherwise, return false.
Insert Operation (insert):

If isFull() is true, print "Queue Overflow."
Otherwise:
If isEmpty() is true, set front = 0 (indicating the first element is being added).
Increment rear by 1.
Set queue[rear] = x, where x is the element to be inserted.
Delete Operation (delete):

If isEmpty() is true, print "Queue Empty."
Otherwise:
If front == rear, set both front and rear to -1 (queue becomes empty).
Otherwise, increment front by 1 to remove the front element.
Display Queue (display):

If isEmpty() is true, print "Queue Empty."
Otherwise:
Iterate from index front to rear.
Print each element queue[i] for i in the range [front, rear].
Main Process:

Continuously offer options to:
Insert an element into the queue.
Display the elements in the queue.
Delete an element from the queue.
Exit the loop when the user chooses to exit.