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
    int input_index = 0;
    int accepted_index = 0;

    while ((input[input_index] != '\0') && (accepted[accepted_index] != '\0'))
    {
        if (input[input_index] != accepted[accepted_index]) {
            accepted_index++;
        } else {
            input_index++;
        }
        // input[input_index] != accepted[accepted_index] ? accepted_index++:input_index++;
    }

    return (input[input_index] == '\0');
}

enum roman_numbers get_digit_value(char d) {
    switch (d)
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

int get_roman_value(char input[]) {
    int input_index = 0;
    int roman_sum = 0;
    enum roman_numbers last_value = NOT_VALID;
    while (input[input_index] != '\0') {
        enum roman_numbers digit_value = get_digit_value(input[input_index]);
        if ((digit_value != NOT_VALID) && 
            (last_value == NOT_VALID || (last_value >= digit_value))) {
            roman_sum += digit_value;
            last_value = digit_value;
            input_index++;
        } else {
            return NOT_VALID;
        }
    }
    return roman_sum;
}

int main() {
    char number[256] = {0};
    int value = 0;

    for (;;)
    {
        printf("Roman: ");
        scanf("%s", number);
        if(is_valid(number)) {
            printf("Valid number\n");
        }
        value = get_roman_value(number);
        if(value != NOT_VALID) {
            break;
        }
    }
    printf("Value: %d\n", value);

    return 0;
}