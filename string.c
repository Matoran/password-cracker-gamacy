#include "string.h"
#include <string.h>
#include <stdlib.h>
    
/*char[] nextString(char[] actualString){
        
}*/

char* jumpToAlphabet(unsigned long long int nb, int nbAlphabet){
	//char letters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!*";
	//char letters[] = "01";
    char* result = malloc(sizeof(char)*20);
	result[19] = '\0';
    unsigned long long int integerDivision = nb;
    unsigned long long int mod = 0;
	unsigned long long int counter = 0;
    while(1){
        mod = integerDivision % nbAlphabet;
        integerDivision /= nbAlphabet;

        if(mod == 0){
            mod = nbAlphabet;
            integerDivision--;
        }

        if(integerDivision  == 0){
			//printf("%d\n",mod);
            result[counter] = ALPHABET[mod-1];

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
