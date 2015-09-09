#include <QCoreApplication>
#include "rbtree.h"
#include "rbt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RBT *rbHandle = new RBT();

//    RBTree *guard = new RBTree();
//    RBTree *root = guard;

    int key[8] = {10,20,3,4,90,100,50,99};
    for(int i=0;i<8;i++)
    {
        RBTree *node = new RBTree(rbHandle->guard,key[i]);
//        root = root->rbInsert(guard,node);
        rbHandle->rbInsert(node);
    }


//    root->middleVisit(guard,root);
    rbHandle->middleVisit(rbHandle->root);

    return a.exec();
}
