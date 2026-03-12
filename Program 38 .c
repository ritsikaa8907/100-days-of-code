//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX-1;
    else
        front--;

    deque[front] = x;
}

void push_back(int x)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (rear == -1)
        front = rear = 0;
    else if (rear == MAX-1)
        rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX-1)
        front = 0;
    else
        front++;
}

void pop_back()
{
    if (rear == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX-1;
    else
        rear--;
}

void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}
