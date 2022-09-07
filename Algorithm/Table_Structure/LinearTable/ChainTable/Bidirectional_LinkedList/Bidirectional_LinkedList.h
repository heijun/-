//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_BIDIRECTIONAL_LINKEDLIST_H
#define TABLE_STRUCTURE_BIDIRECTIONAL_LINKEDLIST_H
typedef int E;

struct ListNode {
    E element;   //保存当前元素
    struct ListNode * next;   //指向下一个结点的指针
    struct ListNode * prev;   //指向上一个结点的指针
};

typedef struct ListNode * Node;

void initNode(Node node);
_Bool insertList(Node head, E element, int index);
_Bool deleteList(Node head, int index);
#endif //TABLE_STRUCTURE_BIDIRECTIONAL_LINKEDLIST_H
