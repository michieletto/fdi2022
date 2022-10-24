#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_vocal(char c) {
    switch (toupper(c))
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }
    return false;
}

void remove_vocals(char s[]) {
    int index = 0;
    int no_vocal_index = 0;
    while(s[index] != '\0') {
        if (!is_vocal(s[index])) {
            s[no_vocal_index] = s[index];
            no_vocal_index++;
        }
        index++;
    }
    s[no_vocal_index]='\0';
}

int main() {
    char s[256];
    printf("Input: ");
    scanf("%s", s);

    remove_vocals(s);

    printf("Output: %s\n", s);

    return 0;
}