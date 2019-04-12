#include<stdio.h>
void merge_sort(int a[],int l,int r);//l=left,r=right
void merge_array(int a[],int l,int m,int r);//m=mid
void merge_sort(int a[],int l,int r){
	int m;
	if(l<r){
		m=(l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge_array(a,l,m,r);
	}
}
void merge_array(int a[],int l,int m,int r){
	int i,j,k,b[100];
	for(i=l;i<=r;i++){
		b[i]=a[i];
	}
	i=l;
	j=m+1;
	k=l;
	while((i<=m)&&(j<=r)) {
		if(b[i]<=b[j]){
			a[k]=b[i];
			i++;
			k++;
		}
		else  {
			a[k]=b[j];
			j++;
			k++;
		}
	}
	if(i<=m){
		while(i<=m) {
			a[k]=b[i];
			i++;
			k++;
		}
	}
	else {
		while(j<=r){
			a[k]=b[j];
			j++;
			k++;
		}
	}
}
int main(void){
	int a[100],n,i;
	printf("\nEnter size of an array= ");
	scanf("%d",&n);
	printf("\nEnter elements of an array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nElements before sorting are:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}	
	merge_sort(a,0,n-1);
	printf("\nAfter sorting Elements are:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return(0);
}
/*		Output Of Program
piyush@17102021:~/aoa$ gcc merge_sort.c -o 17102021
piyush@17102021:~/aoa$ ./17102021

Enter size of an array= 5

Enter elements of an array:
62
61
60
59
58

Elements before sorting are:
62 61 60 59 58 
After sorting Elements are:
58 59 60 61 62 piyush@17102021:~/aoa$ 

*/
