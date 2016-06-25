/**
 *lesson:  ���ݽṹ�γ�����
 *tittle:  ��Ŀ5:һԪ����ʽ�ļ���
 *author:  ThyChan
 *watch:   �ó���������һԪ����ʽ�ļ�/��������,�ɶ�����ʱÿһ����ϵ����ָ����Ϊint����,��������ʽ������ʱ��������int���͵��ַ�,��'Q'.
**/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*˫����������*/
typedef struct PolynList
{
    int coef;                           // ϵ��
    int expn;                           // ָ��
    struct PolynList *last;             //ָ����һ���ڵ���ָ������
    struct PolynList *next;             //ָ����һ���ڵ���ָ������
} PolynList;


/*���ڴ�������ʽ����*/
PolynList *CreatePolyn(PolynList *h)
{
    PolynList *p = NULL, *s = NULL;
    int tab = 0, ret = 0;
    h = (PolynList*)malloc(sizeof(PolynList));          // ����ͷ���㲢���г�ʼ��
    h->next = NULL;
    h->last = NULL;
    s = (PolynList*)malloc(sizeof(PolynList));          //�����ڵ��ռ�,���ڴ洢����
    ret = scanf("%d %d", &s->coef, &s->expn);           //�û��ɶ���������ʽ��ϵ����ָ��,ret����scanf()�������سɹ���������Ŀ�ĸ���
                                                            //����û��ȡ�κ���Ŀ(��������һ�����ֶ���ȴ�����������ַ���ʱ������),scanf()�᷵��ֵ0
                                                            //���Ե���ȡ������int���͵�����ʱ,ret=2,����Ϊ0
    s->next = NULL;                                     //��s��ʼ��
    s->last = h;
    h->next = s;
    while (ret == 2)                                    //���û��ɹ�����ʱ,ѭ��
    {
        p = h;
        tab = 0;                                        //tab��ǩ���ڼ�¼�Ƿ񽫽ڵ������ڶ���ʽ������(0��ʾ��δ����,1��ʾ�Ѳ���)
        s = (PolynList*)malloc(sizeof(PolynList));      //�����ڵ��ռ�
        ret = scanf("%d %d", &s->coef, &s->expn);       //�û�����ϵ����ָ��,ͬʱ���سɹ���ȡ����Ŀ�ĸ���
        while (p->next != NULL && tab == 0 && ret == 2) //��ָ��pָ������һ���ڵ㲻Ϊ��,�û��ɹ����벢�Ҵ�ʱ�ڵ�s��δ����ʱ,ѭ��
        {
            if (s->expn > p->next->expn)                //����ǰ�ڵ���ָ������pָ������һ���ڵ���ָ��ʱ,���ڵ�s���뵽�ڵ���һ���ڵ���ǰ��
            {
                s->last = p;
                s->next = p->next;
                p->next->last = s;
                p->next = s;
                tab = 1;                                //�Ѳ���,���Ǳ�ǩ״̬Ϊ1
            }
            else if (s->expn == p->next->expn)          //����ǰ�ڵ���ָ������pָ������һ���ڵ���ָ��ʱ,ָ������,ϵ���ӵ�ԭ���Ľڵ���
            {
                p->next->coef += s->coef;
                tab = 1;                                //�Ѳ���,���Ǳ�ǩ״̬Ϊ1
            }
            p = p->next;                                //ָ��pָ����һ���ڵ�
        }
        if (tab == 0 && ret == 2)                       //��tab=0,˵���û��������Ľڵ㻹δ��������ʽ��,����ʱ�����Ľڵ���ָ��С�ڵ�ǰ����ʽ����Сָ��,ͬʱ�û��ɹ���������
        {
            s->next = NULL;
            s->last = p;
            p->next = s;                                //���ڵ�s���뵽����ʽ��ĩβ��
        }
    }
    return h;                                           //�����������Ķ���ʽ������ͷ�ڵ�
}

