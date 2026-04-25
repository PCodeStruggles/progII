#include "../unity/unity.h"
#include "../include/ram.h"

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
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NULL(n);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
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
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(4, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(8, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(8, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(2, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    n = allocram(16, r);
    TEST_ASSERT_NOT_NULL_MESSAGE(n, "n null");
    TEST_ASSERT_EQUAL_INT(OCCUPATO, n->s);
    dumpRam("output_bigalloc.txt", r);
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
    UNITY_END();
    return 0;
}

