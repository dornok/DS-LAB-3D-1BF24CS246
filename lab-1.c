#include<stdio.h>
#define max 10

int stack[max];
int top = -1;

void push()
{
    int x;
    printf("Enter value:");
    scanf("%d",&x);

    if(top == max-1)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int value;
    if(top == -1)
    {
        printf("Empty Stack.(Underflow)\n");
    }
    else
    {
        value = stack[top];
        top--;
        printf("Poped value:%d\n",value);
    }
}
void peek()
{
    if(top == -1)
    {
        printf("empty stack.(Underflow)\n");
    }
    else
    {
        printf("Peeked value:%d\n",stack[top]);
    }
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("empty stack.(underflow)\n");
    }
    else
    {
        printf("Stack value:");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void main()
{
    int choice;
    do{
        printf("Enter choice:\n 1.push\n 2.Pop\n 3.peek\n 4.Display\n");
        scanf("%d",&choice);

        switch(choice)
            {
                case 1: push();
                break;

                case 2: pop();
                break;

                case 3: peek();
                break;

                case 4: display();
                break;

                case 0: printf("Exiting program\n");
                break;

                default: printf("Invalid Choice\n");

    }
    }
    while(choice!=0);
}
