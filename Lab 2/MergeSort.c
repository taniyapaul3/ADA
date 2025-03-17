#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void split(int[], int, int);
void combine(int[], int, int, int);

int main() {
    int *a, n, i, j, ch, temp;
    clock_t start, end;

    while(1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);


                a = (int*)malloc(n * sizeof(int));
                if (a == NULL) {
                    printf("Memory allocation failed!\n");
                    return -1;
                }

                printf("\nEnter array elements: ");
                for(i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }

                start = clock();
                split(a, 0, n - 1);
                end = clock();

                printf("\nSorted array is: ");
                for(i = 0; i < n; i++)
                    printf("%d\t", a[i]);

                printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);


                free(a);
                break;

            case 2:
                n = 500;
                while (n <= 14500) {
                    a = (int*)malloc(n * sizeof(int));
                    if (a == NULL) {
                        printf("Memory allocation failed!\n");
                        return -1;
                    }


                    for(i = 0; i < n; i++) {
                        a[i] = n - i;
                    }

                    start = clock();
                    split(a, 0, n - 1);


                    for(j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();

                    printf("\nTime taken to sort %d numbers is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);


                    free(a);

                    n += 1000;
                }
                break;

            case 3:
                exit(0);
        }
    }

    return 0;
}

void split(int a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        split(a, low, mid);
        split(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}

void combine(int a[], int low, int mid, int high) {
    int *c = (int*)malloc((high - low + 1) * sizeof(int));
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high) {
        if(a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }


    while(i <= mid) {
        c[k++] = a[i++];
    }

    while(j <= high) {
        c[k++] = a[j++];
    }

    for(i = low; i <= high; i++) {
        a[i] = c[i - low];
    }

    free(c);
}
