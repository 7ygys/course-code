typedef struct
{
    int i, j;
    int e;
}Triple;

typedef struct
{
    Triple nzElem[100];
    int m,n,t;
}*TSMat;

TSMat allocTSMat(int m, int n, int t)
{
    if (m<1 || n<1 || t<0) return 0;
    TSMat M;
    if (!(M=(TSMat)malloc(sizeof(*M)))) exit (0);
    //if (!(M->nzElem = (Triple*)malloc((t+1) *sizeof(Triple)))) exit (0);
    M->m = m; M->n = n; M->t = t;
    return M;
}

TSMat TransTSMat(TSMat M)
{
    TSMat T = allocTSMat(3, 3, 3);
    if (T->t)
    {
        int p, q=1, col;
        for (col=1;col<=M->m;++col)
        {
            for (p=1;p<=M->n;++p)
            {
                if (M->nzElem[q].j == p && M->nzElem[q].i == col)
                {
                    T->nzElem[q].i = M->nzElem[p].j;
                    T->nzElem[q].j = M->nzElem[p].i;
                    T->nzElem[q].e = M->nzElem[p].e;
                    q++;

                }
            }
        }
    }
    return T;
}

int PrintTSMat(TSMat S)
{
        int p, q=1, col, js=0;
        for (col=1;col<=S->m;++col)
        {
            for (p=1;p<=S->n;++p)
            {
                if (S->nzElem[q].j == p && S->nzElem[q].i == col)
                {
                    if (!(js%3)) printf("\n");
                    printf("%d", S->nzElem[q].e);
                    js++;
                    q++;
                }
                else
                {
                    if (!(js%3)) printf("\n");
                    js++;
                    printf("%d", 0);
                }
            }
        }
        printf("\n");
        return 0;
}


void main()
{
    TSMat M, T;
    M = allocTSMat(3, 3, 3);
    T = allocTSMat(3, 3, 3);

    M->nzElem[1].i = 1;M->nzElem[1].j = 2;M->nzElem[1].e = 3;
    M->nzElem[2].i = 2;M->nzElem[2].j = 1;M->nzElem[2].e = 2;
    M->nzElem[3].i = 2;M->nzElem[3].j = 3;M->nzElem[3].e = 5;

    PrintTSMat(M);

    T = TransTSMat(M);
    PrintTSMat(T);

    printf("\n");
    printf("%d", M->nzElem[1].i);
    printf("%d", M->nzElem[1].j);
    printf("%d\n", M->nzElem[1].e);

    printf("%d", M->nzElem[2].i);
    printf("%d", M->nzElem[2].j);
    printf("%d\n", M->nzElem[2].e);

    printf("%d", M->nzElem[3].i);
    printf("%d", M->nzElem[3].j);
    printf("%d\n", M->nzElem[3].e);

    printf("\n");
    printf("%d", T->nzElem[1].i);
    printf("%d", T->nzElem[1].j);
    printf("%d\n", T->nzElem[1].e);

    printf("%d", T->nzElem[2].i);
    printf("%d", T->nzElem[2].j);
    printf("%d\n", T->nzElem[2].e);

    printf("%d", T->nzElem[3].i);
    printf("%d", T->nzElem[3].j);
    printf("%d\n", T->nzElem[3].e);




}







