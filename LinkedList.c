#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning();
void insert_at_end();
void delete_node();
void search_node();
void display_list();

void main() {
    int choice;

    do {
        printf("\n********* Linked List Menu *********\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_at_beginning(); break;
            case 2: insert_at_end(); break;
            case 3: delete_node(); break;
            case 4: search_node(); break;
            case 5: display_list(); break;
            case 6: exit(0); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
}

void insert_at_beginning() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    printf("Node inserted at the beginning.\n");
}

void insert_at_end() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Node inserted at the end.\n");
}

void delete_node() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void search_node() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);

    struct node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Node with value %d found at position %d.\n", value, position + 1);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with value %d not found.\n", value);
}

void display_list() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


Algorithm for Linked List Operations
Initialize List:

Set head = NULL.
Insert at Beginning:

Allocate memory for a new node.
Set data of the new node from user input.
Set new_node->next to head.
Update head to new_node.
Insert at End:

Allocate memory for a new node.
Set data from user input and new_node->next = NULL.
If list is empty (head == NULL), set head = new_node.
Otherwise, traverse to the last node and set last_node->next = new_node.
Delete Node:

If list is empty, print error.
Get value to delete from user.
Traverse the list to find the node.
Adjust pointers to remove the node and free memory.
Search Node:

If list is empty, print error.
Get value to search from user.
Traverse the list to find the node.
Print position if found; otherwise, print not found message.
Display List:

If list is empty, print error.
Traverse the list and print each node’s value, ending with NULL.
Main Process:

Provide menu options for user actions.
Execute corresponding operations based on user choice.