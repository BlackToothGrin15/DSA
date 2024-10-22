#include<stdio.h>

void main()
{
    int j,i,x[100],n,ind,flag=0;
    printf("Enter number of elements:");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    printf("Enter number to be searched:");
    scanf("%d",&ind);

    for(j=0;j<n;j++)
    {
        if(x[j]==ind)
        {
            flag=1;
            printf("Element found at position:%d",j+1);
        }
    }
    if(flag==0)
    {
        printf("Element not found!");
    }
}