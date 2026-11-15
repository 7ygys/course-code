#include <stdio.h>

typedef struct listnode
{
    char data;
    struct listnode *next
} listnode,*linklist;

void main()
{
    linklist tou,jd;
    int i;

    tou=(linklist)malloc(sizeof(listnode));
    tou->next=NULL;
    //tou->data='Y';

    for (i=0;i<26;i++)
    {
        listnode *p=tou;
        jd=(linklist)malloc(sizeof(listnode));
        jd->data='a'+i;

        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=jd;
        jd->next=NULL;
    }

    listnode *p=tou;

    if (p==NULL)
    {
        printf("table is null\n");
        return;
    }

    while(p!=NULL)
    {
        printf("%c",p->data);
        if (p->next!=NULL) printf("->");
        p=p->next;
    }



}




















