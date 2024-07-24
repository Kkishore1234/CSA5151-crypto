#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;  
}

void affineEncrypt(char *text, int a, int b) {
    int i;
    int len = strlen(text);

    for (i = 0; i < len; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (a * (text[i] - base) + b) % 26 + base;
        }
    }
}

void affineDecrypt(char *text, int a, int b) {
    int i;
    int len = strlen(text);
    int a_inv = modInverse(a, 26);

    if (a_inv == -1) {
        printf("Decryption is not possible for the given 'a' value.\n");
        return;
    }

    for (i = 0; i < len; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int temp = (a_inv * ((text[i] - base) - b + 26)) % 26;
            text[i] = temp + base;
        }
    }
}

int main() {
    char text[100];
    int a, b;
    int choice;
     printf("Kkishore");

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline character

    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);

    // Check if 'a' is coprime with 26
    if (gcd(a, 26) != 1) {
        printf("Invalid 'a' value. It must be coprime with 26.\n");
        return 1;
    }

    printf("Enter the value of 'b' (0-25): ");
    scanf("%d", &b);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        affineEncrypt(text, a, b);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        affineDecrypt(text, a, b);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}