/*������������ʽ����*/
void PolynPrint(PolynList *L)
{
    PolynList *p = L->next;                             //����ָ��ָ������ʽ�����ĵ�һ���ڵ�
    while (p)                                           //����ǰ�ڵ㲻Ϊ��ʱ,ѭ��
    {
        if (p -> coef != 0)                             //��ϵ����Ϊ0
        {
            if (p->coef == 1)                               //��ϵ������1
            {
                if (p->expn != 0)                               //��ָ��������0
                {
                    if (p->expn == 1)                               //��ָ������1,��ϵ��Ϊ1,ָ��Ϊ1,��ʽ������"X"
                        printf("X");
                    else printf("X^%d", p->expn);                   //����ָ����Ϊ1,��ϵ������1,ָ����0��1,��ʽ������"X^%d"
                }
                else printf("1");                               //����ָ������0,��ϵ��Ϊ1,ָ��Ϊ0,��ʽ������"1"
            }
            else if(p->coef ==-1)                           //��ϵ������-1
            {
                if (p->expn != 0)                               //��ָ����Ϊ0
                {
                    if (p->expn == 1)                               //��ָ��Ϊ1,��ϵ��Ϊ-1,ָ��Ϊ1,��ʽ������"-X"
                        printf("-X");
                    else printf("-X^%d", p->expn);                  //����ָ����Ϊ1,��ϵ��Ϊ-1,ָ�������Ǹ�һ,��ʽ������"-X^%d"
                }
                else printf("-1");                              //����ָ��Ϊ0,��ϵ��Ϊ-1,ָ��Ϊ0,��ʽ������"-1"

            }
            else                                            //����ϵ��Ϊ��0��-1
            {
                if (p->expn != 0)                               //��ָ����0
                {
                    if (p->expn == 1)                               //��ָ��Ϊ1,��ϵ��Ϊ�����Ǹ�һ,ָ��Ϊ1,��ʽ������"%dX"
                        printf("%dX", p->coef);
                    else printf("%dX^%d", p->coef, p->expn);        //����ָ��Ϊ��0��1,��ϵ��Ϊ��0��-1,ָ��Ϊ��0��1,��ʽ������"%dX^%d"
                }
                else printf("%d", p->coef);                     //����ָ��Ϊ0,��ʽ������"%d"
            }
        }
        else printf("0");                               //����ϵ��Ϊ0,��ʽ������"0"
        if (p->next && p->next->coef >= 0)              //����һ�Ϊ������һ����ϵ�����ڵ���0
            printf("+");                                    //����"+"������һ���������û�С�+��
        p = p->next;
    }
    printf("\n");
}

