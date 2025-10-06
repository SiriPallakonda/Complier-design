#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempCount = 1;

void generate(char *op1, char *op, char *op2) {
    printf("T%d = %s %s %s\n", tempCount, op1, op, op2);
    tempCount++;
}

int main() {
    char expr[100];
    char operands[10][10];   // to store operands
    char operators[10];      // to store operators
    int opIndex = 0, opdIndex = 0;

    printf("Enter an arithmetic expression (e.g., a+b*c): ");
    scanf("%s", expr);

    for(int i = 0; i < strlen(expr); i++) {
        if(isalpha(expr[i]) || isdigit(expr[i])) {
            operands[opdIndex][0] = expr[i];
            operands[opdIndex][1] = '\0';
            opdIndex++;
        } else if(strchr("+-*/", expr[i])) {
            operators[opIndex++] = expr[i];
        }
    }

    int tempNum = 1;
    char temp[10];
    
    // Simple left-to-right code generation (no operator precedence)
    int opd = 0;
    for(int i = 0; i < opIndex; i++) {
        sprintf(temp, "T%d", tempNum);
        generate(operands[opd], &operators[i], operands[opd+1]);
        strcpy(operands[opd+1], temp); // result becomes next operand
        tempNum++;
        opd++;
    }

    printf("Final assignment: %s = %s\n", operands[opd], operands[opd]);
    return 0;
}
