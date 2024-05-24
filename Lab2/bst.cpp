#include "BST.h"

BST::BST() : root(nullptr) {}

BSTNode* BST::insert(BSTNode* node, Pass pass) {
    if (node == nullptr) {
        return new BSTNode(pass);
    }
    if (pass.id < node->pass.id) {
        node->left = insert(node->left, pass);
    } else {
        node->right = insert(node->right, pass);
    }
    return node;
}

BSTNode* BST::deleteNode(BSTNode* node, int id) {
    if (node == nullptr) return node;
    if (id < node->pass.id) {
        node->left = deleteNode(node->left, id);
    } else if (id > node->pass.id) {
        node->right = deleteNode(node->right, id);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* temp = minValueNode(node->right);
        node->pass = temp->pass;
        node->right = deleteNode(node->right, temp->pass.id);
    }
    return node;
}

BSTNode* BST::minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

BSTNode* BST::search(BSTNode* node, int id) {
    if (node == nullptr || node->pass.id == id)
        return node;
    if (id < node->pass.id)
        return search(node->left, id);
    return search(node->right, id);
}

void BST::inOrderTraversal(BSTNode* node, std::vector<Pass>& passes) {
    if (node != nullptr) {
        inOrderTraversal(node->left, passes);
        passes.push_back(node->pass);
        inOrderTraversal(node->right, passes);
    }
}

void BST::insert(Pass pass) {
    root = insert(root, pass);
}

void BST::deleteNode(int id) {
    root = deleteNode(root, id);
}

Pass* BST::search(int id) {
    BSTNode* node = search(root, id);
    if (node == nullptr) return nullptr;
    return &node->pass;
}

std::vector<Pass> BST::getAllPasses() {
    std::vector<Pass> passes;
    inOrderTraversal(root, passes);
    return passes;
}
