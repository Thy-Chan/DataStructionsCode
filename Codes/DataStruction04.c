/**
 *lesson:  数据结构课程设计
 *tittle:  题目4:有序表 
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct orderedlist                                                  //声明有序表链表
{
    char data;                                                      //字符类型的指针
    struct orderedlist *next;                                       //指向链表下一个节点的指针
    struct orderedlist *last;                                       //指向链表上一个节点的指针
};
//用于创建有序链表,形参类型为链表指针,返回的参数为链表指针
struct orderedlist *creatlist(struct orderedlist *s)
{
    struct orderedlist *head=NULL,*p=NULL;                          //定义链表头节点,链表指针,初始化为NULL
    char temp;                                                      //定义一个临时的字符型变量
    head=(struct orderedlist*)malloc(sizeof(struct orderedlist));   //为头节点申请一个orderedlist类型的存储空间
    head->last=NULL;                                                //头节点的指向上一个节点的指针置为空
    head->next=NULL;                                                //头节点的指向下一个节点的指针置为空
    p=head;                                                         //指针p指向头节点
    s=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //为节点申请一个orderedlist类型的存储空间
    scanf("%c",&s->data);                                           //将用户输入的一个数据存储到节点s的数据域中
    s->last=p;                                                      //s的指向链表上一个节点的指针指向p,即指向头节点
    s->next=NULL;                                                   //s的指向链表下一个节点的指针置为空
    p->next=s;                                                      //p的指向链表下一个节点的指针指向s
    p=s;                                                            //令指针p指向s
    if(s->data=='\n')                                               //若节点存储的数据为换行符，即说明用户输入的数据为空，此时退出
    {
        printf("Error!,此表为空!");
        exit(1);
    }
    while(s->data != '\n')                                          //若节点的数据不为换行符,即用户输入数据还未结束,进行循环,从而构建一个双向链表
    {
        s=(struct orderedlist*)malloc(sizeof(struct orderedlist));  //为节点s申请一个orderedlist类型的存储空间
        scanf("%c",&s->data);                                       //将用户输入的一个数据存储到节点s的数据域中
        s->last=p;                                                  //s的指向链表上一个节点的指针指向p
        s->next=NULL;                                               //s的指向链表下一个节点的指针置为空
        p->next=s;                                                  //p的指向链表下一个节点的指针指向s
        p=s;                                                        //令指针p指向s
    }
    s=head;                                                         //令s指向头指针
    p=s->next;                                                      //令p指向s的下一个节点
    while(s->next!=NULL)                                            //利用冒泡法,通过两次循环将重复的数据节点删除,并同时进行排序
    {
        while(p->next!=NULL)
        {
            if(s->data<p->data)                                     //若节点s的数据小于节点p的数据
                p=p->next;                                          //p指向下一个节点
            else if(s->data==p->data)                               //若节点s的数据等于节点p的数据,进行删除节点
            {
                p->last->next=p->next;                              //令当前指针p的上一个节点的指向下一个节点的指针指向当前节点p的下一个节点
                p->next->last=p->last;                              //令当前指针p的下一个节点的指向上一个节点的指针指向当前节点p的上一个节点
                p=p->next;                                          //p指向下一个节点
            }
            else                                                    //否则节点s的数据大于节点p的数据
            {
                temp=s->data;                                       //将节点s的数据存储到临时变量temp中
                s->data=p->data;                                    //将节点p的数据存储到节点s的数据域中
                p->data=temp;                                       //将临时变量temp的值存储到节点p的数据域中,进而实现排序
                p=p->next;                                          //p指向下一个节点
            }
        }
        s=s->next;                                                  //s指向下一个节点
        p=s->next;                                                  //p指向下一个节点
    }
    return head;                                                    //返回头节点指针
}
//用于将链表1,链表2中出现的公共元素提取出来,构建一个新的有序链表,形参类型为两个链表指针,返回的参数为链表指针
struct orderedlist *compare1(struct orderedlist *p1,struct orderedlist *p2)
{
    struct orderedlist *p3=NULL,*h=NULL,*s=NULL;                    //定义链表指针p3,头节点h,以及指针s,并进行初始化
    h=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //为头节点申请一个orderedlist类型的存储空间
    h->last=NULL;                                                   //头节点的指向上一个节点的指针置为空
    h->next=NULL;                                                   //头节点的指向下一个节点的指针置为空
    p3=h;                                                           //指针p3指向头节点
    while(p1->next!=NULL&&p2->next!=NULL)                           //若链表1,链表2都为结束,进行循环
    {
        if(p1->next->data<p2->next->data)                           //跳过头节点的无关数据,若链表1的节点数据大于链表2的节点数据
            p1=p1->next;                                            //p1后移
        else if(p1->next->data==p2->next->data)                     //若p1指向下一节点数据等于p2指向下一节点数据
        {
            s=(struct orderedlist*)malloc(sizeof(struct orderedlist)); //为节点s申请一个orderedlist类型的存储空间
            s->data=p1->next->data;                                 //节点s的数据存放指针p1的下一节点的数据
            s->last=p3;                                             //s的指向链表上一个节点的指针指向p3
            s->next=NULL;                                           //s的下一节点置为空
            p3->next=s;                                             //p3的下一节点指向s
            p3=s;                                                   //p3指向节点s
            p1=p1->next;                                            //p1后移
            p2=p2->next;                                            //p2后移
        }
        else p2=p2->next;                                           //否则p1指向下一节点数据大于p2指向下一节点数据,p2后移
    }
    return h;                                                       //返回头节点指针
}
//用于比较链表1,链表2中的元素,把链表1中出现但未在链表2中出现的数据提取出来,构建一个新的有序链表,形参类型为两个链表指针,返回的参数为链表指针
struct orderedlist *compare2(struct orderedlist *p1,struct orderedlist *p2)
{
    struct orderedlist *p3=NULL,*h=NULL,*s=NULL;                    //定义链表指针p3,头节点h,以及指针s,并进行初始化
    h=(struct orderedlist*)malloc(sizeof(struct orderedlist));      //为头节点申请一个orderedlist类型的存储空间
    h->last=NULL;                                                   //头节点的指向上一个节点的指针置为空
    h->next=NULL;                                                   //头节点的指向下一个节点的指针置为空
    p3=h;                                                           //指针p3指向头节点
    while(p1->next!=NULL&&p2->next!=NULL)                           //若链表1,链表2都为结束,进行循环
    {
        if(p1->next->data<p2->next->data)                           //跳过头节点的无关数据,若链表1的节点数据小于链表2的节点数据
        {
            s=(struct orderedlist*)malloc(sizeof(struct orderedlist));//为节点s申请一个orderedlist类型的存储空间
            s->data=p1->next->data;                                 //节点s的数据存放指针p1的下一节点的数据
            s->last=p3;                                             //s的指向链表上一个节点的指针指向p3
            s->next=NULL;                                           //s的下一节点置为空
            p3->next=s;                                             //p3的下一节点指向s
            p3=s;                                                   //p3指向节点s
            p1=p1->next;                                            //p1后移
        }
        else if(p1->next->data==p2->next->data)                     //若链表1的节点数据等于链表2的节点数据
            p1=p1->next;                                            //p1后移
        else p2=p2->next;                                           //否则链表1的节点数据大于链表2的节点数据,p2后移
    }
    return h;                                                       //返回头节点指针
}
//用于打印输出链表,形参类型为链表指针,返回的参数为空
void print(struct orderedlist *p)
{
    if(p->next==NULL)                                               //若链表的头指针的下一节点为空,输出链表为空
        printf("链表D为空!");
    else while(p->next!=NULL)                                       //否则当指针p的下一节点不为空时,循环,依次打印出节点数据
    {
        printf("%c",p->next->data);
        p=p->next;
    }
}
//主函数
int main()
{
    struct orderedlist *A=NULL,*B=NULL,*C=NULL,*same=NULL,*D=NULL;  //定义链表A,B,C,same,D
    printf("please input the 'A' linked list : ");
    A=creatlist(A);                                                 //构建链表A
    printf("please input the 'B' linked list : ");
    B=creatlist(B);                                                 //构建链表B
    printf("please input the 'C' linked list : ");
    C=creatlist(C);                                                 //构建链表C
    same=compare1(B,C);                                             //将链表A,链表B中出现的公共元素提取出来,构建一个新的有序链表same
    D=compare2(A,same);                                             //将链表A中出现但未在链表same中出现的数据提取出来,构建一个新的有序链表D
    print(D);                                                       //打印输出链表D
    free(A);                                                        //释放A
    free(B);                                                        //释放B
    free(C);                                                        //释放C
    free(D);                                                        //释放D
    free(same);                                                     //释放same
    return 0;
}
