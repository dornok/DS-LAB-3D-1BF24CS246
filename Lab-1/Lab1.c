#include<stdio.h>
#define max 10

int stack[max];
int top = -1;

void push()
{
	int x;
	printf("Enter data:");
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
		printf("Stack Underflow.\n");
	}
	else
	{
		value = stack[top];
		top--;
		printf("Poped Value:%d\n",value);
	}
}

void peek()
{
	if(top == -1)
	{
		printf("Stack Underflow.\n");
	}
	else
	{
		printf("Peek Value:%d\n",stack[top]);
	}
}
void display()
{
	int i;
	if(top == -1)
	{
		printf("Empty Stack.\n");
	}
	else
	{
		printf("\nStack Elements:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d",stack[i]);
		}
	}

}

void main()
{
	int choice;

	do
	{
		printf("\nEnter Choice:\n 1.Push\n 2.Pop\n 3.Peek\n 4.Display\n");
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

			default: printf("Invalid Choice!!!");
		}
	}
	while(choice!=0);
	getch();
}
