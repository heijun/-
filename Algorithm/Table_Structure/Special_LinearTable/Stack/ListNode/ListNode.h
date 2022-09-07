//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_LISTNODE_H
#define TABLE_STRUCTURE_LISTNODE_H
typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;
#endif //TABLE_STRUCTURE_LISTNODE_H
