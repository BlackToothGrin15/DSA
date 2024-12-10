#include<stdio.h>
void main()
{
    int m,i,j,k,x[100],n,temp;
    printf("Enter size:");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    for(j=1;j<n;j++)
    {
       temp=x[j];
       for(k=j;k>0 && temp<x[k-1];k--)
       {
            x[k]=x[k-1];     
       }
       x[k]=temp;
    }

    printf("Sorted elements:\n");
    for(k=0;k<n;k++)
    {
        printf("%d ",x[k]);
    }
}