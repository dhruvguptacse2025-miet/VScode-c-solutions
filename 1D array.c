#include <stdio.h>

#define MAX_SIZE 100

// Function Prototypes
void traverse(int arr[], int size);
int insertion(int arr[], int size, int pos, int val);
int deletion(int arr[], int size, int pos);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, pos, val;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array Elements: ");
                traverse(arr, size);
                break;

            case 2:
                printf("Enter position to insert (1-%d): ", size + 1);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                size = insertion(arr, size, pos, val);
                if (size != -1) {
                    printf("Array after insertion: ");
                    traverse(arr, size);
                }
                break;

            case 3:
                printf("Enter position to delete (1-%d): ", size);
                scanf("%d", &pos);
                size = deletion(arr, size, pos);
                if (size != -1) {
                    printf("Array after deletion: ");
                    traverse(arr, size);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Traversal: Print all elements
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion: Insert val at pos (1-based index)
int insertion(int arr[], int size, int pos, int val) {
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return size;
    }
    if (size >= MAX_SIZE) {
        printf("Array is full!\n");
        return size;
    }

    // Shift elements to the right
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    return size + 1;
}

// Deletion: Delete element at pos (1-based index)
int deletion(int arr[], int size, int pos) {
    if (pos < 1 || pos > size) {
        printf("Invalid position!\n");
        return size;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}   