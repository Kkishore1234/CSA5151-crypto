#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void monoalphabeticCipher(char *text, const char *key) {
    int i;
    char ch;
    for(i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if(isalpha(ch)) {
            if(islower(ch)) {
                text[i] = tolower(key[ch - 'a']);
            } else {
                text[i] = toupper(key[ch - 'A']);
            }
        }
    }
}
int main() {
    char text[100];
    char key[27];
     printf("Kkishore");
    printf("\nEnter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    printf("Enter the 26-character substitution key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    if(strlen(key) != 26) {
        printf("Invalid key. The key must be exactly 26 characters long.\n");
        return 1;
    }
    for(int i = 0; i < 26; ++i) {
        if(!isalpha(key[i])) {
            printf("Invalid key. The key must contain only alphabetic characters.\n");
            return 1;
        }
        for(int j = i + 1; j < 26; ++j) {
            if(tolower(key[i]) == tolower(key[j])) {
                printf("Invalid key. The key must contain unique characters.\n");
                return 1;
            }
        }
    }
    monoalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}