#include <stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1, itemCount = 0;

void enqueue(int data) {
  if(itemCount >= MAX) {
    printf("Queue is full\n");
    return;
  }

  rear = (rear + 1) % MAX;
  queue[rear] = data;
  itemCount++;
}

void dequeue() {
  if(itemCount == 0) {
    printf("Queue is empty\n");
    return;
  }

  front = (front + 1) % MAX;
  itemCount--;
}

void display() {
  if(itemCount == 0) {
    printf("Queue is empty\n");
    return;
  }

  int i;
  for(i = front; i != rear; i = (i + 1) % MAX) {
    printf("%d ", queue[i]);
  }
  printf("%d\n", queue[i]);
}

int main() {
  int data, choice;
  
  while(1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Enter the data to be enqueued: ");
        scanf("%d", &data);
        enqueue(data);
        break;
        
      case 2:
        dequeue();
        break;
        
      case 3:
        display();
        break;
        
      case 4:
        exit(0);
    }
  }
  
  return 0;
}

