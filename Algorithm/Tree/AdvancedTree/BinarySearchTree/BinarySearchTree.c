//
// Created by yst on 2022/9/7.
//

#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

Node createNode(E element){
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

Node insert(Node root, E element){
    if(root){
        if(root->element > element)    //如果插入结点值小于当前结点，那么说明应该放到左边去
            root->left = insert(root->left, element);
        else if(root->element < element)    //如果插入结点值大于当前结点，那么说明应该放到右边去
            root->right = insert(root->right, element);
    } else {   //当结点为空时，说明已经找到插入的位置了，创建对应结点
        root = createNode(element);
    }
    return root;   //返回当前结点
}

Node find(Node root, E target){
    while (root) {
        if(root->element > target)    //如果要找的值比当前结点小，说明肯定在左边
            root = root->left;
        else if(root->element < target)   //如果要找的值比当前结点大，说明肯定在右边
            root = root->right;
        else
            return root;   //等于的话，说明找到了，就直接返回
    }
    return NULL;   //都找到底了还没有，那就是真没有了
}

Node findMax(Node root){   //查找最大值就更简单了，最右边的一定是最大的
    while (root && root->right)
        root = root->right;
    return root;
}

int main() {
    Node root = insert(NULL, 18);   //插入后，得到根结点
    insert(root, 10);
    insert(root, 20);
    insert(root, 7);
    insert(root, 15);
    insert(root, 22);
    insert(root, 9);

    printf("%p\n", find(root, 17));
    printf("%p\n", find(root, 9));
}