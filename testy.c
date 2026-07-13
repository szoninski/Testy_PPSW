#include <stdio.h>
#include <string.h>


#include "lancuchy.h"
void TestOf_CopyString(void) {
    char cString1[] = "Test poprawnosci cop1";
    char cString2[25] = "";
    printf("CopyString\n\n ");
    printf("Test 1 - ");
    // Sprawdzenie czy funkcja poprawnie kopiuje
    CopyString(cString1, cString2);
    if (strcmp(cString2, cString1) == 0) printf("OK\n\n"); else printf("Error\n\n");
}



void TestOf_eCompareString(void) {
    char cString1[] = "Testowy string 0x01";

    char cStringShorter[] = "Testowy string";

    char cStringLonger[] = "Testowy string 0x01 dlugi";

    char cDifferentString[] = "Testawy string 0x01";

    printf("eCompareString\n\n ");

    printf("Test 1 - ");


    if (eCompareString(cString1, cString1) == EQUAL) printf("OK\n"); else printf("Error\n");
    printf("Test 2 - ");



    if (eCompareString(cString1, cStringLonger) == DIFFERENT) printf("OK\n"); else printf("Error\n");
    printf("Test 3 - ");


    if (eCompareString(cString1, cStringShorter) == DIFFERENT) printf("OK\n"); else printf("Error\n");
    printf("Test 4 - ");


    if (strcmp(cString1, cDifferentString) != 0 && eCompareString(cString1, cDifferentString) == DIFFERENT)
        printf("OK\n\n"); else printf("Error\n\n");
}