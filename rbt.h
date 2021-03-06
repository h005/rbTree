#ifndef RBT_H
#define RBT_H

#include"rbtree.h"
#include<stdio.h>

class RBT
{
public:
    RBT();

    RBTree *root;
    RBTree *guard;

    void leftRotate(RBTree *x);
    void rightRotate(RBTree *x);
    void rbInsert(RBTree *z);
    void rbInsertFixup(RBTree *z);
    RBTree* rbDelete(RBTree *z);
    void rbDeleteFixup(RBTree *z);
    RBTree* rbSuccessor(RBTree *x);
    RBTree* rbMinMum(RBTree *x);
    RBTree* rbMaxMum(RBTree *x);

    void middleVisit(RBTree *tree);
    void afterVisit(RBTree *tree);

    RBTree* rbPrevLeaf(RBTree *leaf);
    RBTree* rbNextLeaf(RBTree *leaf);

};

#endif // RBT_H
