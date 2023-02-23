#include <string.h>
#include <stdio.h>
#include "tokenizer.h"

int main(){
    char input[100];
    printf(">");
    fgets(input, 100, stdin); 
    printf("%s\n", input);
    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
    return 0;
}