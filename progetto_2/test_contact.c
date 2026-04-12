#include <stdbool.h>
#include <stdio.h>

#include "src/contact.h"

typedef struct {
    Contact c1;
    Contact c2;
    int expectedOut;
} eqTestCase;

int main(void)
{
    eqTestCase eqTestCases[] = {
        {{NULL, NULL}, {NULL, NULL}, -99},					// All NULL pointers
        {{"Paolo", "Arnaudo"}, {"Paolo", "arnaudo"}, 0},			// Different surname
        {{NULL, "Arnaudo"}, {"Paolo", "Arnaudo"}, -99},				// NULL first struct name
        {{"Martina", "Giachetto-Mena"}, {NULL, "Arnaudo"},-99},			// NULL second struct name
        {{"Martina", "Giachetto-Mena"}, {"Paolo", "Arnaudo"}, 0},		// Name and surname all different
        {{"Martina", "Giachetto-Mena"}, {"Martina", "Giachetto-Mena"}, 1}	// All equal
    };

    eqTestCase cmpTestCases[] = {
        {{NULL, NULL}, {NULL, NULL}, -99},			// All NULL pointers
        {{"Paolo", "Arnaudo"}, {"Paolo", "Arnaudo", 0}},	// All surnames equal
    };

    size_t eqTestCasesLen = sizeof(eqTestCases)		/ sizeof(eqTestCases[0]);
    size_t cmpTestCasesLen = sizeof(cmpTestCases)	/ sizeof(cmpTestCases[0]);

    // contactEq unit tests
    bool allEqTestsPassed = true;
    for (size_t i = 0; allEqTestsPassed && i < eqTestCasesLen; i++) {
        int ret = contactEq(eqTestCases[i].c1, eqTestCases[i].c2);
        if (ret != eqTestCases[i].expectedOut) {
            printf("contatEq TEST %zu FAILED!\n", i);
            printf("c1.name: %s - c1.name: %s", eqTestCases[i].c1.name,
                   eqTestCases[i].c1.surname);
            printf("c2.name: %s - c2.name: %s", eqTestCases[i].c2.name,
                   eqTestCases[i].c2.surname);
            printf("Expected: %d - Got: %d\n", eqTestCases[i].expectedOut, ret);
            allEqTestsPassed = false;
        }
    }

    // contactEqEff unit tests
    bool allEqEffTestsPassed = true;
    for (size_t i = 0; allEqEffTestsPassed && i < eqTestCasesLen; i++) {
        int ret = contactEqEff(&eqTestCases[i].c1, &eqTestCases[i].c2);
        if (ret != eqTestCases[i].expectedOut) {
            printf("contactEqEff TEST %zu FAILED!\n", i);
            printf("c1.name	: %s - c1.name: %s", eqTestCases[i].c1.name,
                   eqTestCases[i].c1.surname);
            printf("c2.name	: %s - c2.name: %s", eqTestCases[i].c2.name,
                   eqTestCases[i].c2.surname);
            printf("Expected	: %d - Got: %d\n", eqTestCases[i].expectedOut, ret);
            allEqEffTestsPassed = false;
        }
    }

    // contactCmp unit tests
    bool allCmpTestsPassed = true;
    for(size_t i = 0; allCmpTestsPassed && i < cmpTestCasesLen; i++) {
        int ret = contactCmp(cmpTestCases[i].c1, cmpTestCases[i].c2);
        if(ret != cmpTestCases[i].expectedOut) {
            printf("contactCmp TEST %zu FAILED\n", i);
            printf("c1.surname	: %s\n", cmpTestCases[i].c1.surname);
            printf("c2.surname	: %s\n", cmpTestCases[i].c2.surname);
            printf("Expedcted	: %d - Got: %d\n", cmpTestCases[i].expectedOut, ret);
            allCmpTestsPassed = false;
        }
    }
    
    // contactCmpEff unit tests
    bool allCmpEffTestsPassed = true;
    for(size_t i = 0; allCmpEffTestsPassed && i < cmpTestCasesLen; i++) {
        int ret = contactCmpEff(&cmpTestCases[i].c1, &cmpTestCases[i].c2);
        if(ret != cmpTestCases[i].expectedOut) {
            printf("contactCmpEff TEST %zu FAILED\n", i);
            printf("c1.surname	: %s\n", cmpTestCases[i].c1.surname);
            printf("c2.surname	: %s\n", cmpTestCases[i].c2.surname);
            printf("Expedcted	: %d - Got: %d\n", cmpTestCases[i].expectedOut, ret);
            allCmpEffTestsPassed = false;
        }
    }

    if (allEqTestsPassed) {
        printf("All contactEq tests Passed!\n");
    }
    if (allEqEffTestsPassed) {
        printf("All contactEqEff tests Passed!\n");
    }
    if(allCmpTestsPassed) {
        printf("All contactCmp tests passed!\n");
    }
    if(allCmpEffTestCasesPassed) {
        printf("All contactCmpEff tests passed!\n");
    }    
}
