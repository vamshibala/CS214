#include <stdio.h>
#include <ctype.h>

char *strtok_t(char *str, int (*test)(int ch)){
    static char *word = NULL;
    char *token;
    if(str != NULL){
        word = str;
    }
    if(word == NULL) return NULL;
    while(*word && !test(*word)){//skip delimiter
        ++word;
    }
    if(*word == '\0') return NULL;
    token=word;
    while(*word && test(*word)){
        ++word;
    }

    if(*word == '\0'){
        word = NULL;
    } else {
        *word++ = '\0';
    }
    return token;
}

int main(void){
    char str[10000];
    // = "BOB123(&blah02938(*&91820FOO";
    printf("Enter anything seperated by commas : ");
    scanf("%[^\n]s", str);
    char *token;
    for(token = strtok_t(str, isalpha); token ; token = strtok_t(NULL, isalpha)){
        printf("%s\n", token);
    }
    return 0;
}
