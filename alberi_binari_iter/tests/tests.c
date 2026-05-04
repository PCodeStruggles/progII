#include "../unity/unity.h"
#include "../include/tree_iter.h"

#include <stdlib.h>

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void putIter_case1(void)
{
    char* path = "LL";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ADDED, res);
}

void putIter_case2(void)
{
    char* path = "L";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(OVERWRITTEN, res);
}

void putIter_case3(void)
{
    char* path = "LA";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ERROR, res);
}

void putIter_case4(void)
{
    char* path = "LA";
    IntTree tree = NULL;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ERROR, res);
}

void putIter_case5(void)
{
    char* path = NULL;
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ERROR, res);
}

void putIter_case6(void)
{
    char* path = " L";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ERROR, res);
}

void putIter_case7(void)
{
    char* path = "R";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    tree->right = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->right);
    tree->right->data = 12;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(OVERWRITTEN, res);
}

void putIter_case8(void)
{
    char* path = "R";
    IntTree tree = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree);
    tree->data = 10;
    tree->left = malloc(sizeof(IntTreeNode));
    TEST_ASSERT_NOT_NULL(tree->left);
    tree->left->data = 5;
    Response res = putIter(&tree, path, 2);
    TEST_ASSERT_EQUAL_INT(ADDED, res);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(putIter_case1);
    RUN_TEST(putIter_case2);
    RUN_TEST(putIter_case3);
    RUN_TEST(putIter_case4);
    RUN_TEST(putIter_case5);
    RUN_TEST(putIter_case6);
    RUN_TEST(putIter_case7);
    RUN_TEST(putIter_case8);
    UNITY_END();
}
