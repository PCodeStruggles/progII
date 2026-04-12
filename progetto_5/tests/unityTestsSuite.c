#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/intLinkedListSortedSetADT.h"
#include "../include/intSortedSetADT.h"
#include "../unity/unity.h"

void setUp(void) {};
void tearDown(void) {};

IntSortedSetADT mkSSetv(int count, ...)
{
    IntSortedSetADT set = mkSSet();

    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        sset_add(set, num);
    }
    va_end(args);
    return set;
}

char *toString(IntSortedSetADT set)
{
    char *sout = malloc(100 * sizeof(char));

    ListNodePtr nptr = set->first;
    sprintf(sout, "{");
    while (nptr) {
        if (nptr == set->first)
            sprintf(sout + strlen(sout), "%d", nptr->elem);
        else
            sprintf(sout + strlen(sout), ",%d", nptr->elem);
        nptr = nptr->next;
    }

    sprintf(sout + strlen(sout), "}");

    return sout;
}

void mkset_CreateEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(0, s->size);
}

void mkset_CreatePopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(2, 1, 2);
    char *sStringified = toString(s);
    char *expected = "{1,2}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(2, s->size);
}

void sset_add_passingNULLPointer(void)
{
    IntSortedSetADT s = NULL;
    _Bool ret = sset_add(s, 1);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_add_ItemInEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(0, s->size);
    _Bool ret = sset_add(s, 1);
    char *sStringified = toString(s);
    char *expected = "{1}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(1, s->size);
}

void sset_add_NewItemInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 4);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, 3);
    char *sStringified = toString(s);
    char *expected = "{1,2,3,4}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(4, s->size);
}

void sset_add_NewItemAtTheEndInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, 4);
    char *sStringified = toString(s);
    char *expected = "{1,2,3,4}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(4, s->size);
}

void sset_add_NewItemAtTheFrontInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, -1);
    char *sStringified = toString(s);
    char *expected = "{-1,1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(4, s->size);
}

void sset_add_DuplicatedItemInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, 2);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_add_DuplicatedItemAtTheEndInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, 3);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_add_DuplicatedItemAtTheFrontInPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_add(s, 1);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_remove_passingNULLPointer(void)
{
    IntSortedSetADT s = NULL;
    _Bool ret = sset_remove(s, 0);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_remove_RemoveItemFromEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(0, s->size);
    _Bool ret = sset_remove(s, 0);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_remove_RemoveItemNotInSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_remove(s, 4);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_remove_RemoveItemFromPopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_remove(s, 2);
    char *sStringified = toString(s);
    char *expected = "{1,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(2, s->size);
}

void sset_remove_RemoveItemFromSetHead(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_remove(s, 1);
    char *sStringified = toString(s);
    char *expected = "{2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(2, s->size);
}

void sset_remove_RemoveItemFromSetTail(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_remove(s, 3);
    char *sStringified = toString(s);
    char *expected = "{1,2}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(2, s->size);
}

