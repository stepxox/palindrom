#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char *str){
    for(int i = 0; i < strlen(str); i++)
        if(str[i] != str[strlen(str)-i-1]) return false;
    return true;
}

void removeNewLine(char *str){
    if(str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
}

void lowCase(char *str){
    for(int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

void removeSpaces(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(isspace(str[i])){
            for(int j=i;j<strlen(str);j++)
                str[j]=str[j+1];
        }
    }
}

void removePunct(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(ispunct(str[i])){
            for(int j=i;j<strlen(str);j++)
                str[j]=str[j+1];
        }
    }
}

int main(){
    char str[1000];
    while(fgets(str, 1000, stdin) != NULL){\

        removeNewLine(str);
        lowCase(str);
        removeSpaces(str);
        removePunct(str);

        if(isPalindrome(str)){
            printf("%s\n", str);
        }

        else
            printf("Error\n");
    }
    return 0;
}
