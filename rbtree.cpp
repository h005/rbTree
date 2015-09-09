#include "rbtree.h"

#include <stdio.h>

RBTree::RBTree()
{
    key = 0;
    left = right = p = NULL;
    color = BLACK;
}

RBTree::RBTree(RBTree *guard)
{
    key = 0;
    left = right = p = guard;
    color = BLACK;
}

RBTree::RBTree(RBTree *guard, int key)
{
    this->key = key;
    left = right = p = guard;
    color = BLACK;
}
