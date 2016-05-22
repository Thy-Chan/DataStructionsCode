/**
 *lesson:  ���ݽṹ�γ����
 *tittle:  ��Ŀ6:��λ����
 *author:  ThyChan
**/
#include  <stdio.h>
#include  <stdlib.h>
#include  <malloc.h>

/*����һ������Ľṹ��*/
typedef struct Room
{
  int room_level;                                   //����ȼ�
  int room_num;                                     //�����
  int bed_num;                                      //��λ��
  int bsum;                                          //һ������Ĵ���
  int persion_num;                                  //����
  char name[20];                                    //����
  int age;                                          //����
  int bed[10];                                       //�Ƿ�մ�
  int sex;                                          //�Ա�
  int date;                                         //��������
  struct Room *next;
}Room;
/*��ʼ��*/
void init(int *roomlevel, int *room, int *bed)
{
  int i;
  printf("ϵͳ��ʼ����...\n");
  printf("�����뷿��ĵȼ�����");
  scanf("%d",roomlevel);
  for(i=1;i<=*roomlevel;i++)                        //ͨ��ѭ���������ò�ͬ�ȼ��ķ������ʹ�λ��
  {
    printf("\n%d�ȼ��ķ�������",i);
    scanf("%d",&room[i]);
    printf("�õȼ��ڷ���Ĵ�λ����");
    scanf("%d",&bed[i]);
  }
}

