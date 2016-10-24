#include "string.h"
#include <string.h>
#include <stdlib.h>

/*char[] nextString(char[] actualString){

}*/

char* jumpToAlphabet(unsigned long long int nb, char *result){
	//char letters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!*";
	//char letters[] = "01";
    unsigned long long int integerDivision = nb;
    unsigned long long int mod = 0;
	unsigned long long int counter = 0;
    while(1){
        mod = integerDivision % LENGTH_ALPHABET;
        integerDivision /= LENGTH_ALPHABET;

        if(mod == 0){
            mod = LENGTH_ALPHABET;
            integerDivision--;
        }

        if(integerDivision  == 0){
			//printf("%d\n",mod);
            result[counter] = ALPHABET[mod-1];
            result[counter+1] = '\0';
			result = inverseString(result);

            return result;
        }
		//printf("%d\n",mod);
        result[counter] = ALPHABET[mod-1];
		counter++;
    }
}

char* inverseString(char* string){
	int length = strlen(string);
	char tmpChar;

	for(int i = 0; i < (length/2); i++){
		tmpChar = string[i];
		string[i] = string[length-1-i];
		string[length-1-i] = tmpChar;
	}
	return string;
}
