#include <stdio.h>

char encrypt(char ch, int a, int b) {
    if (ch >= 'A' && ch <= 'Z') {
        return ((a * (ch - 'A') + b) % 26) + 'A';
    } else if (ch >= 'a' && ch <= 'z') {
        return ((a * (ch - 'a') + b) % 26) + 'a';
    } else {
        return ch;
    }
}

int main() {
    int a, b,i;
    char plaintext[1000];

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);


    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);

    printf("Ciphertext: ");
    for (i = 0; plaintext[i] != '\0'; i++) {
        printf("%c", encrypt(plaintext[i], a, b));
    }
    printf("\n");



    printf("Values of a not allowed: ");
    for (i = 0; i < 26; i++) {
        if ((i * a) % 26 == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

