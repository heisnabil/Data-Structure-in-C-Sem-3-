#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) return;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); display(); dequeue(); display();
}
