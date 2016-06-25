/**
 *lesson:  数据结构课程设计
 *tittle:  题目8:二叉树的遍历
 *author:  ThyChan
**/

#include <stdio.h>
#include <stdlib.h>
/*定义二叉树节点结构体*/
typedef struct node
{
    char data;
    struct node *lson,*rson;
}BITREE;

/*通过递归建立二叉树*/
BITREE *creatbt()
{
    BITREE *s;
    char c;
    c=getchar();
    if(c=='#')                                           //表示该节点为空
        s=NULL;
    else
    {
        s=(BITREE*)malloc(sizeof(BITREE));
        s->data=c;
        s->lson=creatbt();
        s->rson=creatbt();
    }
    return s;
}
/*递归实现先序遍历*/
void preorder(BITREE *root)
{
	if (root!=NULL)
	{
		printf("%c ",root->data);                        //输出根结点
	    preorder(root->lson);                            //先序遍历左结点
	    preorder(root->rson);                            //先序遍历右结点
	}
	else return;
}
/*非递归实现中序遍历*/
void inorder(BITREE *root)
{
	int i=0;
	BITREE *p,*a[100];
	p=root;
	while (i!=0 || p!=NULL)                              //终止条件
	{
		while (p!=NULL)                                  //一直访到左孩子为空结点
		{
			i++;                                         //进栈
			a[i]=p;
			p=p->lson;
		}
		if (i!=0)                                        //栈不为空，则输出根结点
		{
			p=a[i];
			i--;                                         //出栈
			printf("%c ",p->data);
			p=p->rson;                                   //访问根的右孩子
		}
	}
}

/*对于后序遍历，由于根结点得在访问完左右孩子之后才能访问，所以可采取加标记的方式：*/
void postorder(BITREE *root)                             //非递归实现后序遍历
{
	BITREE *p,*a[100];
	int i=0,b[100];
	p=root; a[0]=NULL;                                   //a用来存放根结点
	while (i!=0 || p!=NULL)                              //终止条件
	{
		while (p!=NULL)                                  //访问到左孩子为空结点
		{
			if (b[i]==2) break;                          //被第二次访问的，退出，进入到输出
			i++;
			a[i]=p;
			b[i]=0;
			p=p->lson;
		}
		if (i!=0)                                        //如果栈中有元素
		{
			if (p==NULL)                                 //孩子为空的情况，则返回访问了一次，b[i]++,p回到根结点
			{ b[i]++; p=a[i];}
			if (b[i]==2)                                 //返回了两次，则输出根结点
			{
			  printf("%c ",p->data);
			  b[i]=0;  i--;
			  p=a[i]; b[i]++;
			}
			if (i==0) {p=NULL; break; }                  //处理了总的根结点，特殊处理
			if (b[i]==1) p=p->rson;		                 //如果是左孩子返回的根结点，则访问该结点的右孩子
		}
	}
}
/*递归实现左右子树的交换*/
void exchange(BITREE *root)
{
	BITREE *p;
	if (root==NULL) return;                              //交换根结点的左右子树
	p=root->lson;
	root->lson=root->rson;
	root->rson=p;
	exchange(root->lson);                                //交换左孩子的子树
	exchange(root->rson);                                //交换右孩子的子树
}

int height(BITREE *root)                                 //递归求二叉树的高度
{
	int maxh=0,h1,h2;
	if (root!=NULL)
	{
		h1=height(root->lson);                           //h1记录左子树的高度
		h2=height(root->rson);                           //h2记录右子树的高度
		maxh=h1>h2?h1+1:h2+1;                            //树的高度等于左子树和右子树中较大的高度+1
	}
	return maxh;
}


int main()
{
    int n,h;
    BITREE *root=NULL;
    while(1)
    {
        printf("-----------------------------------------------------------------\n");
        printf("|--------\t\t二叉树的遍历\t\t\t--------|\n");
        printf("|----------------------------------------------------------------\n");
        printf("|--------\t\t1.建立二叉树\t\t\t--------|\n");
        printf("|--------\t\t2.前序遍历二叉树\t\t--------|\n");
        printf("|--------\t\t3.中序遍历二叉树\t\t--------|\n");
        printf("|--------\t\t4.后序遍历二叉树\t\t--------|\n");
        printf("|--------\t\t5.交换左右子数\t\t\t--------|\n");
        printf("|--------\t\t6.统计二叉树高度\t\t--------|\n");
        printf("|--------\t\t0.Quit\t\t\t\t--------|\n");
        printf("|----------------------------------------------------------------\n");
        printf("Please input the number you select: ");
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1:     system("cls");
                        printf("请以先序遍历的方式建立二叉树(如\"abc###de###\")\n");
                        while((root=creatbt())==NULL)
                        {
                            printf("二叉树为空,请重新建立!\n");
                            getchar();                                      //消除回车的影响
                        }
                        printf("二叉树建立完成!\n按任意键返回...");
                        getchar();                                          //上一步消除回车的影响
                        getchar();                                          //使停顿
                        break;
            case 2:     system("cls");
                        preorder(root);
                        printf("\n按任意键返回...");
                        getchar();
                        break;
            case 3:     system("cls");
                        inorder(root);
                        printf("\n按任意键返回...");
                        getchar();
                        break;
            case 4:     system("cls");
                        postorder(root);
                        printf("\n按任意键返回...");
                        getchar();
                        break;
            case 5:     system("cls");
                        exchange(root);
                        printf("\n左右子树已交换完成!\n按任意键返回...");
                        getchar();
                        break;
            case 6:     system("cls");
                        h=height(root);
                        printf("该二叉树的高度为%d.\n按任意键返回...",h);
                        getchar();
                        break;
            case 0:     exit(0);
                        break;
            default:    printf("Input error!");
                        getchar();
        }
        system("cls");
    }
    return 0;
}
