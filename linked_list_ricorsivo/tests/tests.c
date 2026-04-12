#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "../unity/unity.h"
#include "../include/list_rec.h"

void setUp(void)
{
    return;
}
void tearDown(void)
{
    return;
}

char *toString(ListNodePtr nptr)
{
    char *sout = malloc(100 * sizeof(char));

    sprintf(sout, "{");

    sprintf(sout + strlen(sout), "%d", nptr->data);
    nptr = nptr->next;
    while (nptr) {
        sprintf(sout + strlen(sout), ",%d", nptr->data);
        nptr = nptr->next;
    }

    sprintf(sout + strlen(sout), "}");

    return sout;
}

/* addNode tests */

void addNode_normalCase(void)
{
    ListNodePtr list = NULL;
    int ret = addNode(&list, 10);
    TEST_ASSERT_TRUE(ret);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{10}", listString);
}

void addNode_normalCase2(void)
{
    ListNodePtr list = NULL;
    int ret = addNode(&list, 10);
    TEST_ASSERT_TRUE(ret);
    ret = addNode(&list, 20);
    ret = addNode(&list, 30);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{10,20,30}", listString);
}

/* mkListv tests */

void mkListv_normalCase(void)
{
    ListNodePtr list = mkListv(3, 0, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2}", listString);
}

void mkListv_normalCase2(void)
{
    ListNodePtr list = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString);
}

/* fromTo_rec tests */

void fromTo_rec_normalCase(void)
{
    ListNodePtr list = fromTo_rec(0, 10);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9,10}", listString);
}

void fromTo_rec_normalCase2(void)
{
    ListNodePtr list = fromTo_rec(-5, 10);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10}", listString);
}

void fromTo_rec_mAndnEqual(void)
{
    ListNodePtr list = fromTo_rec(0, 0);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0}", listString);
}

void fromTo_rec_mGreaterThann(void)
{
    ListNodePtr list = fromTo_rec(1, 0);
    TEST_ASSERT_NULL(list);
}

/* fromTo_rec tests */

void fromTo_normalCase(void)
{
    ListNodePtr list = fromTo(0, 10);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9,10}", listString);
}

void fromTo_normalCase2(void)
{
    ListNodePtr list = fromTo(-5, 10);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10}", listString);
}

void fromTo_mAndnEqual(void)
{
    ListNodePtr list = fromTo(0, 0);
    TEST_ASSERT_NOT_NULL(list);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0}", listString);
}

void fromTo_mGreaterThann(void)
{
    ListNodePtr list = fromTo(1, 0);
    TEST_ASSERT_NULL(list);
}

/* included_rec tests */

void included_rec_normalCase(void)
{
    ListNodePtr list1 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString1);
    ListNodePtr list2 = mkListv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,2,3,4}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_TRUE(ret);
}

void included_rec_passingNULLAsList1(void)
{
    ListNodePtr list1 = NULL;
    TEST_ASSERT_NULL(list1);
    ListNodePtr list2 = mkListv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,2,3,4}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_FALSE(ret);
}

void included_rec_passingNULLAsList2(void)
{
    ListNodePtr list1 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString1);
    ListNodePtr list2 = NULL;
    TEST_ASSERT_NULL(list2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_FALSE(ret);
}

void included_rec_listEquals(void)
{
    ListNodePtr list1 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString1);
    ListNodePtr list2 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_TRUE(ret);
}

void included_rec_nonConsequentNumbers(void)
{
    ListNodePtr list1 = mkListv(3, 4, 10, 27);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{4,10,27}", listString1);
    ListNodePtr list2 = mkListv(5, 1, 4, 8, 10, 27);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,4,8,10,27}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_TRUE(ret);
}

void included_rec_nonConsequentNumbersNotIncluded(void)
{
    ListNodePtr list1 = mkListv(3, 4, 10, 27);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{4,10,27}", listString1);
    ListNodePtr list2 = mkListv(5, 1, 4, 8, 11, 27);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,4,8,11,27}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_FALSE(ret);
}

