//Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

int queue[MAX];
int stack[MAX];
int front = -1, rear = -1;
int top = -1;

// enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

// dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// push
void push(int x) {
    stack[++top] = x;
}

// pop
int pop() {
    return stack[top--];
}

// display queue
void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// reverse queue using stack
void reverseQueue() {
    while (front <= rear) {
        push(dequeue());
    }

    while (top != -1) {
        enqueue(pop());
    }
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue:\n");
    display();

    reverseQueue();

    printf("Reversed Queue:\n");
    display();

    return 0;
}
