 #include <stdio.h>
#include <stdlib.h>

#define size 5

int b[size];
int top = -1;

void push(int item)
{
    if (top == size - 1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        top++;
        b[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n Stack Underflow");
    }
    else
    {
    
        top--;
    }

}

void peek()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
     printf("%d\n", b[top]);
    }
	
}

void display()
{
    int i;
    for (i = top; i > -1; i--)
    {
        printf("%d\n", b[i]);
    }
}

int main()
{
    int choice;
    int item;

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter box details: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid choice ");
            break;
        }
    }
}

