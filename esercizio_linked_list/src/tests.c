#include <stdio.h>

#include "../include/list_iter.h"

int main(void)
{
    // fromTo_iter TESTS
    printf("----------------------\n");
    printf("fromTo_iter tests\n");
    printf("----------------------\n");
    
    printf("fromTo_iter(2, 4)\n");
    ListNodePtr fromToList = fromTo_iter(2, 4);
    printList(fromToList);
    printf("\n");
    printf("fromTo_iter(0, 10)\n");
    fromToList = fromTo_iter(0, 10);
    printList(fromToList);
    printf("\n");
    printf("fromTo_iter(0, 0)\n");
    fromToList = fromTo_iter(0, 0);
    printList(fromToList);
    printf("\n");
    printf("fromTo_iter(5, 4)\n");
    fromToList = fromTo_iter(5, 4);
    printList(fromToList);
    printf("\n");
    printf("fromTo_iter(100, 120)\n");
    fromToList = fromTo_iter(100, 120);
    printList(fromToList);
    printf("\n");
    printf("fromTo_iter(-2, -1)\n");
    fromToList = fromTo_iter(-2, -1);
    printList(fromToList);    
    printf("\n");    
    printf("fromTo_iter(-1, -2)\n");
    fromToList = fromTo_iter(-1, -2);
    printList(fromToList);    
    printf("\n");

    // include_iter TESTS
    printf("----------------------\n");
    printf("include_iter tests\n");
    printf("----------------------\n");
    
    ListNodePtr ls1 = fromTo_iter(1,3);
    ListNodePtr ls2 = fromTo_iter(1,3);
    printf("ls1: ");
    printList(ls1);
    printf("\n");
    printf("ls2: ");
    printList(ls2);
    printf("\n");
    printf("ls1 included in ls2: %s\n", included_iter(ls1, ls2) ? "Yes" : "No");

    ls1 = fromTo_iter(1,5);
    ls2 = fromTo_iter(1,3);
    printf("ls1: ");
    printList(ls1);
    printf("\n");
    printf("ls2: ");
    printList(ls2);
    printf("\n");
    printf("ls1 included in ls2: %s\n", included_iter(ls1, ls2) ? "Yes" : "No");

    ls1 = fromTo_iter(1,10);
    ls2 = fromTo_iter(1,15);
    printf("ls1: ");
    printList(ls1);
    printf("\n");
    printf("ls2: ");
    printList(ls2);
    printf("\n");
    printf("ls1 included in ls2: %s\n", included_iter(ls1, ls2) ? "Yes" : "No");

    // reverse_iter TESTS
    printf("----------------------\n");
    printf("reverse_iter tests\n");
    printf("----------------------\n");
    
    ls1 = fromTo_iter(1,10);
    printf("in : ");
    printList(ls1);
    printf("\n");
    ListNodePtr ls1_reverse = reverse_iter(ls1);
    printf("out: ");
    printList(ls1_reverse);
    printf("\n");
    
    ls1 = fromTo_iter(1,1);
    printf("in : ");
    printList(ls1);
    printf("\n");
    ls1_reverse = reverse_iter(ls1);
    printf("out: ");
    printList(ls1_reverse);
    printf("\n");

    // zipSum_iter TESTS
    printf("----------------------\n");
    printf("zipSum_iter tests\n");
    printf("----------------------\n");
    
    ls1 = fromTo_iter(1,10);
    printf("ls1 : ");
    printList(ls1);
    printf("\n");
    ls2 = fromTo_iter(1,10);
    printf("ls2 : ");
    printList(ls2);
    printf("\n");
    ListNodePtr listSum = zipSum_iter(ls1, ls2);
    printf("out : ");
    printList(listSum);
    printf("\n");    

    ls1 = fromTo_iter(1,5);
    printf("ls1 : ");
    printList(ls1);
    printf("\n");
    ls2 = fromTo_iter(1,5);
    printf("ls2 : ");
    printList(ls2);
    printf("\n");
    listSum = zipSum_iter(ls1, ls2);
    printf("out : ");
    printList(listSum);
    printf("\n");

    // remove_all_iter TESTS
    printf("----------------------\n");
    printf("remove_all_iter tests\n");
    printf("----------------------\n");
    
    ls1 = fromTo_iter(1,5);
    printf("in  : ");
    printList(ls1);
    printf("\n");
    printf("remove_all_iter(&ls1, 3)\n");
    remove_all_iter(&ls1, 3);
    printf("out : ");
    printList(ls1);
    printf("\n");
    
    ls1 = fromTo_iter(1,5);
    listAppendNode(ls1, 20);
    listAppendNode(ls1, 12);
    listAppendNode(ls1, 20);    
    printf("in  : ");
    printList(ls1);
    printf("\n");
    printf("remove_all_iter(&ls1, 20)\n");
    remove_all_iter(&ls1, 20);
    printf("out : ");
    printList(ls1);
    printf("\n");

    // duplicate_even_iter TESTS
    printf("----------------------\n");
    printf("duplicate_even_iter tests\n");
    printf("----------------------\n");

    ls1 = fromTo_iter(1,10);
    printf("in  : ");
    printList(ls1);
    printf("\n");
    printf("duplicate_even_iter(&ls1)\n");
    duplicate_even_iter(&ls1);
    printf("out  : ");
    printList(ls1);
    printf("\n");    
    return 0;
}
