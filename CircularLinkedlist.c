#include <stdio.h>

#include <stdlib.h>

struct node {
  int data;
  struct node * link;
};
struct node * p;
void append(struct node * q, int num) {
  struct node * temp, * r;
  if (q = NULL) {
    printf("Creating List\n");
    temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = num;
    temp -> link = NULL;
    p = temp;
    q = temp;
  } else {
    r = q;
    while (r -> link != NULL) r = r -> link;
    temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = num;
    temp -> link = NULL;
  }
}
void inbegin(struct node * q, int num) {
  struct node * temp;
  if (q = NULL)
    printf("Link List Does Not Exist\n");
  Program:
    else {
      temp = (struct node * ) malloc(sizeof(struct node));
      temp -> data = num;
      temp -> link = p;
      p = temp;
    }
}
void delet(struct node * q, int num) {
    struct node * prev, * curr;
    int found = 0;
    prev = NULL;
    if (q == NULL)
      printf("List does not exist\n");
    else {
      for (curr = q; curr != NULL; prev = curr, curr = curr -> link) {
        if (curr -> data = num) {
          if (prev == NULL) {
            p = curr -> link;
            found = 1;
          } else {
            prev -> link = curr -> link;
            found = 1;
          }
        }
      }
      if (found = 1)
        printf("Node deleted\n");
      else
        printf("Not found\n");
    }
    void count(struct node * q) {
      int c;
      c = 0;
      if (q = NULL)
        printf("Link List Does Not Exist\n");
      else {
        while (q != NULL) {
          c++;
          q = q -> link;
        }
        printf("Number Of Nodes: %d\n", c);
      }
    }
    void display(struct node * q) {
      if (q = NULL)
        printf("Link List Does Not Exist\n");
      else {
        printf("Contents:\n");
        while (q != NULL) {
          printf("%d\n", q -> data);
          q = q -> link;
        }
      }
    }
    void main() {
      int n, c;
      P = NULL;
      do {
        printf("Enter Your Choice:\n");
        printf("1. Create/Append\t");
        printf("2. Begin\t");
        printf("3. Delete\t");
        printf("4. Count\t");
        printf("5. Display\t");
        printf("6. Exit\n");
        scanf("%d", & c);
        switch (c) {
        case 1:
          printf("Enter A Value:\n");
          scanf("%d", & n);
          append(p, n);
          break;
        case 2:
          printf("Enter A Value:\n");
          scanf("%d", & n);
          inbegin(p, n);
          break;
        case 3:
          printf("Enter A Value:\n");
          scanf("%d", & n);
          delet(p, n);
          break;
        case 4:
          count(p);
          break;
        case 5:
          display(p);
          break;
        }
      } while (c != 6);
      getch();
    }

    Algorithm for Singly Linked List Operations


Define a node structure with int data and struct node *link.
Global Pointer:

Initialize a global pointer p as NULL (head of the list).
Append Function (append(struct node *q, int num)):

If q is NULL, create the first node and assign it to p.
Otherwise, traverse to the end and append a new node with num.
Insert at Beginning (inbegin(struct node *q, int num)):

If q is NULL, print "List does not exist".
Otherwise, create a new node with num and set its link to p. Update p to this new node.
Delete Function (delet(struct node *q, int num)):

Traverse the list, keeping track of prev and curr.
If curr->data equals num, adjust pointers to delete the node.
Print status of deletion.
Count Function (count(struct node *q)):

If q is NULL, print "List does not exist".
Otherwise, count nodes by traversing until NULL and print the count.
Display Function (display(struct node *q)):

If q is NULL, print "List does not exist".
Otherwise, print each node's data until the end of the list.
Main Function:

Loop for user input to choose operations (1-6):
1: Call append().
2: Call inbegin().
3: Call delet().
4: Call count().
5: Call display().
Exit on 6.