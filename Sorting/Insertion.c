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

    for(j=0;j<n-1;j++)
    {
        m=j+1;
        if(x[m]<x[m-1] && (m-1)>=0)
        {
            while(x[m]<x[m-1])
            {
                temp=x[m];
                x[m]=x[m-1];
                x[m-1]=temp;
                m--;
            }
        }
    }

    printf("Sorted elements:\n");
    for(k=0;k<n;k++)
    {
        printf("%d ",x[k]);
    }
}