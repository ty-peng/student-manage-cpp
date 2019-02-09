#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define h1 "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
#define h2 "┃     学号     │   姓名   │ 宿舍楼 │ 寝室号 │    手机号码    ┃\n"
#define h3 "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"
#define fm "┃ %-12s │  %-8s│ %-6s │  %-4s  │  %-11s   ┃\n"
#define END "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
#define DATA p->data.xh,p->data.mz,p->data.ssl,p->data.qsh,p->data.sj

/*电话号码和寝室信息是否需要长度限制？需要可加*/

int saveflag=0;

typedef struct student
{
    char xh[20];
    char mz[20];
    char ssl[10];
    char qsh[6];
    char sj[20];
};

typedef struct node
{
    struct student data;
    struct node *next;
}Node,*Link;

void menu()
{
    system("cls");/*   DOS命令  清屏    */
    printf("                学生寝室信息基本管理系统\n\n");
    printf("     *********************菜单*********************\n");
    printf("     *      1.输入记录            2.删除记录      *\n");
    printf("     *      3.查找记录            4.修改记录      *\n");
    printf("     *      5.插入记录            6.存储记录      *\n");
    printf("     *      7.显示记录            8.排序记录      *\n");
    printf("     *      0.退出系统                            *\n");
    printf("     **********************************************\n");
}
/*1调用Add  2调用Del  3调用Qur  4调用Modify  5调用Insert  6调用Save  7调用Disp*/

void printheader()/*表头*/
{
    printf(h1);
    printf(h2);
    printf(h3);
}

void printdata(Node *pp)
{Node *p;
p=pp;
printf(fm,DATA);
}

void wrong()
{
    printf("\n*****输入错误，请按任意键返回*****\n");
    getchar();
}

void Nofind()
{
    printf("*****没有找到该学生的记录！*****\n");
}

void Disp(Link l)/*英文字母l*/
{
    Node *p;
    p=l->next;
    if(!p)/*p==0*/
    {
        printf("\n*****没有该学生的记录！*****\n");
        getchar();
        return;
    }
    printf("\n\n");
    printheader();
    while(p)/*逐条输出记录*/
    {
        printdata(p);
        p=p->next;/*指针移动到下一个节点*/
        printf(h3);
    }
    printf("\n按回车键继续！");
    getchar();
    printf("\n");
}

/*查找Qur  以下代码是定位   会在查找中嵌套*/
Node *Locateofnum(Link l,char findmess[])/*按学号查询，findmess保存要查的内容*/
{
    Node *r;
    r=l->next;
    while(r)
    {
        if(strcmp(r->data.xh,findmess)==0)
            return r;
        r=r->next;
    }
    return 0;
}

void *Locateofname(Link l,char findmess[],Node *n[])/*按名字查询，可能不止一个*/
{
    Node *r;
    int i=0;
    r=l->next;
    while(r)
    {
        if(strcmp(r->data.mz,findmess)==0)
            n[i++]=r;
        r=r->next;
    }
}

void stringinput(char *t,int lens,char *notice)
{
    char n[200];
    printf(notice);/*notice直接传提示信息字符串*/
    scanf("%s",n);
    while(strlen(n)>lens)
    {
        printf("\n*****超出长度限制！*****\n");
        printf(notice);
        scanf("%s",n);
    }
    printf("\n");
    strcpy(t,n);/*拷贝*/
}

