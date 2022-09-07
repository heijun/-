//
// Created by yst on 2022/9/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"
_Bool initStack(ArrayStack stack){
    stack->array = malloc(sizeof(E) * 10);
    if(stack->array == NULL) return 0;
    stack->capacity = 10;   //容量还是10
    stack->top = -1;   //由于栈内没有元素，那么栈顶默认就为-1
    return 1;
}

_Bool pushStack(ArrayStack stack, E element){
    if(stack->top + 1 == stack->capacity) {  //栈顶+1如果等于容量的话，那么说明已经塞满了
        int newCapacity = stack->capacity + (stack->capacity >> 1);   //大体操作和顺序表一致
        E * newArray = realloc(stack->array, newCapacity * sizeof(E));
        if(newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[stack->top + 1] = element;
    stack->top++;
    return 1;
}

_Bool isEmpty(ArrayStack stack){   //在出栈之前，我们还需要使用isEmpty判断一下栈是否为空，空栈元素都没有出个毛
    return stack->top == -1;
}

E popStack(ArrayStack stack){
    return stack->array[stack->top--];   //直接返回栈顶元素，注意多加一个自减操作
}

void printStack(ArrayStack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main(){
    struct ArrayStack stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        pushStack(&stack, i*100);
    }
    printStack(&stack);
    while (!isEmpty(&stack)) {
        printf("%d ", popStack(&stack));   //将栈中所有元素依次出栈
    }
}