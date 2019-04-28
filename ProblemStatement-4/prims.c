#include<stdio.h>

#include<stdlib.h>

#define infinity 9999
# define MAX 20
int prims(int *, int *, int);
int find_vertex(int, int *, int *, int *, int *, int *);
int find_vertex(int no_of_edges, int *cost, int *distance, int *from, int *visited, int *spanning) {
    int min_distance, u, v, n = no_of_edges + 1, i;
    int min_cost = 0; //cost of spanning tree
    while (no_of_edges > 0) {
        //find the vertex at minimum distance from the tree
        min_distance = infinity;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance) {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];
        //insert the edge in spanning tree
        *(spanning + u *n + v) = distance[v];
        *(spanning + v *n + u) = distance[v];
        no_of_edges--;
        visited[v] = 1;
        //updated the distance[] array
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && *(cost + i *n + v) < distance[i]) {
                distance[i] = *(cost + i *n + v);
                from[i] = v;
            }
        min_cost = min_cost + *(cost + u *n + v);
    }
    return min_cost;
}
int prims(int *G, int *spanning, int n) {
    int *cost = malloc(MAX *MAX);
    int min_distance, *distance = malloc(MAX), *from = malloc(MAX);
    int *visited = malloc(MAX), no_of_edges, i, min_cost, j;
    //create cost[][] matrix,spanning[][]
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if ( *(G + i *n + j) == 0)
                *(cost + i *n + j) = infinity;
            else
                *(cost + i *n + j) = *(G + i *n + j);
            *(spanning + i *n + j) = 0;
        }
    //initialise visited[],distance[] and from[]
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++) {
        distance[i] = *(cost + 0 *n + i);
        from[i] = 0;
        visited[i] = 0;
    }
    no_of_edges = n - 1; //no. of edges to be added
    return (find_vertex(no_of_edges, cost, distance, from, visited, spanning));
}
int main(void) {
    int *G = malloc(MAX *MAX), *spanning = malloc(MAX *MAX), n;
    int i, j, total_cost;
    printf("Enter no. of vertices:");
    scanf("%d", & n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", G + i*n + j);
    total_cost = prims(G, spanning, n);
    printf("\nspanning tree matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", *(spanning + i *n + j));
        printf("\n");
    }
    printf("Total cost of spanning tree=%d\n", total_cost);
    return 0;
}
