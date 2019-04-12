#include<stdio.h>
#include<stdlib.h>
float *weight=NULL;
float *profit=NULL;//since initialization outside the function(i.e for
GLOBAL) not allowed;
void swap(float *x,float *y){
float t;
t=*x;
*x=*y;
*y=t;
}
void print_array(float *x,int n){
printf("\n");
for(int i=0;i<n;i++)
printf("%f ",x[i]);
printf("\n");
}
void quicksort(float *x,int first,int last){
int pivot,i,j;
float t;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(x[i]>=x[pivot]&&i<last)
i++;
while(x[j]<x[pivot])
j--;
if(i<j){
swap(&x[i],&x[j]);
swap(&weight[i],&weight[j]);
swap(&profit[i],&profit[j]);
}
}
swap(&x[pivot],&x[j]);
swap(&weight[pivot],&weight[j]);
swap(&profit[pivot],&profit[j]);
quicksort(x,first,j-1);
quicksort(x,j+1,last);
}
}
void knapsack(int n,float capacity){
float *x=(float*)malloc(20*sizeof(float)), tp = 0;
int i, j, u;
u=capacity;
for (i=0;i<n;i++)
 x[i]=0.0;
for (i=0;i<n;i++)
 if(weight[i]>u)
 break;
 else {
 x[i]=1.0;
 tp=tp+profit[i];
 u=u-weight[i];
 }
if(i<n)
 x[i]=u/weight[i];
tp=tp+(x[i]*profit[i]);
printf("\nThe result vector is:");
 print_array(x,n);
printf("\nMaximum profit is = %f\n",tp);
}
int main(void){
float capacity,*ratio=(float*)malloc(sizeof(float)*20),temp;
weight=(float*)malloc(20*sizeof(float));
profit=(float*)malloc(20*sizeof(float));
 int n;
 printf("\nEnter the no. of objects = ");
 scanf("%d", &n);
printf("Enter the wts and profits of each object:\n");
 for (int i=0;i<n;i++)
 scanf("%f%f",&weight[i],&profit[i]);
printf("\nEnter the capacity of knapsack = ");
 scanf("%f",&capacity);
for (int i=0;i<n;i++)
 ratio[i]=profit[i]/weight[i];
quicksort(ratio,0,n-1);
 knapsack(n,capacity);
 return(0);
}
/*
OUTPUT:
piyush@17102021:~$ gcc knapsack.c -o 17102021
piyush@17102021:~$ ./17102021
Enter the no. of objects = 3
Enter the wts and profits of each object:
10 60
20 100
30 120
Enter the capacity of knapsack = 50
The result vector is:
1.000000 1.000000 0.666667
Maximum profit is = 240.000000
piyush@17102021:~$
*/
