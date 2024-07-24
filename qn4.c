#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt plaintext using Vigenère cipher
void encrypt(char* plaintext, char* key, char* ciphertext) {
    int ptLen = strlen(plaintext);
    int keyLen = strlen(key);
    
    for (int i = 0, j = 0; i < ptLen; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = ((plaintext[i] - base) + (toupper(key[j]) - 'A')) % 26 + base;
            j = (j + 1) % keyLen;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[ptLen] = '\0';
}

// Function to decrypt ciphertext using Vigenère cipher
void decrypt(char* ciphertext, char* key, char* plaintext) {
    int ctLen = strlen(ciphertext);
    int keyLen = strlen(key);
    
    for (int i = 0, j = 0; i < ctLen; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = ((ciphertext[i] - base) - (toupper(key[j]) - 'A') + 26) % 26 + base;
            j = (j + 1) % keyLen;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[ctLen] = '\0';
}

int main() {
    char plaintext[256];
    char key[256];
    char ciphertext[256];
    printf("Kkishore");

    printf("\nEnter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}