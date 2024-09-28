#include<stdio.h>

int front=-1;
int rear=-1;
int arr[100];
int isFull();
int isEmpty();
void enqueue();
void dequeue();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\tMENU\t\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            return;
            break;
            default:
            printf("Invalid choice\n");
        }
    }
}

int isEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear==100-1)
        return 1;
    else
        return 0;
}

void enqueue()
{
    int data;
    printf("Enter new element:");
    scanf("%d",&data);
    if(isFull())
    {
        printf("Queue overflow!");
        return;
    }
    else if(isEmpty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    } 
    arr[rear]=data;
}

void dequeue()
{
    int x=0;
    if(isEmpty())
    {
        printf("Underflow!\n\n");
        return;
    }
    else if(front==rear)
    {
        x=arr[front];
        front=-1;
        rear=-1;
    }
    else
    {
        x=arr[front];
        front++;
    }
    printf("Element popped is:%d\n\n",x);
}

void display()
{
    
    int i;
    if(isEmpty())
    {
        printf("\n\nThe queue is empty!\n\n");
    }
    else
    {
        printf("\n\nThe queue is:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n\n");
    }
}