//
// Created by yst on 2022/9/7.
//

#ifndef TREE_BINARYBALANCEDTREE_H
#define TREE_BINARYBALANCEDTREE_H
typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int height;   //每个结点需要记录当前子树的高度，便于计算平衡因子
} * Node;

Node createNode(E element);
int max(int a, int b);
int getHeight(Node root);
Node leftRotation(Node root);
Node rightRotation(Node root);
Node leftRightRotation(Node root);
Node rightLeftRightRotation(Node root);
Node insert(Node root, E element);
void printTree(struct  TreeNode *n);

#endif //TREE_BINARYBALANCEDTREE_H
