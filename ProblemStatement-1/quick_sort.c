#include<stdio.h>

void quicksort(int[], int, int);
void quicksort(int x[10], int first, int last) {
    int pivot, i, j, t;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while (x[i] <= x[pivot] && i < last)
                i++;
            while (x[j] > x[pivot])
                j--;
            if (i < j) {
                t = x[i];
                x[i] = x[j];
                x[j] = t;
            }
        }
        t = x[pivot];
        x[pivot] = x[j];
        x[j] = t;
        quicksort(x, first, j - 1);
        quicksort(x, j + 1, last);
    }
}
int main(void) {
    int x[10], i, n;
    printf("enter number of elements:\n");
    scanf("%d", & n);
    printf("enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", & x[i]);
    quicksort(x, 0, n - 1);
    printf("\nsorted elements are:\n");
    for (i = 0; i < n; i++)
        printf(" %d", x[i]);
    printf("\n");
    return (0);
}
/* Output of Code:
apsit@17102021:~$ gcc quick_sort.c -o 17102021
apsit@17102021:~$ ./17102021
enter number of elements:
5
enter the elements:
62
61
60
59
58
sorted elements are:
 58 59 60 61 62
apsit@17102021:~$
*/
