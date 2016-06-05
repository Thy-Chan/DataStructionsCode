/**
 *lesson:  ���ݽṹ�γ����
 *tittle:  ��Ŀ8:�������ı���
 *author:  ThyChan
**/

#include <stdio.h>
#include <stdlib.h>
/*����������ڵ�ṹ��*/
typedef struct node
{
    char data;
    struct node *lson,*rson;
}BITREE;

/*ͨ���ݹ齨��������*/
BITREE *creatbt()
{
    BITREE *s;
    char c;
    c=getchar();
    if(c=='#')                                           //��ʾ�ýڵ�Ϊ��
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
/*�ݹ�ʵ���������*/
void preorder(BITREE *root)
{
	if (root!=NULL)
	{
		printf("%c ",root->data);                        //��������
	    preorder(root->lson);                            //�����������
	    preorder(root->rson);                            //��������ҽ��
	}
	else return;
}
/*�ǵݹ�ʵ���������*/
void inorder(BITREE *root)
{
	int i=0;
	BITREE *p,*a[100];
	p=root;
	while (i!=0 || p!=NULL)                              //��ֹ����
	{
		while (p!=NULL)                                  //һֱ�õ�����Ϊ�ս��
		{
			i++;                                         //��ջ
			a[i]=p;
			p=p->lson;
		}
		if (i!=0)                                        //ջ��Ϊ�գ�����������
		{
			p=a[i];
			i--;                                         //��ջ
			printf("%c ",p->data);
			p=p->rson;                                   //���ʸ����Һ���
		}
	}
}

/*���ں�����������ڸ������ڷ��������Һ���֮����ܷ��ʣ����Կɲ�ȡ�ӱ�ǵķ�ʽ��*/
void postorder(BITREE *root)                             //�ǵݹ�ʵ�ֺ������
{
	BITREE *p,*a[100];
	int i=0,b[100];
	p=root; a[0]=NULL;                                   //a������Ÿ����
	while (i!=0 || p!=NULL)                              //��ֹ����
	{
		while (p!=NULL)                                  //���ʵ�����Ϊ�ս��
		{
			if (b[i]==2) break;                          //���ڶ��η��ʵģ��˳������뵽���
			i++;
			a[i]=p;
			b[i]=0;
			p=p->lson;
		}
		if (i!=0)                                        //���ջ����Ԫ��
		{
			if (p==NULL)                                 //����Ϊ�յ�������򷵻ط�����һ�Σ�b[i]++,p�ص������
			{ b[i]++; p=a[i];}
			if (b[i]==2)                                 //���������Σ�����������
			{
			  printf("%c ",p->data);
			  b[i]=0;  i--;
			  p=a[i]; b[i]++;
			}
			if (i==0) {p=NULL; break; }                  //�������ܵĸ���㣬���⴦��
			if (b[i]==1) p=p->rson;		                 //��������ӷ��صĸ���㣬����ʸý����Һ���
		}
	}
}
/*�ݹ�ʵ�����������Ľ���*/
void exchange(BITREE *root)
{
	BITREE *p;
	if (root==NULL) return;                              //������������������
	p=root->lson;
	root->lson=root->rson;
	root->rson=p;
	exchange(root->lson);                                //�������ӵ�����
	exchange(root->rson);                                //�����Һ��ӵ�����
}

int height(BITREE *root)                                 //�ݹ���������ĸ߶�
{
	int maxh=0,h1,h2;
	if (root!=NULL)
	{
		h1=height(root->lson);                           //h1��¼�������ĸ߶�
		h2=height(root->rson);                           //h2��¼�������ĸ߶�
		maxh=h1>h2?h1+1:h2+1;                            //���ĸ߶ȵ������������������нϴ�ĸ߶�+1
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
        printf("|--------\t\t�������ı���\t\t\t--------|\n");
        printf("|----------------------------------------------------------------\n");
        printf("|--------\t\t1.����������\t\t\t--------|\n");
        printf("|--------\t\t2.ǰ�����������\t\t--------|\n");
        printf("|--------\t\t3.�������������\t\t--------|\n");
        printf("|--------\t\t4.�������������\t\t--------|\n");
        printf("|--------\t\t5.������������\t\t\t--------|\n");
        printf("|--------\t\t6.ͳ�ƶ������߶�\t\t--------|\n");
        printf("|--------\t\t0.Quit\t\t\t\t--------|\n");
        printf("|----------------------------------------------------------------\n");
        printf("Please input the number you select: ");
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1:     system("cls");
                        printf("������������ķ�ʽ����������(��\"abc###de###\")\n");
                        while((root=creatbt())==NULL)
                        {
                            printf("������Ϊ��,�����½���!\n");
                            getchar();                                      //�����س���Ӱ��
                        }
                        printf("�������������!\n�����������...");
                        getchar();                                          //��һ�������س���Ӱ��
                        getchar();                                          //ʹͣ��
                        break;
            case 2:     system("cls");
                        preorder(root);
                        printf("\n�����������...");
                        getchar();
                        break;
            case 3:     system("cls");
                        inorder(root);
                        printf("\n�����������...");
                        getchar();
                        break;
            case 4:     system("cls");
                        postorder(root);
                        printf("\n�����������...");
                        getchar();
                        break;
            case 5:     system("cls");
                        exchange(root);
                        printf("\n���������ѽ������!\n�����������...");
                        getchar();
                        break;
            case 6:     system("cls");
                        h=height(root);
                        printf("�ö������ĸ߶�Ϊ%d.\n�����������...",h);
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
