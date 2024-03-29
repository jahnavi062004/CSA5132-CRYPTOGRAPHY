#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void caesarCipher(char message[], int shift);

int main() {
	char message[100];
	int shift, i;

	printf("Enter a message to encrypt: ");
	fgets(message, sizeof(message), stdin);

	printf("Enter the shift value (1 to 25): ");
	scanf("%d", &shift);


	shift = shift % ALPHABET_SIZE;

	caesarCipher(message, shift);

	printf("Encrypted message: %s\n", message);

	return 0;
}

void caesarCipher(char message[], int shift) {
	int i;

	for (i = 0; message[i] != '\0'; ++i) {
		char ch = message[i];


		if (isupper(ch)) {
			message[i] = ((ch - 'A' + shift) % ALPHABET_SIZE) + 'A';
		}

		else if (islower(ch)) {
			message[i] = ((ch - 'a' + shift) % ALPHABET_SIZE) + 'a';
		}
	}
}
