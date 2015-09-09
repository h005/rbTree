#ifndef RBTREE_H
#define RBTREE_H

#define RED true
#define BLACK false

class RBTree
{
public:
    int key;
    RBTree *left,*right,*p;
    bool color;

public:
    RBTree();
    RBTree(RBTree *guard);
    RBTree(RBTree *guard,int key);
    /*
    void copy(RBTree *x);
    void leftRotate(RBTree *guard,RBTree *x);
    void rightRotate(RBTree *guard,RBTree *x);
    RBTree* rbInsert(RBTree *guard,RBTree *z);
    void rbInsertFixup(RBTree *guard,RBTree *z);
    RBTree* rbDelete(RBTree *guard,RBTree *z);
    void rbDeleteFixup(RBTree *guard,RBTree *z);
    RBTree* rbSuccessor(RBTree *gurad,RBTree *x);
    RBTree* rbMinMum(RBTree *guard, RBTree *x);
    void middleVisit(RBTree *guard, RBTree *root);
    */
};

#endif // RBTREE_H
