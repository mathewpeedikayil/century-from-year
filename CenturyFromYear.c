/**
 * CenturyFromYear.c
 * Created on 07/12/2023
 * Last modified on 10/12/2023
 * No copyright
 * This program takes a year and return the century.
 * Version History: 1.0 - only pure code; 2.0 - comments added.
 * 
 * @author Mathew Philip Peedikayil
 * @version 2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int calculateCentury(int year) {
    static int century = 0;

    // year 1 to year 100 (1st century)
    if(year >=1 && year <=100) {
        century = 1;
    } else {
        /* the year is converted from 
        an integer to a string. */
        int originalYear = year; // year after loop is 0.
        int numberOfDigits = 0;
        while (year != 0) {
            year /= 10;
            numberOfDigits++;
        }
        char yearAsString[numberOfDigits + 1]; // add 1 to deal with null
        sprintf(yearAsString, "%d", originalYear);
        // printf("%s\n", yearAsString);

        /* get the last two characters 
        of yearAsString */
        char lastTwoCharacters[3]; // add 1 to deal with null 
        lastTwoCharacters[0] = yearAsString[numberOfDigits - 2];
        lastTwoCharacters[1] = yearAsString[numberOfDigits - 1];
        lastTwoCharacters[2] = '\0';
        // printf("%s\n", lastTwoCharacters);

        /* checks if 00 or otherwise */
        bool containsNonZero = false;
        int i;
        for (i = 0; i < 3 && lastTwoCharacters[i] != '\0'; i++) {
            if(lastTwoCharacters[i] != '0') {
                containsNonZero = true;
                break;
            }
        }
        // printf("%d\n", containsNonZero);

        // year with three digits
        static char firstCharacter[2]; // add 1 to deal with null
        firstCharacter[0] = yearAsString[0];
        firstCharacter[1] = '\0';
        int firstCharacterInt = atoi(firstCharacter);

        // year with four digits
        static char firstTwoCharacters[3]; // add 1 to deal with null
        firstTwoCharacters[0] = yearAsString[0];
        firstTwoCharacters[1] = yearAsString[1];
        firstTwoCharacters[2] = '\0';
        int firstTwoCharactersInt = atoi(firstTwoCharacters);

        if(containsNonZero == true) {
            if(numberOfDigits == 3) {    
                century = firstCharacterInt + 1; // 370
            }
            if(numberOfDigits == 4) {    
                century = firstTwoCharactersInt + 1; // 1905
            }
        } else {
            if(numberOfDigits == 3) {    
                century = firstCharacterInt; // 300
            }
             if(numberOfDigits == 4) {    
                century = firstTwoCharactersInt; // 1900
            }
        } 
    }

    return century;
}

int main(void) {
    printf("%d\n", calculateCentury(45));
    printf("%d\n", calculateCentury(1900));
    printf("%d\n", calculateCentury(1905));
    printf("%d\n", calculateCentury(300));
    printf("%d\n", calculateCentury(370));

    return 0;
}

// gcc CenturyFromYear.c -o CenturyFromYear && CenturyFromYear

// References
// getting the last character
// https://sabe.io/blog/c-get-last-character-string

// boolean
// https://www.w3schools.com/c/c_booleans.php