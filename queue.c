#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) return;
    if (front == -1) front++;
    queue[++rear] = val;
}

void dequeue() {
    if (front == -1 || front > rear) return;
    front++;
}

void display() {
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); display(); dequeue(); display();
}
