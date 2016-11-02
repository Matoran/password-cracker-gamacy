/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Management of strings with specify Alphabet.
 * Language:  C
 * Date : 2 november 2016
 */

#include "string.h"
#include "stringprivate.h"
#include <string.h>

/*
 *   Convert a number to the correspondent string
 *
 *   number: value to be converted to a string
 *   string: pointer to stock result
 *
 *   returns: the build string
 */
char *jumpToAlphabet(unsigned long long int number, char *string) {
    unsigned long long int mod = 0;
    int counter = 0;
    while (number != 0) {
        mod = number % LENGTH_ALPHABET;
        number /= LENGTH_ALPHABET;
        if (mod == 0) {
            mod = LENGTH_ALPHABET;
            number--;
        }
        string[counter] = ALPHABET[mod - 1];
        counter++;
    }
    string[counter] = '\0';
    return inverseString(string);
}


/*
 *   Inverse the string
 *
 *   string: string to inverse
 *
 *   returns: pointer to string
 */
char *inverseString(char *string) {
    size_t length = strlen(string);
    char tmpChar;

    for (unsigned int i = 0; i < (length / 2); i++) {
        tmpChar = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = tmpChar;
    }
    return string;
}

/*
 *   Search the position of a letter in alphabet
 *   Not used, but useful to crack passwords with LENGTH > 11 characters
 *
 *   character: char to find
 *
 *   returns: the position in the alphabet or -1
 */
int searchLetterInAlphabet(char character) {
    for (int i = 0; i < LENGTH_ALPHABET; ++i) {
        if (ALPHABET[i] == character)
            return i;
    }
    return -1;
}

/*
 *   Jump a number of times from the actualString
 *   Not used, but useful to crack passwords with LENGTH > 11 characters
 *
 *   jump: number of jumps
 *   actualString: base of the jump
 *
 *   returns: the actualString with the jump
 */
char *jumpToAlphabetRelative(unsigned int jump, char *actualString) {
    size_t index = 0;
    size_t length = strlen(actualString);
    inverseString(actualString);
    while (jump != 0) {
        int positionAlphabet = searchLetterInAlphabet(actualString[index]);
        int mod = (positionAlphabet + jump) % LENGTH_ALPHABET;
        jump = (positionAlphabet + jump) / LENGTH_ALPHABET;
        actualString[index] = ALPHABET[mod];
        index++;
        actualString[index > length ? index : length] = '\0';
    }
    return inverseString(actualString);
}
