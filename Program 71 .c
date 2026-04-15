//Implement a hash table using quadratic probing with formula: h(k, i) = (h(k) + i*i) % m

#include <stdio.h>

#define SIZE 10

int table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }

    printf("Table full\n");
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;

        if (table[idx] == -1)
            return -1;

        if (table[idx] == key)
            return idx;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, table[i]);
}

int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    return 0;
}
