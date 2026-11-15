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
//*******************************************************************
//²åÈë
    linklist temp=tou,linshi;
    int j, k=6;
    linshi=(linklist)malloc(sizeof(listnode));
    linshi->data='X';
    for (j=0;j<k-1;j++)
    {
        temp=temp->next;
    }

    linshi->next=temp->next;
    temp->next=linshi;


//É¾³ý
    linklist temptemp=temp->next->next->next;
    temptemp->data='Z';
    temp->next->next->next=temptemp;

//********************************************************************
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
