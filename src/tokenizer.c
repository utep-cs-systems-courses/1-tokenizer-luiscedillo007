#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    return (c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
    return (c != ' ' && c != '\t' && c != '\0');
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){

    if (*str == '\0') {
        return NULL;
    }
    
    // skip whitespace chars
    while (space_char(*str)) {
        str++;
    }

    // Return pointer to start of next word
    return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
    // Find the end of the word
    while (non_space_char(*word)) {
        word++;
    }
    // Return pointer to terminator
    return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
    int count = 0;
    while(*str != NULL && *str != '\0'){
        str = word_start(str);
        str = word_terminator(str);
        count++;
    }
    return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    // This line of code dynamically allocates memory for an array of character pointers using the malloc() function. 
    char *copy = malloc((len + 1) * sizeof(char));
    int i;
    for(i = 0; i < len; i++){
        copy[i] = inStr[i];
    }
    copy[len] = '\0';
    return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
    int num_words = count_words(str);
    // This line of code dynamically allocates memory for an array of character pointers using the malloc() function. 
    // The size of the allocated memory is calculated as (num_words + 1) * sizeof(char *) 
    char **tokens = malloc((num_words + 1) * sizeof(char *));
    char *start = word_start(str);
    char *end = word_terminator(start);
    int i;
    for(i = 0; i < num_words; i++){
        tokens[i] = copy_str(start, end-start);
        start = word_start(end);
        end = word_terminator(start);
    }
    tokens[num_words] = 0;
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    int i = 0;
    while(tokens[i] != 0){
        printf("%s\n", tokens[i]);
        i++;
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    int i = 0;
    while(tokens[i] != 0){
        free(tokens[i]);
        i++;
    }
    free(tokens);
}