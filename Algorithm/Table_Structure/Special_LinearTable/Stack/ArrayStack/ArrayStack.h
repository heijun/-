//
// Created by yst on 2022/9/7.
//

#ifndef TABLE_STRUCTURE_ARRAYSTACK_H
#define TABLE_STRUCTURE_ARRAYSTACK_H
typedef int E;

struct ArrayStack {
    E * array;
    int capacity;
    int top;   //这里使用top来表示当前的栈顶位置，存的是栈顶元素的下标
};

typedef struct ArrayStack * ArrayStack;  //起个别名

_Bool initStack(ArrayStack stack);
_Bool pushStack(ArrayStack stack, E element);
_Bool isEmpty(ArrayStack stack);
E popStack(ArrayStack stack);
void printStack(ArrayStack stack);
#endif //TABLE_STRUCTURE_ARRAYSTACK_H
