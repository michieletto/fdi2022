#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_COLOR_NAME_LEN 5

typedef char* string;

int main() {
    int string_lenghts[] = {5, 5, 3, 5, 4, 0};
    int num_strings = sizeof(string_lenghts)/sizeof(int);

    string char_matrix = (string)malloc(num_strings*(MAX_COLOR_NAME_LEN+1)*(sizeof(char)));
    if (char_matrix == NULL)
        return 0;
    strcpy(char_matrix+0*(MAX_COLOR_NAME_LEN+1), "black");
    strcpy(char_matrix+1*(MAX_COLOR_NAME_LEN+1), "white");
    strcpy(char_matrix+2*(MAX_COLOR_NAME_LEN+1), "red");
    strcpy(char_matrix+3*(MAX_COLOR_NAME_LEN+1), "green");
    strcpy(char_matrix+4*(MAX_COLOR_NAME_LEN+1), "blue");
    strcpy(char_matrix+5*(MAX_COLOR_NAME_LEN+1), "");

    printf("CHAR_MATRIX:\n");
    for(int i=0; i<num_strings; i++) {
        printf("%d. %s (strlen: %ld)\n", i, char_matrix+i*(MAX_COLOR_NAME_LEN+1), strlen(char_matrix+i*(MAX_COLOR_NAME_LEN+1)));
    }

    string *array_of_pointes = (string*)malloc(num_strings*(sizeof(string)));
    if (array_of_pointes == NULL)
        return 0;
    for(int i=0; i<num_strings; i++) {
        array_of_pointes[i] = (string)malloc((string_lenghts[i]+1)*(sizeof(char)));
    }
    
    strcpy(array_of_pointes[0], "black");
    strcpy(array_of_pointes[1], "white");
    strcpy(array_of_pointes[2], "red");
    strcpy(array_of_pointes[3], "green");
    strcpy(array_of_pointes[4], "blue");
    strcpy(array_of_pointes[5], "");

    printf("ARRAY OF CHAR POINTERS:\n");
    for(int i=0; i<num_strings; i++) {
        printf("%d. %s (strlen: %ld)\n", i, array_of_pointes[i], strlen(array_of_pointes[i]));
    }
}