void included_rec_nonConsequentNumbersIncludedButInDiffOrder(void)
{
    ListNodePtr list1 = mkListv(3, 4, 10, 27);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{4,10,27}", listString1);
    ListNodePtr list2 = mkListv(5, 1, 4, 8, 27, 10);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,4,8,27,10}", listString2);
    int ret = included_rec(list1, list2);
    TEST_ASSERT_FALSE(ret);
}

/* reverse_rec tests */

void reverse_rec_normalCase(void)
{
    ListNodePtr list1 = mkListv(3, 4, 10, 27);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{4,10,27}", listString1);
    ListNodePtr r = reverse_rec(list1);
    const char* rString = toString(r);
    TEST_ASSERT_EQUAL_STRING("{27,10,4}", rString);
}

void reverse_rec_normalCase2(void)
{
    ListNodePtr list1 = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString1);
    ListNodePtr r = reverse_rec(list1);
    const char* rString = toString(r);
    TEST_ASSERT_EQUAL_STRING("{9,8,7,6,5,4,3,2,1,0}", rString);
}

/* zipSum_rec tests */

void zipSum_rec_normalCase(void)
{
    ListNodePtr list1 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString1);
    ListNodePtr list2 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString2);
    ListNodePtr sum = zipSum_rec(list1, list2);
    const char* sumString = toString(sum);
    TEST_ASSERT_NOT_NULL(sum);
    TEST_ASSERT_EQUAL_STRING("{2,4,6}", sumString);
}

void zipSum_rec_normalCase2(void)
{
    ListNodePtr list1 = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString1);
    ListNodePtr list2 = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString2);
    ListNodePtr sum = zipSum_rec(list1, list2);
    const char* sumString = toString(sum);
    TEST_ASSERT_NOT_NULL(sum);
    TEST_ASSERT_EQUAL_STRING("{0,2,4,6,8,10,12,14,16,18}", sumString);
}

/* zipSum tests */

void zipSum_normalCase(void)
{
    ListNodePtr list1 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString1);
    ListNodePtr list2 = mkListv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{1,2,3}", listString2);
    ListNodePtr sum = zipSum(list1, list2);
    const char* sumString = toString(sum);
    TEST_ASSERT_NOT_NULL(sum);
    TEST_ASSERT_EQUAL_STRING("{2,4,6}", sumString);
}

void zipSum_normalCase2(void)
{
    ListNodePtr list1 = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(list1);
    const char* listString1 = toString(list1);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString1);
    ListNodePtr list2 = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(list2);
    const char* listString2 = toString(list2);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString2);
    ListNodePtr sum = zipSum(list1, list2);
    const char* sumString = toString(sum);
    TEST_ASSERT_NOT_NULL(sum);
    TEST_ASSERT_EQUAL_STRING("{0,2,4,6,8,10,12,14,16,18}", sumString);
}

/* occurrences_rec tests */

void occurrences_rec_normalCase(void)
{
    ListNodePtr list = mkListv(3, 0, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2}", listString);
    int res = occurrences_rec(list, 1);
    TEST_ASSERT_EQUAL_INT(1, res);
}

void occurrences_rec_normalCase2(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences_rec(list, 1);
    TEST_ASSERT_EQUAL_INT(3, res);
}

void occurrences_rec_normalCase3(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences_rec(list, 2);
    TEST_ASSERT_EQUAL_INT(1, res);
}

void occurrences_rec_normalCase4(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences_rec(list, 5);
    TEST_ASSERT_EQUAL_INT(0, res);
}

void occurrences_rec_passingNULL(void)
{
    ListNodePtr list = NULL;
    int res = occurrences_rec(list, 5);
    TEST_ASSERT_EQUAL_INT(0, res);
}

/* occurrences tests */

void occurrences_normalCase(void)
{
    ListNodePtr list = mkListv(3, 0, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2}", listString);
    int res = occurrences(list, 1);
    TEST_ASSERT_EQUAL_INT(1, res);
}

void occurrences_normalCase2(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences(list, 1);
    TEST_ASSERT_EQUAL_INT(3, res);
}

void occurrences_normalCase3(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences(list, 2);
    TEST_ASSERT_EQUAL_INT(1, res);
}

void occurrences_normalCase4(void)
{
    ListNodePtr list = mkListv(5, 0, 1, 2, 1, 1);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,1,1}", listString);
    int res = occurrences(list, 5);
    TEST_ASSERT_EQUAL_INT(0, res);
}

