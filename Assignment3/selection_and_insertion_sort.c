#include<stdio.h>
#define MAX 200
int n,m;//global variables
int c[MAX];
void selection_sort(int *b);
void insertion_sort(int *a);
int* bubble_sort(int *b,int *a);
void swap(int *x,int *y){
int t;
t=*x;
*x=*y;
*y=t;
}
void print_array(int *d){
int i;
printf("\n");
for(i=0;i<n+m;i++){
printf("%d ",d[i]);
}
printf("\n");
}
void selection_sort(int *b){
//m
int i,j,pos;
printf("\nEnter number of elements for first
half = ");
scanf("%d",&m);
printf("\nEnter elements for First half array
:\n");
for(i=0;i<m;i++){
scanf("%d",&b[i]);
// printf("\n%d",b[i]);
}
for(i=0;i<m-1;i++){
pos=i;
for(j=i+1;j<m;j++){
if(b[pos]>b[j]){
pos=j;
}
}
if(pos!=i){ //That means pos has changed
swap(&b[pos],&b[i]);
}
}
}
void insertion_sort(int *a){
//n
int i,j;
printf("\nEnter number of elements = ");
scanf("%d",&n);
printf("\nEnter elements for Second array
:\n");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=1;i<=n-1;i++){
j=i;
while(j>0 && a[j-1]>a[j]){
swap(&a[j],&a[j-1]);
j--;
}
}
}
int* bubble_sort(int *b,int *a){
int i,j,k=0;
for(i=0;i<m;i++){
c[k++]=b[i];
}
for(i=0;i<n;i++){
c[k++]=a[i];
}
for(i=0;i<n+m-1;i++){
for(j=0;j<n+m-1-i;j++){
if(c[j]>c[j+1]){
swap(&c[j],&c[j+1]);
}
}
}
return(c);
}
int main(void){
int a[100],b[100],*ans,i;
selection_sort(b);
insertion_sort(a);
ans=bubble_sort(b,a);
printf("\nThe Sorted Array is : \n");
print_array(ans);
return(0);
}
