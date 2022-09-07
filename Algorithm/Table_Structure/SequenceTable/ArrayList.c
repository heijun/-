//
// Created by yst on 2022/9/6.
//

#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>



_Bool initList(ArrayList list){
    list->array = malloc(sizeof(E) * 10);
    if(list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertList(ArrayList list, E element, int index){
    if(index < 1 || index > list->size + 1) return 0;

    if(list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        E * newArray = realloc(list->array, newCapacity * sizeof(E));
        if(newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; --i)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

_Bool deleteList(ArrayList list, int index){
    if(index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    list->size--;
    return 1;
}

int sizeList(ArrayList list){
    return list->size;
}

E * getList(ArrayList list, int index){
    if(index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int findList(ArrayList list, E element){
    for (int i = 0; i < list->size; ++i) {
        if(list->array[i] == element) return i + 1;
    }
    return -1;
}

void printList(ArrayList list){   //编写一个函数用于打印表当前的数据
    for (int i = 0; i < list->size; ++i)   //表里面每个元素都拿出来打印一次
        printf("%d ", list->array[i]);
    printf("\n");
}

int main() {
    struct List list;
    if(initList(&list)){
        insertList(&list, 666, 1);  //每次插入操作后都打印一下表，看看当前的情况
        printList(&list);
        insertList(&list, 777, 1);
        printList(&list);
        insertList(&list, 888, 2);
        printList(&list);
    } else{
        printf("顺序表初始化失败，无法启动程序！");
    }
}