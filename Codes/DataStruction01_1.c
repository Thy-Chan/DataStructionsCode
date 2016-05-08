/**
 *数据结构课程设计
 *tittle:题目1_猴子选王_01(向量方式)
 *author:ThyChan
**/

#include <stdio.h>
#include <stdlib.h>
int begin(int m, int n)
{
    int i=0,j=0,k=0,t=0;
    int a[m+1];																	//定义一个n+1个元素的数组，忽略a[0],余下的元素的下标则分别对应猴子的编号
    for(i=1; i<=m; i++)
        a[i]=1;                                                     			//将数组元素1~m全部设置为1
    for(i=1; k!=m; i++)                                     					//若k==m,即数组a[m+1]中元素置为0的个数为m时,表示a[i]中1~m个数已全部置为0,同时t就是最后那个元素的下标.
    {
        if(i>m)
            i-=m;                                                 				//当i>m时,重新从1开始循环,即i=i-m,构成约瑟夫环
        if(a[i]==1)
        {
            j++;
            if(j==n)                                              				//j记为计数,当j==n时,将a[i]置为0,同时将j置为0,将下标i赋值给t,同时k++
            {
                a[i]=0;
                j=0;
                t=i;
                k++;
            }
        }
    }
    return t;
}
int main(void)
{
    int m,n,t;																	//m为猴子的数量，n为猴子所报的数
    printf("请输入猴子的数量m, 以及所报的数字:n\n");
    scanf("%d %d",&m,&n);
    t=begin(m, n);
    printf("第%d个猴子为大王!\n",t);
    return 0;
}
