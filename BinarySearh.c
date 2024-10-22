#include <stdio.h>

int main() {
    int a[100], n, key, low, mid, high, i, chk = 0;
    printf("How Many Elements:\n");
    scanf("%d", &n);
    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("Enter Element %d:\n", (i + 1));
        scanf("%d", &a[i]);
    }
    printf("Enter The Element To Be Searched:\n");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("Value Found At Position %d\n", (mid + 1));
            chk = 1;
            break;
        }
        if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (chk == 0)
        printf("Value Not Found\n");
    return 0;
}

