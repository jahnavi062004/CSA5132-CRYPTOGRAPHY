#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countFrequency(const char *text, int *frequency) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            frequency[tolower(c) - 'a']++;
        }
    }
}

void findMostFrequent(int *frequency, int *index, int *maxFrequency) {
	int i;
    for (i = 0; i < 26; i++) {
        if (frequency[i] > *maxFrequency) {
            *maxFrequency = frequency[i];
            *index = i;
        }
    }
}

int main() {
    const char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    int frequency[26] = {0};
    int maxFrequency = 0;
    int mostFrequentIndex = 0;
    int i;

    countFrequency(ciphertext, frequency);

    findMostFrequent(frequency, &mostFrequentIndex, &maxFrequency);

    int offset = (mostFrequentIndex + 26 - ('e' - 'a')) % 26;

    printf("Decrypted text:\n");
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char decrypted = ((tolower(c) - 'a' - offset + 26) % 26) + 'a';
            printf("%c", isupper(c) ? toupper(decrypted) : decrypted);
        } else {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}

