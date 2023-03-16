#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = *head;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_element(struct Node** head, int key) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == *head && (*head)->data == key) {
        struct Node* temp = *head;
        *head = NULL;
        free(temp);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->data == key) {
        struct Node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

void display_list(struct Node* head) {
    struct Node* temp = head;
    while (temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to delete an element\n");
        printf("Enter 3 to display all elements\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                delete_element(&head, data);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

