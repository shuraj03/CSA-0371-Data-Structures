#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure for the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize a queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow: Cannot enqueue element %d\n", value);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow: Cannot dequeue element\n");
        return -1;
    }
    
    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    return value;
}

// Function to display the elements in the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    
    int current = queue->front;
    printf("Queue elements: ");
    
    while (current != queue->rear) {
        printf("%d ", queue->arr[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[current]);
}

int main() {
    struct Queue queue;
    initialize(&queue);
    
    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    
    // Display queue
    display(&queue);
    
    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    
    // Display queue after dequeue
    display(&queue);
    
    return 0;
}
