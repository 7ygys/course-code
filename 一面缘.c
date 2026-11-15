#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *base;
    char *top;
    int size;
}*Stack;

Stack stack;



void intistack()
{
    if (stack->top - stack->base >= stack->size)
    {
        stack->base = (char *)realloc(stack->base,2 * stack->size * sizeof(char));
        stack->top = stack->base + stack->size;
        stack->size *= 2;
    }
}

void push(char e)
{
    *stack->top = e;
    stack->top++;
}

 char pop()
 {
     return *(--stack->top);
 }

 char gettop()
 {
     return *(stack->top - 1);
 }

 int judge_hw(char *hw)
 {
     int i;
     for (i=0;i<5;i++)
    {
        char e;
        e = pop();
        if (e != *(hw + i)) return 0;

    }
    return 1;
 }

 void main()
 {
    stack = (Stack)malloc(sizeof(struct{char *base;char *top;int size;}));
    stack->base = (char *)malloc(100 * sizeof(char));
    stack->top = stack->base;
    stack->size = 100;

     int i=0,j;
     char hw[] = "123231";
     for (i;i<5;i++)
     {
         char neuro;
         neuro = *(hw + i);
         push(neuro);
         intistack();
         neuro = gettop();
         printf("%c\n",neuro);
     }

    j = judge_hw(hw);
    if(j==1) printf("ÊÇ");
    else printf("²»ÊÇ");


 }






















