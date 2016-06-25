/**
 *lesson:  ���ݽṹ�γ����
 *tittle:  ��Ŀ9:��������������
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
/*����������ڵ�Ľṹ��*/
typedef struct BINODE
{
    int data;
    struct BINODE *lson,*rson;
}BINODE;
/*ͨ���ݹ�ķ�ʽ�������ڵ�*/
BINODE *Insert(BINODE *root,BINODE *son)                             //���������
{
	if (root==NULL) root=son;
	else                                                          //��Ϊ�յ�ʱ�򷵻�
	{
		if (son->data<root->data)                                 //���С�ڸ���������
			root->lson=Insert(root->lson,son);                    //������Ϊ�µĸ��������������
		else if (son->data>=root->data)                           //������ڵ��ڸ��������
			root->rson=Insert(root->rson,son);                    //���к���Ϊ�µĸ�������������
	}
	return root;
}
/*ͨ���ݹ�ķ�ʽ���������������������ڵ�*/
void Output(BINODE *root)
{
    if(root!=NULL)
    {
        Output(root->lson);
        printf("%d ",root->data);
        Output(root->rson);
    }
}
int main()
{
    BINODE *root=NULL, *son=NULL;
    int c;
    printf("��������������\n");
    printf("���������贴���������ĸ����ڵ�(����),���ÿո����.\n"
            "[��ʾ:�����int���ַ�����'#')�����������Ĵ���]��\n\n");
    while(scanf("%d",&c)==1)                                            //ͨ����ȡ�ɹ������ֵ��������������ж������Ƿ����
    {
        son=(BINODE*)malloc(sizeof(BINODE));                            //����洢�ռ�
        son->data=c;
        son->lson=NULL;
        son->rson=NULL;
        root=Insert(root,son);                                          //����ڵ�
    }
    if(root==NULL)  printf("���������Ķ�����Ϊ�գ�");
    else
    {
        printf("�������:\n");
        Output(root);                                                   //�ݹ����
    }
    return 0;
}
