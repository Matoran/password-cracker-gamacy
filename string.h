#ifndef STRING_H
#define STRING_H
#define ALPHABET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!*"
#define LENGTH_ALPHABET 65

char *jumpToAlphabet(unsigned long long int nb, char *result);

char *jumpToAlphabetRelative(unsigned int jump, char *actualString);

char *inverseString(char *string);

int searchLetterInAlphabet(char character);

#endif
