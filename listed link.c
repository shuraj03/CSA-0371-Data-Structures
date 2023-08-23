#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node* deleteNode(struct Node *head, int value) {
    if (head == NULL) {
        return head;
    }
    
    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node *current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    
    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    
    // Insert nodes
    head = insertAtBeginning(head, 3);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 7);
    head = insertAtBeginning(head, 1);
    
    // Display linked list
    printf("Linked list: ");
    display(head);
    
    // Delete node
    head = deleteNode(head, 5);
    
    // Display linked list after deletion
    printf("Linked list after deletion: ");
    display(head);
    
    return 0;
}
