#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int create_digit(int *digit_array, int count) {
    int digit = 0;
    for (int j = 0; j < count; j++) {
        digit = digit * 10 + digit_array[j];
    }
    return digit;
}

// Recursive decoder
char *decodeString_helper(char *s, int *pos) {
    char *result = malloc(10000); // big buffer for simplicity
    result[0] = '\0';

    int digit_array[10];
    int digit_count = 0;

    while (s[*pos] != '\0' && s[*pos] != ']') {
        if (is_digit(s[*pos])) {
            // collect digits
            digit_count = 0;
            while (is_digit(s[*pos])) {
                digit_array[digit_count++] = s[*pos] - '0';
                (*pos)++;
            }
            int repeat = create_digit(digit_array, digit_count);

            (*pos)++; // skip '['
            char *inner = decodeString_helper(s, pos); // recursion
            (*pos)++; // skip ']'

            for (int k = 0; k < repeat; k++) {
                strcat(result, inner);
            }
            free(inner);
        }
        else {
            int len = strlen(result);
            result[len] = s[*pos];
            result[len+1] = '\0';
            (*pos)++;
        }
    }
    return result;
}

char * decodeString(char *s){
    int i =0;
    return decodeString_helper(s,&i);
}