#include<stdio.h>
void bubblesort(int [],int);
int main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	bubblesort(a,n);
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
void bubblesort(int a[100],int n)
{
    int i,p,t;
    for(p=1;p<n;p++)
    {
        for(i=0;i<n-p;i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
}
