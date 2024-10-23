#include<stdio.h>
void main()
{
    int m,pos,temp,x[100],n,i,j,k,min;
    printf("Enter size:");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    for(j=0;j<n;j++)
    {
        pos=j;
        for(k=j+1;k<n;k++)
        {
            if(x[k]<x[pos])
            {
                pos=k;
            }
        }
        temp=x[j];
        x[j]=x[pos];
        x[pos]=temp;
    }

    printf("Sorted list:\n");
    for(m=0;m<n;m++)
    {
        printf("%d ",x[m]);
    }
    
}