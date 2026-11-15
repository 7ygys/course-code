#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct
{
    char *base;
    int front,rear;
    int size;
}*Sqqueue;
    Sqqueue Q;

char push(char e)
{
    if (!Q || (Q->rear + 1)%Q->size == Q->front) return "!!!";

    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1)% Q->size;

    return e;
}

char pop()
{
    char e;

    if (!Q || Q->rear == Q->front) return "!!!";

    e = Q->base[Q->front];
    Q->front = (Q->front + 1)%Q->size;

    return e;
}
/*
int judge_hw(Sqqueue *q, int length)
{
    if(length>1)
    {
        int i,tt,ww;
        for (i=1;i<=length/2;i++)
        {
            tt=pop();
            ww=Q->base[Q->rear-i];
            if(tt!=ww) return 0;
        }
    }

    return 1;

}
*/

int judge_hw(int len)
{
    int half = len / 2;
    char right;

    // 取出前 half 个，暂存（只能拿变量存，队列不能随机访问）
    char temp[100];
    for (int i = 0; i < half; i++)
    {
        temp[i] = pop();
        push(temp[i]);
    }

    // 如果长度是奇数，跳过中间那一个字符
    if (len % 2 == 1)
    {
        char mid = pop();
        push(mid);
    }

    // 依次拿后半段 和 暂存的前半段反向比较
    for (int i = half - 1; i >= 0; i--)
    {
        right = pop();
        push(right);
        if (temp[i] != right)
        {
            return 0;
        }
    }
    return 1;
}




void main()
{
    system("chcp 65001");

    Q=(Sqqueue)malloc(sizeof(Sqqueue));
    Q->base=(char*)malloc(100*sizeof(char));
    Q->size=100;

    Q->front=Q->rear=0;

    int i,length,yon;
    int tt,ww;
    char hw[] = "123321";

    length = strlen(hw);

    for(i=0;i<=strlen(hw);i++)
    {
        push(*(hw+i));
    }

    yon = judge_hw(length);
    printf("%d", yon);
    if(yon==1) printf("是");
    else printf("不是");

}