/*��������*/
Room *creat(int room_level,int room[],int bed[])
{
  Room *head=NULL,*p=NULL,*s=NULL;
  int i,j,k,num=1;
  head=(Room *)malloc(sizeof(Room));                //����ͷ�ڵ�
  head->persion_num=0;
  p=head;
  for(i=1;i<=room_level;i++)                        //��ʼ��ÿ���ȼ��ķ�������
  {
    for(j=1;j<=room[i];j++)                         //��ʼ��ÿ�����������
    {
      s=(Room *)malloc(sizeof(Room));               //����洢�ռ�
      s->room_level=i;                              //���õ�ǰ����ĵȼ�
      s->room_num=num++;                            //���÷����
      s->persion_num=0;                             //���ø÷���Ϊ��
      s->sex=-1;                                    //û��
      s->bsum=bed[i];
      s->date=0;
      for(k=0;k<bed[i];k++)                         //ͨ��ѭ������ÿ�Ŵ���Ϊ��
        s->bed[k]=0;
      p->next=s;                                    //���ӽڵ�
      p=s;                                          //pָ��ǰ�ڵ�
    }
  }
  p->next=NULL;                                     //�����һ���ڵ����һ����Ϊ��
  return head;                                      //���������ͷ�ڵ�
}
/*��ס*/
void checkin(Room *head)
{
  Room *p=NULL;
  int i,sex,lev,bednumber=0,roomnumber=0,date;
  printf("\n\n��ӭʹ�ö���ϵͳ\n");
  printf("������ͻ��Ա�1.��  0.Ů)��");
  scanf("%d",&sex);
  printf("����������ס�ķ���ȼ���");
  scanf("%d",&lev);
  printf("�����뵽������(����:20160522):");
  scanf("%d",&date);
  getchar();                                                    //�������ն���Ļس�
  p=head->next;
  while(p!=NULL)
  {
    if((lev==p->room_level)&&((sex==p->sex)||(p->sex==-1)))     //�ж��Ƿ��������ס���Ա������Ƿ�����
    {
      for(i=0;i<p->bsum;i++)
        if(p->bed[i]==0)                                        //�ж��Ƿ��пյĴ�λ
        {
          roomnumber=p->room_num;                               //��ȡ�����
          bednumber=i+1;
          p->bed[i]=1;                                          //���ô�λ����Ϊ����
          p->sex=sex;                                           //�����Ա�
          p->date=date;
          p->persion_num++;                                     //����÷��������
          break;
        }
        if(roomnumber!=0)                                       //�ж��Ƿ���ס�ɹ�,�ɹ�������ѭ��
          break;
    }
    p=p->next;
  }
  if(roomnumber==0&&bednumber==0)                               //������źʹ�λ�Ŷ�Ϊ0,��ʾ��δ����
    printf("��ǰ����������\n");
  else                                                          //����ͻ�Ԥ����Ϣ
  {
    head->persion_num++;
    p->bed_num=bednumber;
    printf("\nԤ���ɹ���������ͻ���Ϣ��\n");
    printf("������");
    scanf("%s",p->name);
    printf("���䣺");
    scanf("%d",&p->age);
    printf("������\n");
    printf("����    ����    �Ա�    ��������    ����ȼ�    �����   ��λ��   \n");
    if(p->sex==1)
      printf("%s\t%d\t��\t%d\t%d\t%d\t%d\n",p->name,p->age,p->date,p->room_level,p->room_num,p->bed_num);
    else
      printf("%s\t%d\tŮ\t%d\t%d\t%d\t%d\n",p->name,p->age,p->date,p->room_level,p->room_num,p->bed_num);
  }
}
/*�˷�*/
void checkout(Room *head)
{
  Room *p;
  int number,bednumber,i,sex,tab=1;
  char name[20];
  printf("\n\n�˷�\n");
  if(head->persion_num==0)                                     //��������Ϊ0,��ʾ���з��䶼Ϊ�շ�
  {
    printf("���з��䶼Ϊ�շ���,����Ҫ�˷�\n");
    return;
  }
  p=head->next;
  printf("�����뷿��ţ�");
  scanf("%d",&number);
  getchar();                                                    //�������ն���Ļس�
  printf("����������: ");
  scanf("%s",name);
  printf("�������Ա�(1.��   0.Ů����");
  scanf("%d",&sex);
  printf("�����봲λ�ţ�");
  scanf("%d",&bednumber);
  while(p!=NULL)
  {
    if((p->room_num==number)&&(*p->name==*name)&&(p->sex==sex))                           //�˶Կͻ���Ϣ
      for(i=0;i<p->room_level;i++)
        if(i+1==bednumber)                                      //��ʼ����Ϣ
        {
          p->bed[i]=0;
          p->persion_num--;
          head->persion_num--;
          if(p->persion_num<0)
            p->persion_num=0;
          if(p->persion_num==0)
            p->sex=-1;
          printf("�����˷�,��ӭ�´ι��٣�");
          tab=0;
          break;
        }
    p=p->next;
  }
    if(tab==1)
      printf("��Ϣ����,�˷�ʧ��!");

}
/*��ѯ*/
void query(Room *head)
{
  Room *p;
  int i=0;
  p=head->next;
  printf("\n\n�Ѷ������ѯ\n");
  if(head->persion_num==0)                                     //��������Ϊ0,��ʾ���з��䶼Ϊ�շ�
  {
    printf("���з��䶼Ϊ�շ���\n");
    return;
  }
  while(p!=NULL)
  {
    if(p->persion_num!=0)                                       //���÷����������Ϊ0ʱ
    {
      if(p->sex==1)
        printf("����ţ�%d������ȼ���%d����ס������%d��ס�����Ա���",p->room_num,p->room_level,p->persion_num);
      else
        printf("����ţ�%d������ȼ���%d����ס������%d��ס�����Ա�Ů",p->room_num,p->room_level,p->persion_num);
      printf(",��ס��λ��:");
      for(i=0;(i<p->persion_num)&&(p->bed[i]==1);i++)
          printf("%d��  ",i+1);
      printf("\n\n");
    }
    p=p->next;
  }

}
/*������*/
int main()
{
  Room *head;
  int roomlevel=0,room[10],bed[10],n;
  init(&roomlevel,room,bed);          //���г�ʼ��
  system("cls");                      //����
  head=creat(roomlevel,room,bed);     //��������
  while(1)
  {

    printf("\n\n============================================="
           "\n#\t\t�ͷ�����ϵͳ��              #\n"
           "=============================================\n");
    printf("1������\t2���˷�\t3����ѯ\t4: ����\t0���˳�\n\n");
    printf("����:");
    scanf("%d",&n);
    switch(n)
    {
      case 1: checkin(head);break;
      case 2: checkout(head);;break;
      case 3: query(head);break;
      case 4: system("cls");break;
      case 0: exit(0);
      default:  printf("Error! ����������!\n");break;
    }
  }
}
