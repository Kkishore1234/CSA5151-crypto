#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void decryptSubstitution(char *ciphertext, char *plaintext) {
    char substitution[256];
    memset(substitution, 0, sizeof(substitution));
    substitution['5'] = 't';   
    substitution['8'] = 'h';   
    substitution['3'] = 'e';   
    substitution['4'] = 'o';   
    substitution['1'] = 'a';   
    substitution['6'] = 'r';   
    substitution['9'] = 'i';   
    substitution['0'] = 'n';  
    substitution[';'] = 's';   
    substitution['('] = 'd';   
    substitution[')'] = 'l';  
    substitution['†'] = 'c';   
    substitution['¶'] = 'm';   
    substitution[':'] = 'u';   
    substitution['['] = 'v';   
    substitution[']'] = 'w';  
    substitution['*'] = 'f';   
    substitution['?'] = 'g';  
    substitution['—'] = 'y';   
    substitution['.'] = 'p';   

    int len = strlen(ciphertext);
    int i;
    for (i = 0; i < len; ++i) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = substitution[ciphertext[i]];
        } else {
            plaintext[i] = ciphertext[i];  
        }
    }
    plaintext[len] = '\0';  
}

int main() {
	 printf("Kkishore");	
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
                        "(88)5*†;46(;88*96*?;8)‡(;485);5†2:‡(;4956*2(5—4)8¶8*"
                        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    char plaintext[1000];

    decryptSubstitution(ciphertext, plaintext);

    printf("Decrypted plaintext:\n%s\n", plaintext);
     printf("Kkishore");

    return 0;
}