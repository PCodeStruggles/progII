#include "../include/ram.h"
#include "../unity/unity.h"

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

/* initram tests */

void initram_normalCase(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
}

void initram_sizeNotPowerOf2(void)
{
    int size = 7;
    RAM r = initram(size);
    TEST_ASSERT_NULL_MESSAGE(r, "r not null");
}

void initram_sizeNegative(void)
{
    int size = -1;
    RAM r = initram(size);
    TEST_ASSERT_NULL_MESSAGE(r, "r not null");
}

/* allocram tests */

void allocram_EmptyTreeWithKsmallerThanRootSize(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
}

void allocram_OneNodeAllocatedAndTryingToAllocateRightSibling(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
}

void allocram_noSpaceAvailable(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NULL(n);
}

void allocram_multiplesAllocations(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(8, r);
    TEST_ASSERT_NULL_MESSAGE(n, "n = alloc(8, r) should fail and return NULL");
    n = allocram(2, r);
    TEST_ASSERT_NULL_MESSAGE(n, "n = alloc(2, r) should fail and return NULL");
}

void allocram_bigAlloc(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->lbuddy->s, "r->lbuddy->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s, "r->rbuddy->s != LIBERO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->rbuddy->s, "r->rbuddy->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->rbuddy->s, "r->rbuddy->rbuddy->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    // dumpRam("bigAlloc.txt", r);
}

void allocram_allocFailWhenTreeisFull(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->lbuddy->s, "r->lbuddy->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s, "r->rbuddy->s != LIBERO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->rbuddy->s, "r->rbuddy->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->rbuddy->s, "r->rbuddy->rbuddy->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(2, r);
    TEST_ASSERT_NULL_MESSAGE(n, "n = allocram(2, r) should return NULL");
}

void allocram_allocationTakesWholeRam(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(8, r);
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
}

void allocram_allocationOfNegativeK(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(-5, r);
    TEST_ASSERT_NULL(n);
}

void allocram_negativeAllocAfterSuccessfulAlloc(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(-10, r);
    TEST_ASSERT_NULL(n);
}

void allocram_passingNULLPoiter(void)
{
    RAM r = NULL;
    RAM n = allocram(10, r);
    TEST_ASSERT_NULL(n);
}

/* deallocram tests */

void deallocram_deallocCausesInternalParentNodeToBecomeLeaf(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->lbuddy->s, "r->lbuddy->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s, "r->rbuddy->s != LIBERO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n->parent->lbuddy, "n->parent->lbuddy should not be NULL");
    TEST_ASSERT_NOT_NULL_MESSAGE(n->parent->rbuddy, "n->parent->rbuddy should not be NULL");
    Risultato res = deallocram(n);
    TEST_ASSERT_EQUAL_INT_MESSAGE(OK, res, "Risultato res = deallocram(n) should return OK");
}

void deallocram_deallocDoesNotCauseInternalParentNodeToBecomeLeaf(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->lbuddy->s, "r->lbuddy->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s, "r->rbuddy->s != LIBERO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n->parent->lbuddy, "n->parent->lbuddy should not be NULL");
    TEST_ASSERT_NOT_NULL_MESSAGE(n->parent->rbuddy, "n->parent->rbuddy should not be NULL");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    Risultato res = deallocram(n);
    TEST_ASSERT_EQUAL_INT_MESSAGE(OK, res, "Risultato res = deallocram(n) should return OK");
}

void deallocram_passingNULLPointer(void)
{
    Risultato res = deallocram(NULL);
    TEST_ASSERT_EQUAL_INT_MESSAGE(NOK, res, "Risultato res = deallocram(NULL) should return NOK");
}

/* numfree tests */

void numfree_justRootAllocated(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    int res = numfree(r);
    TEST_ASSERT_EQUAL_INT(size, res);
}

void numfree_justOneNodeAllocated(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    int res = numfree(r);
    TEST_ASSERT_EQUAL_INT(12, res);
}

void numfree_justTwoNodeAllocated(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    n = allocram(4, r);
    int res = numfree(r);
    TEST_ASSERT_EQUAL_INT(8, res);
}

void numfree_ThreeNodeAllocated(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    n = allocram(4, r);
    n = allocram(4, r);
    int res = numfree(r);
    TEST_ASSERT_EQUAL_INT(4, res);
}

