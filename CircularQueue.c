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


Circular Queue Algorithm (Sorted)
Initialize:

Create an array queue[SIZE].
Set front (f) and rear (r) to -1.
Check if Empty:

Return 1 if f == -1, else return 0.
Check if Full:

Return 1 if f == 0 && r == SIZE - 1 or f == r + 1, else return 0.
Insert:

If full, print "Circular Queue Overflow".
If empty, set f = r = 0, insert the element.
If r reaches end, wrap around (r = 0).
Otherwise, increment r and insert.
Delete:

If empty, print "Circular Queue Empty".
If f == r, reset (f = r = -1).
If f reaches end, wrap around (f = 0).
Otherwise, increment f.
Display:

If empty, print "Circular Queue Empty".
If f <= r, print from f to r.
If f > r, print from f to end and from start to r.
Main Loop:

Present menu for insert, delete, display, or exit.
Loop until exit choice is made.