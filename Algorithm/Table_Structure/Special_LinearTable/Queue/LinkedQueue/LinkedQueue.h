//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_LINKEDQUEUE_H
#define TABLE_STRUCTURE_LINKEDQUEUE_H
typedef int E;

struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * Node;

struct Queue{
    Node front, rear;
};

typedef struct Queue * LinkedQueue;   //因为要存储首位两个指针，所以这里封装一个新的结构体吧


#endif //TABLE_STRUCTURE_LINKEDQUEUE_H
