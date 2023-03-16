#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char ename[50];
    int eno;
    float salary;
    struct employee* next;
};

struct employee* head = NULL;

void insert_employee() {
    struct employee* new_employee = (struct employee*)malloc(sizeof(struct employee));
    printf("Enter employee name: ");
    scanf("%s", new_employee->ename);
    printf("Enter employee number: ");
    scanf("%d", &new_employee->eno);
    printf("Enter employee salary: ");
    scanf("%f", &new_employee->salary);
    new_employee->next = head;
    head = new_employee;
    printf("Employee added successfully.\n");
}

void increase_salary() {
    int eno;
    printf("Enter employee number: ");
    scanf("%d", &eno);
    struct employee* current = head;
    while (current != NULL) {
        if (current->eno == eno) {
            current->salary *= 1.1;
            printf("Salary increased by 10%% for employee %s (Employee Number: %d).\n", current->ename, current->eno);
            return;
        }
        current = current->next;
    }
    printf("Employee with Employee Number %d not found.\n", eno);
}

void search_employee() {
    char ename[50];
    printf("Enter employee name: ");
    scanf("%s", ename);
    struct employee* current = head;
    while (current != NULL) {
        if (strcmp(current->ename, ename) == 0) {
            printf("Employee details for %s:\nEmployee Name: %s\nEmployee Number: %d\nEmployee Salary: %.2f\n", ename, current->ename, current->eno, current->salary);
            return;
        }
        current = current->next;
    }
    printf("Employee with name %s not found.\n", ename);
}

int main() {
    int choice;
    while (1) {
        printf("Choose an option:\n1. Add employee\n2. Increase salary\n3. Search employee\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_employee();
                break;
            case 2:
                increase_salary();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}