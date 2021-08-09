#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "encryption.h"

void encrypted(char message[256], int key) {
	char ch;

	for (int i = 0; message[i] != '\0'; ++i) {
		ch = message[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			message[i] = ch;
		}
	}

}

void decrypted(char message_buff[256], int key) {

	char ch;

	for (int i = 0; message_buff[i] != '\0'; ++i) {
		ch = message_buff[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;
			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}
			message_buff[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;
			if (ch < 'A') {
				ch = ch + 'Z' - 'A' + 1;
			}
			message_buff[i] = ch;
		}
	}

}
