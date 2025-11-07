#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue() {
    if (front == NULL)
        printf("Queue Empty\n");
    else {
        struct Node *temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
}
void display() {
    struct Node *temp = front;
    if (!temp) printf("Queue Empty\n");
    else {
        printf("Queue: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
