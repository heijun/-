//
// Created by yst on 2022/9/7.
//

#ifndef TREE_BINARYSEARCHTREE_H
#define TREE_BINARYSEARCHTREE_H
typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

Node createNode(E element);
Node insert(Node root, E element);
Node find(Node root, E target);
Node findMax(Node root);

#endif //TREE_BINARYSEARCHTREE_H