void Add(Link l)/*加到队尾*/
{
    Node *p,*r,*s;/*临时*/
    char ch,flag=0,num[12]={' '};
    r=l;
    s=l->next;
    system("cls");
    while(r->next!=NULL)
    r=r->next;/*循环直接将指针指向最末尾，准备添加（注意没有大括号只循环这部分，与下面的while无关）*/

    while(1)/*一次输入多条记录*/
    {
        while(1)/*输入学号为0退出*/
        {int a=1;
            while(a)
            {stringinput(num,12,"请输入学号（按0返回主菜单）\n");
            int i;
            for(i=0;i<strlen(num);i++)
            {
                if(num[i]<'0'||num[i]>'9')break;
            }
            if(i<strlen(num)){printf("输入错误，请重新输入\n");continue;}
            else a=0;
            }
            flag=0;
            if(strcmp(num,"0")==0)return;/*输入0返回主菜单*/
            s=l->next;
            while(s)/*查询是否有重复的，否则重新输入*/
            {
                if(strcmp(s->data.xh,num)==0)
                {
                    flag=1;
                    break;
                }
                s=s->next;
            }
            if(flag==1)
            {
                getchar();
                printf("该学号已经存在，重新输入请按 y ,按其他键退出\n");
                scanf("%c",&ch);
                if(ch=='y'||ch=='Y')
                    continue;
                else return;
            }
            else break;

        }
        p=(Node *)malloc(sizeof(Node));
        if(!p)
        {
            printf("\n*****申请内存空间失败！*****\n");
            return;
        }
        strcpy(p->data.xh,num);

        int x=1;
            while(x)
            {stringinput(p->data.mz,8,"姓名:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.ssl,10,"宿舍楼（如 行健轩）:");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.qsh,4,"寝室号(如A000):");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.sj,11,"手机号码:");
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }

        p->next=NULL;/*表明这是尾部节点*/
        r->next=p;/*将新建的节点加入链表尾部*/
        r=p;
        saveflag=1;
    }
    return;
}

void Qur(Link l)/*查找*/
{
    int select;/*选择用  值为1时按学号查，值为2时按姓名查*/
    char searchinput[20];/*保存输入内容*/
    Node *p;
    Node *n[5]={NULL};/*存放按姓名查找的指针*/
    int i=0;
    if(!l->next)/*空时*/
    {
        system("cls");
        printf("\n*****没有学生的记录！*****\n");
        getchar();
    return;
    }
    system("cls");
    printf("\n1. 按学号查找           2. 按姓名查找\n\n*****请输入1或2*****\n");
    scanf("%d",&select);
    if(select==1)
    {
        int a=1;
            while(a)
            {stringinput(searchinput,12,"请输入已有的想查找的学号:");
            int i;
            for(i=0;i<strlen(searchinput);i++)
            {
                if(searchinput[i]<'0'||searchinput[i]>'9')break;
            }
            if(i<strlen(searchinput)){printf("输入错误，请重新输入\n");continue;}
            else a=0;
            }
        p=Locateofnum(l,searchinput);
        if(p)
           {
            printheader();
            printdata(p);
            printf(END);
            printf("*****按任意键返回*****");
            getchar();
           }
        else
            {Nofind();
            printf("\n按任意键返回\n");
        getchar();}
    }
    else if(select==2)
    {

        int a=1;
            while(a)
            {stringinput(searchinput,8,"请输入已有的想查找的姓名:");
            int i;
            for(i=0;i<strlen(searchinput);i++)
            {
                if(searchinput[i]>='0')break;
            }
            if(i<strlen(searchinput)){printf("输入错误，请重新输入\n");continue;}
            else a=0;
            }









        Locateofname(l,searchinput,n);
        while((p=n[i++])!=NULL)
        {
            printheader();
            printdata(p);
            printf(END);
        }getchar();

        if(n[0]==NULL)
            {Nofind();
        getchar();}
        printf("\n*****按任意键返回*****\n");
    }
    else
        wrong();
    getchar();
}

void Del(Link l)/*删除*//*若按姓名删除，有重名时容易误删,不需要判断学号正确与否*/
{
    Node *p,*r;
    char findmess[20]={' '},ch;
    if(!l->next)
    {
        system("cls");
        printf("\n*****没有学生的记录！*****\n");
        getchar();
        return;
    }
    system("cls");
    printf("\n已有记录如下：\n");
    Disp(l);
    stringinput(findmess,12,"请输入已有的想删除的学号:");
    getchar();
    p=Locateofnum(l,findmess);
    if(p)
    {printf("确定要删除 %s ?\n输入y确定，输入其他键取消并返回菜单\n",findmess);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        if(p)
        {
            r=l;
            while(r->next!=p)
                r=r->next;
                r->next=p->next;/*去除p所指节点*/
                free(p);
                printf("\n*****删除成功！*****\n");
                getchar();
                saveflag=1;
        }
        else {Nofind();
        getchar();}
        getchar();
    }

    }
    else {printf("\n该记录不存在！不需要删除！\n");getchar();}
}

