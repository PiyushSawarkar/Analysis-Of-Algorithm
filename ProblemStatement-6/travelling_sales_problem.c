typedef struct{int *a,*visited,*n,*cost;}tsp;
get(tsp *dt){
 int *i=malloc(4),*j=malloc(4);
 printf("Enter No. of Cities: ");
 scanf("%d",&*dt->n);
 printf("\nEnter Cost Matrix\n");
 for(*i=0;*i < *dt->n;(*i)++){
 for( *j=0;*j < *dt->n;(*j)++)
 scanf("%d",&*(dt->a+*i*(*dt->n)+*j));
 dt->visited[*i]=0;
 }
 printf("\nThe cost list is:\n");
 for( *i=0;*i < *dt->n;(*i)++){
 for(*j=0;*j < *dt->n;(*j)++)
 printf(" %d ",*(dt->a+*i*(*dt->n)+*j));
 printf("\n");
 }
}
int* least(tsp *dt,int *c){
 int *i=malloc(4),*nc=malloc(4);*nc=999;
 int *min=malloc(4),*kmin=malloc(4);*min=999;
 for(*i=0;*i < *dt->n;(*i)++)
 if((*(dt->a+*c*(*dt->n)+*i)!=0)&&(dt->visited[*i]==0))
 if(*(dt->a+*c*(*dt->n)+*i) < *min){
 *min=*(dt->a+*i*(*dt->n)+0)+*(dt->a+*c*(*dt->n)+*i);
 *kmin=*(dt->a+*c*(*dt->n)+*i);
 *nc=*i;
 }
 if(*min!=999)
 *dt->cost+=*kmin;
 return nc;
}
mincost(tsp *dt,int *city){
 int *ncity=malloc(4);
 dt->visited[*city]=1;
 printf("%d -->",*city);
 ncity=least(dt,city);
 if(*ncity==999){
 *ncity=0;
 printf("%d",*ncity);
 *dt->cost+=*(dt->a+*city*(*dt->n)+*ncity);
 return;
 }
 mincost(dt,ncity);
}
put(tsp *dt){
 printf("\nMinimum cost: %d\n",*dt->cost);
}
main(){
 tsp *dt=malloc(sizeof(tsp));
 dt->a=calloc(100,4);
 dt->visited=calloc(10,4);
 dt->n=calloc(1,4);
 dt->cost=calloc(1,4);
 get(dt);
 printf("The Path is:\n");
 int *zero_val=calloc(1,4);
 mincost(dt,zero_val);
 put(dt);
 free(dt);
}
