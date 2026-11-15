#include <stdio.h>

typedef struct listnode
{
    char data;
    struct listnode *left,*right
} listnode,*linklist;



void main()
{
    linklist jd;
    int i;
    linklist head;
    head=(linklist)malloc(sizeof(listnode));
    head->left=NULL;
    head->right=NULL;

    for (i=0;i<26;i++)
    {
        listnode *p=head;
        jd=(linklist)malloc(sizeof(listnode));
        jd->data='a'+i;

        while(p->right!=NULL)
        {
            p=p->right;
        }

        p->right=jd;
        jd->left=p;
        jd->right=NULL;
    }

    listnode *p=head;

    if (p==NULL)
    {
        printf("table is null\n");
        return;
    }

    while(p!=NULL)
    {
        if (p->right!=NULL) printf("<-");
        printf("%c",p->data);
        if (p->right!=NULL) printf("->");
        p=p->right;
    }



}
