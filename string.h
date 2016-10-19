#ifndef STRING_H
#define STRING_H
typedef struct Alphabet{
	char[] letters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!*";
} Alphabet;

char[] nextString(char[] actualString);    
#endif
