#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generatePlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int i, j, k = 0;
    used['J' - 'A'] = 1;
    for (i = 0; i < strlen(key); ++i) {
        if (!used[toupper(key[i]) - 'A']) {
            matrix[k / SIZE][k % SIZE] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; ++i) {
        if (!used[i]) {
            matrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}

void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decryptPlayfair(char ciphertext[], char matrix[SIZE][SIZE], char plaintext[]) {
    int len = strlen(ciphertext);
    int i, r1, c1, r2, c2;

    for (i = 0; i < len; i += 2) {
        findPosition(matrix, ciphertext[i], &r1, &c1);
        findPosition(matrix, ciphertext[i + 1], &r2, &c2);

        if (r1 == r2) {
            plaintext[i] = matrix[r1][(c1 + SIZE - 1) % SIZE];
            plaintext[i + 1] = matrix[r2][(c2 + SIZE - 1) % SIZE];
        } else if (c1 == c2) {
            plaintext[i] = matrix[(r1 + SIZE - 1) % SIZE][c1];
            plaintext[i + 1] = matrix[(r2 + SIZE - 1) % SIZE][c2];
        } else {
            plaintext[i] = matrix[r1][c2];
            plaintext[i + 1] = matrix[r2][c1];
        }
    }
    plaintext[len] = '\0';
}

int main() {
	 printf("Kkishore");
    char key[] = "MONARCHY";
    char matrix[SIZE][SIZE];
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char plaintext[1000];

    generatePlayfairMatrix(key, matrix);

    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    decryptPlayfair(ciphertext, matrix, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}