#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int my_strlen(const char *str);
void cypher(char *str, const char *cypher);
void createEncoding(char *encode, char *decode);
void testIt(const char *str, char *encode, char *decode);

const int MinEncode = 48;
const int MaxEncode = 122;

int main() 
{
    srand((unsigned int)time(NULL));
    	
	char encode[129];
	char decode[129];
	createEncoding(encode, decode);
	
	printf("Encode: %s\n", encode + MinEncode); 
	printf("Decode: %s\n", decode + MinEncode); 
	
	testIt("Hello", encode, decode);
	
	testIt("Now is the time for all good people to get together!", encode, decode);

	testIt("", encode, decode);
	
    return 0;
}

void testIt(const char *str, char *encode, char *decode)
{
	int len = strlen(str);
	char *copy = (char *)calloc(len+1, sizeof(char));
	
	strcpy(copy, str);
	
	printf("\nOriginal: '%s'\n", str);
	cypher(copy, encode);
	printf(" Encoded: '%s'\n", copy);
	cypher(copy, decode);
	printf(" Decoded: '%s'\n", copy);
	
	free(copy);
}

void createEncoding(char *encode, char *decode)
{
	int i;
	
	encode[128] = 0;
	decode[128] = 0;
	
	// Fill encoding with all 256 values
	for(i=0; i<128; i++)
	{
		encode[i] = (char)i;
	}
	
	// Shuffle it
	for(i=MinEncode; i<=MaxEncode;  i++)
	{
		// Pick a random location and wap
		int j = rand() % (MaxEncode - MinEncode) + MinEncode;
		char a = encode[i];
		char b = encode[j];
		encode[i] = b;
		encode[j] = a;
	}
	
	// Create a decoding
	for(i=0; i<128; i++)
	{
		char coded = encode[i];
		decode[(unsigned int)coded] = (char)i;
	}
	
}