void Modify(Link l)
{
    int a=8;
    Node *p;
    char findmess[20]={' '};
    if(!l->next)
    {
        system("cls");
        printf("\n*****没有学生的记录！*****\n");
        getchar();
        return;
    }
    system("cls");
    printf("*****原记录*****");
    Disp(l);
    stringinput(findmess,12,"请输入已有的想修改的学号:");
    p=Locateofnum(l,findmess);
    if(p)
    {
        while(a!=0)
        {printf("\n1.全部修改\n2.修改姓名  3.修改宿舍楼\n4.修改寝室号  5.修改电话号码\n0.退出修改\n请输入相应的数字：");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            int x;
            x=1;
            while(x)
            {stringinput(p->data.mz,8,"新的姓名:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.ssl,10,"新的宿舍楼(如 行健轩):");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.qsh,4,"新的寝室号（如A000）:");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.sj,11,"新的手机号码:");
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }
            break;
            case 2:x=1;
            while(x)
            {stringinput(p->data.mz,8,"新的姓名:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }
            break;
            case 3:
            x=1;
            while(x)
            {stringinput(p->data.ssl,10,"新的宿舍楼(如 行健轩):");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }
            break;
            case 4:
            x=1;
            while(x)
            {stringinput(p->data.qsh,4,"新的寝室号（如A000）:");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }
            break;
            case 5:
            while(x)
            {stringinput(p->data.sj,11,"新的手机号码:");
            x=1;
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }
            break;
            case 0:break;
        }
        }
        printf("\n*****修改成功！*****\n");
        Disp(l);
        printf("\n按任意键返回\n");
        saveflag=1;
    }
    else
    {Nofind();
    printf("\n按回车键返回菜单！\n");
    getchar();
    }
    getchar();
}

void Insert(Link l)
{
    Link p,v,newinfo;/*p newinfo  前 后*/
    char ch,s[20]={' '},num[20]={' '};/*s,num*/
    int flag=0;
    v=l->next;
    system("cls");
    Disp(l);
    while(1)
    {

        int x=1;
            while(x)
            {stringinput(s,12,"请输入想插入哪个学号后面:");
            int i;
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]<'0'||s[i]>'9')break;
            }
            if(i<strlen(s)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }

        flag=0;
        v=l->next;
        while(v)/*验证学号存在*/
        {
            if(strcmp(v->data.xh,s)==0)
            {
                flag=1;
                break;
            }
            v=v->next;
        }
        if(flag==1)break;/*跳出执行插入过程*/
        else
        {
            getchar();
            printf("\n*****学号 %s 的记录未找到，重新输入？\n输入y继续，输入其他键退出\n",s);
            scanf("%c",&ch);
            if(ch=='y'||ch=='Y')continue;
            else return;
        }
    }

    int x=1;
            while(x)
            {stringinput(num,12,"请输入想插入的学号:");
            int i;
            for(i=0;i<strlen(num);i++)
            {
                if(num[i]<'0'||num[i]>'9')break;
            }
            if(i<strlen(num)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }

    v=l->next;
    while(v)/*验证学号是否已经存在*/
    {
        if(strcmp(v->data.xh,num)==0)
        {
        printf("***** %s 该学号已经存在！*****\n",num);
        printheader();
        printdata(v);
        printf("\n");
        getchar();
        getchar();
        return;
        }
        v=v->next;
    }
    newinfo=(Node *)malloc(sizeof(Node));
    if(!newinfo)
    {
        printf("\n*****分配空间失败！*****\n");
        return;
    }
    strcpy(newinfo->data.xh,num);



     x=1;
            while(x)
            {stringinput(newinfo->data.mz,8,"姓名:");
            int i;
            for(i=0;i<strlen(newinfo->data.mz);i++)
            {
                if(newinfo->data.mz[i]>='0')break;
            }
            if(i<strlen(newinfo->data.mz)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.ssl,10,"宿舍楼(如 行健轩):");

            int i;
            for(i=0;i<strlen(newinfo->data.ssl);i++)
            {
                if(newinfo->data.ssl[i]>='0')break;
            }
            if(i<strlen(newinfo->data.ssl)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.qsh,4,"寝室号（如A000）:");
            int i;
            for(i=0;i<strlen(newinfo->data.qsh);i++)
            {
                if(!((newinfo->data.qsh[0]>='a'&&newinfo->data.qsh[0]<='z')||(newinfo->data.qsh[0]>='A'&&newinfo->data.qsh[0]<='Z')))break;
                if(i>0&&(!(newinfo->data.qsh[i]>='0'&&newinfo->data.qsh[i]<='9')))break;
            }
            if(i<strlen(newinfo->data.qsh)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.sj,11,"手机号码:");
            int i;
            for(i=0;i<strlen(newinfo->data.sj);i++)
            {
                if(!(newinfo->data.sj[i]>='0'&&newinfo->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(newinfo->data.sj)){printf("输入错误，请重新输入\n");continue;}
            else x=0;
            }

    newinfo->next=NULL;
    saveflag=1;
    p=l->next;
    while(1)
    {
        if(strcmp(p->data.xh,s)==0)
        {
            newinfo->next=p->next;
            p->next=newinfo;
            break;
        }
        p=p->next;
    }
    Disp(l);
    printf("\n\n");
    getchar();
}

void Sort(Link l)
{
    int select,x=1;
    struct student temp;
    Node *p1,*p2,*p;/*p1 p2指向要排序的节点，p指向顺序靠前的节点*/
    int i=0;
    system("cls");
    printf("\n1.按学号排序   2.按寝室楼排序\n请输入1或2\n");
    scanf("%d",&select);

    if(l->next==NULL)
    {
        system("cls");
        printf("\n*****没有学生的记录！\n*****\n");
        getchar();
        return;
    }
    while(x)
    {if(select==1)
    {system("cls");
    p1=l->next;
    while(p1)
    {
        p2=p1->next;
        p=p1;
        while(p2)
        {
            if(strcmp(p2->data.xh,p->data.xh)<=0)p=p2;
            p2=p2->next;
        }
        temp=p->data;
        p->data=p1->data;
        p1->data=temp;
        p1=p1->next;
    }
    x=0;
    Disp(l);
    saveflag=1;
    printf("\n*****按学号排序完成！*****\n");
    }
    else if(select==2)
    {
        system("cls");
    p1=l->next;
    while(p1)
    {
        p2=p1->next;
        p=p1;
        while(p2)
        {
            if(strcmp(p2->data.ssl,p->data.ssl)<=0)p=p2;
            p2=p2->next;
        }
        temp=p->data;
        p->data=p1->data;
        p1->data=temp;
        p1=p1->next;
    }
    x=0;
    Disp(l);
    saveflag=1;
    printf("\n*****按宿舍楼排序完成！*****\n");
    }
    else {
        printf("\n输入错误，请重新选择:");
        scanf("%d",&select);
        getchar();

    }
    }
}

void Save(Link l)/*存盘*/
{
    FILE *fp;
    Node *p;
    int count=0;
    fp=fopen(".\\student","wb");                                   /*只写 打开二进制文件，试试其他文件？*/
    if(fp==NULL)
    {
        printf("\n*****打开文件错误！*****\n");
        getchar();
        return;
    }
    p=l->next;
    while(p)
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)/*每次写一条记录或一个节点信息至文件*/
        {
            p=p->next;
            count++;
        }
        else break;
    }
    if(count>0)
    {
        getchar();
        printf("\n\n*****存盘完成，共 %d 条记录*****\n",count);
        getchar();
        saveflag=0;
    }
    else{
        system("cls");
        printf("*****链表为空，没有记录可保存！\n");
        getchar();
    }
    fclose(fp);
}

int main()
{
   Link l;
   FILE *fp;
   int select;
   char ch;
   int count=0;
   Node *p,*r;
   l=(Node *)malloc(sizeof(Node));
   if(!l)
   {
       printf("\n*****申请内存空间失败！*****\n");
       return 0;
   }
   l->next=NULL;
   r=l;
   fp=fopen("F:\\student","ab+");/*可读可写，可以自动创建文件*/
   if(fp==NULL)
   {
    printf("\n*****无法打开文件！*****\n");
    exit(0);
   }
   while(!feof(fp))
   {
       p=(Node *)malloc(sizeof(Node));
       if(!p)
       {
           printf("*****申请内存空间失败！*****\n");
           exit(0);
       }
       if(fread(p,sizeof(Node),1,fp)==1)/*每次读取一条记录*/
       {
           p->next=NULL;
           r->next=p;
           r=p;
           count++;
       }
   }
   fclose(fp);
   printf("\n*****打开文件成功，共有 %d 条记录*****\n",count);
   printf("\n*****按回车键进入菜单*****\n");
   getchar();
   while(l)
   {
       system("cls");
       menu();
       p=r;
       printf("\n请输入对应的数字进入相应功能:\n");
       scanf("%d",&select);
       if(select==0)
       {
           if(saveflag==1)
           {
               getchar();
               printf("*****是否保存修改？*****\n请输入y确认，输入n不保存\n");
               int a=1;
               while(a)
               {scanf("%c",&ch);
               if(ch=='y'||ch=='Y')
                {Save(l);a=0;}
               else if(ch=='n'||ch=='N'){printf("\n*****未保存！*****\n");a=0;}
               else {printf("\n*****输入错误，请重新输入*****\n");a=1;}
               }
           }
           printf("\n*****感谢使用！*****\n");
           getchar();
           break;
       }
       switch(select)
       {
        case 1:Add(l);break;
        case 2:Del(l);break;
        case 3:Qur(l);break;
        case 4:Modify(l);break;
        case 5:Insert(l);break;
        case 6:Save(l);break;
        case 7:system("cls");Disp(l);getchar();break;
        case 8:Sort(l);printf("\n按回车键继续！\n");getchar();break;
        default:wrong();getchar();break;
       }
   }
   return 0;
}
