/**
 *lesson:  ���ݽṹ�γ�����
 *tittle:  ��Ŀ4:������ 
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct orderedlist                                                  //��������������
{
    char data;                                                      //�ַ����͵�ָ��
    struct orderedlist *next;                                       //ָ��������һ���ڵ���ָ��
    struct orderedlist *last;                                       //ָ��������һ���ڵ���ָ��
};
//���ڴ�����������,�β�����Ϊ����ָ��,���صĲ���Ϊ����ָ��
struct orderedlist *creatlist(struct orderedlist *s)
{
    struct orderedlist *head=NULL,*p=NULL;                          //��������ͷ�ڵ�,����ָ��,��ʼ��ΪNULL
    char temp;                                                      //����һ����ʱ���ַ��ͱ���
    head=(struct orderedlist*)malloc(sizeof(struct orderedlist));   //Ϊͷ�ڵ�����һ��orderedlist���͵Ĵ洢�ռ�
    head->last=NULL;                                                //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    head->next=NULL;                                                //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    p=head;                                                         //ָ��pָ��ͷ�ڵ�
    s=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //Ϊ�ڵ�����һ��orderedlist���͵Ĵ洢�ռ�
    scanf("%c",&s->data);                                           //���û�������һ�����ݴ洢���ڵ�s����������
    s->last=p;                                                      //s��ָ��������һ���ڵ���ָ��ָ��p,��ָ��ͷ�ڵ�
    s->next=NULL;                                                   //s��ָ��������һ���ڵ���ָ����Ϊ��
    p->next=s;                                                      //p��ָ��������һ���ڵ���ָ��ָ��s
    p=s;                                                            //��ָ��pָ��s
    if(s->data=='\n')                                               //���ڵ��洢������Ϊ���з�����˵���û�����������Ϊ�գ���ʱ�˳�
    {
        printf("Error!,�˱�Ϊ��!");
        exit(1);
    }
    while(s->data != '\n')                                          //���ڵ������ݲ�Ϊ���з�,���û��������ݻ�δ����,����ѭ��,�Ӷ�����һ��˫������
    {
        s=(struct orderedlist*)malloc(sizeof(struct orderedlist));  //Ϊ�ڵ�s����һ��orderedlist���͵Ĵ洢�ռ�
        scanf("%c",&s->data);                                       //���û�������һ�����ݴ洢���ڵ�s����������
        s->last=p;                                                  //s��ָ��������һ���ڵ���ָ��ָ��p
        s->next=NULL;                                               //s��ָ��������һ���ڵ���ָ����Ϊ��
        p->next=s;                                                  //p��ָ��������һ���ڵ���ָ��ָ��s
        p=s;                                                        //��ָ��pָ��s
    }
    s=head;                                                         //��sָ��ͷָ��
    p=s->next;                                                      //��pָ��s����һ���ڵ�
    while(s->next!=NULL)                                            //����ð�ݷ�,ͨ������ѭ�����ظ������ݽڵ�ɾ��,��ͬʱ��������
    {
        while(p->next!=NULL)
        {
            if(s->data<p->data)                                     //���ڵ�s������С�ڽڵ�p������
                p=p->next;                                          //pָ����һ���ڵ�
            else if(s->data==p->data)                               //���ڵ�s�����ݵ��ڽڵ�p������,����ɾ���ڵ�
            {
                p->last->next=p->next;                              //�ǰָ��p����һ���ڵ���ָ����һ���ڵ���ָ��ָ����ǰ�ڵ�p����һ���ڵ�
                p->next->last=p->last;                              //�ǰָ��p����һ���ڵ���ָ����һ���ڵ���ָ��ָ����ǰ�ڵ�p����һ���ڵ�
                p=p->next;                                          //pָ����һ���ڵ�
            }
            else                                                    //�����ڵ�s�����ݴ��ڽڵ�p������
            {
                temp=s->data;                                       //���ڵ�s�����ݴ洢����ʱ����temp��
                s->data=p->data;                                    //���ڵ�p�����ݴ洢���ڵ�s����������
                p->data=temp;                                       //����ʱ����temp��ֵ�洢���ڵ�p����������,����ʵ������
                p=p->next;                                          //pָ����һ���ڵ�
            }
        }
        s=s->next;                                                  //sָ����һ���ڵ�
        p=s->next;                                                  //pָ����һ���ڵ�
    }
    return head;                                                    //����ͷ�ڵ�ָ��
}
//���ڽ�����1,����2�г��ֵĹ���Ԫ����ȡ����,����һ���µ���������,�β�����Ϊ��������ָ��,���صĲ���Ϊ����ָ��
struct orderedlist *compare1(struct orderedlist *p1,struct orderedlist *p2)
{
    struct orderedlist *p3=NULL,*h=NULL,*s=NULL;                    //��������ָ��p3,ͷ�ڵ�h,�Լ�ָ��s,�����г�ʼ��
    h=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //Ϊͷ�ڵ�����һ��orderedlist���͵Ĵ洢�ռ�
    h->last=NULL;                                                   //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    h->next=NULL;                                                   //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    p3=h;                                                           //ָ��p3ָ��ͷ�ڵ�
    while(p1->next!=NULL&&p2->next!=NULL)                           //������1,����2��Ϊ����,����ѭ��
    {
        if(p1->next->data<p2->next->data)                           //����ͷ�ڵ����޹�����,������1�Ľڵ����ݴ�������2�Ľڵ�����
            p1=p1->next;                                            //p1����
        else if(p1->next->data==p2->next->data)                     //��p1ָ����һ�ڵ����ݵ���p2ָ����һ�ڵ�����
        {
            s=(struct orderedlist*)malloc(sizeof(struct orderedlist)); //Ϊ�ڵ�s����һ��orderedlist���͵Ĵ洢�ռ�
            s->data=p1->next->data;                                 //�ڵ�s�����ݴ���ָ��p1����һ�ڵ�������
            s->last=p3;                                             //s��ָ��������һ���ڵ���ָ��ָ��p3
            s->next=NULL;                                           //s����һ�ڵ���Ϊ��
            p3->next=s;                                             //p3����һ�ڵ�ָ��s
            p3=s;                                                   //p3ָ���ڵ�s
            p1=p1->next;                                            //p1����
            p2=p2->next;                                            //p2����
        }
        else p2=p2->next;                                           //����p1ָ����һ�ڵ����ݴ���p2ָ����һ�ڵ�����,p2����
    }
    return h;                                                       //����ͷ�ڵ�ָ��
}
//���ڱȽ�����1,����2�е�Ԫ��,������1�г��ֵ�δ������2�г��ֵ�������ȡ����,����һ���µ���������,�β�����Ϊ��������ָ��,���صĲ���Ϊ����ָ��
struct orderedlist *compare2(struct orderedlist *p1,struct orderedlist *p2)
{
    struct orderedlist *p3=NULL,*h=NULL,*s=NULL;                    //��������ָ��p3,ͷ�ڵ�h,�Լ�ָ��s,�����г�ʼ��
    h=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //Ϊͷ�ڵ�����һ��orderedlist���͵Ĵ洢�ռ�
    h->last=NULL;                                                   //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    h->next=NULL;                                                   //ͷ�ڵ���ָ����һ���ڵ���ָ����Ϊ��
    p3=h;                                                           //ָ��p3ָ��ͷ�ڵ�
    while(p1->next!=NULL&&p2->next!=NULL)                           //������1,����2��Ϊ����,����ѭ��
    {
        if(p1->next->data<p2->next->data)                           //����ͷ�ڵ����޹�����,������1�Ľڵ�����С������2�Ľڵ�����
        {
            s=(struct orderedlist*)malloc(sizeof(struct orderedlist));//Ϊ�ڵ�s����һ��orderedlist���͵Ĵ洢�ռ�
            s->data=p1->next->data;                                 //�ڵ�s�����ݴ���ָ��p1����һ�ڵ�������
            s->last=p3;                                             //s��ָ��������һ���ڵ���ָ��ָ��p3
            s->next=NULL;                                           //s����һ�ڵ���Ϊ��
            p3->next=s;                                             //p3����һ�ڵ�ָ��s
            p3=s;                                                   //p3ָ���ڵ�s
            p1=p1->next;                                            //p1����
        }
        else if(p1->next->data==p2->next->data)                     //������1�Ľڵ����ݵ�������2�Ľڵ�����
            p1=p1->next;                                            //p1����
        else p2=p2->next;                                           //��������1�Ľڵ����ݴ�������2�Ľڵ�����,p2����
    }
    return h;                                                       //����ͷ�ڵ�ָ��
}
//���ڴ�ӡ��������,�β�����Ϊ����ָ��,���صĲ���Ϊ��
void print(struct orderedlist *p)
{
    if(p->next==NULL)                                               //��������ͷָ������һ�ڵ�Ϊ��,��������Ϊ��
        printf("����DΪ��!");
    else while(p->next!=NULL)                                       //������ָ��p����һ�ڵ㲻Ϊ��ʱ,ѭ��,���δ�ӡ���ڵ�����
    {
        printf("%c",p->next->data);
        p=p->next;
    }
}
//������
int main()
{
    struct orderedlist *A=NULL,*B=NULL,*C=NULL,*same=NULL,*D=NULL;  //��������A,B,C,same,D
    printf("please input the 'A' linked list : ");
    A=creatlist(A);                                                 //��������A
    printf("please input the 'B' linked list : ");
    B=creatlist(B);                                                 //��������B
    printf("please input the 'C' linked list : ");
    C=creatlist(C);                                                 //��������C
    same=compare1(B,C);                                             //������A,����B�г��ֵĹ���Ԫ����ȡ����,����һ���µ���������same
    D=compare2(A,same);                                             //������A�г��ֵ�δ������same�г��ֵ�������ȡ����,����һ���µ���������D
    print(D);                                                       //��ӡ��������D
    free(A);                                                        //�ͷ�A
    free(B);                                                        //�ͷ�B
    free(C);                                                        //�ͷ�C
    free(D);                                                        //�ͷ�D
    free(same);                                                     //�ͷ�same
    return 0;
}
