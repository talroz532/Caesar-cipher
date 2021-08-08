#define _CRT_SECURE_NO_WARNINGS

#include "encryption.h"
#include <stdio.h>
#include <string.h>

void timer(char time_buffer[30]);


int main(int argc, char* argv[])
{
	char message[256];
	int key;

	char time_buffer[30];
	timer(time_buffer);


	if (argc == 2) {

		if (strcmp(argv[1], "decrypt") == 0) {

			printf("Enter a message to decrypt: ");
			fgets(message, 256, stdin);
			printf("Enter key: ");
			if (scanf("%d", &key) != 1) {
				printf("input error");
				exit(1);
			}
			decrypted(message, key);
			printf("decrypted: %s", message);
		}
		else if (strcmp(argv[1], "encrypt") == 0) {

			int checker = mkdir("C:\\encrypted");
			if (!checker) {
				printf("Directory created\n");
			}


			char* file_dir = "C:\\encrypted\\test1.txt";
			FILE* fptr;
			fptr = fopen(file_dir, "a");

			if (fptr == NULL) {
				printf("Error file opening");
				exit(1);
			}

			printf("Enter a message to encrypt: ");
			fgets(message, 256, stdin);
			printf("Enter key: ");

			if (scanf("%d", &key) != 1) {
				printf("input error");
				exit(1);
			}



			encrypted(message, key);
			printf("encrypted-> %s", message);
			fprintf(fptr, "%s |KEY %d| : %s", time_buffer, key, message );

			fclose(fptr);
		}
		else {
			printf("error, please type (decrypt/encrypt)");
			exit(1);
		}

	}
	else {
		printf("no argument were entered (decrypt/encrypt).\n");
	}

	
	return 0;
}


void timer(char time_buffer[30]) {
	time_t timer;
	struct time* time_info;

	timer = time(NULL);
	time_info = localtime(&timer);

	strftime(time_buffer, 30, "[%Y-%m-%d %H:%M:%S]", time_info);
}
