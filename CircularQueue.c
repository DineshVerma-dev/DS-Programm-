#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int f = -1;
int r = -1;

int empty() {
    if (f == -1)
        return 1;
    else
        return 0;
}

int full() {
    if ((f == 0 && r == SIZE - 1) || (f == r + 1))
        return 1;
    else
        return 0;
}

void insert(int x) {
    if (full() == 1) {
        printf("Circular Queue Overflow\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        queue[r] = x;
    } else if (r == SIZE - 1 && f != 0) {
        r = 0;
        queue[r] = x;
    } else {
        r++;
        queue[r] = x;
    }
}

void delet() {
    if (empty() == 1) {
        printf("Circular Queue Empty\n");
    } else if (f == r) {
        f = r = -1;
    } else if (f == SIZE - 1) {
        f = 0;
    } else {
        f++;
    }
}

void display() {
    int i;
    if (empty() == 1) {
        printf("Circular Queue Empty\n");
    } else if (f <= r) {
        printf("Contents:\n");
        for (i = f; i <= r; i++) {
            printf("%d\n", queue[i]);
        }
    } else {
        printf("Contents:\n");
        for (i = f; i < SIZE; i++) {
            printf("%d\n", queue[i]);
        }
        for (i = 0; i <= r; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int x, c;
    do {
        printf("Enter Your Choice:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("Enter an Element:\n");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        }
    } while (c != 4);
    return 0;
}
