#include <stdio.h>

#include "../include/linkedListQueue.h"
#include "./unity/unity.h"

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

// mkQueue() Tests

void mkQueue_basic(void)
{
    CharQueueADT q =  mkQueue();
    TEST_ASSERT_NOT_NULL(q);
    TEST_ASSERT_NULL(q->front);
    TEST_ASSERT_NULL(q->rear);
    TEST_ASSERT_EQUAL_size_t(0, q->size);
}

// dsQueue() Tests
// void dsQueue(CharQueueADT *pq);

void dsQueue_basic(void)
{
    CharQueueADT q = mkQueue();
    dsQueue(&q);
    TEST_ASSERT_NULL(q);
}

// enqueue Tests
// bool enqueue(CharQueueADT q, const char e);

void enqueue_basic(void)
{
    CharQueueADT q = mkQueue();
    TEST_ASSERT_NOT_NULL(q);
    bool ret = enqueue(q, 'A');
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_size_t(1, q->size);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
}

void enqueue_passingNULLPointer(void)
{
    CharQueueADT q = NULL;
    bool ret = enqueue(q, 'A');
    TEST_ASSERT_FALSE(ret);
}

void enqueue_MultipleNodes(void)
{
    CharQueueADT q = mkQueue();
    TEST_ASSERT_NOT_NULL(q);
    bool ret = enqueue(q, 'A');
    ret = enqueue(q, 'B');
    ret = enqueue(q, 'C');
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_size_t(3, q->size);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('C', q->rear->data);
}

// dequeue Tests
// bool dequeue(CharQueueADT q, char*res);

void dequeue_basic(void)
{
    CharQueueADT q = mkQueue();
    TEST_ASSERT_NOT_NULL(q);
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    char res;
    bool ret = dequeue(q, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    TEST_ASSERT_EQUAL_size_t(2, q->size);
    TEST_ASSERT_EQUAL_CHAR('B', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('C', q->rear->data);
}

void dequeue_passingQNULLPointer(void)
{
    CharQueueADT q = NULL;
    char res;
    bool ret = dequeue(q, &res);
    TEST_ASSERT_FALSE(ret);
}

void dequeue_passingCharNULLPointer(void)
{
    CharQueueADT q = mkQueue();
    bool ret = dequeue(q, NULL);
    TEST_ASSERT_FALSE(ret);
}

// isEmpty Tests
// bool isEmpty(CharQueueADT q);

void isEmpty_emptyQ(void)
{
    CharQueueADT q = mkQueue();
    bool ret = isEmpty(q);
    TEST_ASSERT_TRUE(ret);
}

void isEmpty_notEmptyQ(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    bool ret = isEmpty(q);
    TEST_ASSERT_FALSE(ret);
}

void isEmpty_passingNULLPointer(void)
{
    bool ret = isEmpty(NULL);
    TEST_ASSERT_FALSE(ret);
}

void isEmpty_emptyQAfterDequeueing(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    char res;
    dequeue(q, &res);
    bool ret = isEmpty(q);
    TEST_ASSERT_TRUE(ret);
}

// size Tests
// int size(CharQueueADT q)

void size_basic(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    TEST_ASSERT_EQUAL_size_t(1, size(q));
}

void size_MultipleNodes(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    TEST_ASSERT_EQUAL_size_t(4, size(q));
}

void size_enqueueingAndDequeueingNodes(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    dequeue(q, &res);
    TEST_ASSERT_EQUAL_size_t(3, size(q));
}

void size_passingNULLPointer(void)
{
    TEST_ASSERT_EQUAL_size_t(0, size(NULL));
}

// peek Tests
// bool peek(CharQueueADT q, int position, char* res)

void peek_basic(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    bool ret = peek(q, 0, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', res);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('D', q->rear->data);
    TEST_ASSERT_EQUAL_size_t(4, q->size);
}

void peek_middlePosition(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    bool ret = peek(q, 2, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('C', res);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('D', q->rear->data);
    TEST_ASSERT_EQUAL_size_t(4, q->size);
}

void peek_lastPosition(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    bool ret = peek(q, q->size-1, &res);
    TEST_ASSERT_TRUE(ret);
    TEST_ASSERT_EQUAL_CHAR('D', res);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('D', q->rear->data);
    TEST_ASSERT_EQUAL_size_t(4, q->size);
}

void peek_negativePosition(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    bool ret = peek(q, -1, &res);
    TEST_ASSERT_FALSE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('D', q->rear->data);
    TEST_ASSERT_EQUAL_size_t(4, q->size);
}

void peek_outOfBoundsPosition(void)
{
    CharQueueADT q = mkQueue();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    char res;
    bool ret = peek(q, q->size, &res);
    TEST_ASSERT_FALSE(ret);
    TEST_ASSERT_EQUAL_CHAR('A', q->front->data);
    TEST_ASSERT_EQUAL_CHAR('D', q->rear->data);
    TEST_ASSERT_EQUAL_size_t(4, q->size);
}

void peek_passingQNULLPointer(void)
{
    char ret;
    bool res = peek(NULL, 0, &ret);
    TEST_ASSERT_FALSE(res);
}

void peek_passingCharNULLPointer(void)
{
    CharQueueADT q = mkQueue();
    bool res = peek(q, 0, NULL);
    TEST_ASSERT_FALSE(res);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(mkQueue_basic);
    RUN_TEST(dsQueue_basic);
    RUN_TEST(enqueue_basic);
    RUN_TEST(enqueue_passingNULLPointer);
    RUN_TEST(enqueue_MultipleNodes);
    RUN_TEST(dequeue_basic);
    RUN_TEST(dequeue_passingQNULLPointer);
    RUN_TEST(dequeue_passingCharNULLPointer);
    RUN_TEST(isEmpty_emptyQ);
    RUN_TEST(isEmpty_notEmptyQ);
    RUN_TEST(isEmpty_passingNULLPointer);
    RUN_TEST(isEmpty_emptyQAfterDequeueing);
    RUN_TEST(size_basic);
    RUN_TEST(size_MultipleNodes);
    RUN_TEST(size_enqueueingAndDequeueingNodes);
    RUN_TEST(size_passingNULLPointer);
    RUN_TEST(peek_basic);
    RUN_TEST(peek_middlePosition);
    RUN_TEST(peek_lastPosition);
    RUN_TEST(peek_negativePosition);
    RUN_TEST(peek_outOfBoundsPosition);
    RUN_TEST(peek_passingQNULLPointer);
    RUN_TEST(peek_passingCharNULLPointer);
    UNITY_END();
    return 0;
}
