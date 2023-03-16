#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void create_list(struct Node** head, int n) {
    struct Node* new_node = NULL;
    struct Node* temp = *head;

    for (int i = 1; i <= n; i++) {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ", i);
        scanf("%d", &(new_node->data));
        new_node->prev = temp;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
        } else {
            temp->next = new_node;
        }

        temp = new_node;
    }
}

void sort_list(struct Node** head) 
{
    struct Node* temp1 = *head;
    struct Node* temp2 = NULL;

    while (temp1->next != NULL) 
	{
        temp2 = temp1->next;

        while (temp2 != NULL) 
		{
            if (temp1->data > temp2->data) 
			{
                int temp_data = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp_data;
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }
}

struct Node* search_list(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    return temp;
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
    int choice, n, data, key;
    struct Node* search_node = NULL;

    while (1) {
        printf("Enter 1 to create list with N elements\n");
        printf("Enter 2 to sort the list in ascending order\n");
        printf("Enter 3 to search an element in the list\n");
        printf("Enter 4 to display the list\n");
        printf("Enter 5 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to create: ");
                scanf("%d", &n);
                create_list(&head, n);
                break;
            case 2:
                sort_list(&head);
                printf("List sorted in ascending order.\n");
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search_node = search_list(head, key);

                if (search_node != NULL) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 4:
                display_list(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
