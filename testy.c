#include <stdio.h>
#include <string.h>

#include "lancuchy.h"
#include "konwersje.h"
#include "dekodowanie.h"
void TestOf_CopyString(void) {
    char cString1[] = "KK7 GOJ";
    char cString2[10] = "";
    printf("CopyString\n\n");
    printf("Test 1 - ");
    // weryfikuje czy funkcja kopiuje poprawnie

    CopyString(cString1, cString2);
    if (strcmp(cString2, cString1) == 0) printf("OK\n\n"); else printf("Error\n\n");
}


void TestOf_eCompareString(void) {
    char cString1[] = "Testowy string 0x01";

    char cStringShorter[] = "Testowy string";

    char cStringLonger[] = "Testowy string 0x01 dlugi";

    char cDifferentString[] = "Testawy string 0x01";

    printf("eCompareString\n\n");

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


void TestOf_AppendString(void) {

    char cDestinationStr1[] = "test ";
    char cDestinationStr2[] = "";
    char cDestinationStr3[] = "test";
    char cSourceStr1[] = "dzialania";
    char cSourceStr2[] = "";
    char cSourceStr3[] = "dzialania ";

    printf("AppendString\n\n");

    printf("Test 1 - ");
        // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do niepustego lancucha
    AppendString(cSourceStr1, cDestinationStr1);

    if (strcmp(cDestinationStr1, "test dzialania") == 0) printf("OK\n"); else printf("Error\n");



    printf("Test 2 - ");
        // Sprawdzenie czy funkcja poprawnie dodaje pusty lancuch do niepustego lancucha

    AppendString(cSourceStr2,cDestinationStr3);

    if (strcmp(cDestinationStr3, "test") == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - ");
    // Sprawdzenie czy funkcja poprawnie dodaje pusty lancuch do pustego lancucha
    AppendString(cSourceStr2, cDestinationStr2);
    if (strcmp(cDestinationStr2, "") == 0) printf("OK\n\n"); else printf("Error\n\n");

    }


void TestOf_ReplaceCharactersInString(void) {
        char cOldChar = 'o';
        char cNewChar = 'e';
        char cNewString[] = "kk7 goj";

        printf("ReplaceCharactersInString\n\n");

		printf("Test 1 -");
        // sprawdzam czy znaki w lancuchu sie poprawnie wymieniaja

		ReplaceCharactersInString(cNewString, cOldChar, cNewChar);
        if (strcmp(cNewString, "kk7 gej") == 0) printf("OK\n\n"); else printf("Error\n\n");
    }

//testy konwersji


void TestOf_UIntToHexStr(void) {
    char cString[15];
    printf("UIntToHexStr\n\n");
    printf("Test 1 -");
    UIntToHexStr(0x000F,cString);
    if (strcmp(cString, "0x000F") == 0) printf("OK\n\n"); else printf("Error\n");
    }

void TestOf_AppendUIntToString(void) {
    char cDestinationStr1[10] = "Test";
    char cDestinationStr2[10] = "";
    unsigned int uiValue = 1;
    printf("AppendUIntToString\n\n");
    printf("Test 1 -");

    // sprawdzenie czy funkcja poprawnie dodaje liczby do pustego lancucha znakowaego
    AppendUIntToString(uiValue, cDestinationStr1);
    if (strcmp(cDestinationStr1, "Test0x0001") == 0) printf("OK\n"); else printf("Error\n");

    //sprawdzenie czy funckja dodaje liczbe do niepustego lancucha
    printf("Test 2 -");
    AppendUIntToString(uiValue, cDestinationStr2);
    if (strcmp(cDestinationStr2, "0x0001") == 0) printf("OK\n"); else printf("Error\n");
}

void TestOf_eHexStringToUInt(void) {
    char cstring_good[] = "0x000A";
    char cstring_bad_1[] = "test";
    char cstring_bad_2[] = "0x";
    char cstring_bad_3[] = "0x12345";
    unsigned int uiResult;
    printf("eHexStringToUInt\n\n");
    printf("Test 1 - ");
    //sprawdza czy podany poprawnie lancuch dziala zgodnie z zaloezniami funkcji
    if ((eHexStringToUInt(cstring_good,&uiResult) == OK) && uiResult == 10) printf("OK\n"); else printf("Error\n\n");

    printf("Test 2 - ");
    //sprawdza czy funckaj rozpoznaje bledny zapis lancucha
    if ((eHexStringToUInt(cstring_bad_1,&uiResult) == ERROR)) printf("OK\n"); else printf("Error\n\n");
    //sprawdza czy funkcja zgodnie z zalozeniem odrzuci zbyt krotki lacouch
    printf("Test 3 - ");
    if ((eHexStringToUInt(cstring_bad_2,&uiResult) == ERROR)) printf("OK\n"); else printf("Error\n\n");
    //sprawdza czy funckaj zgodnie z zalozeniem odrzuci zbyt dlugi lancuch
    printf("Test 4 - ");
    if ((eHexStringToUInt(cstring_bad_3,&uiResult) == ERROR)) printf("OK\n"); else printf("Error\n\n");
}


int main() {
        printf("lancuchy test \n\n");
        TestOf_CopyString();
        TestOf_eCompareString();
        TestOf_ReplaceCharactersInString();
        TestOf_AppendString();


        printf("konwersje test \n\n");
        TestOf_UIntToHexStr();
        TestOf_eHexStringToUInt();
        TestOf_AppendUIntToString();

        return 0;
    }
