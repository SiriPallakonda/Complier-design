#include <stdio.h>
#include <ctype.h>
#include <string.h>

int tempCount = 1;

void generate(char *op1, char *op, char *op2) {
    printf("LOAD %s\n", op1);
    if(strcmp(op, "+") == 0) printf("ADD %s\n", op2);
    else if(strcmp(op, "-") == 0) printf("SUB %s\n", op2);
    else if(strcmp(op, "*") == 0) printf("MUL %s\n", op2);
    else if(strcmp(op, "/") == 0) printf("DIV %s\n", op2);
    printf("STORE T%d\n\n", tempCount);
    tempCount++;
}

int main() {
    char expr[100];
    char operands[10][10];  
    char operators[10];     
    int opIndex = 0, opdIndex = 0;

    printf("Enter an arithmetic expression (e.g., a+b*c): ");
    scanf("%s", expr);

    // Separate operands and operators
    for(int i = 0; i < strlen(expr); i++) {
        if(isalpha(expr[i]) || isdigit(expr[i])) {
            operands[opdIndex][0] = expr[i];
            operands[opdIndex][1] = '\0';
            opdIndex++;
        } else if(strchr("+-*/", expr[i])) {
            operators[opIndex++] = expr[i];
        }
    }

    int opd = 0;
    char temp[10];

    // Simple left-to-right code generation (without operator precedence)
    for(int i = 0; i < opIndex; i++) {
        sprintf(temp, "T%d", tempCount);
        char opStr[2]; opStr[0] = operators[i]; opStr[1] = '\0';
        generate(operands[opd], opStr, operands[opd+1]);
        strcpy(operands[opd+1], temp);  
        opd++;
    }

    printf("Final Result stored in %s\n", operands[opd]);
    return 0;
}
