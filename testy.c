#include <stdio.h>
#include <string.h>


#include "lancuchy.h"
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
    char cSourceStr3[] = "dzialania";

    printf("AppendString\n\n ");

    printf("Test 1 - ");
        // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do niepustego lancucha
    AppendString(cSourceStr1, cDestinationStr1);

    if (strcmp(cDestinationStr1, "test dzialania") == 0) printf("OK\n"); else printf("Error\n");
    printf("Test 2 - ");
        // Sprawdzenie czy funkcja poprawnie dodaje pusty lancuch do niepustego lancucha

    AppendString(cSourceStr2,cDestinationStr3);

    if (strcmp(cDestinationStr3, "test") == 0) printf("OK\n"); else printf("Error\n");
    printf("Test 3 - ");
        // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do pustego lancucha
        AppendString(cSourceStr3, cDestinationStr2);
        if (strcmp(cDestinationStr2, "dzialania") == 0) printf("OK\n\n"); else printf("Error\n\n");
    }


    void TestOf_ReplaceCharactersInString(void) {
        char cOldChar = 't';
        char cNewChar = 'l';
        char cNewString[] = "test stringu";
        printf("ReplaceCharactersInString\n\n");
        printf("Test 1 -");
        // Sprawdzenie czy funkcja poprawnie zamienia znak w lancuchu
        ReplaceCharactersInString(cNewString, cOldChar, cNewChar);
        if (strcmp(cNewString, "lesl slringu") == 0) printf("OK\n\n"); else printf("Error\n\n");
    }

    void TestOf_UIntToHexStr(void) {}
    int main() {
        TestOf_CopyString();
        TestOf_eCompareString();
        TestOf_UIntToHexStr(); //dorobić test ui to hex
        TestOf_ReplaceCharactersInString();
        return 0;
    }
