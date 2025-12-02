#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void createList() {
    int n, i, data;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Data: ");
        scanf("%d", &data);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void insertLeft() {
    int data, key;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    printf("Enter the key value to insert to left: ");
    scanf("%d", &key);
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found BHai\n");
        free(newNode);
        return;
    }

    newNode->data = data;

    if (temp == head) {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void deleteByValue() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp == head && temp == tail) {
        head = tail = NULL;
    } else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    } else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n---- LINKED LIST MENU -----\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert Left of Node\n");
        printf("3. Delete by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList();
                    break;
            case 2: insertLeft();
                    break;
            case 3: deleteByValue();
                    break;
            case 4: displayList();
                    break;
            case 5: printf("Program End\n");
                    exit(0);
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}
