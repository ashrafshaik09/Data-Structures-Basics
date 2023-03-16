#include<stdio.h>
void shellsort(int a[100],int n)
{
    int i,j,p,gap,temp;
    for(gap=n/2;gap>=1;gap=gap/2)
    {
        for(i=gap;i<n;i++)
        {
            for(j=i;j>=gap;j=j-gap)
            {
                if(a[j]<a[j-gap])
                {
                    temp=a[j];
                    a[j]=a[j-gap];
                    a[j-gap]=temp;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    	printf("%d\t",a[i]);
}
int main()
{
	int n,a[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	shellsort(a,n);
    return 0;
}
