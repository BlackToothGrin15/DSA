#include<stdio.h>

void main()
{
    int flag=0,x[100],ind,begin=0,last,i,j,n,mid;
    printf("Enter size of list:");
    scanf("%d",&n);

    printf("Enter elements(in order):\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    printf("Enter element to be searched:");
    scanf("%d",&ind);

    last=n-1;
    while(begin<=last)
    {
        mid=(begin+last)/2;
        if(x[mid]==ind)
        {
            flag=1;
            printf("Element found at position:%d",mid+1);
            break;
        }
        else if(ind>x[mid])
        {
            begin=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    if(flag==0)
    {
        printf("Element not found!");
    }
}