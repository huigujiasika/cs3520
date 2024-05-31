#include <stdio.h>

#define MAX_LETTERS 26

char alphabet[MAX_LETTERS];

void initialize_array(char *a) {
    char *p;
    char current_letter = 'a';

    for (p = a; p < (a + MAX_LETTERS); p++) {
        *p = current_letter++;
    }
}

void print_characters_in_reverse(char *b) {
    static int var = 0;
    char *p;
    
    if (var == 0) {
        initialize_array(b);
        var = !var;
    }

    printf("\nReversing alphabets...\n");


    for (p = (b + MAX_LETTERS - 1); p >= b; p--) {
        printf("%c ", *p);
    }
    printf("\n");
}

int main(void) {
    int i = 0;
    while (i++ <= 9 ) {
        print_characters_in_reverse(alphabet);
    }
}
