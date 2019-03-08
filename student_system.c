#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char name[20]={"d://student.txt"};
typedef struct student Stu;
struct student
{
    char stu_no[20];
    char stu_name[20];
    char stu_sex;
    double stu_score[5];
    double stu_ave;
    double stu_sum;
    int rank;
    Stu *next;
};
void jiemian()
{
   printf("__________________________________________________________________\n\
*                                                                *\n\
*                        学生学籍信息管理系统                    *\n\
*功能区：1、新建学生文件           |                             *\n\
*        2、增加学生信息           |                             *\n\
*        3、显示学生信息           |                             *\n\
*        4、查询学生信息           | 注意事项：                  *\n\
*        5、删除学生信息           |    1、此系统只能统计5门成绩 *\n\
*        6、对学生信息进行排序     |    2、n代表男生，v代表女生  *\n\
*        7、保存至文件中           |                             *\n\
*        8、从记录中读取文件       |                             *\n\
*        9、修改学生信息           |                             *\n\
*        10、退出学生信息管理系统  |                             *\n\
__________________________________________________________________\n");

}
void outPut(Stu *p)
{
        int i;
        printf("%s ",p->stu_no);
        printf("%s    ",p->stu_name);
        printf("%c   ",p->stu_sex);
        for(i=0;i<5;i++)
        printf("%.2lf ",p->stu_score[i]);
        printf("%.2lf    ",p->stu_ave);
        printf("%.2lf  ",p->stu_sum);
        printf("%d\n",p->rank);
}
void shuchu(Stu *head)
{
    Stu *p=head;
    printf("学号       姓名 性别  成绩1  成绩2  成绩3  成绩4  成绩5  个人平均分  总分  名次\n");
    while(p!=0)
    {
        outPut(p);
        p=p->next;
    }
}
void inPut(Stu *p)
{
    int i;
    double sum=0;
    printf("输入学生的学号\n");
    getchar();
   scanf("%s",p->stu_no);
   printf("输入学生的姓名\n");
   getchar();
   scanf("%s",p->stu_name);
   printf("输入学生的性别\n");
   getchar();
   scanf("%c",&p->stu_sex);
   printf("输入学生的五门成绩\n");
   getchar();
   for(i=0;i<5;i++)
   {
       scanf("%lf",&p->stu_score[i]);
       sum+=p->stu_score[i];
   }
   p->stu_sum=sum;
   p->stu_ave=sum/5;
}
Stu *creat()
{
    int i=1;
    char n='y';
    Stu *head,*tail,*p;
    head=0;
    printf("输入学生信息\n");
     do{
        printf("输入第%d个学生的信息\n",i);
        p=(Stu *)malloc(sizeof(Stu));
        p->next=0;
        inPut(p);
        p->rank=i;
        if(head==0)
            head=p;
        else
            tail->next=p;
        tail=p;
        i++;
        printf("如果继续输入请输入y，否则输入N\n");
        getchar();
        n=getchar();
    }while(n=='y'||n=='Y');
    printf("输入结束\n");
    return head;
}
void nob(Stu *head)//按学号排序
{

    Stu *q,*p;
    Stu *temp,t;
    p=head;
    int i;
    while(p!=0)
    {
        temp=p;
        for(q=p->next;q!=0;q=q->next)
            if(strcmp(temp->stu_no,q->stu_no)>0)
               temp=q;
         strcpy(t.stu_no,p->stu_no);
         strcpy(p->stu_no,temp->stu_no);
         strcpy(temp->stu_no,t.stu_no);
         strcpy(t.stu_name,p->stu_name);
         strcpy(p->stu_name,temp->stu_name);
         strcpy(temp->stu_name,t.stu_name);
         t.stu_sex=p->stu_sex;
         p->stu_sex=temp->stu_sex;
         temp->stu_sex=t.stu_sex;
         for(i=0;i<5;i++)
         {
             t.stu_score[i]=p->stu_score[i];
             p->stu_score[i]=temp->stu_score[i];
             temp->stu_score[i]=t.stu_score[i];
         }
             t.stu_ave=p->stu_ave;
             p->stu_ave=temp->stu_ave;
             temp->stu_ave=t.stu_ave;
             t.stu_sum=p->stu_sum;
             p->stu_sum=temp->stu_sum;
             temp->stu_sum=t.stu_sum;
            t.rank=p->rank;
             p->rank=temp->rank;
             temp->rank=t.rank;
              p=p->next;
    }
}
void sortdown(Stu *head)//按照总成绩降序排名
{
    Stu *q,*p;
    Stu *temp,t;
    p=head;
    int i,k=1;
    while(p!=0)
    {
        temp=p;p->rank=k;
        for(q=p->next;q!=0;q=q->next)
            if(temp->stu_sum<q->stu_sum)
               temp=q;
         strcpy(t.stu_no,p->stu_no);
         strcpy(p->stu_no,temp->stu_no);
         strcpy(temp->stu_no,t.stu_no);
         strcpy(t.stu_name,p->stu_name);
         strcpy(p->stu_name,temp->stu_name);
         strcpy(temp->stu_name,t.stu_name);
         t.stu_sex=p->stu_sex;
         p->stu_sex=temp->stu_sex;
         temp->stu_sex=t.stu_sex;
         for(i=0;i<5;i++)
         {
             t.stu_score[i]=p->stu_score[i];
             p->stu_score[i]=temp->stu_score[i];
             temp->stu_score[i]=t.stu_score[i];
         }
             t.stu_ave=p->stu_ave;
             p->stu_ave=temp->stu_ave;
             temp->stu_ave=t.stu_ave;
             t.stu_sum=p->stu_sum;
             p->stu_sum=temp->stu_sum;
             temp->stu_sum=t.stu_sum;
             p=p->next;
             k++;
    }
}
void sortup(Stu *head)//按照总成绩升序排排名
{
    Stu *q,*p;
    Stu *temp,t;
    p=head;
    int i;
    while(p!=0)
    {
        temp=p;;
        for(q=p->next;q!=0;q=q->next)
            if(temp->stu_sum>q->stu_sum)
               temp=q;
         strcpy(t.stu_no,p->stu_no);
         strcpy(p->stu_no,temp->stu_no);
         strcpy(temp->stu_no,t.stu_no);
         strcpy(t.stu_name,p->stu_name);
         strcpy(p->stu_name,temp->stu_name);
         strcpy(temp->stu_name,t.stu_name);
         t.stu_sex=p->stu_sex;
         p->stu_sex=temp->stu_sex;
         temp->stu_sex=t.stu_sex;
         for(i=0;i<5;i++)
         {
             t.stu_score[i]=p->stu_score[i];
             p->stu_score[i]=temp->stu_score[i];
             temp->stu_score[i]=t.stu_score[i];
         }
             t.stu_ave=p->stu_ave;
             p->stu_ave=temp->stu_ave;
             temp->stu_ave=t.stu_ave;
             t.stu_sum=p->stu_sum;
             p->stu_sum=temp->stu_sum;
             temp->stu_sum=t.stu_sum;
             t.rank=p->rank;
             p->rank=temp->rank;
             temp->rank=t.rank;
             p=p->next;
    }
}
Stu *search(Stu *head)
{
    int n,srank;
    Stu *p=head;
    char souxun[20];
   printf("请输入查询学生的信息的方式\n");
   printf("输入1，代表通过学号查询\n");
   printf("输入2，代表通过姓名查询\n");
   printf("输入3，代表通过名次查询\n");
   scanf("%d",&n);
   do
   {
       if(n!=1&&n!=2&&n!=3)
      {
          printf("输入错误，重新输入指令数字\n");
          scanf("%d",&n);
      }
       if(n==1)
      {
       printf("输入查询人的学号\n");
       scanf("%s",souxun);
      }
       if(n==2)
      {
       printf("输入查询人的姓名\n");
       scanf("%s",souxun);
      }
      if(n==3)
      {
       printf("输入查询人名次\n");
       scanf("%d",&srank);
      }
    }while(n<1||n>3);
    while(p!=0)
    {
       if(n==1&&strcmp(p->stu_no,souxun)==0)
       return p;
       else if(n==2&&strcmp(p->stu_name,souxun)==0)
       return p;
       else if(n==3&&p->rank==srank)
       return p;
       p=p->next;
   }
   return 0;
}
Stu *shangchu1(Stu *head,Stu *sx)
{
    Stu *p=head,*pre;
    while(p!=0)
    {
        if(p==sx)
        break;
        pre=p;
        p=p->next;
    }
        if(p==head)
            head=p->next;
        else
       pre->next=p->next;

        return head;
}
void shifang(Stu *head)
{
    Stu *p=head;
    while(p!=0)
    {
        free(p);
        p=p->next;
    }
}
void SAVE(Stu *head)
{
    Stu *p=head;
    FILE *fp;
    int i;
    fp=fopen("name","w+");
    if(fp==0)
    {
        printf("can't open file\n");
        exit(1);
    }
    nob(head);
    while(p!=0)
    {
        //替换fwrite(p,sizeof(Stu),1,fp);
        fprintf(fp,"%s %s %c ",p->stu_no,p->stu_name,p->stu_sex);
        for(i=0;i<5;i++)
        fprintf(fp,"%.2f ",p->stu_score[i]);
        fprintf(fp,"%.2f ",p->stu_ave);
        fprintf(fp,"%.2f ",p->stu_sum);
        fprintf(fp,"%d\n",p->rank);
        p=p->next;
    }
    fprintf(fp,"\n");
    fflush(fp);
    fclose(fp);
    printf("文件已经保存完毕。\n");
}
Stu * NWF()
{
    printf("您正在进行的是新建一个文件的操作\n");
   Stu *head;
   head=creat();
   sortdown(head);
   nob(head);
   printf("信息录入完成\n");
   SAVE(head);

   return head;
}
void CREASE(Stu *head)
{
    printf("您正在进行的是增加学生信息的操作\n");
    char n='y';
    Stu *p,*pre;
    pre=head->next;
   printf("如下输入增加人的信息\n");
  while(n=='y'||n=='Y')
      {
        p=(Stu *)malloc(sizeof(Stu));
        inPut(p);
        head->next=p;
        p->next=pre;
        sortdown(head);
        printf("如果你想继续增加请输入y，否则输入n\n");
        getchar();
        n=getchar();
      }
    printf("增加的操作结束，信息输入完毕\n");
}
void XIESHI(Stu *head)
{
    printf("显示的学生信息如下\n");
    Stu *p=head;
    printf("学号       姓名 性别  成绩1  成绩2  成绩3  成绩4  成绩5  个人平均分  总分  名次\n");
    while(p!=0)
    {
        outPut(p);
        p=p->next;
    }
}
void SEARCH(Stu *head)
{
    int x=1;
   printf("您正在进行的是查询学生信息的操作\n");
   Stu *sx;
   while(x==1)
   {
       sx=search(head);
       if(sx==0)
       {
           printf("未搜询到您所要查询的学生的信息\n");
       }
       else
       outPut(sx);
       printf("如想继续查询，请输入1，返回主界面请输入2\n");
       scanf("%d",&x);
   }
   printf("已返回主界面\n");
}
Stu *DELE(Stu *head)
{
    char d,e;
    printf("您正在进行的是删除学生信息的操作\n");

    do
    {
        printf("请输入删除学生的相关信息\n");
        Stu *sx;
        sx=search(head);
        if(sx==0)
      {
        printf("抱歉您要删除的学生信息不存在\n");
        printf("请问是否继续删除，若继续输入Y，否则输入n\n");
      }
       else
      {
        outPut(sx);
        printf("以上是您要删除的学生信息\n");
        printf("请您确认是否删除?确定删除请输入Y，否则输入N\n");
        getchar();
        d=getchar();
        if(d=='Y'||d=='y')
        {
            head=shangchu1(head,sx);
            sortdown(head);
            shuchu(head);
            printf("以上是删除后的所有信息,请问是否继续删除，若继续输入Y，否则输入n\n");
        }
        else
        printf("删除失败，请问是否继续删除，若继续输入Y，否则输入n\n");
      }

         getchar();
        e=getchar();
    }while(e=='Y'||e=='y');
    printf("删除操作结束，已返回主界面\n");
    return head;

}
void SORT(Stu *head)
{
    int sort;
    printf("您正在进行的是对学生信息排序的操作\n");
    printf("说明您想排序的条件\n");
    printf("输入1，按学号排序\n");
    printf("输入2，按总成绩降序排序\n");
    printf("输入3，按总成绩升序排序\n");
    scanf("%d",&sort);
    if(sort==1)
    {
        nob(head);
        printf("如下是信息按照学号排序\n");
    }
    else if(sort==2)
    {
        sortdown(head);
        printf("如下是信息按照总成绩降序排名\n");
    }
    else if(sort==3)
    {
        sortup(head);
        printf("如下是信息按照总成绩升序排排名\n");
    }
    shuchu(head);
}
Stu *READ()
{
    printf("您所读取的学生信息如下\n");
    Stu *p,*tail,*head=NULL;
    FILE *fp;
    int i;
    //char n;
    fp=fopen("name","r");
    if(fp==0)
    {
        printf("can't open the file\n");
        exit(1);
    }
    tail=head;
    //替换fread(head,sizeof(Stu),1,fp);
    //shuchu(head);
  do
  {

    p=(Stu *)malloc(sizeof(Stu));
    //fread(p,sizeof(Stu),1,fp);
    fscanf(fp,"%s%s",p->stu_no,p->stu_name);
    do
    {
        fscanf(fp,"%c",&p->stu_sex);
    }while(p->stu_sex==' ');
    for(i=0;i<5;i++)
    fscanf(fp,"%lf",&p->stu_score[i]);
    fscanf(fp,"%lf",&p->stu_ave);
    fscanf(fp,"%lf",&p->stu_sum);
    fscanf(fp,"%d",&p->rank);
        if(head==NULL)
    head=p;
    else
    tail->next=p;
        p->next=NULL;
        tail=p;
        if(p->rank==1)
        break;
        //shuchu(head);
  } while(1);
    shuchu(head);
    printf("文件读取完毕\n");
    return head;
}
void CHANGE(Stu *head)
{
    printf("您正在进行的是修改学生信息的操作\n");
    Stu *sx;
    char d='y';
    int flag;
 while(d=='y'||d=='Y')
  {     printf("请先查找要修改信息的学生\n");
        sx=search(head);
        if(sx==0)
            printf("抱歉，未找到该学生的信息，无法修改\n");
        else
        {
            outPut(sx);
            printf("如果想修改该学生的一条信息请输入1，如果想修改多条信息请输入2\n");
            scanf("%d",&flag);
            if(flag==2)
          {
            printf("请重新输入该学生的所有的信息\n");
            inPut(sx);
          }
          if(flag==1)
          { do

           {
            printf("输入1修改学生学号\n输入2修改学生姓名\n输入3修改学生性别\n输入4修改学生成绩1\n输入5修改学生成绩2\n输入6修改学生成绩3\n输入7修改学生成绩4\n输入8修改学生成绩5\n");
            scanf("%d",&flag);
            if(flag==1)
            {
                printf("输入更改后的学号\n");
                getchar();
                scanf("%s",sx->stu_no);
            }
            else if(flag==2)
            {
                printf("输入更改后的姓名\n");
                getchar();
                scanf("%s",sx->stu_name);
            }
            else if(flag==3)
            {
                printf("输入更改后的性别\n");
                getchar();
                scanf("%c",&sx->stu_sex);
            }
            else if(flag==4)
            {
                printf("输入更改后的成绩1\n");
                scanf("%lf",&sx->stu_score[0]);
            }
            else if(flag==5)
            {
                printf("输入更改后的成绩2\n");
                scanf("%lf",&sx->stu_score[1]);
            }
            else if(flag==6)
            {
                printf("输入更改后的成绩3\n");
                scanf("%lf",&sx->stu_score[2]);
            }
           else if(flag==7)
            {
                printf("输入更改后的成绩4\n");
                scanf("%lf",&sx->stu_score[3]);
            }
            else if(flag==8)
            {
                printf("输入更改后的成绩5\n");
                scanf("%lf",&sx->stu_score[4]);
            }
            else
            {
                printf("输入错误，请重新输入数字\n");
                scanf("%d",&flag);
            }
          }while(flag>8||flag<1);
          }
          printf("修改成功！\n");
        }
           printf("如想继续修改其他信息请输入y，否则输入n\n");
           getchar();
           d=getchar();
   }
        sortdown(head);
        shuchu(head);
        printf("已返回主界面\n");
}
int main()
{
   jiemian();
   int x;
   Stu *head;
   printf("您好有什么可以问您效劳吗？\n");
   printf("请输入相应的数字指令\n");
   while(scanf("%d",&x)!=-1)
   {
       system("cls");//清屏
       jiemian();
       if(x==1)
       {
           head=NWF();

       }
       else if(x==2)
       {
           CREASE(head);
       }
       else if(x==3)
       {
           XIESHI(head);

       }
       else if(x==4)
       {
           SEARCH(head);
       }
       else if(x==5)
       {
           head=DELE(head);
       }
       else if(x==6)
       {
           SORT(head);
       }
       else if(x==7)
       {
           SAVE(head);
       }
       else if(x==8)
       {
           head=READ();
       }
       else if(x==10)
       {
           shifang(head);
           printf("欢迎使用本系统,下次再来\n");
           exit(1);
       }
       else if(x==9)
       {
           CHANGE(head);
       }
       printf("请问还有什么需求吗？\n");
   }
    return 0;
}


