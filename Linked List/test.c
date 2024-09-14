#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*head;

void createList(int n);
void displayList();
void insertNode(int new);
void deleteNode(int dl);

void main()
{
    int n,new,dl,c;
    char ch='y';
    printf("How many nodes?:");
    scanf("%d",&n);

    createList(n);
    displayList();

    printf("\nOPERATIONS AVAILABLE:\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n\n");

    printf("Enter choice[1/2]:");
    scanf("%d",&c);

    if(c==1)
    {

        printf("\nAfter which node do you want to insert?:");
        scanf("%d",&new);
    
        insertNode(new);
        displayList();
    }
    else if(c==2)
    {

        printf("\nWhich node to delete?:");
        scanf("%d",&dl);

        deleteNode(dl);
        displayList();
    }
    else
    {
        printf("Invalid input\n");
    }
}

void createList(int n)
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
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("Enter data for node %d:",i);
        scanf("%d",&data);

        newnode->data=data;
        newnode->link=NULL;
        temp->link=newnode;
        temp=temp->link;
    }
}

void displayList()
{
    struct node *temp;
    int i;
    temp=head;
    printf("\nThe linked list is:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}

void insertNode(int new)
{
    struct node *freshnode, *temp;
    int i,dt;
    
    printf("\nCreating new node...\n");
    sleep(2);

    freshnode=(struct node*) malloc(sizeof(struct node));

    printf("Node created successfully\n");
    sleep(2);

    printf("Enter data for new node:");
    scanf("%d",&dt);

    printf("\nInserting node into the list...\n");
    sleep(2);

    freshnode->data=dt;

    temp=head;
    if(new==0)
    {
        freshnode->link=head;
        head=freshnode;
    }
    else
    {
        for(i=1;i<=new;i++)
        {
            if(i!=new)
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
    printf("Node inserted successfully\n");
    sleep(2);
}

void deleteNode(int dl)
{
    struct node *ptr1, *ptr2;
    int i;
    ptr1=head;
    ptr2=head->link;

    printf("\nDeleting node...\n");
    sleep(2);

    if(dl==1)
    {
        head=ptr2;
        ptr1->link=NULL;
        return;
    }
    else
    {
        ptr2=ptr2->link;
        ptr1=ptr1->link;
        for(i=2;i<=dl;i++)
        {
            if(i!=dl-1)
            {
                ptr2=ptr2->link;
                ptr1=ptr1->link;
            }
            else
            {
                ptr1->link=ptr2->link;
                ptr2->link=NULL;
            }
        }
    }
    printf("Node deleted successfully\n");
    sleep(1);
}