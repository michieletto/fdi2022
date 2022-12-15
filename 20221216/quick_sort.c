#include <stdio.h>

void print_array(int v[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", v[i]);
    }
    printf(" ]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* partition(int* pivot, int *low, int *high) {
    for(;;) {
        // incremento low finché il valore puntato
        // è minore del valore preso come pivot 
        while (*low < *pivot)       
            low++;
        // decremento high finché il valore puntato
        // è maggioreo uguale del valore preso come pivot
        while (*high >= *pivot)
            high--;
        // se low precede ancora high
        if (low<high)
            // scambio i due valori
            swap(low, high);
        else {
            // altrimenti scambio low con il pivot
            swap(low, pivot);
            return low;
        }
    }
}

void quick_sort_ptr(int* pivot, int* low, int* high){
    if (low<=high) {
        pivot = partition(pivot, low, high);

        quick_sort_ptr(pivot-1, low, pivot-2);
        quick_sort_ptr(high+1, pivot+1, high);
    }
}

void quick_sort(int v[], int size) {
    if (size <= 1)
        return;
    return quick_sort_ptr(v+size-1, v, v+size-2);
}

int main(void)
{
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
    int size = sizeof(v) / sizeof(v[0]);
    printf("===============================================\n");
    printf("                  QUICK SORT\n");
    printf("===============================================\n");

    printf("Pre-order: ");
    print_array(v, size);

    quick_sort(v, size);

    printf("Post-order:");
    print_array(v, size);

    return 0;
}