void numfree_fullTree(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    n = allocram(4, r);
    n = allocram(4, r);
    n = allocram(4, r);
    int res = numfree(r);
    TEST_ASSERT_EQUAL_INT(0, res);
}

void numfree_passingNULLPointer(void)
{
    int res = numfree(NULL);
    TEST_ASSERT_EQUAL_INT(0, res);
}

/* ram2str tests */

void ram2str_justRootAllocated(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    char *ramstr = ram2str(r);
    TEST_ASSERT_EQUAL_STRING("8 f##", ramstr);
}

void ram2str_rootAllocatedWith2EmptyChildren(void)
{
    int size = 8;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s should be OCCUPATO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s,
                                  "r->rbuddy-> shoudl be LIBERO");
    char *ramstr = ram2str(r);
    dumpRam("ram2str.txt", r);
    TEST_ASSERT_EQUAL_STRING("8 io##f##", ramstr);
}

void ram2str_bigAlloc(void)
{
    int size = 16;
    RAM r = initram(size);
    TEST_ASSERT_NOT_NULL_MESSAGE(r, "r null");
    TEST_ASSERT_EQUAL_INT(size, r->KB);
    TEST_ASSERT_EQUAL_INT(LIBERO, r->s);
    TEST_ASSERT_NULL_MESSAGE(r->parent, "r->parent not null");
    TEST_ASSERT_NULL_MESSAGE(r->lbuddy, "r->lbuddy not null");
    TEST_ASSERT_NULL_MESSAGE(r->rbuddy, "r->rbuddy not null");
    RAM n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->s, "r->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->lbuddy->s,
                                  "r->lbuddy->s != INTERNO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->s, "r->rbuddy->s != LIBERO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_EQUAL_INT_MESSAGE(INTERNO, r->rbuddy->s,
                                  "r->rbuddy->s != INTERNO");
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    TEST_ASSERT_EQUAL_INT_MESSAGE(LIBERO, r->rbuddy->rbuddy->s,
                                  "r->rbuddy->rbuddy->s != OCCUPATO");
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n = allocram(4, r) returned NULL");
    TEST_ASSERT_EQUAL_INT_MESSAGE(OCCUPATO, n->s, "n->s != OCCUPATO");
    dumpRam("bigAlloc.txt", r);
    char *ramstr = ram2str(r);
}

void ram2str_passingNULL(void)
{
    const char* ramstr = ram2str(NULL);
    TEST_ASSERT_EQUAL_STRING("#", ramstr);
}

/* str2ram tests */

void str2ram_testing(void)
{
    char* strTree = "16 iio##o##io##o##";
    RAM r = str2ram(strTree);
    dumpRam("str2ram.txt", r);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(initram_normalCase);
    RUN_TEST(initram_sizeNotPowerOf2);
    RUN_TEST(initram_sizeNegative);
    RUN_TEST(allocram_EmptyTreeWithKsmallerThanRootSize);
    RUN_TEST(allocram_OneNodeAllocatedAndTryingToAllocateRightSibling);
    RUN_TEST(allocram_noSpaceAvailable);
    RUN_TEST(allocram_allocationTakesWholeRam);
    RUN_TEST(allocram_allocationOfNegativeK);
    RUN_TEST(allocram_multiplesAllocations);
    RUN_TEST(allocram_bigAlloc);
    RUN_TEST(allocram_negativeAllocAfterSuccessfulAlloc);
    RUN_TEST(allocram_passingNULLPoiter);
    RUN_TEST(allocram_allocFailWhenTreeisFull);
    RUN_TEST(deallocram_deallocCausesInternalParentNodeToBecomeLeaf);
    RUN_TEST(deallocram_deallocDoesNotCauseInternalParentNodeToBecomeLeaf);
    RUN_TEST(deallocram_passingNULLPointer);
    RUN_TEST(numfree_justRootAllocated);
    RUN_TEST(numfree_justOneNodeAllocated);
    RUN_TEST(numfree_justTwoNodeAllocated);
    RUN_TEST(numfree_ThreeNodeAllocated);
    RUN_TEST(numfree_fullTree);
    RUN_TEST(numfree_passingNULLPointer);
    RUN_TEST(ram2str_justRootAllocated);
    RUN_TEST(ram2str_rootAllocatedWith2EmptyChildren);
    RUN_TEST(ram2str_bigAlloc);
    RUN_TEST(ram2str_passingNULL);
    RUN_TEST(str2ram_testing);
    UNITY_END();
    return 0;
}
