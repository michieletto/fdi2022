#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_latin(int square[], int size) {
    bool check_rows[size];
    bool check_cols[size];

    for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++)
        {
            check_rows[j] = false;
            check_cols[j] = false;
        }
        for (int j = 0; j < size; j++)
        {
            int value_row = square[i*size+j] - 1;
            int value_col = square[j*size+i] - 1;
            if ((value_row < 0) || (value_row >= size)) {
                printf("Value not in range at square[%d, %d] = %d\n", i, j, value_row+1);
                return false;
            }
            if ((value_col < 0) || (value_col >= size)) {
                printf("Value not in range at square[%d, %d] = %d\n", j, i, value_col+1);
                return false;
            }
            if(check_rows[value_row]) {
                printf("Repeated value at square[%d, %d] = %d\n", i, j, value_row+1);
                return false;
            }
            if(check_cols[value_col]) {
                printf("Repeated value at square[%d, %d] = %d\n", j, i, value_col+1);
                return false;
            }
            check_rows[value_row] = true;
            check_cols[value_col] = true;
        }
    }

    return true;
}

void swap_row(int square[], int size, int row_from, int row_to){
    int temp;

    for (int j = 0; j < size; j++)
    {
        temp = square[row_from*size+j];
        square[row_from*size+j] = square[row_to*size+j];
        square[row_to*size+j] = temp;
    }
}

void swap_col(int square[], int size, int col_from, int col_to){
    int temp;

    for (int i = 0; i < size; i++)
    {
        temp = square[i*size+col_from];
        square[i*size+col_from] = square[i*size+col_to];
        square[i*size+col_to] = temp;
    }
}

void print_reduced(int square[], int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %d", square[i*size+j]);
        }
        printf("\n");
    }
}

void reduce(int square[], int size) {
    // check colonne
    printf("check cols\n");
    for (int i = 0; i < size;)
    {
        printf("index: %d     square[%d]: %d\n", i, i, square[i]-1);
        print_reduced(square, size);
        if ((square[i]-1) == i)
            i++;
        else
            swap_col(square, size, i, square[i]-1);
    }
    // check righe
    printf("check rows\n");
    for (int i = 1; i < size;)
    {
        printf("index: %d     square[%d]: %d\n", i, i, square[i*size]-1);
        print_reduced(square, size);
        if ((square[i*size]-1) == i)
            i++;
        else
            swap_row(square, size, i, square[i*size]-1);
    }

}

int main() {
    int size = 0;

    for(;;) {
        printf("Size?\n");
        scanf("%d", &size);
        if (size>0) {
            break;
        }
    }

    int square[size*size];

    // Just get the data
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Element at square[%d][%d]: ", i, j);
            scanf("%d", &square[i*size+j]);
        }
        printf("\n");
    }

    bool valid = is_latin(square, size);

    printf("The square is %s\n", valid ? "latin" : "not latin");

    if (valid) {
        reduce(square, size);
        printf("\nThe reduced matrix is:\n");
        print_reduced(square, size);
    }    

    return 0;
}