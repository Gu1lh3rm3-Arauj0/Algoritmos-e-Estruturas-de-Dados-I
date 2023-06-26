#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insertKey(Node** hashTable, int key, int position) {
    Node* newNode = createNode(key);

    if (hashTable[position] == NULL) {
        hashTable[position] = newNode;
    } else {
        Node* current = hashTable[position];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printHashTable(Node** hashTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        printf("%d -> ", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("\\\n");
    }
}

void freeHashTable(Node** hashTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(hashTable);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, C;
        scanf("%d %d", &M, &C);

        Node** hashTable = (Node**)malloc(M * sizeof(Node*));
        for (int i = 0; i < M; i++) {
            hashTable[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int position = key % M;
            insertKey(hashTable, key, position);
        }

        printHashTable(hashTable, M);
        freeHashTable(hashTable, M);

        if (T > 0) {
            printf("\n");
        }
    }

    return 0;
}
