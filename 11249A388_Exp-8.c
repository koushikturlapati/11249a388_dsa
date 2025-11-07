#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insertBegin(int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Inserted %d at beginning\n", data);
}
void insertEnd(int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Inserted %d at end\n", data);
}
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty, deletion not possible\n");
        return;
    }
    struct node *temp = head;
    if (temp->next == NULL) {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("Deleted %d from end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}
void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    insertBegin(30);
    insertBegin(20);
    insertBegin(10);
    insertEnd(40);
    insertEnd(50);
    display();
    deleteBegin();
    deleteEnd();
    display();
    return 0;
}
