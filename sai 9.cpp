#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidGrammar(const char *str) {
    int i, length = strlen(str);
    if (length == 0) return 0;

   
    if (!isupper(str[0])) return 0;

    
    if (str[length - 1] != '.' && str[length - 1] != '!' && str[length - 1] != '?') return 0;

   
    for (i = 1; i < length - 1; i++) {
        if (!isalnum(str[i]) && str[i] != ' ' && str[i] != ',' && str[i] != ';') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[256];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 

    if (isValidGrammar(input)) {
        printf("The sentence satisfies the grammar rules.\n");
    } else {
        printf("The sentence does not satisfy the grammar rules.\n");
    }

    return 0;
}

