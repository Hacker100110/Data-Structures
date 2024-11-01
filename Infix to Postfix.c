#include <stdio.h>
#include <ctype.h>
#define size 10

char a[size];
int top = -1;

void push(char p)
{
    if (top == size - 1)
    {
        printf("Stack Overflow!!");
    }
    else
    {
        top++;
        a[top] = p;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!!");
    }
    else
    {
        char ch = a[top];
        top--;
        return ch;
    }
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

void convert(char s[])
{
    int i = 0;
    int x;
    while (s[i] != '\0')
    {
        if (isalnum(s[i]))
            printf("%c ", s[i]);
        else if (s[i] == '(')
            push(s[i]);
        else if (s[i] == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (top != -1 && precedence(a[top]) >= precedence(s[i]))
                printf("%c ", pop());
            push(s[i]);
        }
        i++;
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }
}

int main()
{
    char s[size];
    printf("Enter infix expression:");
    scanf("%s", s);
    printf("The Postfix Expression is:");
    convert(s);
    return 0;
}

