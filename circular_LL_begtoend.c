#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

void insertAtBeg(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void deleteFromEnd() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (temp->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != head) temp = temp->next;
    free(temp->next);
    temp->next = head;
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
    insertAtBeg(10); insertAtBeg(20); display(); deleteFromEnd(); display();
}
