#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_CODE 1000

typedef struct {
    char name[20];
    int value;
} Symbol;

typedef struct {
    char code[MAX_CODE][100];
    int codeIndex;
} CodeGenerator;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
CodeGenerator codeGen;

void addSymbol(char *name, int value) {
    strcpy(symbolTable[symbolCount].name, name);
    symbolTable[symbolCount].value = value;
    symbolCount++;
}

void generateCode(char *instruction) {
    strcpy(codeGen.code[codeGen.codeIndex], instruction);
    codeGen.codeIndex++;
}

void printSymbolTable() {
    printf("Symbol Table:\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("Name: %s, Value: %d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

void printGeneratedCode() {
    printf("Generated Code:\n");
    for (int i = 0; i < codeGen.codeIndex; i++) {
        printf("%s\n", codeGen.code[i]);
    }
}

int main() {
    codeGen.codeIndex = 0;

    addSymbol("x", 10);
    addSymbol("y", 20);
    
    generateCode("LOAD x");
    generateCode("ADD y");
    generateCode("STORE z");

    printSymbolTable();
    printGeneratedCode();

    return 0;
}

