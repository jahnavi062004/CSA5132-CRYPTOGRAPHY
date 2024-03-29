#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char decrypt(char ch, int a, int b) {
    int inverse_a = -1;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            inverse_a = i;
            break;
        }
    }

    if (ch >= 'A' && ch <= 'Z') {
        return (((inverse_a * ((ch - 'A') - b + 26)) % 26) + 'A');
    } else if (ch >= 'a' && ch <= 'z') {
        return (((inverse_a * ((ch - 'a') - b + 26)) % 26) + 'a');
    } else {
        return ch;
    }
}

char findMostFrequentLetter(char *ciphertext) {
    int freq[26] = {0};

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            freq[ciphertext[i] - 'A']++;
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            freq[ciphertext[i] - 'a']++;
        }
    }

    int maxFreq = 0;
    char mostFrequentLetter;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentLetter = 'A' + i;
        }
    }

    return mostFrequentLetter;
}

int main() {
    char ciphertext[1000];
    char mostFrequentLetter = 'B'; 
    char secondMostFrequentLetter = 'U'; 

    printf("Enter the ciphertext: ");
    scanf(" %[^\n]", ciphertext);

    int a, b;
    a = (secondMostFrequentLetter - mostFrequentLetter + 26) % 26;

    printf("Possible plaintexts:\n");
    for (b = 0; b < 26; b++) {
        printf("a = %d, b = %d: ", a, b);
        for (int i = 0; ciphertext[i] != '\0'; i++) {
            printf("%c", decrypt(ciphertext[i], a, b));
        }
        printf("\n");
    }

    return 0;
}

