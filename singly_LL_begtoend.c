#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

void insertAtBeg(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insertAtBeg(10); insertAtBeg(20); display(); deleteFromEnd(); display();
}
