#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void generateCipherAlphabet(char *keyword, char *cipherAlphabet) {
    int i, j;
    int used[26] = {0}; 
    int keywordLen = strlen(keyword);
    for (i = 0; i < keywordLen; ++i) {
        char ch = toupper(keyword[i]);
        if (isalpha(ch) && !used[ch - 'A']) {
            cipherAlphabet[i] = ch;
            used[ch - 'A'] = 1;
        }
    }
    char letter = 'A';
    for (j = 0; j < 26; ++j) {
        if (!used[j]) {
            while (used[letter - 'A']) {
                ++letter;
            }
            cipherAlphabet[i++] = letter++;
        }
    }
    cipherAlphabet[i] = '\0';
}
void encryptMonoalphabetic(char *plaintext, char *cipherAlphabet, char *ciphertext) {
    int i;
    int len = strlen(plaintext);

    for (i = 0; i < len; ++i) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = cipherAlphabet[toupper(plaintext[i]) - 'A'] + (base - 'A');
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[len] = '\0';
}
void decryptMonoalphabetic(char *ciphertext, char *cipherAlphabet, char *plaintext) {
    int i;
    int len = strlen(ciphertext);

    for (i = 0; i < len; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            int index = strchr(cipherAlphabet, toupper(ciphertext[i])) - cipherAlphabet;
            plaintext[i] = index + base;
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[len] = '\0';
}

int main() {
	 printf("Kkishore");
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello World!";
    char cipherAlphabet[27];
    char ciphertext[1000];
    char decryptedText[1000];
    generateCipherAlphabet(keyword, cipherAlphabet);
    printf("Cipher Alphabet: %s\n", cipherAlphabet);
    encryptMonoalphabetic(plaintext, cipherAlphabet, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    decryptMonoalphabetic(ciphertext, cipherAlphabet, decryptedText);
    printf("Decrypted plaintext: %s\n", decryptedText);
    return 0;
}