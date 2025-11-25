#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void createList(int n) {
    int value;
    if (n <= 0) return;
    printf("Enter value for node 1: ");
    scanf("%d", &value);
    head = createNode(value);
    struct Node* temp = head;
    for (int i = 2; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }
}
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAfterElement(int value, int element) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found!\n", element);
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertBeforeElement(int value, int element) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->data == element) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != element) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Element %d not found!\n", element);
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int lengthOfList() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    int choice, n, value, position, element;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n5. Insert After Element\n6. Insert Before Element\n7. Display List\n8. Length of List\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 5:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Insert after which element? ");
                scanf("%d", &element);
                insertAfterElement(value, element);
                break;
            case 6:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Insert before which element? ");
                scanf("%d", &element);
                insertBeforeElement(value, element);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Length of list = %d\n", lengthOfList());
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
