/**
 *lesson:  数据结构课程设计
 *tittle:  题目5:一元多项式的减法
 *author:  ThyChan
 *watch:   该程序仅限于一元多项式的加/减法计算,成对输入时每一项的系数及指数都为int类型,结束多项式的输入时请输入非int类型的字符,如'Q'.
**/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*双链表的声明*/
typedef struct PolynList
{
    int coef;                           // 系数
    int expn;                           // 指数
    struct PolynList *last;             //指向上一个节点的指针链表
    struct PolynList *next;             //指向下一个节点的指针链表
} PolynList;


/*用于创建多项式链表*/
PolynList *CreatePolyn(PolynList *h)
{
    PolynList *p = NULL, *s = NULL;
    int tab = 0, ret = 0;
    h = (PolynList*)malloc(sizeof(PolynList));          // 生成头结点并进行初始化
    h->next = NULL;
    h->last = NULL;
    s = (PolynList*)malloc(sizeof(PolynList));          //分配节点空间,用于存储数据
    ret = scanf("%d %d", &s->coef, &s->expn);           //用户成对输入多项式的系数和指数,ret接受scanf()函数返回成功读入的项目的个数
                                                            //若它没读取任何项目(如它期望一个数字而而却键入非数字字符串时的情况),scanf()会返回值0
                                                            //所以当读取到两个int类型的数字时,ret=2,否则为0
    s->next = NULL;                                     //对s初始化
    s->last = h;
    h->next = s;
    while (ret == 2)                                    //当用户成功输入时,循环
    {
        p = h;
        tab = 0;                                        //tab标签用于记录是否将节点插入于多项式链表中(0表示还未插入,1表示已插入)
        s = (PolynList*)malloc(sizeof(PolynList));      //分配节点空间
        ret = scanf("%d %d", &s->coef, &s->expn);       //用户输入系数和指数,同时返回成功读取的项目的个数
        while (p->next != NULL && tab == 0 && ret == 2) //当指针p指向的下一个节点不为空,用户成功输入并且此时节点s还未插入时,循环
        {
            if (s->expn > p->next->expn)                //若当前节点的指数大于p指向的下一个节点的指数时,将节点s插入到节点下一个节点的前面
            {
                s->last = p;
                s->next = p->next;
                p->next->last = s;
                p->next = s;
                tab = 1;                                //已插入,标记标签状态为1
            }
            else if (s->expn == p->next->expn)          //若当前节点的指数等于p指向的下一个节点的指数时,指数不变,系数加到原来的节点上
            {
                p->next->coef += s->coef;
                tab = 1;                                //已插入,标记标签状态为1
            }
            p = p->next;                                //指针p指向下一个节点
        }
        if (tab == 0 && ret == 2)                       //若tab=0,说明用户所输入的节点还未插入多项式中,即此时输入的节点的指数小于当前多项式的最小指数,同时用户成功输入数据
        {
            s->next = NULL;
            s->last = p;
            p->next = s;                                //将节点s插入到多项式的末尾处
        }
    }
    return h;                                           //返回所创建的多项式链表的头节点
}

/*用于输出多项式链表*/
void PolynPrint(PolynList *L)
{
    PolynList *p = L->next;                             //链表指针指向多项式链表的第一个节点
    while (p)                                           //若当前节点不为空时,循环
    {
        if (p -> coef != 0)                             //若系数不为0
        {
            if (p->coef == 1)                               //若系数等于1
            {
                if (p->expn != 0)                               //若指数不等于0
                {
                    if (p->expn == 1)                               //若指数等于1,即系数为1,指数为1,格式化输出"X"
                        printf("X");
                    else printf("X^%d", p->expn);                   //否则指数不为1,即系数等于1,指数非0非1,格式化输出"X^%d"
                }
                else printf("1");                               //否则指数等于0,即系数为1,指数为0,格式化输出"1"
            }
            else if(p->coef ==-1)                           //若系数等于-1
            {
                if (p->expn != 0)                               //若指数不为0
                {
                    if (p->expn == 1)                               //若指数为1,即系数为-1,指数为1,格式化输出"-X"
                        printf("-X");
                    else printf("-X^%d", p->expn);                  //否则指数不为1,即系数为-1,指数非零非负一,格式化输出"-X^%d"
                }
                else printf("-1");                              //否则指数为0,即系数为-1,指数为0,格式化输出"-1"

            }
            else                                            //否则系数为非0非-1
            {
                if (p->expn != 0)                               //若指数非0
                {
                    if (p->expn == 1)                               //若指数为1,即系数为非零非负一,指数为1,格式化输出"%dX"
                        printf("%dX", p->coef);
                    else printf("%dX^%d", p->coef, p->expn);        //否则指数为非0非1,即系数为非0非-1,指数为非0非1,格式化输出"%dX^%d"
                }
                else printf("%d", p->coef);                     //否则指数为0,格式化输出"%d"
            }
        }
        else printf("0");                               //否则系数为0,格式化输出"0"
        if (p->next && p->next->coef >= 0)              //若下一项不为空且下一项的系数大于等于0
            printf("+");                                    //输出"+"，最后一项及负数后面没有“+”
        p = p->next;
    }
    printf("\n");
}

