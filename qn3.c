#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void createMatrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    int flag[26] = {0};
    flag['J' - 'A'] = 1; 
    for (i = 0; key[i] != '\0'; ++i) {
        if (key[i] == 'J') {
            key[i] = 'I'; 
        }
        if (flag[key[i] - 'A'] == 0) {
            matrix[k / SIZE][k % SIZE] = key[i];
            flag[key[i] - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; ++i) {
        if (flag[i] == 0) {
            matrix[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}
void prepareText(char text[]) {
    int i, j = 0;
    char prepared[100];
    
    for (i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            prepared[j++] = toupper(text[i]);
        }
    }
    prepared[j] = '\0';
    for (i = 0; i < j; i += 2) {
        if (prepared[i] == prepared[i + 1]) {
            for (int k = j; k > i + 1; --k) {
                prepared[k] = prepared[k - 1];
            }
            prepared[i + 1] = 'X';
            j++;
        }
    }
    if (j % 2 != 0) {
        prepared[j++] = 'X';
    }
    prepared[j] = '\0';
    
    strcpy(text, prepared);
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
void playfairEncrypt(char text[], char matrix[SIZE][SIZE]) {
    int i, row1, col1, row2, col2;
    for (i = 0; text[i] != '\0'; i += 2) {
        findPosition(matrix, text[i], &row1, &col1);
        findPosition(matrix, text[i + 1], &row2, &col2);
        
        if (row1 == row2) {
            text[i] = matrix[row1][(col1 + 1) % SIZE];
            text[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            text[i] = matrix[(row1 + 1) % SIZE][col1];
            text[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            text[i] = matrix[row1][col2];
            text[i + 1] = matrix[row2][col1];
        }
    }
}
int main() {
    char key[100], text[100];
    char matrix[SIZE][SIZE];
     printf("Kkishore");
    printf("\nEnter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    createMatrix(key, matrix);
    prepareText(text);
    playfairEncrypt(text, matrix);
    printf("Encrypted text: %s\n", text);
    return 0;
}