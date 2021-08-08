#ifndef TWOLINKLIST_H
#define TWOLINKLIST_H

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList *lst);
void printTwoLinkIntNode(TwoLinkNode *n);
void printTwoLinkIntList(TwoLinkList *lst);
void pushFront(TwoLinkList *lst, int data);
void pushBack(TwoLinkList *lst, int data);
TwoLinkNode* remFront(TwoLinkList *lst);
TwoLinkNode* remBack(TwoLinkList *lst);
void twoLinkListTest() ;



#endif // TWOLINKLIST_H
