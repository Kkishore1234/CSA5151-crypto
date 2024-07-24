#include <stdio.h>
#include <string.h>
#include <ctype.h>
void caesarCipher(char text[], int k) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + k) % 26 + offset;
        }
    }
}

int main() {
    char text[100];
    int k;
    printf("Enter the text to be encrypted: ");
    printf("Kkishore");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter the shift value (1-25): ");
    scanf("%d", &k);
    if (k < 1 || k > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25.\n");
        return 1;
    }
    caesarCipher(text, k);
    printf("Encrypted text: %s\n", text);

    return 0;
}