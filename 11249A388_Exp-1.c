#include <stdio.h>
int main() {
    int arr[100], n, choice, i, pos, element;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\n----- Array Operations Menu -----\n");
        printf("1. Display\n");
        printf("2. Search\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Array elements are: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &element);
                int found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == element) {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("Element not found!\n");
                break;
            case 3:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                } else {
                    for (i = n; i >= pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos - 1] = element;
                    n++;
                    printf("Element inserted successfully!\n");
                }
                break;
            case 4:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    element = arr[pos - 1];
                    for (i = pos - 1; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                    printf("Deleted element: %d\n", element);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
