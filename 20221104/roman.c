#include <stdio.h>
#include <stdbool.h>

enum roman_numbers {
    M = 1000,
    D = 500,
    C = 100,
    L = 50,
    X = 10,
    V = 5,
    I = 1,
    NOT_VALID = 0,
};

bool is_valid(char input[]) {
    char accepted[] = "MDCLXVI";
    int index_input = 0;
    int index_accepted = 0;
    while ((input[index_input]!='\0') && (accepted[index_accepted] != '\0')) {
        if (input[index_input] == accepted[index_accepted]) {
            index_input++;
        } else {
            index_accepted++;
        }
        // input[index_input] == accepted[index_accepted] ? index_input++:index_accepted++;
    }
    
    return input[index_input] == '\0';
}

enum roman_numbers get_digit(char digit){
    switch (digit)
    {
    case 'M':
        return M;
    case 'D':
        return D;
    case 'C':
        return C;
    case 'L':
        return L;
    case 'X':
        return X;
    case 'V':
        return V;
    case 'I':
        return I;  
    }
    return NOT_VALID;
}

int get_value(char input[]) {
    int index_input = 0;
    int roman_sum = 0;

    while (input[index_input]!='\0')
    {
        roman_sum += get_digit(input[index_input]);
        index_input++;
    }
    
    return roman_sum;
}

int main() {
    char number[256] = {0};

    for (;;)
    {
        printf("Roman: ");
        scanf("%s", number);
        if(is_valid(number)) {
            printf("Valid number\n");
            break;
        }
        printf("Not a roman number!\n");
    }
    int value = get_value(number);
    printf("Value: %d\n", value);
    
    return 0;
}