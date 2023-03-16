#include<stdio.h> 
void merge_sort(int, int);
void merge_array(int, int, int, int);
int arr[100];
int main()
{
	int i,n;
 	printf("\nEnter number of Elements:\n");
 	scanf("%d",&n);
 	printf("Enter Elements:");
 	for (i = 0; i < n; i++)
 		scanf("%d", &arr[i]);
 	merge_sort(0, n- 1);
 	printf("\nSorted Data :");
 	for (i = 0; i <n; i++) {
		printf("%d\t", arr[i]);
  	}
}
void merge_sort(int l, int h) {
  int m;
  if (l < h) {
    m = (l + h) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, h);
    merge_array(l, m, m + 1, h); // Merging two arrays
  }
}
void merge_array(int a, int b, int c, int d) {
  int t[100];
  int i = a, j = c, k = 0;
  while (i <= b && j <= d) {
    if (arr[i] < arr[j])
      t[k++] = arr[i++];
    else
      t[k++] = arr[j++];
  }
  //collect remaining elements
  while (i <= b)
    t[k++] = arr[i++];
  while (j <= d)
    t[k++] = arr[j++];
//copy elements to the original array
  for (i = a,j = 0; i <= d; i++,j++)
	arr[i]=t[j];
}