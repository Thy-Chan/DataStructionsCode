/**
 *���ݽṹ�γ�����
 *tittle:��Ŀ1_����ѡ��_02(������ʽ)
 *author:ThyChan
**/

#include <stdio.h>
#include <stdlib.h>
struct Monkey
{
    int num;                                                                    //���ӵı���
    struct Monkey *next;                                                        //ָֻ����һ������
};
struct Monkey *p,*q,*head=NULL,*temp;
struct Monkey* number(struct Monkey *head,int m)
{
    int i;
    for(i=1;i<=m;i++)                                                            //��������������.
    {
        q=(struct Monkey *)malloc(sizeof(struct Monkey));
        q->num=i;
        if(head==NULL)
            head=p=q;
        if(i==m)                                                                //��i=mʱ,����һ���ڵ�����һ��ָ��ָ����һ���ڵ�,������Լɪ����.
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
    while(p->next!=p)                                                          //�ж��Ƿ�������һ���ڵ㣨��Ϊ�䱾����,����,���˳�.
    {
        for(i=1; i<n-1; i++)                                                    //ÿ��n������1�ڵ�
            p=p->next;
        temp=p->next;                                                           //��һ���ڵ��ĵ�ַ�ĸ���temp
        p->next=temp->next;
        p=p->next;                                                              //p.nextָ����һ���ڵ�
        free(temp);                                                             //�ͷ�temp
    }
    printf("��%d������Ϊ����!\n",p->num);
}
int main(void)
{
    int m,n;                                                                     //mΪ���ӵ�������nΪ���ӱ�����
    printf("���������ӵ�����m, �Լ�����������:n\n");
    scanf("%d %d",&m,&n);
    head=number(head,m);
    begin(head,m,n);
    return 0;
}
