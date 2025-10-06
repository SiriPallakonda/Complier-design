%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
E : E '+' E { printf("Addition\n"); }
  | E '-' E { printf("Subtraction\n"); }
  | E '*' E { printf("Multiplication\n"); }
  | E '/' E { printf("Division\n"); }
  | '-' E %prec UMINUS { printf("Unary minus\n"); }
  | '(' E ')' { printf("Parenthesis\n"); }
  | NUMBER { printf("Number\n"); }
  ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an arithmetic expression:\n");
    yyparse();
    printf("Parsing completed successfully.\n");
    return 0;
}
