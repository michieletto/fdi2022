#include <stdio.h>
#include <string.h>

void print_array(int v[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", v[i]);
    }
    printf(" ]\n");
}

void merge_again(int* v1, int size1, int *v2, int size2) {
    int v1_tmp[size1];
    memcpy(&v1_tmp, v1, size1*sizeof(int));
    int v2_tmp[size2];
    memcpy(&v2_tmp, v2, size2*sizeof(int));

    int first=0, second=0, merge=0;
    while(first<size1 && second<size2) {
        if(v1_tmp[first] < v2_tmp[second]) {
            v1[merge] = v1_tmp[first];
            first++;
        } else {
            v1[merge] = v2_tmp[second];
            second++;
        }
        merge++;
    }
    if(first<size1)
        memcpy(v1+merge, v1_tmp+first, (size1-first)*sizeof(int));
    if(second<size2)
        memcpy(v1+merge, v2_tmp+second, (size2-second)*sizeof(int));
}

void merge_sort_ptr(int* start, int* end){
    if (start<end) {
        int *middle = start + (end-start)/2;
        merge_sort_ptr(start, middle);
        merge_sort_ptr(middle+1, end);
        
        merge_again(start, middle-start+1, middle+1, end-middle);
    }
}

void merge_sort(int v[], int size) {
    if (size <= 1)
        return;
    return merge_sort_ptr(v, v+size-1);
}

int main(void)
{
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
    int size = sizeof(v) / sizeof(v[0]);
    printf("===============================================\n");
    printf("                  MERGE SORT\n");
    printf("===============================================\n");

    printf("Pre-order: ");
    print_array(v, size);

    merge_sort(v, size);

    printf("Post-order:");
    print_array(v, size);

    return 0;
}