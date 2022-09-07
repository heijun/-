//
// Created by yst on 2022/9/7.
//

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>



void initList(Node node){
    node->next = NULL;
}

_Bool insertList(Node head, E element, int index){
    if(index < 1) return 0;
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool deleteList(Node head, int index){
    if(index < 1) return 0;   //大体和上面是一样的
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

E * getList(Node head, int index){
    if(index < 1) return 0;
    do {
        head = head->next;
        if(head == NULL) return 0;
    } while (--index);
    return &head->element;
}

int findList(Node head, E element){
    head = head->next;
    int i = 1;
    while (head) {
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList(Node head){
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

void printList(Node head){
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);   //因为头结点不存放数据，所以从第二个开始打印
    }
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 0; i < 3; ++i) {
        insertList(&head, i * 100, i);
    }
    deleteList(&head, 0);   //这里我们尝试删除一下第一个元素
    printList(&head);
}