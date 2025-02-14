#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_PRODUCTIONS 10

char productions[MAX][MAX_PRODUCTIONS][MAX];
int numProductions;

void eliminateLeftFactoring() {
    for (int i = 0; i < numProductions; i++) {
        char firstChar = productions[i][0][0];
        int j = 1;
        while (j < MAX_PRODUCTIONS && productions[i][j][0] == firstChar) {
            j++;
        }
        if (j > 1) {
            printf("Left factoring detected in production: %s\n", productions[i][0]);
            printf("New productions:\n");
            for (int k = 0; k < j; k++) {
                printf("%s\n", productions[i][k]);
            }
            printf("Introduce new non-terminal for left factoring.\n");
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    
    for (int i = 0; i < numProductions; i++) {
        printf("Enter production %d: ", i + 1);
        scanf("%s", productions[i][0]);
    }

    eliminateLeftFactoring();
    return 0;
}

