typedef struct {
    int *i, *n, *j, *temp, *x, *y, *dmin, *d, *l, *m, *r, *a, *t;
}puzzle;
int *cal(int *temp, int *t, int *m, int *n) {
    int *i = malloc(4), *j = malloc(4);
    *m = 0;
    for ( *i = 0;*i < *n;( *i) ++)
        for ( *j = 0;*j < *n;( *j) ++)
            if ( *(temp + *i **n + *j) != *(t + *i **n + *j))
                ( *m) ++;
    return m;
}
int *check(int *a, int *t, int *n) {
    int *i = malloc(4), *j = malloc(4), *f = malloc(4);*f = 1;
    for ( *i = 0;*i < *n;( *i) ++)
        for ( *j = 0;*j < *n;( *j) ++)
            if ( *(a + *i **n + *j) != *(t + *i **n + *j))
                *f = 0;
    return f;
}
move_left(puzzle *pz) {
    int *p = malloc(4);
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            *(pz->temp + *pz->i **pz->n + *pz->j) = *(pz->a + *pz->i **pz->n + *pz->j);
    if ( *pz->y != 0) {
        *p = *(pz->temp + *pz->x **pz->n + *pz->y);
        *(pz->temp + *pz->x **pz->n + *pz->y) = *(pz->temp + ( *pz->x) **pz->n + ( *pz->y - 1));
        *(pz->temp + ( *pz->x) **pz->n + ( *pz->y - 1)) = *p;
    }
    pz->m = cal(pz->temp, pz->t, pz->m, pz->n);
    *pz->dmin = *pz->l + *pz->m;
    if ( *pz->dmin < *pz->d) {
        *pz->d = *pz->dmin;
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                *(pz->r + *pz->i **pz->n + *pz->j) = *(pz->temp + *pz->i **pz->n + *pz->j);
    }
}
move_right(puzzle *pz) {
    int *p = malloc(4);
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            *(pz->temp + *pz->i **pz->n + *pz->j) = *(pz->a + *pz->i **pz->n + *pz->j);
    if ( *pz->y != *pz->n - 1) {
        *p = *(pz->temp + *pz->x **pz->n + *pz->y);
        *(pz->temp + *pz->x **pz->n + *pz->y) = *(pz->temp + ( *pz->x) **pz->n + ( *pz->y + 1));
        *(pz->temp + ( *pz->x) **pz->n + ( *pz->y + 1)) = *p;
    }
    pz->m = cal(pz->temp, pz->t, pz->m, pz->n);
    *pz->dmin = *pz->l + *pz->m;
    if ( *pz->dmin < *pz->d) {
        *pz->d = *pz->dmin;
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                *(pz->r + *pz->i **pz->n + *pz->j) = *(pz->temp + *pz->i **pz->n + *pz->j);
    }
}
move_up(puzzle *pz) {
    int *p = malloc(4);
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            *(pz->temp + *pz->i **pz->n + *pz->j) = *(pz->a + *pz->i **pz->n + *pz->j);
    if ( *pz->x != 0) {
        *p = *(pz->temp + *pz->x **pz->n + *pz->y);
        *(pz->temp + *pz->x **pz->n + *pz->y) = *(pz->temp + ( *pz->x1) **pz->n + *pz->y);
        *(pz->temp + ( *pz->x - 1) **pz->n + *pz->y) = *p;
    }
    pz->m = cal(pz->temp, pz->t, pz->m, pz->n);
    *pz->dmin = *pz->l + *pz->m;
    if ( *pz->dmin < *pz->d) {
        *pz->d = *pz->dmin;
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                *(pz->r + *pz->i **pz->n + *pz->j) = *(pz->temp + *pz->i **pz->n + *pz->j);
    }
}
move_down(puzzle *pz) {
    int *p = malloc(4);
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            *(pz->temp + *pz->i **pz->n + *pz->j) = *(pz->a + *pz->i **pz->n + *pz->j);
    if ( *pz->x != *pz->n - 1) {
        *p = *(pz->temp + *pz->x **pz->n + *pz->y);
        *(pz->temp + *pz->x **pz->n + *pz->y) = *(pz->temp + ( *pz->x + 1) **pz->n + *pz->y);
        *(pz->temp + ( *pz->x + 1) **pz->n + *pz->y) = *p;
    }
    pz->m = cal(pz->temp, pz->t, pz->m, pz->n);
    *pz->dmin = *pz->l + *pz->m;
    if ( *pz->dmin < *pz->d) {
        *pz->d = *pz->dmin;
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                *(pz->r + *pz->i **pz->n + *pz->j) = *(pz->temp + *pz->i **pz->n + *pz->j);
    }
}
main() {
    puzzle *pz = malloc(sizeof(puzzle));
    pz->i = malloc(4);
    pz->j = malloc(4);
    pz->n = malloc(4);
    *pz->n = 4;
    pz->a = malloc(100 *4);
    pz->t = malloc(100 *4);
    pz->temp = malloc(100 *4);
    pz->r = malloc(100 *4);
    pz->m = calloc(1, 4);
    pz->x = calloc(1, 4);
    pz->y = calloc(1, 4);
    pz->dmin = calloc(1, 4);
    pz->l = calloc(1, 4);
    pz->d = malloc(4);
    *pz->d = 1000;
    printf("\nEnter the matrix to be solved,space with zero :\n");
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            scanf("%d", & *(pz->a + ( *pz->i) *( *pz->n) + *pz->j));
    printf("\nEnter the target matrix,space with zero :\n");
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            scanf("%d", & *(pz->t + ( *pz->i) *( *pz->n) + *pz->j));
    printf("\nEntered Matrix is :\n");
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++) {
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            printf(" %d ", *(pz->a + ( *pz->i) *( *pz->n) + *pz->j));
        printf("\n");
    }
    printf("\nTarget Matrix is :\n");
    for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++) {
        for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
            printf("%d\t", *(pz->t + ( *pz->i) *( *pz->n) + *pz->j));
        printf("\n");
    }
    while (!( *check(pz->a, pz->t, pz->n))) {
        ( *pz->l) ++;
        *pz->d = 1000;
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                if ( *(pz->a + *pz->i **pz->n + *pz->j) == 0) {
                    *pz->x = *pz->i;
                    *pz->y = *pz->j;
                }
        move_up(pz);
        move_down(pz);
        move_right(pz);
        move_left(pz);

        printf("\nCalculated Intermediate Matrix Value :\n");
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++) {
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++)
                printf("%d\t", *(pz->r + *pz->i **pz->n + *pz->j));
            printf("\n");
        }
        for ( *pz->i = 0;*pz->i < *pz->n;( *pz->i) ++)
            for ( *pz->j = 0;*pz->j < *pz->n;( *pz->j) ++) {
                *(pz->a + *pz->i **pz->n + *pz->j) = *(pz->r + *pz->i **pz->n + *pz->j);
                *(pz->temp + *pz->i **pz->n + *pz->j) = 0;
            }
        printf("Minimum cost : %d\n", *pz->d);
    }
}
