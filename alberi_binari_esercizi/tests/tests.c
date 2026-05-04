#include <stdlib.h>

#include "../include/tree_rec.h"
#include "../unity/unity.h"

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void findmin_case1(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;

    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;

    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;

    root->right->data = 15;
    int min = findMinBST(root); 
    TEST_ASSERT_EQUAL_MESSAGE(min, 5, "int min = findMinBST(root) should return 5");
}

void findmin_case2(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;
    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return;
    root->left->left->data = 2;

    int min = findMinBST(root); 
    TEST_ASSERT_EQUAL_MESSAGE(min, 2, "int min = findMinBST(root) should return 2");
}

void findmin_case3(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    int min = findMinBST(root); 
    TEST_ASSERT_EQUAL_MESSAGE(min, root->data, "int min = findMinBST(root) should return 10");
}

void findmin_NULLPointer(void)
{
    int min = findMinBST(NULL);
    TEST_ASSERT_EQUAL_MESSAGE(min, INT_MAX, "int min = findMinBST(root) should return INT_MAX");

}

void searchBST_case1(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;
    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return;
    root->left->left->data = 2;

    bool ret = searchBST(root, 2);
    TEST_ASSERT_TRUE(ret);
}

void searchBST_case2(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;
    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return;
    root->left->left->data = 2;

    bool ret = searchBST(root, 3);
    TEST_ASSERT_FALSE(ret);
}

void searchBST_case3(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;
    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return;
    root->left->left->data = 2;

    bool ret = searchBST(root, 10);
    TEST_ASSERT_TRUE_MESSAGE(ret, "bool ret = searchBST(root, 10) should return true");
}

void searchBST_case4(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    root->left = malloc(sizeof(IntTreeNode));
    if(root->left == NULL) return;
    root->left->data = 5;

    root->right = malloc(sizeof(IntTreeNode));
    if(root->right == NULL) return;
    root->right->data = 15;

    root->left->left = malloc(sizeof(IntTreeNode));
    if(root->left->left == NULL) return;
    root->left->left->data = 2;

    bool ret = searchBST(root, -1);
    TEST_ASSERT_FALSE_MESSAGE(ret, "bool ret = searchBST(root, -1) should return false");
}

void searchBST_case5(void)
{
    IntTree root = malloc(sizeof(IntTreeNode));
    if(root == NULL) return;
    root->data = 10;

    bool ret = searchBST(root, 5);
    TEST_ASSERT_FALSE_MESSAGE(ret, "bool ret = searchBST(root, 5) should return false");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(findmin_case1);
    RUN_TEST(findmin_case2);
    RUN_TEST(findmin_case3);
    RUN_TEST(findmin_NULLPointer);
    RUN_TEST(searchBST_case1);
    RUN_TEST(searchBST_case2);
    RUN_TEST(searchBST_case3);
    RUN_TEST(searchBST_case4);
    RUN_TEST(searchBST_case5);
    UNITY_END();    
    return 0;
}
