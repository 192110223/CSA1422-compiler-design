#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void lexicalAnalyzer(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            continue;
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Operator: %c\n", input[i]);
        } else {
            printf("Invalid character: %c\n", input[i]);
        }
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter an expression: ");
    fgets(input, MAX_LEN, stdin);
    lexicalAnalyzer(input);
    return 0;
}

