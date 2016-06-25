/**
 *lesson:  数据结构课程设计
 *tittle:  题目9:创建二叉排序树
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
/*定义二叉树节点的结构体*/
typedef struct BINODE
{
    int data;
    struct BINODE *lson,*rson;
}BINODE;
/*通过递归的方式排序插入节点*/
BINODE *Insert(BINODE *root,BINODE *son)                             //排序插入结点
{
	if (root==NULL) root=son;
	else                                                          //根为空的时候返回
	{
		if (son->data<root->data)                                 //如果小于根结点的数据
			root->lson=Insert(root->lson,son);                    //以左孩子为新的根，继续往左插入
		else if (son->data>=root->data)                           //如果大于等于根结点数据
			root->rson=Insert(root->rson,son);                    //以有孩子为新的根，往右树插入
	}
	return root;
}
/*通过递归的方式按照中序遍历依次输入各节点*/
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
    printf("创建二叉排序树\n");
    printf("请输入所需创建二叉树的各个节点(数字),并用空格隔开.\n"
            "[提示:输入非int型字符（如'#')结束二叉树的创建]：\n\n");
    while(scanf("%d",&c)==1)                                            //通过获取成功输入的值返回其个数进行判断输入是否结束
    {
        son=(BINODE*)malloc(sizeof(BINODE));                            //分配存储空间
        son->data=c;
        son->lson=NULL;
        son->rson=NULL;
        root=Insert(root,son);                                          //插入节点
    }
    if(root==NULL)  printf("您所创建的二叉树为空！");
    else
    {
        printf("中序遍历:\n");
        Output(root);                                                   //递归输出
    }
    return 0;
}
