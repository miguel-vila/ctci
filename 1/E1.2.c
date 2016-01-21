#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char* string) {
	int length = strlen(string);
	for (int i = 0; i < length / 2 ; ++i)
	{
		char c = string[i];
		char c2 = string[length - i - 1];
		string[i] = c2;
		string[length - i - 1] = c;
	}
}

bool eq(char* s1, char* s2) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if(l1 != l2) {
		return false;
	} else {
		for (int i = 0; i < l1; ++i)
		{
			if(s1[i]!=s2[i]) {
				return false;
			}
		}
		return true;
	}
}

void checkReverse(char* string, char* expected) {
	reverse(string);
	if(eq(string, expected)) {
		printf("OK\n");
	} else {
		printf("Fail: Expected: %s  -> Got: %s \n", expected, string);
	}
}

int main()
{
	char base1[5] = "hola";
	char expected1[5] = "aloh";
	checkReverse(base1,expected1);
	char base2[8] = "1234567";
	char expected2[8] = "7654321";
	checkReverse(base2,expected2);
	return EXIT_SUCCESS;
}