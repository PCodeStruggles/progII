#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/charArrayQueue.h"
#include "./unity/unity.h"

void setUp(void) { return; }

void tearDown(void) { return; }

void mkQueueTest(void)
{
    CharQueueADT q = mkQueue();
    TEST_ASSERT_NOT_NULL(q);
}

void enqueueTest_PushNodeIntoEmptyQ(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    char expected[] = {'A'};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a, 1);
    TEST_ASSERT_EQUAL_size_t(1, q->size);
    TEST_ASSERT_EQUAL_INT(1, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY, q->capacity);
}

void enqueueTest_AppendNodeWithinCapacity(void)
{
    size_t nSampleElements = 3;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 3;
    q->a = sample;
    q->front = 0;
    q->rear = 3;
    bool ret = enqueue(q, 'D');
    char expected[] = {'A', 'B', 'C', 'D'};
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a, 4);
    TEST_ASSERT_EQUAL_INT(4, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY, q->capacity);
    free(sample);
}

void enqueueTest_AppendNodeExceedingCapacity(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 0;
    q->rear = 8;
    bool ret = enqueue(q, 'Z');
    char expected[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'Z'};
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a, 9);
    TEST_ASSERT_EQUAL_INT(9, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY * 2, q->capacity);
    free(sample);
}

void enqueueTest_PushNodeWhenRearLessThanFront(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 7;
    q->a = sample;
    q->front = 1;
    q->rear = 8;
    bool ret = enqueue(q, 'Z');
    char expected[] = {'Z', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a, 8);
    TEST_ASSERT_EQUAL_INT(8, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY, q->capacity);
    free(sample);
}

void enqueueTest_PushNodeWhenRearAndFrontEqual(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'F', 'G', 'H', 'A', 'B', 'C', 'D', 'E'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 3;
    q->rear = 3;
    bool ret = enqueue(q, 'Z');
    char expected[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'Z'};
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a, 9);
    TEST_ASSERT_EQUAL_INT(9, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY*2, q->capacity);
}

void enqueueTest_PassingNULLPointer(void)
{
    CharQueueADT q = NULL;
    bool ret = enqueue(q, 'Z');
    TEST_ASSERT_FALSE(ret);
}

void dequeueTest_(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 0;
    q->rear = 8;
    char res;
    bool ret = dequeue(q, &res);
    char expected[] = {'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, q->a + 1, 7);
    TEST_ASSERT_EQUAL_INT(7, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY, q->capacity);
    free(sample);
}

void dequeueTest_DequeueFromEmptyQ(void)
{
    CharQueueADT q = mkQueue();
    char res;
    bool ret = dequeue(q, &res);
    TEST_ASSERT_FALSE(ret);
}

void dequeueTest_PassingNULLPointer(void)
{
    CharQueueADT q = NULL;
    char res;
    bool ret = dequeue(q, &res);    
    TEST_ASSERT_FALSE(ret);
}

void dequeueTest_EmptyingQueue(void)
{
    size_t nSampleElements = 1;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) { 'A' }, nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 1;
    q->a = sample;
    q->front = 0;
    q->rear = 1;
    char res;
    bool ret = dequeue(q, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    TEST_ASSERT_EQUAL_INT(0, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY/2, q->capacity);
}

void dequeueTest_DequeueingLeadsToArrayShrinking(void)
{
    size_t nSampleElements = 2;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 2;
    q->a = sample;
    q->front = 0;
    q->rear = 2;
    char res;
    bool ret = dequeue(q, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    TEST_ASSERT_EQUAL_INT(1, q->size);
    TEST_ASSERT_EQUAL_INT(INITIAL_CAPACITY/2, q->capacity);
}

void peekTest_(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 0;
    q->rear = 8;
    char res;
    bool ret = peek(q, 0, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    free(sample);
}


void peekTest_PositionOutOfBound(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 0; // letter: E
    q->rear = 8; // letter: C
    char res;
    bool ret = peek(q, 9, &res);
    TEST_ASSERT_FALSE(ret);
    //TEST_ASSERT_EQUAL_CHAR('G', res);
    free(sample);
}

void peekTest_lastElement(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 0;
    q->rear = 8;
    char res;
    bool ret = peek(q, 7, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('H', res);
    free(sample);
}

void peekTest_RearLessThanFront(void)
{
    size_t nSampleElements = 8;
    char* sample = malloc(sizeof(char) * nSampleElements);
    memcpy(sample, (char[]) {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    },
    nSampleElements * sizeof(char));
    CharQueueADT q = mkQueue();
    q->capacity = INITIAL_CAPACITY;
    q->size = 8;
    q->a = sample;
    q->front = 4; // letter: E
    q->rear = 2; // letter: C
    char res;
    bool ret = peek(q, 2, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('G', res);
    free(sample);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(mkQueueTest);
    RUN_TEST(enqueueTest_PushNodeIntoEmptyQ);
    RUN_TEST(enqueueTest_AppendNodeWithinCapacity);
    RUN_TEST(enqueueTest_AppendNodeExceedingCapacity);
    RUN_TEST(enqueueTest_PushNodeWhenRearLessThanFront);
    RUN_TEST(enqueueTest_PushNodeWhenRearAndFrontEqual);
    RUN_TEST(enqueueTest_PassingNULLPointer);
    RUN_TEST(dequeueTest_);
    RUN_TEST(dequeueTest_DequeueFromEmptyQ);
    RUN_TEST(dequeueTest_EmptyingQueue);
    RUN_TEST(dequeueTest_PassingNULLPointer);
    RUN_TEST(dequeueTest_DequeueingLeadsToArrayShrinking);
    RUN_TEST(peekTest_);
    RUN_TEST(peekTest_lastElement);
    RUN_TEST(peekTest_RearLessThanFront);
    RUN_TEST(peekTest_PositionOutOfBound);
    UNITY_END();
    return 0;
}