void occurrences_passingNULL(void)
{
    ListNodePtr list = NULL;
    int res = occurrences(list, 5);
    TEST_ASSERT_EQUAL_INT(0, res);
}

/* remove_all_rec tests */

void remove_all_rec_normalCase(void)
{
    ListNodePtr list = mkListv(3, 0, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2}", listString);
    remove_all_rec(&list, 1);
    const char* listStringAfterRemove = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,2}", listStringAfterRemove);
}

void remove_all_rec_normalCase2(void)
{
    ListNodePtr list = mkListv(4, 0, 1, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,1,2}", listString);
    remove_all_rec(&list, 1);
    const char* listStringAfterRemove = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,2}", listStringAfterRemove);
}

void remove_all_rec_normalCase3(void)
{
    ListNodePtr list = mkListv(4, 0, 1, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,1,2}", listString);
    remove_all_rec(&list, 0);
    const char* listStringAfterRemove = toString(list);
    TEST_ASSERT_EQUAL_STRING("{1,1,2}", listStringAfterRemove);
}

/* duplicate_even_rec tests */

void duplicate_even_rec_normalCase(void)
{
    ListNodePtr list = mkListv(3, 0, 1, 2);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2}", listString);
    duplicate_even_rec(list);
    const char* duplicate = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,0,1,2,2}", duplicate);
}

void duplicate_even_rec_normalCase2(void)
{
    ListNodePtr list = mkListv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    const char* listString = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,1,2,3,4,5,6,7,8,9}", listString);
    duplicate_even_rec(list);
    const char* duplicate = toString(list);
    TEST_ASSERT_EQUAL_STRING("{0,0,1,2,2,3,4,4,5,6,6,7,8,8,9}", duplicate);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(addNode_normalCase);
    RUN_TEST(addNode_normalCase2);
    RUN_TEST(mkListv_normalCase);
    RUN_TEST(mkListv_normalCase2);
    RUN_TEST(fromTo_rec_normalCase);
    RUN_TEST(fromTo_rec_normalCase2);
    RUN_TEST(fromTo_rec_mAndnEqual);
    RUN_TEST(fromTo_rec_mGreaterThann);
    RUN_TEST(fromTo_normalCase);
    RUN_TEST(fromTo_normalCase2);
    RUN_TEST(fromTo_mAndnEqual);
    RUN_TEST(fromTo_mGreaterThann);
    RUN_TEST(included_rec_passingNULLAsList1);
    RUN_TEST(included_rec_passingNULLAsList2);
    RUN_TEST(included_rec_normalCase);
    RUN_TEST(included_rec_listEquals);
    RUN_TEST(included_rec_nonConsequentNumbers);
    RUN_TEST(included_rec_nonConsequentNumbersNotIncluded);
    RUN_TEST(included_rec_nonConsequentNumbersIncludedButInDiffOrder);
    RUN_TEST(reverse_rec_normalCase);
    RUN_TEST(reverse_rec_normalCase2);    
    RUN_TEST(zipSum_rec_normalCase);
    RUN_TEST(zipSum_rec_normalCase2);
    RUN_TEST(zipSum_normalCase);
    RUN_TEST(zipSum_normalCase2);    
    RUN_TEST(occurrences_rec_normalCase);
    RUN_TEST(occurrences_rec_normalCase2);
    RUN_TEST(occurrences_rec_normalCase3);
    RUN_TEST(occurrences_rec_normalCase4);
    RUN_TEST(occurrences_rec_passingNULL);
    RUN_TEST(occurrences_normalCase);
    RUN_TEST(occurrences_normalCase2);
    RUN_TEST(occurrences_normalCase3);
    RUN_TEST(occurrences_normalCase4);
    RUN_TEST(occurrences_passingNULL);    
    RUN_TEST(remove_all_rec_normalCase);
    RUN_TEST(remove_all_rec_normalCase2);
    RUN_TEST(remove_all_rec_normalCase3);
    RUN_TEST(duplicate_even_rec_normalCase);
    RUN_TEST(duplicate_even_rec_normalCase2);
    UNITY_END();
    return 0;
}