/*���ڶ���ʽ�ĺϲ�,������ʽ�ļ�/������*/
PolynList *MergeList(PolynList *La, char tab, PolynList *Lb)        //tab���ڱ��������е�����
{
    PolynList *pa = NULL, *pb = NULL, *pc = NULL, *Lc = NULL, *s = NULL, *p=NULL;
    pa = La;                                                        //ָ������ʽ����A��ͷָ��
    pb = Lb;                                                        //ָ������ʽ����B��ͷָ��
    Lc = (PolynList*)malloc(sizeof(PolynList));                     //Ϊ�ϲ����Ķ���ʽ��ͷ���������ռ�
    Lc->next = NULL;
    Lc->last = NULL;                                                //���г�ʼ��
    pc = Lc;                                                        //����ָ��ָ��ͷ�ڵ�Lc
    while (pa->next && pb->next)                                    //����A������B�Ľڵ㶼��Ϊ��ʱ
    {
        s = (PolynList*)malloc(sizeof(PolynList));                  //�����ڵ�,�����ռ�
        if (pa->next->expn < pb->next->expn)                        //������A�Ľڵ���ָ��<����B�Ľڵ���ָ��
        {
            if (tab == '-')                                         //��A-B ��ȡ�ڵ�pb��ϵ�����෴��,�洢���µĽڵ���
                s->coef = -pb->next->coef;
            else
                s->coef = pb->next->coef;                           //��A+B,��ȡ�ڵ�pb��ϵ��.�洢���µĽڵ���
            s->expn = pb->next->expn;                               //�洢pb�ڵ���ָ��
            s->last = pc;
            s->next = NULL;
            pc->next = s;                                           //pcָ����ָ�����Ľ���
            pc = pc->next;                                          //pcָ����һ���ڵ�,��s
            pb = pb->next;                                          //����Bָ���ý�����ָ��pb����
        }
        else if (pa->next->expn > pb->next->expn )                  //������A�Ľڵ���ָ��>����B�Ľڵ���ָ��
        {
            s->coef = pa->next->coef;                               //��ȡ�ڵ�pb��ϵ����ָ��.�洢���µĽڵ���
            s->expn = pa->next->expn;
            s->last = pc;
            s->next = NULL;
            pc->next = s;                                           //pcָ����ָ�����Ľ���
            pc = pc->next;
            pa = pa->next;                                          //����Aָ���ý�����ָ��pa����
        }
        else                                                        //��������A�Ľڵ���ָ��=����B�Ľڵ���ָ��
        {
            if (tab == '-')
                s->coef = pa->next->coef - pb->next->coef;          //A-Bʱָ������ʱ��ϵ������
            else
                s->coef = pa->next->coef + pb->next->coef;          //A+Bʱָ������ʱ��ϵ������
            if (s->coef==0)                                         //���ϲ����Ķ���ʽϵ��Ϊ0ʱ,��ָ����ʼΪ0,����֮���Ĵ���
                s->expn=0;
            else                                                    //�����ϲ����Ķ���ʽ��ָ����Ϊpa��ָ��
                s->expn = pa->next->expn;
            s->last = pc;
            s->next = NULL;
            pc->next = s;
            pc = pc->next;
            pa = pa->next;                                          //��ָ�붼������
            pb = pb->next;
        }
    }
    if(pa->next)                                                    //��pa��δΪ��ʱ,������Aʣ���Ľڵ㶼�洢���ϲ����Ķ���ʽ��
    {
        while(pa->next)
        {
            s = (PolynList*)malloc(sizeof(PolynList));
            s->coef = pa->next->coef;
            s->expn = pa->next->expn;
            s->last = pc;
            s->next = NULL;
            pc->next = s;
            pc = pc->next;
            pa = pa->next;                                          //ָ���ý�����ָ������
        }
    }
    if(pb->next)                                                    //��pb��δΪ��ʱ,������Bʣ���Ľڵ㶼�洢���ϲ����Ķ���ʽ��
    {
        while(pb->next)
        {
            s = (PolynList*)malloc(sizeof(PolynList));
            if (tab == '-')
                s->coef = -pb->next->coef;
            else
                s->coef = pb->next->coef;
            s->expn = pb->next->expn;
            s->last = pc;
            pc->next = s;
            s->next = NULL;
            pc = pc->next;
            pb = pb->next;                                          //ָ���ý�����ָ������
        }
    }
    pc=Lc;                                                          //pcָ���ϲ����Ķ���ʽ������ͷ�ڵ�
    while(pc->next!=NULL)                                           //��ʱ�Ժϲ����Ķ���ʽ���м���,���Ƿ�����ͬ����,���������кϲ�
    {
        p=pc->next;
        while(p&&p->next)
        {
            if (p->next->expn == pc->next->expn)
            {
                p->next->coef += pc->next->coef;                    //ָ������ʱ��ϵ������
                pc->next=p->next;                                   //�����ڵ�
                p=p->next;
                p->last=pc;
            }
            p=p->next;
        }
        pc=pc->next;
    }
    return Lc;                                                      //���غϲ����Ķ���ʽ������ͷ�ڵ�
}
/*������*/
int main()
{
    PolynList *ha = NULL, *hb = NULL, *hc1 = NULL, *hc2 = NULL;
    printf("[ע:�ó���������һԪ����ʽ�ļ�/��������,"
           "�ɶ�����ʱÿһ����ϵ����ָ����Ϊint����,"
           "��������ʽ������ʱ��������int���͵��ַ�,��'Q'.]\n\n");

    printf("����������ʽA(x): ");
    ha = CreatePolyn(ha);                                           //��������ʽ����A
    getchar();
    printf("����������ʽB(x): ");
    hb = CreatePolyn(hb);                                           //��������ʽ����B
    printf("\n");

    printf("����ʽA(x)=");
    PolynPrint(ha);                                                 //��ʽ����������ʽ����A
    printf("����ʽB(x)=");
    PolynPrint(hb);                                                 //��ʽ����������ʽ����B
    printf("\n");

    printf("A(x)+B(x)=");
    hc1 = MergeList(ha, '+', hb);                                   //����A+B����
    PolynPrint(hc1);                                                //��ʽ������
    printf("A(x)-B(x)=");
    hc2 = MergeList(ha, '-', hb);                                   //����A-B����
    PolynPrint(hc2);                                                //��ʽ������
    return 0;
}
