//#include <QCoreApplication>
#include <stdio.h>
#include "twoLinkList.h"
#include "OneLinkList.h"

#define right 1
#define wrong 0

#define true  1
#define false 0

// 1. -----------------------------------------------------------
int getData(TwoLinkNode *n) {
    return n->dat;
}

int validation (char* sequence){
    int i =0;
    int num_parenthes =0;
    char f;
    char b;

    printf("\nChecking the correctness of the compilation\n");


    TwoLinkList *lst = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(lst);
    printTwoLinkIntList(lst);

    while (sequence[i] != 0 ){
        if (sequence[i]=='[' || sequence[i]==']' || sequence[i]=='(' ||
            sequence[i]==')' || sequence[i]=='{' || sequence[i]=='}'){
            pushFront(lst, sequence[i]);
            num_parenthes++;
        }
        i++;
    }

    if (num_parenthes == 0 || num_parenthes % 2 != 0){
        return wrong;       // 0
    }
    else{
        num_parenthes /= 2;
    }

    for (int j = 0; j < num_parenthes; ++j) {
        f = getData(remFront(lst));
        b = getData(remBack(lst));
        printf("front=%c back=%c\n", f, b);
        if( (f == '(' && b == ')') || (f == '[' && b == ']') || (f == '{' && b == '}') ||
            (b == '(' && f == ')') || (b == '[' && f == ']') || (b == '{' && f == '}') ){}
        else {
            return wrong;       // 0
        }
    }

    return right;               // 1
}


// 2.--------------------------------------------------------------------------------------------------
int getDataOne(OneLinkNode *n) {
    return n->dat;
}

void OneListCPY (void){
    int sizeList = 10;
    printf("\nOneListCPY\n");

    //--------- Init list 1 --------
    OneLinkList *lst1 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst1);
    //--------- Init list 2 ------
    OneLinkList *lst2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst2);

    //---- filling out the list 1 ---
    for (int i = 0; i < sizeList; ++i) {
        insert(lst1, i*7);
    }

    printf("List 1 - ");
    printOneLinkIntList(lst1);

    OneLinkNode *list1 = lst1->head;

    //---- copy list 1 to list 2 ---
    for (int i = 0; i < sizeList; ++i) {
        insert(lst2, getDataOne( list1+(i*2) ));
    }

    printf("List 2 - ");
    printOneLinkIntList(lst2);

    printf("List 1 after copy - ");     // control check that there are no changes in list 1
    printOneLinkIntList(lst1);
}


// 3.----------------------------------------------------------------------------------------
int SortListCheck (void){
    int sizeList = 10;
    printf("\nSortListCheck\n");

    //--------- Init list 3 --------
    OneLinkList *lst3 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst3);

    //------ filling the sorted list 3 -------
    for (int i = 0; i < sizeList; ++i) {
        insert(lst3, i*7);
    }
    //----------------------------------------

//    //---- filling in an unsorted list 3 ---
//    int j;
//    int size = (sizeList / (sizeList/2) )+ 1;
//    for (j = 1; j < size; ++j) {
//        for (int i = 0; i < sizeList/2; ++i) {
//            insert(lst3, i*j);
//        }
//    }
//    //--------------------------------------

    printf("List 3 - ");
    printOneLinkIntList(lst3);

    OneLinkNode *list3 = lst3->head;

    //---- sorting check ---
    int tmp_previous;

    for (int i = 1; i < sizeList; ++i) {
        tmp_previous = getDataOne( list3+((i-1)*2) );
        if (tmp_previous > getDataOne( list3+(i*2)) )
            return 0;
    }

    return 1;
}


//======================================================================================================
int main(int argc, char *argv[])
{
    //    1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
    //       Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
    //       неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
    //       Например: (2+(2*2)) или [2/{5*(4+7)}]
    char sequence[] = "[2/{5*(4+7)}]";
    printf(validation (sequence) ? "The sequence is correct\n" : "The sequence is not correct\n" );


    //    2. Создать функцию, копирующую односвязный список (без удаления первого списка).
    OneListCPY ();


    //    3.  Реализуйте алгоритм, который определяет, отсортирован ли связный список.
    printf( SortListCheck () ? "List 3 sorted\n" : "List 3 is not sorted\n" );



    return 0;
}

