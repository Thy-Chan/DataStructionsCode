/**
 *数据结构课程设计
 *tittle:题目1_猴子选王_02(链表方式)
 *author:ThyChan
**/

#include <stdio.h>
#include <stdlib.h>
struct Monkey
{
    int num;                                                                    //猴子的编号
    struct Monkey *next;                                                        //只指向下一个猴子
};
struct Monkey *p,*q,*head=NULL,*temp;
struct Monkey* number(struct Monkey *head,int m)
{
    int i;
    for(i=1;i<=m;i++)                                                            //构建有序单链表.
    {
        q=(struct Monkey *)malloc(sizeof(struct Monkey));
        q->num=i;
        if(head==NULL)
            head=p=q;
        if(i==m)                                                                //当i=m时,最后一个节点的下一个指针指向第一个节点,即构成约瑟夫环.
            q->next=head;
        p->next=q;
        p=q;
    }
    return head;
}
void begin(struct Monkey *head,int m,int n)
{
    p=head;
    int i;
    while(p->next!=p)                                                          //判断是否是最后一个节点（即为其本身）,若是,则退出.
    {
        for(i=1; i<n-1; i++)                                                    //每隔n个跳过1节点
            p=p->next;
        temp=p->next;                                                           //下一个节点的地址的赋给temp
        p->next=temp->next;
        p=p->next;                                                              //p.next指向下一个节点
        free(temp);                                                             //释放temp
    }
    printf("第%d个猴子为大王!\n",p->num);
}
int main(void)
{
    int m,n;                                                                     //m为猴子的数量，n为猴子报的数
    printf("请输入猴子的数量m, 以及所报的数字:n\n");
    scanf("%d %d",&m,&n);
    head=number(head,m);
    begin(head,m,n);
    return 0;
}
