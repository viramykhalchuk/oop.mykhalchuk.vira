#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <vector>

class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, Pass pass);
    BSTNode* deleteNode(BSTNode* node, int id);
    BSTNode* minValueNode(BSTNode* node);
    BSTNode* search(BSTNode* node, int id);
    void inOrderTraversal(BSTNode* node, std::vector<Pass>& passes);

public:
    BST();

    void insert(Pass pass);
    void deleteNode(int id);
    Pass* search(int id);
    std::vector<Pass> getAllPasses();
};

#endif 
