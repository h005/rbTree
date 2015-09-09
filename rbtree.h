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

};

#endif // RBTREE_H
