#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    char *key = "QWERTYUIOPASDFGHJKLZXCVBNM";

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i]))
                ciphertext[i] = tolower(key[plaintext[i] - 'a']);
            else
                ciphertext[i] = key[plaintext[i] - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0'; 
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    if (plaintext[strlen(plaintext) - 1] == '\n')
        plaintext[strlen(plaintext) - 1] = '\0';

    encrypt(plaintext, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
