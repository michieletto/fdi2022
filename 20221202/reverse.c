#include <stdio.h>
#include <stdint.h>

void print_reverse(int a[], int size) {
    printf("Reverse = [");
    for (int i = size; i > 0; i--)
    {
        printf(" %d", a[i-1]);
    }
    printf(" ]\n");
}

void print_array(int messages[], int size) {
    printf("Array = [");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", messages[i]);
    }
    printf(" ]\n");
}

void print_ptr_reverse(int *a, int size) {
    printf("Reverse = [\n");
    int *ptr_end = a + size;
    int *ptr_start = a;
    for (;ptr_start < ptr_end; ptr_end--)
    {
        printf(" %d <---- %p\n", *(ptr_end-1), (ptr_end-1));
    }
    printf(" ]\n");
}

void print_ptr_rev_alt(int *a, int size) {
    printf("Reverse = [\n");
    int *ptr_end = a + size - 1;
    int *ptr_start = a;
    for (;ptr_start <= ptr_end; ptr_end--)
    {
        printf(" %d <---- %p\n", *ptr_end, ptr_end);
    }
    printf(" ]\n");
}

void print_ptr_array(int *a, int size) {
    printf("Array = [\n");
    int *ptr_end = a + size;
    int *ptr_start = a;
    for (; ptr_start < ptr_end; ptr_start++)
    {
        printf(" %d <---- %p\n", *ptr_start, ptr_start);
    }
    printf(" ]\n");
}

void wrong_swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void wrong_ptr_swap(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int a[], int size) {
    for (int i = 0; i < size/2; i++)
    {
        swap(&a[i], &a[size-1-i]);
    }   
}

void reverse_ptr(int a[], int size) {
    int *ptr_end = a + size - 1;
    int *ptr_start = a;
    for (; ptr_start < ptr_end;)
    {
        swap(ptr_start, ptr_end);
        ptr_start++;
        ptr_end--;
    }   
}

int main() {
    int a[] = {1, 2, 3, 4, 5};

    printf("size of a = %ld\n", sizeof(a));
    printf("size of int = %ld\n", sizeof(int));

    int size = sizeof(a)/sizeof(a[0]);

    printf("size = %d\n", size);

    int8_t int_a_8_bit;
    int16_t int_a_16_bit;
    int32_t int_a_32_bit;
    printf("size of int8_t = %ld\n", sizeof(int8_t));
    printf("size of int16_t = %ld\n", sizeof(int16_t));
    printf("size of int32_t = %ld\n", sizeof(int32_t));

    printf("\n >>> Array <<<\n");
    print_array(a, size);
    print_reverse(a, size);

    printf("\n >>> Pointers <<<\n");
    print_ptr_array(a, size);
    print_ptr_reverse(a, size);
    print_ptr_rev_alt(a, size);

    printf(">>> wrong_swap <<<\n");
    printf("Before: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    wrong_swap(a[0], a[size-1]);
    printf("After: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    printf(">>> wrong__ptr_swap <<<\n");
    printf("Before: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    wrong_ptr_swap(&a[0], &a[size-1]);
    printf("After: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    printf(">>> swap <<<\n");
    printf("Before: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    //swap(&a[0], &a[size-1]);
    printf("After: a[0] = %d, a[size-1] = %d\n", a[0], a[size-1]);
    
    printf("Before:\n");
    print_array(a, size);
    reverse(a, size);
    printf("After:\n");
    print_array(a,size);

    printf("Before:\n");
    print_array(a, size);
    reverse_ptr(a, size);
    printf("After:\n");
    print_array(a,size);

    return 0;
}