#ifndef BSTNODE_H
#define BSTNODE_H

#include "Pass.h"

class BSTNode {
public:
    Pass pass;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Pass pass);
};

#endif 
