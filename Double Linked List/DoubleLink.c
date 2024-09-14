#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}*head;

void createList(int n);
void displayList();
void displayReverse();
void insert(int index, int n);
void delete(int dl,int n);

void main()
{
    int dl,n,index;
    printf("How many nodes?:");
    scanf("%d",&n);

    createList(n);
    displayList();
    displayReverse();

    printf("\nAfter which node do you want to insert?:");
    scanf("%d",&index);
    insert(index,n);
    n+=1;
    displayList();
    displayReverse();

    printf("\nWhich node do you want to delete?:");
    scanf("%d",&dl);
    delete(dl,n);
    displayList();
    displayReverse();
}

void createList(int n)
{
    struct node *newnode, *temp;
    int data,i;
    printf("Enter data for head node:");
    scanf("%d",&data);

    head=(struct node*) malloc(sizeof(struct node));

    head->data=data;
    head->llink=NULL;
    head->rlink=NULL;

    temp=head;

    for(i=2;i<=n;i++)
    {
        newnode=(struct node*) malloc(sizeof(struct node));
        printf("Enter data for node %d:",i);
        scanf("%d",&data);

        newnode->data=data;
        temp->rlink=newnode;
        newnode->llink=temp;
        temp=temp->rlink;
        newnode->rlink=NULL;
    }
}

void displayList()
{
    struct node *temp;
    temp=head;
    printf("\nThe double linked list:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->rlink;
    }
}

void displayReverse()
{
    struct node *temp;
    temp=head;
    while(temp->rlink!=NULL)
    {
        temp=temp->rlink;
    }
    printf("\nThe list in reverse order:\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->llink;
    }
}

void insert(int index, int n)
{
    struct node *freshnode, *temp;
    int data,i;
    printf("Enter data for node:");
    scanf("%d",&data);
    temp=head;

    freshnode=(struct node*) malloc(sizeof(struct node));
    freshnode->data=data;

    if(index==0)
    {
        
        freshnode->llink=NULL;
        freshnode->rlink=head;
        head->llink=freshnode;
        head=freshnode;
    }
    else if(index==n)
    {
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
        freshnode->rlink=NULL;
        temp->rlink=freshnode;
        freshnode->llink=temp;
    }
    else
    {
        for(i=1;i<=index;i++)
        {
            if(i!=index)
                temp=temp->rlink;
            else
            {
                freshnode->llink=temp;
                freshnode->rlink=temp->rlink;
                (temp->rlink)->llink=freshnode;
                temp->rlink=freshnode;
            }
        }
    }
}
void delete(int dl, int n)
{
    struct node *temp;
    int i;
    temp=head;
    if(dl==0)
    {
        head=temp->rlink;
        temp->rlink=NULL;
        head->llink=NULL;
    }
    else if(dl==n)
    {
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
        (temp->llink)->rlink=NULL;
        temp->llink=NULL;
    }
    else
    {
        for(i=1;i<=dl;i++)
        {
            if(i!=dl)
                temp=temp->rlink;
            else
            {
                (temp->llink)->rlink=temp->rlink;
                (temp->rlink)->llink=temp->llink;
                temp->rlink=NULL;
                temp->llink=NULL;
            }

        }
    }
}