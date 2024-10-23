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

    for(j=0;j<n;j++)
    {
        for(k=0;k<n-j-1;k++)
        {
            if(x[k]>x[k+1])
            {
                temp=x[k];
                x[k]=x[k+1];
                x[k+1]=temp;
            }
        }
    }
    printf("Sorted list:\n");
    for(m=0;m<n;m++)
    {
        printf("%d ",x[m]);
    }
}