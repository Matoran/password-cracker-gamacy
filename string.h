#ifndef STRING_H
#define STRING_H
#define ALPHABET "ABC"
#define LENGTH_ALPHABET 3

char *jumpToAlphabet(unsigned long long int nb, char *result);

char *jumpToAlphabetRelative(unsigned int jump, char *actualString);

char *inverseString(char *string);

int searchLetterInAlphabet(char character);

#endif
