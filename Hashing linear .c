#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Define the structure for a hash table
struct HashTable {
    int keys[SIZE];
    int values[SIZE];
    int occupied[SIZE];
};

// Function to initialize the hash table
void initialize(struct HashTable *table) {
    for (int i = 0; i < SIZE; i++) {
        table->keys[i] = -1;  // -1 indicates an empty slot
        table->values[i] = -1;
        table->occupied[i] = 0;  // 0 indicates the slot is unoccupied
    }
}

// Hash function to calculate the index
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable *table, int key, int value) {
    int index = hash(key);

    while (table->occupied[index]) {
        index = (index + 1) % SIZE;
    }

    table->keys[index] = key;
    table->values[index] = value;
    table->occupied[index] = 1;
}

// Function to search for a value based on a given key
int search(struct HashTable *table, int key) {
    int index = hash(key);

    while (table->occupied[index]) {
        if (table->keys[index] == key) {
            return table->values[index];
        }
        index = (index + 1) % SIZE;
    }

    return -1; // Not found
}

int main() {
    struct HashTable table;
    initialize(&table);

    // Insert key-value pairs
    insert(&table, 10, 100);
    insert(&table, 20, 200);
    insert(&table, 30, 300);
    insert(&table, 40, 400);

    // Search for values
    int value1 = search(&table, 10);
    int value2 = search(&table, 30);
    int value3 = search(&table, 50);

    printf("Value for key 10: %d\n", value1); // Expected output: 100
    printf("Value for key 30: %d\n", value2); // Expected output: 300
    printf("Value for key 50: %d\n", value3); // Expected output: -1 (not found)

    return 0;
}
