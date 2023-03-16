#include<stdio.h>
#include<stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

struct Node* head;

void reverse() {
   struct Node *current, *prev, *next;
   current = head;
   prev = NULL;

   while(current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   head = prev;
}

void insert(int value) {
   struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
   temp->data = value;
   temp->next = head;
   head = temp;
}

void print() {
   struct Node* temp = head;
   printf("List is: ");
   while(temp != NULL) {
      printf("%d ",temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main() {
   head = NULL;
   int n, i, x;
   printf("Enter number of elements: ");
   scanf("%d",&n);
   for(i=0; i<n; i++) {
      printf("Enter element %d: ",i+1);
      scanf("%d",&x);
      insert(x);
      print();
   }
   reverse();
   printf("Reversed ");
   print();
   return 0;
}
