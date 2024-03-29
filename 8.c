#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateCipherSequence(char *keyword, char *cipherSeq) {
    int i, j, len;
    char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

    len = strlen(keyword);

    strcpy(cipherSeq, keyword);

    // Mark the letters of the keyword as used in the alphabet
    for (i = 0; i < len; i++) {
        keyword[i] = tolower(keyword[i]);
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (alphabet[j] == keyword[i]) {
                alphabet[j] = ' ';
                break;
            }
        }
    }

    for (i = 0, j = len; i < ALPHABET_SIZE; i++) {
        if (alphabet[i] != ' ') {
            cipherSeq[j++] = alphabet[i];
        }
    }

    cipherSeq[j] = '\0';
}

void encrypt(char *plaintext, char *cipherSeq, char *ciphertext) {
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                ciphertext[i] = tolower(cipherSeq[plaintext[i] - 'a']);
            } else {
                ciphertext[i] = toupper(cipherSeq[plaintext[i] - 'A']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "";
    char cipherSeq[ALPHABET_SIZE + 1]; 
    char ciphertext[100];

    generateCipherSequence(keyword, cipherSeq);
    encrypt(plaintext, cipherSeq, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
