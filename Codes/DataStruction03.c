/**
 *lesson:  数据结构课程设计
 *tittle:  题目3:工资核算
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
struct pay                              //声明一个结构体
{
    char name[20];                      //姓名
    char department[20];                //部门
    int basepay;                        //基本工资
    int allowance;                      //福利
    int total;                          //总工资
};
int main()
{
    int i,n;
    printf("请输入单位人员的人数：\n");
    scanf("%d",&n);                         //n为该单位的总人数
    struct pay paydata[n];                  //定义一个pay的结构体数组paydata[n]
    FILE *fp;                               //定义指向文件的指针变量fp
    fp = fopen("paydata.txt","w");          //表示打开名为"paydata.txt"的文件，使用文件方式为"只写"
    for(i=0; i<n; i++)
    {
        printf("请输入名字，部门，基本工资和福利 :\n");
        scanf("%s %s %d %d",paydata[i].name,paydata[i].department,&paydata[i].basepay,&paydata[i].allowance);   //输入每个人的数据
        paydata[i].total=paydata[i].basepay+paydata[i].allowance;                                               //总工资=基本工资+福利
        fprintf(fp,"%s\t%s\t%d\t%d\t%d\n",paydata[i].name,paydata[i].department,
                paydata[i].basepay,paydata[i].allowance,paydata[i].total);                                      //将数据存入"paydata.txt"文件中
    }
    fclose(fp);                                                                                                 //关闭由指针fp指定的文件
    fp = fopen("paydata.txt","r");                                                                              //表示打开名为"paydata.txt"的文件，使用文件方式为"只读"
    for(i=0; i<n; i++)
        fscanf(fp,"%s\t%s\t%d\t%d\t%d\n",paydata[i].name,paydata[i].department,
               &paydata[i].basepay,&paydata[i].allowance,&paydata[i].total);                                    //将数据从paydata文件中读取出来
    for(i=0; i<n; i++)
        printf("%-15s%-15s\t%d\t%d\t%d\n",paydata[i].name,
               paydata[i].department,paydata[i].basepay+100,paydata[i].allowance,paydata[i].total+100);         //输出数据到屏幕上
    fclose(fp);                                                                                                 //关闭由指针fp指定的文件
    return 0;
}

