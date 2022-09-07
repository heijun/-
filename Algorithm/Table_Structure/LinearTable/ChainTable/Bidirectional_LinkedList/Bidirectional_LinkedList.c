//
// Created by yst on 2022/9/7.
//

#include "Bidirectional_LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void initNode(Node node){
    node->next = node->prev = NULL;
}

_Bool insertList(Node head, E element, int index){
    if(index < 1) return 0;   //跟单链表一样，还是先找到对应的位置
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    Node node = malloc(sizeof (struct ListNode));  //创建新的结点
    if(node == NULL) return 0;
    node->element = element;

    if(head->next) {   //首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
        head->next->prev = node;   //如果存在则修改对应的两个指针
        node->next = head->next;
    } else {
        node->next = NULL;   //不存在直接将新结点的后继指针置为NULL
    }

    head->next = node;   //接着是前驱结点，直接操作就行
    node->prev = head;
    return 1;
}

_Bool deleteList(Node head, int index){
    if(index < 1) return 0;   //跟单链表一样，还是先找到对应的位置
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;

    Node tmp = head->next;  //先拿到待删除结点
    if(head->next->next) {   //这里有两种情况待删除结点存在后继结点或是不存在
        head->next->next->prev = head;
        head->next = head->next->next;   //按照上面分析的来
    }else{
        head->next = NULL;   //相当于删的是最后一个结点，所以直接后继为NULL就完事
    }
    free(tmp);   //最后释放已删除结点的内存
    return 1;
}

int main() {
    struct ListNode head;
    initNode(&head);
    for (int i = 0; i < 5; ++i)  //插5个元素吧
        insertList(&head, i * 100, i);

    Node node = &head;   //先来正向遍历一次
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);

    printf("\n");   //再来反向遍历一次
    do {
        printf("%d -> ", node->element);
        node = node->prev;
    } while (node->prev != NULL);
}