#include <stdio.h>
#include <ctype.h>

#define MAX 100

float st[MAX];
int top = -1;
void push(float st[], float val);
float pop(float st[]);
float eval(char exp[]);

int main()
{
    float val;
    char exp[100];

    printf("\n Enter any postfix expression : ");
    gets(exp);

    val = eval(exp);

    printf("\n Value of the postfix expression = %.2f", val);

    return 0;
}


float eval(char exp[])
{
    int i = 0;
    float a, b, value;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
            push(st, (float)(exp[i] - '0'));
        else
        {
            a = pop(st);
            b = pop(st);

            switch (exp[i])
            {
                case '+':
                    value = b + a;
                    break;
                case '-':
                    value = b - a;
                    break;
                case '/':
                    value = b / a;
                    break;
                case '*':
                    value = b * a;
                    break;
                case '%':
                    value = (int)b % (int)a;
                    break;
            }

            push(st, value);
        }
        i++;
    }

    return pop(st);
}

void push(float st[], float val)
{
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW");
    else
    {
        top++;
        st[top] = val;
    }
}

float pop(float st[])
{
    float val = -1;
    if (top == -1)
        printf("\n STACK UNDERFLOW");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}



