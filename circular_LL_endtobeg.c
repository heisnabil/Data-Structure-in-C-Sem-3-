#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteFromBeg() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (temp->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head) temp = temp->next;
    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    free(toDelete);
}

void display() {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    insertAtEnd(10); insertAtEnd(20); display(); deleteFromBeg(); display();
}
