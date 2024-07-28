#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#define MAX_PRODUCTIONS 10
#define MAX_PROD_LENGTH 10
void FIRST(char[], char);
void addToResultSet(char[], char);

int numofProductions;
char productionSet[MAX_PRODUCTIONS][MAX_PROD_LENGTH];

int main() {
    int i;
    char choice, c, result[20];
    
    printf("\nEnter the number of productions: ");
    scanf("%d", &numofProductions);
    getchar(); 
    
    for (i = 0; i < numofProductions; i++) {
        printf("Enter production number %d: ", i + 1);
        fgets(productionSet[i], MAX_PROD_LENGTH, stdin);
        productionSet[i][strlen(productionSet[i]) - 1] = '\0'; 
    }
    
    do {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c); 
        
        FIRST(result, c); // Compute first
        printf("\nFIRST(%c)={", c);
        
        for (i = 0; result[i] != '\0'; i++)
            printf("%c", result[i]); // Print result
        
        printf("}\n");
        
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice); 
        
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(char Result[], char c) {
    int i, j, k, foundEpsilon;
    char subResult[20];
    subResult[0] = '\0';
    Result[0] = '\0';
    
    if (!isupper(c)) { // If c is terminal, first of c is c
        addToResultSet(Result, c);
        return;
    }
    
    for (i = 0; i < numofProductions; i++) { // If c is non-terminal, read each production
        if (productionSet[i][0] == c) {
            if (productionSet[i][2] == '\0' || productionSet[i][2] == '$') { // Production of type A -> $ or A -> epsilon
                addToResultSet(Result, '$');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                        if (subResult[k] != '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }
                    
                    if (!foundEpsilon)
                        break;
                    
                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++)
        if (Result[k] == val)
            return;
    
    Result[k] = val;
    Result[k + 1] = '\0';
}
