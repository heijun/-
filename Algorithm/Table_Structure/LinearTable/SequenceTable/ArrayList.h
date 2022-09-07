//
// Created by yst on 2022/9/6.
//

#ifndef TABLE_STRUCTURE_ARRAYLIST_H
#define TABLE_STRUCTURE_ARRAYLIST_H
typedef int E;

struct List {
    E * array;
    int capacity;
    int size;
};

typedef struct List * ArrayList;

_Bool initList(ArrayList list);
_Bool insertList(ArrayList list, E element, int index);
_Bool deleteList(ArrayList list, int index);
int sizeList(ArrayList list);
E * getList(ArrayList list, int index);
int findList(ArrayList list, E element);
void printList(ArrayList list);

#endif //TABLE_STRUCTURE_ARRAYLIST_H
