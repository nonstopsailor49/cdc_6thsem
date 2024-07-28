#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int iskeyword(char buffer[]) {
   
    char keywords[32][10] = {"auto", "break", "case", "char", "const", 
                             "continue", "default", "do", "double", "else", 
                             "enum", "extern", "float", "for", "goto", "if", 
                             "int", "long", "register", "return","short", 
                             "signed", "sizeof", "static", "struct", "switch", 
                             "typedef", "union","unsigned", "void", "volatile", "while"};
    int i, flag = 0;

    
    for(i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    
    fp = fopen("lex.txt", "r");
    if(fp == NULL) {
        printf("Error while opening the file!\n");
        exit(0);
    }
    
    while((ch = fgetc(fp)) != EOF) {
        // Check if the character is an operator
        for(i = 0; i < 6; ++i) {
            if(ch == operators[i]) {
                printf("%c is operator.\n", ch);
            }
        }

        // Check if the character is alphanumeric
        if(isalnum(ch)) {
            buffer[j++] = ch;
        } 
        // If it's a space or newline and buffer is not empty
        else if((ch == ' ' || ch == '\n' || ch == ',' || ch == ';') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            // Check if the buffer contains a keyword
            if(iskeyword(buffer) == 1) {
                printf("%s is keyword.\n", buffer);
            } else {
                printf("%s is an identifier.\n", buffer);
            }
        }
    }
    
    // Close the file
    fclose(fp);
    return 0;
}
