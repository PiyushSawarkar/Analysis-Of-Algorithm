find(int *i, int *parent) {
    while (parent[ *i]) {
        *i = parent[ *i];
    }
    return *i;
}
uni(int *i, int *j, int *parent) {
    if ( *i != *j) {
        parent[ *j] = *i;
        return 1;
    }
    return 0;
}
int *get_cost_mat(int *n) {
    int *cost = malloc(( *n + 1) *( *n + 1) *4);
    int *i = malloc(4), *j = malloc(4);
    printf("\nEnter Elements :\n");
    for ( *i = 1;*i <= *n;( *i) ++) {
        for ( *j = 1;*j <= *n;( *j) ++) {
            scanf("%d", & *(cost + ( *i) *( *n) + ( *j)));
            if ( *(cost + ( *i) *( *n) + ( *j)) == 0) {
                *(cost + ( *i) *( *n) + ( *j)) = 999;
            }
        }
    }
    return cost;
}
do_calculation(int *cost, int *n) {
    int *i = malloc(4),
        *j = malloc(4),
        *k = malloc(4),
        *a = malloc(4),
        *b = malloc(4),
        *u = malloc(4),
        *v = malloc(4),
        *ne = malloc(4);
    int *min = malloc(4), *mincost = malloc(4);
    int *parent = calloc(( *n + 1), 4);
    *ne = 1;
    *mincost = 0;
    while ( *ne < *n) {
        for ( *i = 1, *min = 999;*i <= *n;( *i) ++) {
            for ( *j = 1;*j <= *n;( *j) ++) {
                if ( *(cost + ( *i) *( *n) + ( *j)) < *min) {
                    *min = *(cost + ( *i) *( *n) + ( *j));
                    *a = *u = *i;
                    *b = *v = *j;
                }
            }
        }
        *u = find(u, parent);
        *v = find(v, parent);
        if (uni(u, v, parent)) {
            ( *ne) ++;
            ( *mincost) += ( *min);
        }
        *(cost + ( *a) *( *n) + ( *b)) = *(cost + ( *b) *( *n) + ( *a)) = 999;
    }
    return *mincost;
}
print_result(int val) {
    printf("\nThe min is : %d ", val);
}
kruskal(int *n) {
    print_result(do_calculation(get_cost_mat(n), n));
}
main() {
    int *n = malloc(4);
    printf("\nEnter the no. of vertices = ");
    scanf("%d", &*n);
    kruskal(n);
}
