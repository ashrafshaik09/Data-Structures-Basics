#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_first(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

void insert_last(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_middle(struct Node** head, int data, int pos) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* temp = *head;
    int i = 1;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void delete_first(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void delete_last(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delete_middle(struct Node** head, int pos) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    int i;
    for (i = 1; i <= pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}


void display_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
struct Node* head = NULL;
int choice, data, position;
while (1) {
    printf("Enter 1 to insert an element at the beginning\n");
    printf("Enter 2 to insert an element at the end\n");
    printf("Enter 3 to insert an element at a specific position\n");
    printf("Enter 4 to delete an element from the beginning\n");
    printf("Enter 5 to delete an element from the end\n");
    printf("Enter 6 to delete an element from a specific position\n");
    printf("Enter 7 to display all elements\n");
    printf("Enter 8 to exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_first(&head, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_last(&head, data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_middle(&head, data, position);
            break;
        case 4:
            delete_first(&head);
            break;
        case 5:
            delete_last(&head);
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &position);
            delete_middle(&head, position);
            break;
        case 7:
            display_list(head);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

return 0;
}