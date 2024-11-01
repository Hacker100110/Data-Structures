#include<stdio.h>
#include<stdlib.h>
#define size 5

int b[size];
int front=-1,rear=-1;

int isFull(){
    if (rear == size-1)
    return 1;
    else
    return 0;
}

int isEmpty(){
    if(front==-1 || front>rear)
    return 1;
    else
    return 0;   
}

void enqueue(int item)
{
    if (isFull())
    printf("\n Queue Full");
    else{
        if(front == -1)
        front = 0;
        b[++rear]= item;
    }
}

void dequeue(){
    if (isEmpty())
    printf("\n Queue Empty");
    else{
        printf("Deleting  %d",b[front]);
        front++;
    }
}

int display(){
    int i;
    for(i=front;i<=rear;i++){
        printf("The element is:  %d\n",b[i]);
    }
}



int main(){
    int choice;
    int item;
    while(1){
        printf("\n\n Menu:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter bill details(Name,ID,Qty,Price):");
            scanf(" %d",&item);
            enqueue(item);
            break;
        case 2:
        dequeue(item);
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        break;
        }
    }
}

