//
// Created by yst on 2022/9/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

_Bool initQueue(ArrayQueue queue){
    queue->array = malloc(sizeof(E) * 10);
    if(queue->array == NULL) return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;   //默认情况下队首和队尾都指向0的位置
    return 1;
}

_Bool offerQueue(ArrayQueue queue, E element){
    if((queue->rear + 1) % queue->capacity == queue->front)   //先判断队列是否已满，如果队尾下一个就是队首，那么说明已满
        return 0;
    queue->rear = (queue->rear + 1) % queue->capacity;   //队尾先向前移动一位，注意取余计算才能实现循环
    queue->array[queue->rear] = element;   //在新的位置插入元素
    return 1;
}

_Bool isEmpty(ArrayQueue queue){   //在出队之前需要先看看容量是否足够
    return queue->rear == queue->front;
}

E pollQueue(ArrayQueue queue){
    queue->front = (queue->front + 1) % queue->capacity;   //先将队首指针后移
    return queue->array[queue->front];   //出队，完事
}

void printQueue(ArrayQueue queue){
    printf("<<< ");
    int i = queue->front;   //遍历队列需要从队首开始
    do {
        i = (i + 1) % queue->capacity;   //先向后循环移动
        printf("%d ", queue->array[i]);  //然后打印当前位置上的元素
    } while (i != queue->rear);   //当到达队尾时，结束
    printf("<<<\n");
}

int main(){
    struct ArrayQueue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i * 100);
    }
    printQueue(&queue);
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }
}