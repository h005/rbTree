#include <QCoreApplication>
#include "rbtree.h"
#include "rbt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RBT *rbHandle = new RBT();

//    RBTree *guard = new RBTree();
//    RBTree *root = guard;

    int len = 10;

    RBTree **node;
    node = new RBTree*[len];

    int key[10] = {26,17,101,41,14,90,100,50,66,99};
    for(int i=0;i<len;i++)
    {
        node[i] = new RBTree(rbHandle->guard,key[i]);
//        root = root->rbInsert(guard,node);
        rbHandle->rbInsert(node[i]);
    }

    rbHandle->rbDelete(node[2]);
    rbHandle->rbDelete(node[8]);
    rbHandle->rbDelete(node[0]);

//    root->middleVisit(guard,root);
    rbHandle->middleVisit(rbHandle->root);

    rbHandle->afterVisit(rbHandle->root);
    return a.exec();
}
