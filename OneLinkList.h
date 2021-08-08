#ifndef ONELINKLIST_H
#define ONELINKLIST_H

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;


void oneLinkTest();
OneLinkNode* rm(OneLinkList *lst, int data);
void insert(OneLinkList *lst, int data);
void printOneLinkIntList(OneLinkList *lst);
void initOneLinkList(OneLinkList *lst);
void printOneLinkIntNode(OneLinkNode *n);

#endif // ONELINKLIST_H
