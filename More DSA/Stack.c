#include<stdio.h>

int arr[100];
int size=-1;
int isFull();
int isEmpty();
void push();
void pop();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\nSTACK MENU\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            return;
            break;
            default:
            printf("\n\nInvalid input\n\n");
            break;
        }
    }
}

int isEmpty()
{
    if(size==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(size==100)
        return 1;
    else
        return 0;
}

void push()
{
    int data;
    printf("Enter new element:");
    scanf("%d",&data);
    if(isFull())
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {
        size++;
    }
    arr[size]=data;
}

void pop()
{
    int x=0;
    if(isEmpty())
    {
        printf("\n\nStack Underflow!\n\n");
        return;
    }
    else
    {
        x=arr[size];
        size--;
        printf("\n\nElement popped is:%d\n\n",x);
    }
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("\n\nStack is empty!\n\n");
    }
    else
    {
        printf("\n\nThe stack is:\n\n");
        for(i=size;i>=0;i--)
        {
            printf("%d\n",arr[i]);
        }
    }
}