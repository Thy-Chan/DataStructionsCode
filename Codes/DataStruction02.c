/**
 *lesson:  数据结构课程设计
 *tittle:  题目2:字符逆转
 *author:  ThyChan
**/
#include<stdio.h>
#include<stdlib.h>
struct String
{
    char s;
    struct String* next;                        //指向该字符的下一个字符
};
void add(struct String** pointer, int data)
{
    struct String* new_String = (struct String*) malloc(sizeof(struct String)); //分配空间
    new_String->s=data;                         //存放字符
    new_String->next=*pointer;                  //节点地址指向当前的指针
    *pointer= new_String;                       //指针指向当前的链表new_String,通过循环，从而实现从尾部指向头部的单向链表
}
void printList(struct String *head)
{
    while(head!= NULL)                          //当前指针不为空时，进行循环
    {
        printf("%c ", head->s);                 //打印当前节点数据
        head = head->next;                      //指向下一个
    }
}
int main()
{
    char c;                                     //用于接收用户输入的字符
    struct String* head = NULL;                 //将初始头指针设置为空
    printf("请输入一系列字符:\n");
    while((c=getchar())!='\n')                  //输入字符,当为换行时结束输入
        add(&head,c);
    printf("逆转后的字符为:  ");
    printList(head);                            //打印链表
}
