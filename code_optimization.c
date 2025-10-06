#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char lhs[10];
    char rhs[50];
} Statement;

int main() {
    int n;
    Statement code[MAX], optimized[MAX];
    int optCount = 0;

    printf("Enter number of intermediate code statements: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter statements in form T = A op B:\n");
    for(int i = 0; i < n; i++) {
        fgets(code[i].rhs, sizeof(code[i].rhs), stdin);
        code[i].rhs[strcspn(code[i].rhs, "\n")] = '\0'; // remove newline
        printf("Enter LHS for statement %d: ", i+1);
        scanf("%s", code[i].lhs);
        getchar(); // consume newline
    }

    // Optimization: common subexpression elimination
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < optCount; j++) {
            if(strcmp(code[i].rhs, optimized[j].rhs) == 0) {
                printf("Replacing %s with %s (common subexpression)\n", code[i].lhs, optimized[j].lhs);
                found = 1;
                break;
            }
        }
        if(!found) {
            optimized[optCount++] = code[i];
        }
    }

    printf("\nOptimized Intermediate Code:\n");
    for(int i = 0; i < optCount; i++) {
        printf("%s = %s\n", optimized[i].lhs, optimized[i].rhs);
    }

    return 0;
}
