#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*head;

void createCircList(int n);
void displayList(int n);
void insert(int index, int n);
void delete(int dl);

void main()
{
    int dl,n,index;
    printf("How many nodes?:");
    scanf("%d",&n);

    createCircList(n);
    displayList(n);

    printf("\nAfter which node to insert[starting at head node]:");
    scanf("%d",&index);
    insert(index,n);
    n+=1;
    displayList(n);

    printf("\nWhich node to delete?:");
    scanf("%d",&dl);
    delete(dl);
    n-=1;
    displayList(n);
}

void createCircList(int n)
{
    struct node *newnode, *temp;
    int data,i;
    head=(struct node*) malloc(sizeof(struct node));

    printf("Enter data for head node:");
    scanf("%d",&data);

    head->data=data;
    head->link=NULL;

    temp=head;
    for(i=2;i<=n;i++)
    {
        printf("Enter data for node %d:",i);
        scanf("%d",&data);

        newnode=(struct node*) malloc(sizeof(struct node));
        
        newnode->data=data;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }
    newnode->link=head;
}

void displayList(int n)
{
    struct node *temp;
    int i=1;
    temp=head;
    printf("\nThe circular linked list is:\n");
    while(i<=n)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
        i++;
    }
}
void insert(int index, int n)
{
    struct node *freshnode, *temp;
    int data,i;
    freshnode=(struct node*) malloc(sizeof(struct node));
    printf("Enter data for new node:");
    scanf("%d",&data);

    freshnode->data=data;

    temp=head->link;
    if(index==0 || index==n)
    {
        while(temp->link!=head)
        {
            temp=temp->link;
        }
        temp->link=freshnode;
        freshnode->link=head;
        head=freshnode;
    }
    else
    {
        for(i=1;i<=index;i++)
        {
            if(i!=index-1)
            {
                temp=temp->link;
            }
            else
            {
                freshnode->link=temp->link;
                temp->link=freshnode;
            }
        }
    }
}
void delete(int dl)
{
    struct node *ptr1, *ptr2;
    int i;
    ptr1=head;
    ptr2=head->link;
    if(dl==0)
    {
        while(ptr2->link!=head)
        {
            ptr2=ptr2->link;
        }
        ptr2->link=head->link;
        head->link=NULL;
        head=ptr2->link;
    }
    else
    {
        for(i=1;i<dl;i++)
        {
            if(i!=dl-1)
            {
                ptr1=ptr1->link;
                ptr2=ptr2->link;
            }
            else
            {
                ptr1->link=ptr2->link;
                ptr2->link=NULL;
            }
        }
    }
}