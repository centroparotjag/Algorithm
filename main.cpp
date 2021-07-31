#include <QCoreApplication>
#include <stdio.h>


// 1. ==================================================
#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void initQueue() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    }

    arr[tail++] = node;
    items++;
}

Node* rem() {
    int i = 0;
    int idx = 0;
    Node *tmp;


    if (items == 0)
        return NULL;

    int flag = idx % SZ;
    int pr = arr[idx]->pr;

    //------ search for nearest highest priority -------
    for (idx = 0; idx < tail; ++idx) {
        if (arr[idx]->pr < pr){
            pr = arr[idx]->pr;
            flag = idx % SZ;
        }
    }

    tmp = arr[flag];
    arr[flag] = NULL;
    i  = flag;
    items--;
    tail--;

    //----- shift of the tail to the head -------------
    while (i < tail) {             // shift << 1
            idx = i % SZ;
            arr[idx] = arr[idx+1];
            i++;
    }

    //----- removing the last in the tail -------------
    arr[i] = NULL;

    return tmp;
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");

    //printf("items-%d head-%d tail-%d\n", items, head, tail); // debug
}

void prQueueTest() {
    initQueue();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    printQueue();

    for (int i = 0; i < 7; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();

    for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();
}



// 2. ============================================
void dec_to_bin_recursively (int number){
    if (number > 0){
        dec_to_bin_recursively(number / 2);
        printf("%d", number % 2);
    }
    else {
        printf("%d", 0);
    }
}

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void arrstackTest() {
    printf("\n");
    int size = 32;

    for (int i = 0; i < size; ++i) {
        pushStack(i);
    }


    for (int i = 0; i < size; ++i) {
        printf("dec = %d to bin = 0b", cursor);
        dec_to_bin_recursively (popStack());
        printf("\n");
    }

    popStack();
}





//======================================================================================================
int main(int argc, char *argv[])
{
    QCoreApplication q(argc, argv);


    //    1. Описать очередь с приоритетным исключением
    prQueueTest();


    //    2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
    arrstackTest();


    return 0;
}

