/**
 *lesson:  数据结构课程设计
 *tittle:  题目7:文本文件单词的检索及计数
 *author:  ThyChan
**/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 100000
char a[20],f[M],path[30];           //定义全局变量 a[20]用于存储单词,f[M]用于存放文件中的文本,path[30]用于存放用户输入的路径

/*函数申明*/
void Deal();                        //实现选择返回或退出
void CreatFile();                   //创建文件并进行读写文本
void Analyze();                     //检索文本内容及位置
void Display();                     //显示输出文本内容

/*主函数*/
int main()
{
    int n=-1;
    while(n!='0')
    {
        printf("\n ================================================================\n");
        printf("║\t\t\t【文本文件单词检索及计数】\t\t║\n");
        printf("║--------------------------------------------------------------║\n");
        printf("║\t\t\t(1):创建文件\t\t\t\t║     \n");
        printf("║\t\t\t(2):检索单词总次数及位置\t\t║          \n");
        printf("║\t\t\t(3):显示文本 \t\t\t\t║          \n");
        printf("║\t\t\t(0):退出      \t\t\t\t║          \n");
        printf(" ================================================================\n");
        printf("请选择:\t");
        scanf("%d",&n);
        getchar();                                      //消除多余的回车换行
        switch (n)                                      //进行选项选择
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
/*实现选择返回或退出*/
void Deal()
{
    char i=' ';
    printf("返回请输入y,结束请输入n\t:");
    while(i!='y')
    {
        i=getchar();
        getchar();
        if(i=='n') exit(0);
        else if(i!='y')
        {
            printf("输入错误,请重新输入:");
            continue;
        }
    }
}
/*创建文件并进行读写文本*/
void CreatFile()
{
    FILE *fp;
    char ch;
    int i;
    printf("请输入您所需创建文件名(含完整路径):");
    scanf("%s",path);                                               //读入磁盘文件名
    getchar();
    if((fp=fopen(path,"w"))==NULL)                                  //建立新文件
    {
        printf("cannot open file\n");                               //建立新文件出错误信息
        exit(1);                                                    //终止调用过程、关闭所有文件
    }
    printf("请输入文本(以'#'结束输入):\n");
    ch=getchar( );                                                  //从键盘读入一个字符
    while(ch!='#')                                                  //读到#时停止输入
    {
        fputc(ch,fp);                                               //将ch内字符写入fp指向的文件
        ch=getchar( );
    }
    getchar();
    fclose(fp);                                                     //关闭fp所指向的文件
    if((fp=fopen(path,"r"))==NULL)                                  //将filename 以'r'方式打开
    {
        printf("cannot open file\n");
        exit (1);
    }
    else
    {
        printf("已成功读取数据%s！\n\n",path);
        for(i=0;(f[i]=fgetc(fp))!=EOF;i++)                          //将文件中的数据都存放到f[i]中
            ;
        f[i]='\n';                                                  //倒数第二个单元存放一个换行符,方便于后面单词的检索
        f[i+1]='\0';                                                //最后存放空字符,用于结束
    }
    fclose(fp);
    Deal();
}
/*检索文本内容及位置*/
void Analyze()
{
  char str[20];
  int lines=1,words=0,i=0,j=0,n=0,t=0,l=0,w=0;
  printf("请输入需统计的单词：");
  scanf("%s",str);
  getchar();
  for(i=0;f[i]!='\0';i++)                                               //通过循环,进行所以字符的遍历
  {
    if(f[i]!=' '&&f[i]!='\n')                                           //当f[i]不为空格或换行时,表明为字母,将其存储到a[j]中
    {
        a[j]=f[i];
        j++;
    }
    else                                                                //否则表明一个单词已结束
    {
        a[j]='\0';                                                      //结尾添加空白符
        if(j!=0)                                                        //j!=0说明此时并不是连续的空格或换行符,行单词数+1
            words++;
        if(strcmp(a,str)==0)                                            //用户输入的单词与从文本中所读取的单词进行比较,相同则标记出现的次数+1
        {
            n++;
            if(t==0)                                                    //t用于标记是否是首次出现,是则将此时的行数,位置记录下来
            {
                l=lines;
                w=words;
                t=1;
            }
        }
        j=0;
    }
    if(f[i]=='\n')                                                      //换行则行数+1,行单词数置0
    {
        lines++;
        words=0;
    }
  }
  if(n==0)
    printf("%s未曾出现过!\n",str);
  else
  {
      printf("该文件中%s出现的次数为:%d\n",str,n);
      printf("%s在该文本中首次出现在%d行,第%d个单词处.\n\n",str,l,w);
  }
  Deal();
}
/*显示输出文本内容*/
void Display()
{

    FILE *fp;
    char ch;
    if((fp=fopen(path,"r"))==NULL)                        //将path 以'r'方式打开
    {
        printf("cannot open file\n");
        exit (1);
    }
    else
    {
        printf("\n文件%s:\n",path);
        while((ch=fgetc(fp))!=EOF)                        //通过循环进行输出每个字符
            putchar(ch);
        printf("\n\n");
    }
    fclose(fp);
    Deal();
}