#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Symbol {
    char name[10];
    char type[10];
    int address;
};

int main() {
    char expr[100];
    struct Symbol table[50];
    int count = 0;
    
    printf("Enter an expression ending with $: ");
    fgets(expr, sizeof(expr), stdin);
    
    for(int i = 0; expr[i] != '\0' && expr[i] != '$'; i++) {
        if(isalpha(expr[i])) {
            strcpy(table[count].name, "");
            table[count].name[0] = expr[i];
            table[count].name[1] = '\0';
            strcpy(table[count].type, "Identifier");
            table[count].address = i;
            count++;
        } else if(strchr("+-*/=", expr[i]) != NULL) {
            strcpy(table[count].name, "");
            table[count].name[0] = expr[i];
            table[count].name[1] = '\0';
            strcpy(table[count].type, "Operator");
            table[count].address = i;
            count++;
        }
    }

    printf("\nSymbol Table:\n");
    printf("S.No\tName\tType\t\tAddress\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t\t%d\n", i+1, table[i].name, table[i].type, table[i].address);
    }

    return 0;
}
