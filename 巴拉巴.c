#include <stdio.h>
#include <stdlib.h>
typedef struct{
char *elem;
int length;
int size;
}sqlist;
/*
int main(){
    sqlist list;
    list.elem=(char*)malloc(100*sizeof(char));
    list.length=0;
    list.size=100;

    list.elem[0]='A';
    list.length++;

    printf("%c\n", *list.elem);

    return 0;
}
*/



int main(){
    sqlist list;
    list.elem=(char*)malloc(100*sizeof(char));
    list.length=0;
    list.size=100;
    int i;

    for (i=0;i<100;i++){
        char a = i;
        list.elem[0]='A';
        list.length++;
        printf("%c\n", *(list.elem + i));
        //printf("%p", list.elem);
    }

    return 0;
}
