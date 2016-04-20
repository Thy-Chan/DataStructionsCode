/**
 *lesson:  ���ݽṹ�γ�����
 *tittle:  ��Ŀ2:�ַ���ת
 *author:  ThyChan
**/
#include<stdio.h>
#include<stdlib.h>
struct String
{
    char s;
    struct String* next;                        //ָ�����ַ�����һ���ַ�
};
void add(struct String** pointer, int data)
{
    struct String* new_String = (struct String*) malloc(sizeof(struct String)); //�����ռ�
    new_String->s=data;                         //�����ַ�
    new_String->next=*pointer;                  //�ڵ���ַָ����ǰ��ָ��
    *pointer= new_String;                       //ָ��ָ����ǰ������new_String,ͨ��ѭ�����Ӷ�ʵ�ִ�β��ָ��ͷ���ĵ�������
}
void printList(struct String *head)
{
    while(head!= NULL)                          //��ǰָ�벻Ϊ��ʱ������ѭ��
    {
        printf("%c ", head->s);                 //��ӡ��ǰ�ڵ�����
        head = head->next;                      //ָ����һ��
    }
}
int main()
{
    char c;                                     //���ڽ����û��������ַ�
    struct String* head = NULL;                 //����ʼͷָ������Ϊ��
    printf("������һϵ���ַ�:\n");
    while((c=getchar())!='\n')                  //�����ַ�,��Ϊ����ʱ��������
        add(&head,c);
    printf("��ת�����ַ�Ϊ:  ");
    printList(head);                            //��ӡ����
}
