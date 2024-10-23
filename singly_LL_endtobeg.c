#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *head = NULL;

void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeg() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insertAtEnd(10); insertAtEnd(20); display(); deleteFromBeg(); display();
}
