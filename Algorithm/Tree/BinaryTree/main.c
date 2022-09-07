#include <stdio.h>
#include <malloc.h>


typedef char ElementType;

typedef struct TNode *Position; /* 结构体指针 */
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
}TNode;


void CreateBinaryTree ( BinTree *T ) {
    ElementType ch;
    scanf("%c",&ch);

    if (ch == '#')
        *T = NULL;
    else {
        *T = (BinTree)malloc(sizeof(TNode));
        //C 库函数 void *malloc(size_t size)分配所需的内存空间，并返回一个指向它的指针
        (*T)->Data = ch;
        CreateBinaryTree(&((*T)->Left));
        CreateBinaryTree(&((*T)->Right));
    }
}
/*先序遍历*/
void PreOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        printf("%c", BT->Data);
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}
/*中序遍历*/
void InOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        PreOrderTraversal( BT->Left );
        printf("%c", BT->Data);
        PreOrderTraversal( BT->Right );
    }
}
/*后序遍历*/
void PostOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        PostOrderTraversal( BT->Left );
        PostOrderTraversal( BT->Right );
        printf("%c", BT->Data);
    }
}
/*先序遍历输出二叉树叶子结点*/
void PreOrderPrintLeaves ( BinTree BT ) {
    if ( BT ) {
        if ( !BT->Left && !BT->Right )
            printf("%c", BT->Data);
        PreOrderPrintLeaves( BT->Left );
        PreOrderPrintLeaves( BT->Right );
    }
}
/*后序遍历求二叉树的高度*/
int PostOrderGetHeight ( BinTree BT) {
    int HL, HR, MaxH;

    if ( BT ) {
        HL = PostOrderGetHeight( BT->Left );
        HR = PostOrderGetHeight( BT->Right );
        MaxH = ( HL > HR ) ? HL : HR;
        return (MaxH + 1);
    }
    else
        return 0;
}


void printTree(struct TNode *n)
{
    static int level = -1; //记录是第几层次
    int i;

    if (NULL == n)
        return;

    level++;
    printTree(n->Right);
    level--;

    level++;
    for (i = 0; i < level; i++)
        printf("\t");
    printf("%c\n", n->Data);
    printTree(n->Left);
    level--;
}

int main() {
    BinTree myTree;
    printf("Create your Binary Tree:\n");
    CreateBinaryTree(&myTree);
    printf("\n PreOrder:");
    PreOrderTraversal(myTree);

    printf("\n InOrder:");
    InOrderTraversal(myTree);

    printf("\n PostOrder:");
    PostOrderTraversal(myTree);

    printf("\n Leaves:");
    PreOrderPrintLeaves(myTree);
    printf("\n");
    int high = PostOrderGetHeight(myTree);
    printf("The height of the tree: %4d", high);
    printf("\n");
    printTree(myTree);
    return 0;
}