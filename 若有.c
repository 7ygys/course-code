#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *base;
    char *top;
    int size;
}*Stack;





void intistack(Stack stack)
{
    if (stack->top - stack->base >= stack->size)
    {
        stack->base = (char *)realloc(stack->base,2 * stack->size * sizeof(char));
        stack->top = stack->base + stack->size;
        stack->size *= 2;
    }
}

void push(Stack stack,char e)
{
    *stack->top = e;
    stack->top++;
}

 char pop(Stack stack)
 {
     return *(--stack->top);
 }

 char gettop(Stack stack)
 {
     return *(stack->top - 1);
 }

 void main()
 {
     Stack stack;

    stack = (Stack)malloc(sizeof(struct{char *base;char *top;int size;}));
    stack->base = (char *)malloc(100 * sizeof(char));
    stack->top = stack->base;
    stack->size = 100;

     int i=0;
     for (i;i<26;i++)
     {
         char neuro;
         neuro = 'a' + i;
         push(stack,neuro);
         intistack(stack);
         neuro = gettop(stack);
         printf("%c\n",neuro);
     }

    char x,y;
    x = gettop(stack);
    y = pop(stack);
     printf("%c\n",x);
     printf("%c\n",y);
 }
