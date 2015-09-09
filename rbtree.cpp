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
/*

void RBTree::copy(RBTree *x)
{
    this->key = x->key;
    this->left = x->left;
    this->right = x->right;
    this->p = x->p;
    this->color = x->color;
}

void RBTree::leftRotate(RBTree *guard, RBTree *x)
{
    RBTree *y = x->right;
    x->right = y->left;
    if(y->left != guard)
       y->left->p = x;
    y->p = x->p;
    if(x->p == guard)
    {
        this->copy(y);
        y = this;
    }
    else
        if(x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
    y->left = x;
    x->p = y;
}

void RBTree::rightRotate(RBTree *guard, RBTree *y)
{
    RBTree *x = y->left;
    y->left = x->right;
    if(x->right != guard)
        x->right->p = y;
    x->p = y->p;
    if(y->p == guard)
    {
        this->copy(x);
        x = this;
    }
    else
        if(y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
    x->right = y;
    y->p = x;
}

RBTree* RBTree::rbInsert(RBTree *guard, RBTree *z)
{
    RBTree *y = guard;
    RBTree *x = this;
    while(x != guard)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->p = y;

    if(y == guard)
    {
//        this->key = z->key;
        this = new RBTree();
        this->copy(z);
        z = this;
    }
    else
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    z->left = guard;
    z->right = guard;
    z->color = RED;
    rbInsertFixup(guard,z);
    return this;
}

void RBTree::rbInsertFixup(RBTree *guard, RBTree *z)
{
    while(z->p->color == RED)
    {
        if(z->p == z->p->p->left)
        {
            RBTree *y = z->p->p->right;
            if(y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if(z->p->right == z)
                {
                    z = z->p;
                    leftRotate(guard,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(guard,z->p->p);
            }
        }
        else
        {
            RBTree *y = z->p->p->left;
            if(y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if(z->p->left == z)
                {
                    z = z->p;
                    rightRotate(guard,z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(guard,z->p->p);
            }
        }
        this->color = BLACK;
    }
}

RBTree* RBTree::rbDelete(RBTree *guard, RBTree *z)
{
    RBTree *y = NULL,*x = NULL;
    if(z->left == guard || z->right ==  guard)
        y = z;
    else
        y = rbSuccessor(guard,z);
    if(y->left != guard)
        x = y->left;
    else
        x = y->right;
    x->p = y->p;
    if(y->p == guard)
    {
        this->copy(x);
        x = this;
    }
    else
        if(y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;

    if(y != z)
    {
        z->key = y->key;
        // copy y's satellite data into z
    }
    if(y->color == BLACK)
        rbDeleteFixup(guard,x);
    return y;
}

void RBTree::rbDeleteFixup(RBTree *guard, RBTree *x)
{
    RBTree *w;
    while(x != this && x->color==BLACK)
    {
        if(x == x->p->left)
        {
            w = x->p->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                leftRotate(guard,x->p);
                w = x->p->right;
            }
            // case 2 w is black and the two children of w is black
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if(w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(guard,w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                leftRotate(guard,x->p);
                x = this;
            }
        }
        else
        {
            w = x->p->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                rightRotate(guard,x->p);
                w = x->p->left;
            }
            // case 2
            if(w->right->color == BLACK && w->left->color ==  BLACK)
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if(w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(guard,w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rightRotate(guard,x->p);
                x = this;
            }
        }
    }
    x->color = BLACK;
}

RBTree* RBTree::rbSuccessor(RBTree *guard, RBTree *x)
{
    if(x->right != guard)
        return rbMinMum(guard,x->right);
    RBTree *y = x->p;
    while(y != guard && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;
}

RBTree *RBTree::rbMinMum(RBTree *guard, RBTree *x)
{
    while(x->left != guard)
        x = x->left;
    return x;
}

void RBTree::middleVisit(RBTree *guard, RBTree *root)
{
    if(root ==  guard)
        return;
    middleVisit(guard,root->left);
    printf("%d ",root->key);
    middleVisit(guard,root->right);
}


*/
