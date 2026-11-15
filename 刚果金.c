#include <stdio.h>
#include <stdlib.h>
typedef struct{
char *elem;
int length;
int size;
}sqlist;

int main()
{
    sqlist list;
    list.elem=(char*)malloc(7*sizeof(char));
    list.length=0;
    list.size=7;
    int i,j,k;
    char cr;

    for (i=0;i<7;i++){
        char a = i;
        list.elem[i]='A';
        list.length++;
        printf("%c\n", *(list.elem + i));
        //printf("%p", list.elem);
    }

    //增加-----------------------------------------------------------------------------
    printf("请输入元素:");
    j=scanf("%c", &cr);
    printf("请输入插入位置:");
    k=scanf("%d", &j);

    if (list.length>=list.size)
    {
        list.elem=(char*)realloc(list.elem,8*sizeof(char));
        list.length++;
    }
    for (k=list.length-1;k>=j-1;k--)
    {
       list.elem[k+1]=list.elem[k];
    }
    list.elem[j-1]=cr;

    for (i=0;i<8;i++){
        printf("%c\n", *(list.elem + i));
        //printf("%p", list.elem);
    }

    //删除-----------------------------------------------------------------------------
    printf("请输入删除元素位置:");
    k=scanf("%d", &j);

    if (j=list.length)
    {
        list.length--;
    }

    else
    {
        for (j;j<=list.length;k++)
        {
            list.elem[j-1]=list.elem[j];
        }
    }

    list.length--;
    for (i=0;i<7;i++){
        printf("%c\n", *(list.elem + i))；
        //printf("%p", list.elem);
    }



    return 0;
}





























