/**
 *lesson:  ���ݽṹ�γ�����
 *tittle:  ��Ŀ3:���ʺ���
 *author:  ThyChan
**/
#include <stdio.h>
#include <stdlib.h>
struct pay                              //����һ���ṹ��
{
    char name[20];                      //����
    char department[20];                //����
    int basepay;                        //��������
    int allowance;                      //����
    int total;                          //�ܹ���
};
int main()
{
    int i,n;
    printf("�����뵥λ��Ա��������\n");
    scanf("%d",&n);                         //nΪ�õ�λ��������
    struct pay paydata[n];                  //����һ��pay�Ľṹ������paydata[n]
    FILE *fp;                               //����ָ���ļ���ָ������fp
    fp = fopen("paydata.txt","w");          //��ʾ������Ϊ"paydata.txt"���ļ���ʹ���ļ���ʽΪ"ֻд"
    for(i=0; i<n; i++)
    {
        printf("���������֣����ţ��������ʺ͸��� :\n");
        scanf("%s %s %d %d",paydata[i].name,paydata[i].department,&paydata[i].basepay,&paydata[i].allowance);   //����ÿ���˵�����
        paydata[i].total=paydata[i].basepay+paydata[i].allowance;                                               //�ܹ���=��������+����
        fprintf(fp,"%s\t%s\t%d\t%d\t%d\n",paydata[i].name,paydata[i].department,
                paydata[i].basepay,paydata[i].allowance,paydata[i].total);                                      //�����ݴ���"paydata.txt"�ļ���
    }
    fclose(fp);                                                                                                 //�ر���ָ��fpָ�����ļ�
    fp = fopen("paydata.txt","r");                                                                              //��ʾ������Ϊ"paydata.txt"���ļ���ʹ���ļ���ʽΪ"ֻ��"
    for(i=0; i<n; i++)
        fscanf(fp,"%s\t%s\t%d\t%d\t%d\n",paydata[i].name,paydata[i].department,
               &paydata[i].basepay,&paydata[i].allowance,&paydata[i].total);                                    //�����ݴ�paydata�ļ��ж�ȡ����
    for(i=0; i<n; i++)
        printf("%-15s%-15s\t%d\t%d\t%d\n",paydata[i].name,
               paydata[i].department,paydata[i].basepay+100,paydata[i].allowance,paydata[i].total+100);         //�������ݵ���Ļ��
    fclose(fp);                                                                                                 //�ر���ָ��fpָ�����ļ�
    return 0;
}

