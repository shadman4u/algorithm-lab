//finding the max element of an array
#include<stdio.h>

int max(int a[],int n)
{
    int i,max_num;
    max_num=a[0];
    for(i=0;i<n;i++)
    {
        if(max_num<a[i])
        {
            max_num=a[i];
        }
    }
    return max_num;
}

int main()
{
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        printf("Element %d: ",i);
        scanf("%d",&a[i]);
    }
    int max_num=max(a,n);
    int count[max_num+1];
    for(i=0;i<=max_num;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(i=1;i<=max_num;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    int b[n];
    for(i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}