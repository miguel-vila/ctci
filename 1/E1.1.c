#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool unique(char* string) {
	bool isPresent[255];
	for (int i = 0; i < 255; ++i)
	{
		isPresent[i] = false;
	}
	int length = strlen(string);
	for (int i = 0; i < length; ++i)
	{
		char c = string[i];
		if (isPresent[c])
		{
			return false;
		}
		isPresent[c] = true;
	}
	return true;
}

void testUnique(char* uniqueStr) {
	if (unique(uniqueStr))
	{
		printf("ok\n");
	} else {
		printf("FAIL\n");
	}	
}

void testNotUnique(char* notUniqueStr) {
	if (!unique(notUniqueStr))
	{
		printf("ok\n");
	} else {
		printf("FAIL\n");
	}	
}

int main(){
	testUnique( "abcdefgh;123" );
	testUnique( "-12#$%&/()=?" );
	testNotUnique( "-12#$%&/()=?1" );
	testNotUnique( "#-12#$%&/()=?1" );
	return EXIT_SUCCESS;
}