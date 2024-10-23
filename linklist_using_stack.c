#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void display() {
    struct Node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    push(10); push(20); push(30); display(); pop(); display();
}
