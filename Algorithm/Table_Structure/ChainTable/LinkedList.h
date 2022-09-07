//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_LINKEDLIST_H
#define TABLE_STRUCTURE_LINKEDLIST_H
typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initList(Node node);
_Bool deleteList(Node head, int index);
E * getList(Node head, int index);
int findList(Node head, E element);
int sizeList(Node head);

#endif //TABLE_STRUCTURE_LINKEDLIST_H
