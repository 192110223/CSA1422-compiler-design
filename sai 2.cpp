#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int isComment(const char *line) {
    
    if (strncmp(line, "//", 2) == 0) {
        return 1; 
    }
    
   
    if (strncmp(line, "/*", 2) == 0) {
        return 1;
    }
    
    
    if (strstr(line, "*/") != NULL) {
        return 1; 
    }
    
    return 0; 
}

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    if (isComment(line)) {
        printf("The line is a comment.\n");
    } else {
        printf("The line is not a comment.\n");
    }

    return 0;
}

