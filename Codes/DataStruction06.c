/**
 *lesson:  数据结构课程设计
 *tittle:  题目6:床位分配
 *author:  ThyChan
**/
#include  <stdio.h>
#include  <stdlib.h>
#include  <malloc.h>

/*定义一个房间的结构体*/
typedef struct Room
{
  int room_level;                                   //房间等级
  int room_num;                                     //房间号
  int bed_num;                                      //床位号
  int bsum;                                          //一个房间的床数
  int persion_num;                                  //人数
  char name[20];                                    //姓名
  int age;                                          //年龄
  int bed[10];                                       //是否空床
  int sex;                                          //性别
  int date;                                         //到达日期
  struct Room *next;
}Room;
/*初始化*/
void init(int *roomlevel, int *room, int *bed)
{
  int i;
  printf("系统初始化中...\n");
  printf("请输入房间的等级数：");
  scanf("%d",roomlevel);
  for(i=1;i<=*roomlevel;i++)                        //通过循环依次设置不同等级的房间数和床位数
  {
    printf("\n%d等级的房间数：",i);
    scanf("%d",&room[i]);
    printf("该等级内房间的床位数：");
    scanf("%d",&bed[i]);
  }
}

/*创建链表*/
Room *creat(int room_level,int room[],int bed[])
{
  Room *head=NULL,*p=NULL,*s=NULL;
  int i,j,k,num=1;
  head=(Room *)malloc(sizeof(Room));                //建立头节点
  head->persion_num=0;
  p=head;
  for(i=1;i<=room_level;i++)                        //初始化每个等级的房间数据
  {
    for(j=1;j<=room[i];j++)                         //初始化每个房间的数据
    {
      s=(Room *)malloc(sizeof(Room));               //分配存储空间
      s->room_level=i;                              //设置当前房间的等级
      s->room_num=num++;                            //设置房间号
      s->persion_num=0;                             //设置该房间为空
      s->sex=-1;                                    //没人
      s->bsum=bed[i];
      s->date=0;
      for(k=0;k<bed[i];k++)                         //通过循环设置每张床都为空
        s->bed[k]=0;
      p->next=s;                                    //连接节点
      p=s;                                          //p指向当前节点
    }
  }
  p->next=NULL;                                     //将最后一个节点的下一个设为空
  return head;                                      //返回链表的头节点
}
/*入住*/
void checkin(Room *head)
{
  Room *p=NULL;
  int i,sex,lev,bednumber=0,roomnumber=0,date;
  printf("\n\n欢迎使用订房系统\n");
  printf("请输入客户性别（1.男  0.女)：");
  scanf("%d",&sex);
  printf("请输入想入住的房间等级：");
  scanf("%d",&lev);
  printf("请输入到达日期(例如:20160522):");
  scanf("%d",&date);
  getchar();                                                    //用于吸收多余的回车
  p=head->next;
  while(p!=NULL)
  {
    if((lev==p->room_level)&&((sex==p->sex)||(p->sex==-1)))     //判断是否客满或者住宿性别条件是否满足
    {
      for(i=0;i<p->bsum;i++)
        if(p->bed[i]==0)                                        //判断是否有空的床位
        {
          roomnumber=p->room_num;                               //提取房间号
          bednumber=i+1;
          p->bed[i]=1;                                          //将该床位设置为有人
          p->sex=sex;                                           //设置性别
          p->date=date;
          p->persion_num++;                                     //计算该房间的人数
          break;
        }
        if(roomnumber!=0)                                       //判断是否入住成功,成功则跳出循环
          break;
    }
    p=p->next;
  }
  if(roomnumber==0&&bednumber==0)                               //若房间号和床位号都为0,表示都未分配
    printf("当前客已满！！\n");
  else                                                          //输出客户预定信息
  {
    head->persion_num++;
    p->bed_num=bednumber;
    printf("\n预定成功，请输入客户信息：\n");
    printf("姓名：");
    scanf("%s",p->name);
    printf("年龄：");
    scanf("%d",&p->age);
    printf("订单：\n");
    printf("姓名    年龄    性别    到达日期    房间等级    房间号   床位号   \n");
    if(p->sex==1)
      printf("%s\t%d\t男\t%d\t%d\t%d\t%d\n",p->name,p->age,p->date,p->room_level,p->room_num,p->bed_num);
    else
      printf("%s\t%d\t女\t%d\t%d\t%d\t%d\n",p->name,p->age,p->date,p->room_level,p->room_num,p->bed_num);
  }
}
/*退房*/
void checkout(Room *head)
{
  Room *p;
  int number,bednumber,i,sex,tab=1;
  char name[20];
  printf("\n\n退房\n");
  if(head->persion_num==0)                                     //若总人数为0,表示所有房间都为空房
  {
    printf("所有房间都为空房！,不需要退房\n");
    return;
  }
  p=head->next;
  printf("请输入房间号：");
  scanf("%d",&number);
  getchar();                                                    //用于吸收多余的回车
  printf("请输入姓名: ");
  scanf("%s",name);
  printf("请输入性别(1.男   0.女）：");
  scanf("%d",&sex);
  printf("请输入床位号：");
  scanf("%d",&bednumber);
  while(p!=NULL)
  {
    if((p->room_num==number)&&(*p->name==*name)&&(p->sex==sex))                           //核对客户信息
      for(i=0;i<p->room_level;i++)
        if(i+1==bednumber)                                      //初始化信息
        {
          p->bed[i]=0;
          p->persion_num--;
          head->persion_num--;
          if(p->persion_num<0)
            p->persion_num=0;
          if(p->persion_num==0)
            p->sex=-1;
          printf("您已退房,欢迎下次光临！");
          tab=0;
          break;
        }
    p=p->next;
  }
    if(tab==1)
      printf("信息错误,退房失败!");

}
/*查询*/
void query(Room *head)
{
  Room *p;
  int i=0;
  p=head->next;
  printf("\n\n已订房间查询\n");
  if(head->persion_num==0)                                     //若总人数为0,表示所有房间都为空房
  {
    printf("所有房间都为空房！\n");
    return;
  }
  while(p!=NULL)
  {
    if(p->persion_num!=0)                                       //当该房间的人数不为0时
    {
      if(p->sex==1)
        printf("房间号：%d，房间等级：%d，已住人数：%d，住房人性别：男",p->room_num,p->room_level,p->persion_num);
      else
        printf("房间号：%d，房间等级：%d，已住人数：%d，住房人性别：女",p->room_num,p->room_level,p->persion_num);
      printf(",已住床位号:");
      for(i=0;(i<p->persion_num)&&(p->bed[i]==1);i++)
          printf("%d号  ",i+1);
      printf("\n\n");
    }
    p=p->next;
  }

}
/*主函数*/
int main()
{
  Room *head;
  int roomlevel=0,room[10],bed[10],n;
  init(&roomlevel,room,bed);          //进行初始化
  system("cls");                      //清屏
  head=creat(roomlevel,room,bed);     //创建链表
  while(1)
  {

    printf("\n\n============================================="
           "\n#\t\t客房管理系统！              #\n"
           "=============================================\n");
    printf("1：订房\t2：退房\t3：查询\t4: 清屏\t0：退出\n\n");
    printf("操作:");
    scanf("%d",&n);
    switch(n)
    {
      case 1: checkin(head);break;
      case 2: checkout(head);;break;
      case 3: query(head);break;
      case 4: system("cls");break;
      case 0: exit(0);
      default:  printf("Error! 请重新输入!\n");break;
    }
  }
}
