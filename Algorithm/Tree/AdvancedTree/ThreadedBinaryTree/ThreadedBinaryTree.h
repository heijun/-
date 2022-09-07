//
// Created by yst on 2022/9/7.
//

#ifndef TREE_THREADEDBINARYTREE_H
#define TREE_THREADEDBINARYTREE_H
typedef char dataType;
typedef struct node
{
    dataType data; //根节点的值
    struct node *lchild; //左孩子
    struct node *rchild; //右孩子
    int ltag; //左标记，“ltag=0”表示当前节点有左孩子，“ltag=1”表示当前节点没有左孩子
    int rtag; //右标记，“rtag=0”表示当前节点有右孩子，“rtag=1”表示当前节点没有右孩子
}BiTree;

BiTree *creat();
void InThreaded(BiTree *p);
BiTree *Next(BiTree *t);
BiTree *Prior(BiTree *t);
void InorderTraverse(BiTree *t);

#endif //TREE_THREADEDBINARYTREE_H
