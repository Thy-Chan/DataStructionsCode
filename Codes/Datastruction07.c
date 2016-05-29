/**
 *lesson:  ���ݽṹ�γ����
 *tittle:  ��Ŀ7:�ı��ļ����ʵļ���������
 *author:  ThyChan
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100000
char a[20],f[M],path[30];           //����ȫ�ֱ��� a[20]���ڴ洢����,f[M]���ڴ���ļ��е��ı�,path[30]���ڴ���û������·��

/*��������*/
void Deal();                        //ʵ��ѡ�񷵻ػ��˳�
void CreatFile();                   //�����ļ������ж�д�ı�
void Analyze();                     //�����ı����ݼ�λ��
void Display();                     //��ʾ����ı�����

/*������*/
int main()
{
    int n=-1;
    while(n!='0')
    {
        printf("\n ================================================================\n");
        printf("�U\t\t\t���ı��ļ����ʼ�����������\t\t�U\n");
        printf("�U--------------------------------------------------------------�U\n");
        printf("�U\t\t\t(1):�����ļ�\t\t\t\t�U     \n");
        printf("�U\t\t\t(2):���������ܴ�����λ��\t\t�U          \n");
        printf("�U\t\t\t(3):��ʾ�ı� \t\t\t\t�U          \n");
        printf("�U\t\t\t(0):�˳�      \t\t\t\t�U          \n");
        printf(" ================================================================\n");
        printf("��ѡ��:\t");
        scanf("%d",&n);
        getchar();                                      //��������Ļس�����
        switch (n)                                      //����ѡ��ѡ��
        {
            case 1:     CreatFile();break;
            case 2:     Analyze();break;
            case 3:     Display();break;
            case 0:     break;
            default:    printf("Error!@*#!\n");Deal();
        }
        continue;
    }
    return 0;
}
/*ʵ��ѡ�񷵻ػ��˳�*/
void Deal()
{
    char i=' ';
    printf("����������y,����������n\t:");
    while(i!='y')
    {
        i=getchar();
        getchar();
        if(i=='n') exit(0);
        else if(i!='y')
        {
            printf("�������,����������:");
            continue;
        }
    }
}
/*�����ļ������ж�д�ı�*/
void CreatFile()
{
    FILE *fp;
    char ch;
    int i;
    printf("�����������贴���ļ���(������·��):");
    scanf("%s",path);                                               //��������ļ���
    getchar();
    if((fp=fopen(path,"w"))==NULL)                                  //�������ļ�
    {
        printf("cannot open file\n");                               //�������ļ���������Ϣ
        exit(1);                                                    //��ֹ���ù��̡��ر������ļ�
    }
    printf("�������ı�(��'#'��������):\n");
    ch=getchar( );                                                  //�Ӽ��̶���һ���ַ�
    while(ch!='#')                                                  //����#ʱֹͣ����
    {
        fputc(ch,fp);                                               //��ch���ַ�д��fpָ����ļ�
        ch=getchar( );
    }
    getchar();
    fclose(fp);                                                     //�ر�fp��ָ����ļ�
    if((fp=fopen(path,"r"))==NULL)                                  //��filename ��'r'��ʽ��
    {
        printf("cannot open file\n");
        exit (1);
    }
    else
    {
        printf("�ѳɹ���ȡ����%s��\n\n",path);
        for(i=0;(f[i]=fgetc(fp))!=EOF;i++)                          //���ļ��е����ݶ���ŵ�f[i]��
            ;
        f[i]='\n';                                                  //�����ڶ�����Ԫ���һ�����з�,�����ں��浥�ʵļ���
        f[i+1]='\0';                                                //����ſ��ַ�,���ڽ���
    }
    fclose(fp);
    Deal();
}
/*�����ı����ݼ�λ��*/
void Analyze()
{
  char str[20];
  int lines=1,words=0,i=0,j=0,n=0,t=0,l=0,w=0;
  printf("��������ͳ�Ƶĵ��ʣ�");
  scanf("%s",str);
  getchar();
  for(i=0;f[i]!='\0';i++)                                               //ͨ��ѭ��,���������ַ��ı���
  {
    if(f[i]!=' '&&f[i]!='\n')                                           //��f[i]��Ϊ�ո����ʱ,����Ϊ��ĸ,����洢��a[j]��
    {
        a[j]=f[i];
        j++;
    }
    else                                                                //�������һ�������ѽ���
    {
        a[j]='\0';                                                      //��β��ӿհ׷�
        if(j!=0)                                                        //j!=0˵����ʱ�����������Ŀո���з�,�е�����+1
            words++;
        if(strcmp(a,str)==0)                                            //�û�����ĵ�������ı�������ȡ�ĵ��ʽ��бȽ�,��ͬ���ǳ��ֵĴ���+1
        {
            n++;
            if(t==0)                                                    //t���ڱ���Ƿ����״γ���,���򽫴�ʱ������,λ�ü�¼����
            {
                l=lines;
                w=words;
                t=1;
            }
        }
        j=0;
    }
    if(f[i]=='\n')                                                      //����������+1,�е�������0
    {
        lines++;
        words=0;
    }
  }
  if(n==0)
    printf("%sδ�����ֹ�!\n",str);
  else
  {
      printf("���ļ���%s���ֵĴ���Ϊ:%d\n",str,n);
      printf("%s�ڸ��ı����״γ�����%d��,��%d�����ʴ�.\n\n",str,l,w);
  }
  Deal();
}
/*��ʾ����ı�����*/
void Display()
{

    FILE *fp;
    char ch;
    if((fp=fopen(path,"r"))==NULL)                        //��path ��'r'��ʽ��
    {
        printf("cannot open file\n");
        exit (1);
    }
    else
    {
        printf("\n�ļ�%s:\n",path);
        while((ch=fgetc(fp))!=EOF)                        //ͨ��ѭ���������ÿ���ַ�
            putchar(ch);
        printf("\n\n");
    }
    fclose(fp);
    Deal();
}