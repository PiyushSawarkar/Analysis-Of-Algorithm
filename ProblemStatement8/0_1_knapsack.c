max(int a, int b) {
 return (a > b)? a : b;
}
knapSack(int *W, int *wt, int *val, int *n){
 int *i=malloc(4), *w=malloc(4);
 int K[*n+1][*W+1];
 for (*i = 0; *i <= *n; *i+=1)
 for (*w = 0; *w <= *W; *w+=1){
 if (*i==0 || *w==0)
 K[*i][*w] = 0;
 else if (wt[*i-1] <= *w)
 K[*i][*w] = max(val[*i-1] + K[*i-1][*w-wt[*i-1]], K[*i1][*w]);
 else
 K[*i][*w] = K[*i-1][*w];
 }
 return K[*n][*W];
}
main(){
 int *i=malloc(4), *n=malloc(4), *val=malloc(20*sizeof(int)),
*wt=malloc(20*sizeof(int))
 , *W=malloc(4);
 printf("\nEnter number of items = ");
 scanf("%d", &*n);
 printf("Enter value and weight of items:\n");
 for(*i = 0;*i < *n; (*i)++)
 scanf("%d%d", &val[*i], &wt[*i]);
 printf("Enter size of knapsack:");
 scanf("%d", &*W);
 printf("%d", knapSack(W, wt, val, n));
 return 0;
}
