#include <stdio.h>

void print_array(int v[], int size) {
	printf("[");
	for (int i=0; i < size; i++) {
		printf(" %d", v[i]);
	}
	printf(" ]\n");
}

void swap(int *a, int* b) {
    int temp = *a;
    *a = * b;
    *b = temp;
}

void selection_sort(int v[], int size) {
	for (int next=0; next < size-1; next++) {
        // Cerco il minimo a partire da next
		int min_index = next;
		for (int i = next+1; i < size; i++) {
			if (v[i] < v[min_index])
				min_index = i;
        }
		// Scambio next con il minimo trovato
		swap(&v[next], &v[min_index]);
	}
}

int main(void) {
    int v[] = {25, 14, 12, 5, 37, 29, 10, 7, 20, 17};
    int size = sizeof(v)/sizeof(v[0]);
    printf("===============================================\n");
    printf("             SELECTION SORT\n");
    printf("===============================================\n");

    printf("Pre-order: ");
	print_array(v, size);

	selection_sort(v, size);

	printf("Post-order:");
	print_array(v, size);

    return 0;
}