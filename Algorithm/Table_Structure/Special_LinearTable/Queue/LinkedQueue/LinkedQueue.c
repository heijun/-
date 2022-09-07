//
// Created by yst on 2022/9/7.
//

#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

bool initQueue(LinkedQueue queue){
    Node node = malloc(sizeof(struct LNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;   //一开始两个指针都是指向头结点的，表示队列为空
    return 1;
}

bool offerQueue(LinkedQueue queue, E element){
    Node node = malloc(sizeof(struct LNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;   //先让尾结点的下一个指向新的结点
    queue->rear = node;   //然后让队尾指针指向新的尾结点
    return 1;
}

bool isEmpty(LinkedQueue queue){   //在出队之前需要先看看容量是否足够
    return queue->rear == queue->front;
}

void printQueue(LinkedQueue queue){
    printf("<<< ");
    Node node = queue->front->next;
    while (1) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
        printf("%d ", node->element);
        if(node == queue->rear) break;    //当已经打印最后一个元素后，再结束
        else node = node->next;
    }
    printf("<<<\n");
}

E pollQueue(LinkedQueue queue){
    E e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;  //直接让头结点指向下下个结点
    if(queue->rear == node) queue->rear = queue->front;   //如果队尾就是待出队的结点，那么队尾回到队首位置上
    free(node);   //释放内存
    return e;
}

int main(){
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue, i*100);

    }
    printQueue(&queue);
    while (!isEmpty(&queue)){
        printf("%d ", pollQueue(&queue));
    }
}