#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return 1;
  } else {
    element = queue[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    }  else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\nFront -> Position %d ", front);
    printf("\nItems -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\nRear -> Position %d \n", rear);
  }
}

int peak() {
    if(isEmpty())
    printf(" \n Empty Queue\n");
    else{
        printf("\nPeak-->%d",queue[front]);
    }
}

int main(){
    int choice;
    int element;
    while(1){
        printf("\n\nMenu:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the number to be inserted in queue:");
            scanf("%d",&element);
            enQueue(element);
            break;
            case 2:
            deQueue(element);
            break;
            case 3:
            display();
            break;
            case 4:
            peak();
            break;
            case 5:
            printf("\nExiting Program!!");
            exit(0);
            default: printf("\nInvalid Option\n");  
            break;
        }
    }
}