/*用于多项式的合并,即多项式的加/减运算*/
PolynList *MergeList(PolynList *La, char tab, PolynList *Lb)        //tab用于标记所进行的运算
{
    PolynList *pa = NULL, *pb = NULL, *pc = NULL, *Lc = NULL, *s = NULL, *p=NULL;
    pa = La;                                                        //指向多项式链表A的头指针
    pb = Lb;                                                        //指向多项式链表B的头指针
    Lc = (PolynList*)malloc(sizeof(PolynList));                     //为合并后的多项式的头结点分配空间
    Lc->next = NULL;
    Lc->last = NULL;                                                //进行初始化
    pc = Lc;                                                        //链表指针指向头节点Lc
    while (pa->next && pb->next)                                    //链表A及链表B的节点都不为空时
    {
        s = (PolynList*)malloc(sizeof(PolynList));                  //创建节点,分配空间
        if (pa->next->expn < pb->next->expn)                        //若链表A的节点的指数<链表B的节点的指数
        {
            if (tab == '-')                                         //若A-B 则取节点pb的系数的相反数,存储在新的节点中
                s->coef = -pb->next->coef;
            else
                s->coef = pb->next->coef;                           //若A+B,则取节点pb的系数.存储在新的节点中
            s->expn = pb->next->expn;                               //存储pb节点的指数
            s->last = pc;
            s->next = NULL;
            pc->next = s;                                           //pc指针连指数大的结点
            pc = pc->next;                                          //pc指向下一个节点,即s
            pb = pb->next;                                          //链表B指向该结点的指针pb后移
        }
        else if (pa->next->expn > pb->next->expn )                  //若链表A的节点的指数>链表B的节点的指数
        {
            s->coef = pa->next->coef;                               //则取节点pb的系数和指数.存储在新的节点中
            s->expn = pa->next->expn;
            s->last = pc;
            s->next = NULL;
            pc->next = s;                                           //pc指针连指数大的结点
            pc = pc->next;
            pa = pa->next;                                          //链表A指向该结点的指针pa后移
        }
        else                                                        //否则链表A的节点的指数=链表B的节点的指数
        {
            if (tab == '-')
                s->coef = pa->next->coef - pb->next->coef;          //A-B时指数相等时，系数相减
            else
                s->coef = pa->next->coef + pb->next->coef;          //A+B时指数相等时，系数相加
            if (s->coef==0)                                         //当合并后的多项式系数为0时,将指数初始为0,便于之后的处理
                s->expn=0;
            else                                                    //否则合并后的多项式的指数设为pa的指数
                s->expn = pa->next->expn;
            s->last = pc;
            s->next = NULL;
            pc->next = s;
            pc = pc->next;
            pa = pa->next;                                          //两指针都往后移
            pb = pb->next;
        }
    }
    if(pa->next)                                                    //若pa还未为空时,将链表A剩余的节点都存储到合并后的多项式中
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
            pa = pa->next;                                          //指向该结点的指针后移
        }
    }
    if(pb->next)                                                    //若pb还未为空时,将链表B剩余的节点都存储到合并后的多项式中
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
            pb = pb->next;                                          //指向该结点的指针后移
        }
    }
    pc=Lc;                                                          //pc指向合并后的多项式链表的头节点
    while(pc->next!=NULL)                                           //此时对合并后的多项式进行检查,看是否存在同类项,存在则进行合并
    {
        p=pc->next;
        while(p&&p->next)
        {
            if (p->next->expn == pc->next->expn)
            {
                p->next->coef += pc->next->coef;                    //指数相等时，系数相加
                pc->next=p->next;                                   //跳过节点
                p=p->next;
                p->last=pc;
            }
            p=p->next;
        }
        pc=pc->next;
    }
    return Lc;                                                      //返回合并后的多项式链表的头节点
}
/*主函数*/
int main()
{
    PolynList *ha = NULL, *hb = NULL, *hc1 = NULL, *hc2 = NULL;
    printf("[注:该程序仅限于一元多项式的加/减法计算,"
           "成对输入时每一项的系数及指数都为int类型,"
           "结束多项式的输入时请输入非int类型的字符,如'Q'.]\n\n");

    printf("请输入多项式A(x): ");
    ha = CreatePolyn(ha);                                           //创建多项式链表A
    getchar();
    printf("请输入多项式B(x): ");
    hb = CreatePolyn(hb);                                           //创建多项式链表B
    printf("\n");

    printf("多项式A(x)=");
    PolynPrint(ha);                                                 //格式化输出多项式链表A
    printf("多项式B(x)=");
    PolynPrint(hb);                                                 //格式化输出多项式链表B
    printf("\n");

    printf("A(x)+B(x)=");
    hc1 = MergeList(ha, '+', hb);                                   //进行A+B运算
    PolynPrint(hc1);                                                //格式化输出
    printf("A(x)-B(x)=");
    hc2 = MergeList(ha, '-', hb);                                   //进行A-B运算
    PolynPrint(hc2);                                                //格式化输出
    return 0;
}
