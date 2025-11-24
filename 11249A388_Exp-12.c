#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash table full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[(index + i) % SIZE] = key;
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> Empty\n", i);
    }
}
int main() {
    int n, key;
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of keys to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
