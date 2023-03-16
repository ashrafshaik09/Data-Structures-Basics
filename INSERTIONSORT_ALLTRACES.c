#include<stdio.h>
void insertionsort(int [],int);
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	insertionsort(a,n);
    return 0;
}
void insertionsort(int a[100],int n)
{
	int i,element,j,p;
	for(i=1;i<n;i++)
	{
		element=a[i];
		j=i-1;
		while(j>=0 && a[j]>element)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=element;
		for(p=0;p<n;p++)
		{
			printf("%d\t",a[p]);
		}
		printf("\n");
	}
}
