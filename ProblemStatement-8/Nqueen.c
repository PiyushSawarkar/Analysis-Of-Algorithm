typedef struct {
    int *board, *count;
}etq;
main() {
    etq *dt = malloc(sizeof(etq));
    dt->board = calloc(20, 4);
    dt->count = calloc(1, 4);
    int *n = malloc(4), *i = malloc(4), *j = malloc(4);
    printf("\nEnter number of Queens:");
    scanf("%d", & *n);
    int *one_val = malloc(4);*one_val = 1;
    queen(one_val, n, dt);
    printf("\n");
}
print(int *n, etq *dt) {
    int *i = malloc(4), *j = malloc(4);
    printf("\nSolution %d:\n\n", ++ *dt->count);
    for ( *i = 1;*i <= *n; ++ *i)
        printf("\t%d", *i);
    for ( *i = 1;*i <= *n; ++ *i) {
        printf("\n\n%d", *i);
        for ( *j = 1;*j <= *n; ++ *j) //for nxn board
            if (dt->board[ *i] == *j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
    }
}
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
place(int *row, int *column, etq *dt) {
    int *i = malloc(4);
    for ( *i = 1;*i <= *row - 1; ++ *i) {
        //checking column and digonal conflicts
        if (dt->board[ *i] == *column)
            return 0;
        else
        if (abs(dt->board[ *i] - *column) == abs( *i - *row))
            return 0;
    }
    return 1; //no conflicts
}
//function to check for proper positioning of queen
queen(int *row, int *n, etq *dt) {
    int *column = malloc(4);
    for ( *column = 1;*column <= *n;( *column) ++)
        if (place(row, column, dt)) {
            dt->board[ *row] = *column; //no conflicts so place queen
            if ( *row == *n) //dead end
                print(n, dt); //printing the board configuration
            else { //try queen with next position
                int *a = malloc(4);*a = *row + 1;
                queen(a, n, dt);
            }
        }
}
