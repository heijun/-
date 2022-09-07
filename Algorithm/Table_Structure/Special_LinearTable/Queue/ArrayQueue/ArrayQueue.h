//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_ARRAYQUEUE_H
#define TABLE_STRUCTURE_ARRAYQUEUE_H
typedef int E;

struct ArrayQueue {
    E * array;
    int capacity;   //数组容量
    int rear, front;   //队尾、队首指针
};

typedef struct ArrayQueue * ArrayQueue;
#endif //TABLE_STRUCTURE_ARRAYQUEUE_H
