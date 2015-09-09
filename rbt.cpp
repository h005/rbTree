#include "rbt.h"

RBT::RBT()
{
    guard = new RBTree();
    root = guard;
}

void RBT::leftRotate(RBTree *x)
{
    RBTree *y = x->right;
    x->right = y->left;
    if(y->left != guard)
        y->left->p = x;
    y->p = x->p;
    if(x->p == guard)
        root = y;
    else
        if(x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
    y->left = x;
    x->p = y;
}

void RBT::rightRotate(RBTree *y)
{
    RBTree *x = y->left;
    y->left = x->right;
    if(x->right != guard)
        x->right->p = y;
    x->p = y->p;
    if(y->p ==  guard)
        root = x;
    else
        if(y ==  y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
    x->right = y;
    y->p = x;
}

void RBT::rbInsert(RBTree *z)
{
    RBTree *y = guard;
    RBTree *x = root;
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
        root = z;
    else
        if(z->key < y->key)
            y->left = z;
        else
            y->right = z;
    z->left = guard;
    z->right = guard;
    z->color = RED;
    rbInsertFixup(z);

}

void RBT::rbInsertFixup(RBTree *z)
{
    while(z->p->color == RED)
    {
        if(z->p == z->p->p->right)
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
                    leftRotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(z->p->p);
            }
        }
        else
        {
            RBTree *y = z->p->p->left;
            if(y->color ==  RED)
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
                    rightRotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(z->p->p);
            }
        }
        // root->color = BLACK;
    }
    root->color = BLACK;
}

RBTree *RBT::rbDelete(RBTree *z)
{
    RBTree *y = NULL, *x = NULL;
    if(z->left == guard || z->right == guard)
        y = z;
    else
        y = rbSuccessor(z);
    if(y->left != guard)
        x = y->left;
    else
        x = y->right;
    x->p = y->p;
    if(y->p == guard)
        root = x;
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
        rbDeleteFixup(x);
    return y;
}

void RBT::rbDeleteFixup(RBTree *x)
{
    RBTree *w;
    while(x != root && x->color == BLACK)
    {
        if(x == x->p->left)
        {
            w = x->p->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                leftRotate(x->p);
                w = x->p->right;
            }
            // case 2 w is black and the two children of w are all black
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
                    rightRotate(w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->p);
                x = root;
            }
        }
        else
        {
            w = x->p->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                rightRotate(x->p);
                w = x->p->left;
            }
            // case 2
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                w = x->p;
            }
            else
            {
                if(w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->p);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

RBTree *RBT::rbSuccessor(RBTree *x)
{
    if(x->right != guard)
        return rbMinMum(x->right);
    RBTree *y = x->p;
    while(y != guard && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;
}

RBTree *RBT::rbMinMum(RBTree *x)
{
    while(x->left != guard)
        x = x->left;
    return x;
}

void RBT::middleVisit(RBTree *tree)
{
    if(tree == guard)
        return;
    middleVisit(tree->left);
    printf("%d ",tree->key);
    middleVisit(tree->right);
}




