void sset_member_passingNULLPointer(void)
{
    IntSortedSetADT s = NULL;
    _Bool ret = sset_member(s, 10);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_member_SearchItemFromEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(0, s->size);
    _Bool ret = sset_member(s, 1);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_member_SearchItemNotInSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_member(s, 4);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_member_SearchItemInSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_member(s, 2);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_member_SearchFirstItem(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_member(s, 1);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_member_SearchLastItem(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = sset_member(s, 3);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void isEmptySSet_passingNULLPointer(void)
{
    IntSortedSetADT s = NULL;
    _Bool ret = isEmptySSet(s);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void isEmptySSet_emptySet(void)
{
    IntSortedSetADT s = mkSSet();
    _Bool ret = isEmptySSet(s);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void isEmptySSet_PopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    _Bool ret = isEmptySSet(s);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_size_PassingNULLPointer(void)
{
    IntSortedSetADT s = NULL;
    int ret = sset_size(s);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_size_EmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    int ret = sset_size(s);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_size_PopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
    int ret = sset_size(s);
    char *sStringified = toString(s);
    char *expected = "{1,2,3}";
    TEST_ASSERT_EQUAL_STRING(expected, sStringified);
    TEST_ASSERT_EQUAL_INT(3, ret);
    TEST_ASSERT_EQUAL_size_t(3, s->size);
}

void sset_equals_passingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    _Bool ret = sset_equals(s1, s2);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_equals_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    _Bool ret = sset_equals(s1, s2);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_equals_EqualsPopulatedSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    int ret = sset_equals(s1, s2);
    char *s1Stringified = toString(s1);
    char *s2Stringified = toString(s2);
    TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_equals_DifferentPopulatedSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(3, 1, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    int ret = sset_equals(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_equals_S2SubSetofS1(void)
{
    IntSortedSetADT s1 = mkSSetv(4, 1, 2, 3, 4);
    IntSortedSetADT s2 = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(4, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    int ret = sset_equals(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_equals_S1SubSetofS2(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_equals(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_equals_S1EmptyS2Populated(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_equals(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_equals_S1NULLPointerS2Populated(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    // TEST_ASSERT_NOT_NULL(s1);
    // TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_equals(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subseteq_PassingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    _Bool ret = sset_subseteq(s1, s2);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subseteq_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    _Bool ret = sset_subseteq(s1, s2);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subseteq_S1SubSetofS2(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subseteq_S1SubSetofS2NonConsecutiveNumbers(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 4, 6, 8);
    IntSortedSetADT s2 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subseteq_S1NotSubSetofS2NonConsecutiveNumbers(void)
{
    IntSortedSetADT s1 = mkSSetv(4, 4, 6, 8, 18);
    IntSortedSetADT s2 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(4, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subseteq_S1NULLPointerS2PopulatedSet(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subseteq_S1EmptySet2PopulatedSet(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subseteq_S1PopulatedSetS2EmptySet(void)
{
    IntSortedSetADT s1 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    IntSortedSetADT s2 = mkSSet();
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(10, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(0, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subseteq_S1S2EqualSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    int ret = sset_subseteq(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subset_PassingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    _Bool ret = sset_subset(s1, s2);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subset_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    _Bool ret = sset_subset(s1, s2);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subset_S1S2EqualSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    int ret = sset_subset(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_subset_S1StrictSubsetOfS2(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 2, 3);
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_subset(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_subset_S1StrictSubsetOfS2NonConsecutiveNumbers(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 23, 98);
    IntSortedSetADT s2 = mkSSetv(10, 1, 2, 3, 4, 6, 7, 9, 23, 98, 100);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subset(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}


void sset_subset_S1NotStrictSubsetOfS2NonConsecutiveNumbers(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(10, 1, 2, 3, 4, 6, 7, 9, 23, 98, 100);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    int ret = sset_subset(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(0, ret);
}


void sset_subset_S1EmptySetS2PopulatedSet(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(4, 1, 2, 3, 4);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(4, s2->size);
    int ret = sset_subset(s1, s2);
    // char *s1Stringified = toString(s1);
    // char *s2Stringified = toString(s2);
    // TEST_ASSERT_EQUAL_STRING(s1Stringified, s2Stringified);
    TEST_ASSERT_EQUAL_INT(1, ret);
}

void sset_union_passingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    IntSortedSetADT unionSet = sset_union(s1, s2);
    TEST_ASSERT_NULL(unionSet);
}

void sset_union_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    IntSortedSetADT unionSet = sset_union(s1, s2);
    TEST_ASSERT_NOT_NULL(unionSet);
    TEST_ASSERT_EQUAL_size_t(0, unionSet->size);
}

void sset_union_S1S2PopulatedSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(10, 1, 2, 3, 4, 6, 7, 9, 23, 98, 100);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    IntSortedSetADT unionSet = sset_union(s1, s2);
    TEST_ASSERT_NOT_NULL(unionSet);
    char *unionSetString = toString(unionSet);
    char *expected = "{1,2,3,4,6,7,9,23,24,98,100}";
    TEST_ASSERT_EQUAL_STRING(expected, unionSetString);
}

void sset_union_S1S2IdenticalSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT unionSet = sset_union(s1, s2);
    TEST_ASSERT_NOT_NULL(unionSet);
    char *unionSetString = toString(unionSet);
    char *expected = "{1,24,98}";
    TEST_ASSERT_EQUAL_STRING(expected, unionSetString);
}

void sset_union_S1EmptySetS2PopulatedSet(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT unionSet = sset_union(s1, s2);
    TEST_ASSERT_NOT_NULL(unionSet);
    char *unionSetString = toString(unionSet);
    char *expected = "{1,24,98}";
    TEST_ASSERT_EQUAL_STRING(expected, unionSetString);
}

void sset_intersection_passingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    IntSortedSetADT intersection = sset_intersection(s1, s2);
    TEST_ASSERT_NULL(intersection);
}

void sset_intersection_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    IntSortedSetADT intersection = sset_intersection(s1, s2);
    TEST_ASSERT_NOT_NULL(intersection);
    TEST_ASSERT_EQUAL_size_t(0, intersection->size);
}

void sset_intersection_S1S2PopulatedSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(10, 1, 2, 3, 4, 6, 7, 9, 23, 98, 100);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    IntSortedSetADT intersection = sset_intersection(s1, s2);
    TEST_ASSERT_NOT_NULL(intersection);
    char *intersectionString = toString(intersection);
    char *expected = "{1,98}";
    TEST_ASSERT_EQUAL_STRING(expected, intersectionString);
}

void sset_intersection_S1S2IdenticalSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT intersection = sset_intersection(s1, s2);
    TEST_ASSERT_NOT_NULL(intersection);
    char *intersectionString = toString(intersection);
    char *expected = "{1,24,98}";
    TEST_ASSERT_EQUAL_STRING(expected, intersectionString);
}

void sset_intersection_S1EmptySetS2PopulatedSet(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT intersection = sset_intersection(s1, s2);
    TEST_ASSERT_NOT_NULL(intersection);
    TEST_ASSERT_EQUAL_size_t(0, intersection->size);
}


// Subtraction
void sset_subtraction_passingNULLPointers(void)
{
    IntSortedSetADT s1 = NULL;
    IntSortedSetADT s2 = NULL;
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NULL(subtraction);
}

void sset_subtraction_EmptySets(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSet();
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NOT_NULL(subtraction);
    TEST_ASSERT_EQUAL_size_t(0, subtraction->size);
}

void sset_subtraction_S1S2PopulatedSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(10, -1, 2, 3, 4, 6, 7, 9, 23, 98, 100);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(10, s2->size);
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NOT_NULL(subtraction);
    char *subtractionString = toString(subtraction);
    char *expected = "{1,24}";
    TEST_ASSERT_EQUAL_STRING(expected, subtractionString);
}

void sset_subtraction_S1S2PopulatedSetsS1GreaterThanS2(void)
{
    IntSortedSetADT s1 = mkSSetv(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    IntSortedSetADT s2 = mkSSetv(3, 1, 2, 3);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(10, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NOT_NULL(subtraction);
    char *subtractionString = toString(subtraction);
    char *expected = "{0,4,5,6,7,8,9}";
    TEST_ASSERT_EQUAL_STRING(expected, subtractionString);
}

void sset_subtraction_S1S2IdenticalSets(void)
{
    IntSortedSetADT s1 = mkSSetv(3, 1, 24, 98);
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(3, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NOT_NULL(subtraction);
    // char *subtractionString = toString(subtraction);
    // char *expected = "{1,24,98}";
    TEST_ASSERT_EQUAL_size_t(0, subtraction->size);
    // TEST_ASSERT_EQUAL_STRING(expected, subtractionString);
}

void sset_subtraction_S1EmptySetS2PopulatedSet(void)
{
    IntSortedSetADT s1 = mkSSet();
    IntSortedSetADT s2 = mkSSetv(3, 1, 24, 98);
    TEST_ASSERT_NOT_NULL(s1);
    TEST_ASSERT_EQUAL_size_t(0, s1->size);
    TEST_ASSERT_NOT_NULL(s2);
    TEST_ASSERT_EQUAL_size_t(3, s2->size);
    IntSortedSetADT subtraction = sset_subtraction(s1, s2);
    TEST_ASSERT_NOT_NULL(subtraction);
    TEST_ASSERT_EQUAL_size_t(0, subtraction->size);
}

void sset_min_passingNULLPointers(void)
{
    IntSortedSetADT s = NULL;
    int ptr;
    _Bool ret = sset_min(s, &ptr);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_min_passingEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    int ptr;
    _Bool ret = sset_min(s, &ptr);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_min_PopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 24, 98);
    int ptr;
    _Bool ret = sset_min(s, &ptr);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_INT(1, ptr);
}

void sset_min_PopulatedSetNegativeMin(void)
{
    IntSortedSetADT s = mkSSetv(4, -123,1, 24, 98);
    int ptr;
    _Bool ret = sset_min(s, &ptr);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_INT(-123, ptr);
}


void sset_max_passingNULLPointers(void)
{
    IntSortedSetADT s = NULL;
    int ptr;
    _Bool ret = sset_max(s, &ptr);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_max_passingEmptySet(void)
{
    IntSortedSetADT s = mkSSet();
    int ptr;
    _Bool ret = sset_max(s, &ptr);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void sset_max_PopulatedSet(void)
{
    IntSortedSetADT s = mkSSetv(3, 1, 24, 98);
    int ptr;
    _Bool ret = sset_max(s, &ptr);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_INT(98, ptr);
}

void sset_max_PopulatedSetBigMax(void)
{
    IntSortedSetADT s = mkSSetv(5, -123,1, 24, 98, 1231);
    int ptr;
    _Bool ret = sset_max(s, &ptr);
    TEST_ASSERT_EQUAL_INT(1, ret);
    TEST_ASSERT_EQUAL_INT(1231, ptr);
}


int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(mkset_CreateEmptySet);
    RUN_TEST(mkset_CreatePopulatedSet);
    RUN_TEST(sset_add_passingNULLPointer);
    RUN_TEST(sset_add_ItemInEmptySet);
    RUN_TEST(sset_add_NewItemInPopulatedSet);
    RUN_TEST(sset_add_NewItemAtTheEndInPopulatedSet);
    RUN_TEST(sset_add_NewItemAtTheFrontInPopulatedSet);
    RUN_TEST(sset_add_DuplicatedItemInPopulatedSet);
    RUN_TEST(sset_add_DuplicatedItemAtTheEndInPopulatedSet);
    RUN_TEST(sset_add_DuplicatedItemAtTheFrontInPopulatedSet);
    RUN_TEST(sset_remove_passingNULLPointer);
    RUN_TEST(sset_remove_RemoveItemFromEmptySet);
    RUN_TEST(sset_remove_RemoveItemFromPopulatedSet);
    RUN_TEST(sset_remove_RemoveItemNotInSet);
    RUN_TEST(sset_remove_RemoveItemFromSetHead);
    RUN_TEST(sset_remove_RemoveItemFromSetTail);
    RUN_TEST(sset_member_passingNULLPointer);
    RUN_TEST(sset_member_SearchItemFromEmptySet);
    RUN_TEST(sset_member_SearchItemNotInSet);
    RUN_TEST(sset_member_SearchItemInSet);
    RUN_TEST(sset_member_SearchFirstItem);
    RUN_TEST(sset_member_SearchLastItem);
    RUN_TEST(isEmptySSet_passingNULLPointer);
    RUN_TEST(isEmptySSet_emptySet);
    RUN_TEST(isEmptySSet_PopulatedSet);
    RUN_TEST(sset_size_PassingNULLPointer);
    RUN_TEST(sset_size_EmptySet);
    RUN_TEST(sset_size_PopulatedSet);
    RUN_TEST(sset_equals_passingNULLPointers);
    RUN_TEST(sset_equals_EmptySets);
    RUN_TEST(sset_equals_EqualsPopulatedSets);
    RUN_TEST(sset_equals_DifferentPopulatedSets);
    RUN_TEST(sset_equals_S2SubSetofS1);
    RUN_TEST(sset_equals_S1SubSetofS2);
    RUN_TEST(sset_equals_S1EmptyS2Populated);
    RUN_TEST(sset_equals_S1NULLPointerS2Populated);
    RUN_TEST(sset_subseteq_PassingNULLPointers);
    RUN_TEST(sset_subseteq_EmptySets);
    RUN_TEST(sset_subseteq_S1SubSetofS2);
    RUN_TEST(sset_subseteq_S1SubSetofS2NonConsecutiveNumbers);
    RUN_TEST(sset_subseteq_S1NotSubSetofS2NonConsecutiveNumbers);
    RUN_TEST(sset_subseteq_S1NULLPointerS2PopulatedSet);
    RUN_TEST(sset_subseteq_S1EmptySet2PopulatedSet);
    RUN_TEST(sset_subseteq_S1PopulatedSetS2EmptySet);
    RUN_TEST(sset_subseteq_S1S2EqualSets);
    RUN_TEST(sset_subset_PassingNULLPointers);
    RUN_TEST(sset_subset_S1S2EqualSets);
    RUN_TEST(sset_subset_EmptySets);
    RUN_TEST(sset_subset_S1StrictSubsetOfS2);
    RUN_TEST(sset_subset_S1EmptySetS2PopulatedSet);
    RUN_TEST(sset_subset_S1StrictSubsetOfS2NonConsecutiveNumbers);
    RUN_TEST(sset_subset_S1NotStrictSubsetOfS2NonConsecutiveNumbers);
    RUN_TEST(sset_union_passingNULLPointers);
    RUN_TEST(sset_union_EmptySets);
    RUN_TEST(sset_union_S1S2PopulatedSets);
    RUN_TEST(sset_union_S1S2IdenticalSets);
    RUN_TEST(sset_union_S1EmptySetS2PopulatedSet);
    RUN_TEST(sset_intersection_passingNULLPointers);
    RUN_TEST(sset_intersection_EmptySets);
    RUN_TEST(sset_intersection_S1S2PopulatedSets);
    RUN_TEST(sset_intersection_S1S2IdenticalSets);
    RUN_TEST(sset_intersection_S1EmptySetS2PopulatedSet);
    RUN_TEST(sset_subtraction_passingNULLPointers);
    RUN_TEST(sset_subtraction_EmptySets);
    RUN_TEST(sset_subtraction_S1S2PopulatedSets);
    RUN_TEST(sset_subtraction_S1S2IdenticalSets);
    RUN_TEST(sset_subtraction_S1EmptySetS2PopulatedSet);
    RUN_TEST(sset_subtraction_S1S2PopulatedSetsS1GreaterThanS2);
    RUN_TEST(sset_min_passingNULLPointers);
    RUN_TEST(sset_min_passingEmptySet);
    RUN_TEST(sset_min_PopulatedSet);
    RUN_TEST(sset_min_PopulatedSetNegativeMin);
    RUN_TEST(sset_max_passingNULLPointers);
    RUN_TEST(sset_max_passingEmptySet);
    RUN_TEST(sset_max_PopulatedSet);
    RUN_TEST(sset_max_PopulatedSetBigMax);    
    UNITY_END();
    return 0;
}
