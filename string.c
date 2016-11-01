/*
 * Authors: LOPES Marco, ISELI Cyril and RINGOT Gaëtan
 * Purpose: Management of strings with specify Alphabet.
 * Language:  C
 * Year : 2016-2017
 */

#include "string.h"
#include <string.h>

/*char[] nextString(char[] actualString){

}*/

/*
 * Function: jumpToAlphabet
 * ----------------------------
 *   Returns the final string
 *
 *   nb: the value need to be evaluated 
 *   result: the string result.
 *
 *   returns: the string with the value inside. 
 */
char *jumpToAlphabet(unsigned long long int nb, char *result) {
    unsigned long long int integerDivision = nb;
    unsigned long long int mod = 0;
    int counter = 0;
    while (integerDivision != 0) {
        mod = integerDivision % LENGTH_ALPHABET;
        integerDivision /= LENGTH_ALPHABET;
        if (mod == 0) {
            mod = LENGTH_ALPHABET;
            integerDivision--;
        }
        //printf("%d\n",mod);
        result[counter] = ALPHABET[mod - 1];
        counter++;
    }
    result[counter] = '\0';
    result = inverseString(result);
    return result;
}


/*
 * Function: inverseString
 * ----------------------------
 *   Returns the string.
 *
 *   string: 
 *
 *   returns: 
 */
char *inverseString(char *string) {
    int length = strlen(string);
    char tmpChar;

    for (int i = 0; i < (length / 2); i++) {
        tmpChar = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = tmpChar;
    }
    return string;
}

int searchLetterInAlphabet(char character) {
    for (int i = 0; i < LENGTH_ALPHABET; ++i) {
        if (ALPHABET[i] == character)
            return i;
    }
    return -1;
}

char *jumpToAlphabetRelative(unsigned int jump, char *actualString) {
    int index = 0;
    int length = strlen(actualString);
    inverseString(actualString);
    while (jump != 0) {
        int positionAlphabet = searchLetterInAlphabet(actualString[index]);
        int mod = (positionAlphabet + jump) % LENGTH_ALPHABET;
        jump = (positionAlphabet + jump) / LENGTH_ALPHABET;
        actualString[index] = ALPHABET[mod];
        index++;
    }
    actualString[index > length ? index : length] = '\0';

    return inverseString(actualString);
}


