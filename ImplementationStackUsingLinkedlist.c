#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * link;
};
struct node * p;
struct node * top;
void push(struct node * q, int num) {
  struct node * temp;
  if (q == NULL) {
    printf("Creating stack\n");
    temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = num;
    temp -> link = NULL;
    p = temp;
    top = p;
  } else {
    temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = num;
    temp -> link = p;
    p = temp;
    top = p;
  }
}
void pop(struct node * q) {
  if (q == NULL)
    printf("stack does not exist");
  else {
    p = q -> link;
    top = p;
  }
}
void count(struct node * q) {
  int c;
  c = 0;
  if (q == NULL)
    printf("Link List Does Not Exists");
  else {
    while (q != NULL) {
      c++;
      q = q -> link;
    }
    printf("Number Of Nodes %d\n", c);
  }
}
void display(struct node * q) {
  if (q == NULL)
    printf("Link List Does Not Exists\n");
  else {
    printf("Contents:\n");
    while (q != NULL) {
      printf("%d\n", q -> data);
      q = q -> link;
    }
  }
}
int main() {
  int n, c;
  p = NULL;
  do {
    printf("Enter Your Choice:\n");
    printf("1.Create/push\t");
    printf("\t2.pop\t");
    printf("\t3.Count\t");
    printf("\t4.Display\t");
    printf("\t5.Exit\n");
    scanf("%d", & c);
    switch (c) {
    case 1:
      printf("Enter A Value:\n");
      scanf("%d", & n);
      push(p, n);
      break;
    case 2:
      pop(p);
      break;
    case 3:
      count(p);
      break;
    case 4:
      display(p);
      break;
    }
  }
  while (c != 5);
  return 0;
}

Algorithm for Stack Implementation using Linked List
Define Structure:

Define struct node with int data and a pointer link.
Initialize Pointers:

Create pointers p and top for the stack.
Push Operation:

Function: push(struct node * q, int num)
If q is empty:
Allocate memory, set data, and link to NULL.
If not empty:
Allocate memory, set data, and link to current top (p).
Pop Operation:

Function: pop(struct node * q)
If q is empty, print an error.
Otherwise, update p to q->link.
Count Operation:

Function: count(struct node * q)
Initialize counter c to 0.
If q is empty, print an error.
Traverse q, incrementing c until q is NULL.
Display Operation:

Function: display(struct node * q)
If q is empty, print an error.
Otherwise, traverse q and print data.
Main Function:

Initialize p to NULL.
Loop to display a menu and accept user choices for operations.
Call appropriate functions based on user input.
End Program:

Return 0 to indicate successful execution.