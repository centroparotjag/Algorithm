//#include <QCoreApplication>
#include <stdio.h>
#include "twoLinkList.h"
#include "OneLinkList.h"



// 1. -----------------------------------------------------------
#define right 1
#define wrong 0

int getData(TwoLinkNode *n) {
    return n->dat;
}


int validation (char* sequence){
    int i =0;
    int num_parenthes =0;
    char f;
    char b;

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

    //--------- Init list --------
    OneLinkList *lst1 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst1);
    //--------- Init list 2 ------
    OneLinkList *lst2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst2);

    //---- filling out the list ---
    for (int i = 0; i < sizeList; ++i) {
        insert(lst1, i*7);

    }

    printf("List 1 - ");
    printOneLinkIntList(lst1);

    OneLinkNode *list1 = lst1->head;

    //---- copy list to list 2 ---
    for (int i = 0; i < sizeList; ++i) {
        insert(lst2, getDataOne(list1+i*2));   //n->dat;

    }

    printf("List 2 - ");
    printOneLinkIntList(lst2);

    printf("List 1 after copy - ");
    printOneLinkIntList(lst1);

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



    return 0;
}

