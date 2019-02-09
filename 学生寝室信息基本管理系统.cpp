#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define h1 "����������������������������������������������������������������������������������������������������������������\n"
#define h2 "��     ѧ��     ��   ����   �� ����¥ �� ���Һ� ��    �ֻ�����    ��\n"
#define h3 "�ǩ�������������������������������������������������������������������������������������������������������������\n"
#define fm "�� %-12s ��  %-8s�� %-6s ��  %-4s  ��  %-11s   ��\n"
#define END "����������������������������������������������������������������������������������������������������������������\n"
#define DATA p->data.xh,p->data.mz,p->data.ssl,p->data.qsh,p->data.sj

/*�绰�����������Ϣ�Ƿ���Ҫ�������ƣ���Ҫ�ɼ�*/

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
    system("cls");/*   DOS����  ����    */
    printf("                ѧ��������Ϣ��������ϵͳ\n\n");
    printf("     *********************�˵�*********************\n");
    printf("     *      1.�����¼            2.ɾ����¼      *\n");
    printf("     *      3.���Ҽ�¼            4.�޸ļ�¼      *\n");
    printf("     *      5.�����¼            6.�洢��¼      *\n");
    printf("     *      7.��ʾ��¼            8.�����¼      *\n");
    printf("     *      0.�˳�ϵͳ                            *\n");
    printf("     **********************************************\n");
}
/*1����Add  2����Del  3����Qur  4����Modify  5����Insert  6����Save  7����Disp*/

void printheader()/*��ͷ*/
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
    printf("\n*****��������밴���������*****\n");
    getchar();
}

void Nofind()
{
    printf("*****û���ҵ���ѧ���ļ�¼��*****\n");
}

void Disp(Link l)/*Ӣ����ĸl*/
{
    Node *p;
    p=l->next;
    if(!p)/*p==0*/
    {
        printf("\n*****û�и�ѧ���ļ�¼��*****\n");
        getchar();
        return;
    }
    printf("\n\n");
    printheader();
    while(p)/*���������¼*/
    {
        printdata(p);
        p=p->next;/*ָ���ƶ�����һ���ڵ�*/
        printf(h3);
    }
    printf("\n���س���������");
    getchar();
    printf("\n");
}

/*����Qur  ���´����Ƕ�λ   ���ڲ�����Ƕ��*/
Node *Locateofnum(Link l,char findmess[])/*��ѧ�Ų�ѯ��findmess����Ҫ�������*/
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

void *Locateofname(Link l,char findmess[],Node *n[])/*�����ֲ�ѯ�����ܲ�ֹһ��*/
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
    printf(notice);/*noticeֱ�Ӵ���ʾ��Ϣ�ַ���*/
    scanf("%s",n);
    while(strlen(n)>lens)
    {
        printf("\n*****�����������ƣ�*****\n");
        printf(notice);
        scanf("%s",n);
    }
    printf("\n");
    strcpy(t,n);/*����*/
}

void Add(Link l)/*�ӵ���β*/
{
    Node *p,*r,*s;/*��ʱ*/
    char ch,flag=0,num[12]={' '};
    r=l;
    s=l->next;
    system("cls");
    while(r->next!=NULL)
    r=r->next;/*ѭ��ֱ�ӽ�ָ��ָ����ĩβ��׼����ӣ�ע��û�д�����ֻѭ���ⲿ�֣��������while�޹أ�*/

    while(1)/*һ�����������¼*/
    {
        while(1)/*����ѧ��Ϊ0�˳�*/
        {int a=1;
            while(a)
            {stringinput(num,12,"������ѧ�ţ���0�������˵���\n");
            int i;
            for(i=0;i<strlen(num);i++)
            {
                if(num[i]<'0'||num[i]>'9')break;
            }
            if(i<strlen(num)){printf("�����������������\n");continue;}
            else a=0;
            }
            flag=0;
            if(strcmp(num,"0")==0)return;/*����0�������˵�*/
            s=l->next;
            while(s)/*��ѯ�Ƿ����ظ��ģ�������������*/
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
                printf("��ѧ���Ѿ����ڣ����������밴 y ,���������˳�\n");
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
            printf("\n*****�����ڴ�ռ�ʧ�ܣ�*****\n");
            return;
        }
        strcpy(p->data.xh,num);

        int x=1;
            while(x)
            {stringinput(p->data.mz,8,"����:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.ssl,10,"����¥���� �н�����:");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.qsh,4,"���Һ�(��A000):");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(p->data.sj,11,"�ֻ�����:");
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("�����������������\n");continue;}
            else x=0;
            }

        p->next=NULL;/*��������β���ڵ�*/
        r->next=p;/*���½��Ľڵ��������β��*/
        r=p;
        saveflag=1;
    }
    return;
}

void Qur(Link l)/*����*/
{
    int select;/*ѡ����  ֵΪ1ʱ��ѧ�Ų飬ֵΪ2ʱ��������*/
    char searchinput[20];/*������������*/
    Node *p;
    Node *n[5]={NULL};/*��Ű��������ҵ�ָ��*/
    int i=0;
    if(!l->next)/*��ʱ*/
    {
        system("cls");
        printf("\n*****û��ѧ���ļ�¼��*****\n");
        getchar();
    return;
    }
    system("cls");
    printf("\n1. ��ѧ�Ų���           2. ����������\n\n*****������1��2*****\n");
    scanf("%d",&select);
    if(select==1)
    {
        int a=1;
            while(a)
            {stringinput(searchinput,12,"���������е�����ҵ�ѧ��:");
            int i;
            for(i=0;i<strlen(searchinput);i++)
            {
                if(searchinput[i]<'0'||searchinput[i]>'9')break;
            }
            if(i<strlen(searchinput)){printf("�����������������\n");continue;}
            else a=0;
            }
        p=Locateofnum(l,searchinput);
        if(p)
           {
            printheader();
            printdata(p);
            printf(END);
            printf("*****�����������*****");
            getchar();
           }
        else
            {Nofind();
            printf("\n�����������\n");
        getchar();}
    }
    else if(select==2)
    {

        int a=1;
            while(a)
            {stringinput(searchinput,8,"���������е�����ҵ�����:");
            int i;
            for(i=0;i<strlen(searchinput);i++)
            {
                if(searchinput[i]>='0')break;
            }
            if(i<strlen(searchinput)){printf("�����������������\n");continue;}
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
        printf("\n*****�����������*****\n");
    }
    else
        wrong();
    getchar();
}

void Del(Link l)/*ɾ��*//*��������ɾ����������ʱ������ɾ,����Ҫ�ж�ѧ����ȷ���*/
{
    Node *p,*r;
    char findmess[20]={' '},ch;
    if(!l->next)
    {
        system("cls");
        printf("\n*****û��ѧ���ļ�¼��*****\n");
        getchar();
        return;
    }
    system("cls");
    printf("\n���м�¼���£�\n");
    Disp(l);
    stringinput(findmess,12,"���������е���ɾ����ѧ��:");
    getchar();
    p=Locateofnum(l,findmess);
    if(p)
    {printf("ȷ��Ҫɾ�� %s ?\n����yȷ��������������ȡ�������ز˵�\n",findmess);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        if(p)
        {
            r=l;
            while(r->next!=p)
                r=r->next;
                r->next=p->next;/*ȥ��p��ָ�ڵ�*/
                free(p);
                printf("\n*****ɾ���ɹ���*****\n");
                getchar();
                saveflag=1;
        }
        else {Nofind();
        getchar();}
        getchar();
    }

    }
    else {printf("\n�ü�¼�����ڣ�����Ҫɾ����\n");getchar();}
}

void Modify(Link l)
{
    int a=8;
    Node *p;
    char findmess[20]={' '};
    if(!l->next)
    {
        system("cls");
        printf("\n*****û��ѧ���ļ�¼��*****\n");
        getchar();
        return;
    }
    system("cls");
    printf("*****ԭ��¼*****");
    Disp(l);
    stringinput(findmess,12,"���������е����޸ĵ�ѧ��:");
    p=Locateofnum(l,findmess);
    if(p)
    {
        while(a!=0)
        {printf("\n1.ȫ���޸�\n2.�޸�����  3.�޸�����¥\n4.�޸����Һ�  5.�޸ĵ绰����\n0.�˳��޸�\n��������Ӧ�����֣�");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            int x;
            x=1;
            while(x)
            {stringinput(p->data.mz,8,"�µ�����:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("�����������������\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.ssl,10,"�µ�����¥(�� �н���):");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("�����������������\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.qsh,4,"�µ����Һţ���A000��:");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("�����������������\n");continue;}
            else x=0;
            }


            x=1;
            while(x)
            {stringinput(p->data.sj,11,"�µ��ֻ�����:");
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("�����������������\n");continue;}
            else x=0;
            }
            break;
            case 2:x=1;
            while(x)
            {stringinput(p->data.mz,8,"�µ�����:");
            int i;
            for(i=0;i<strlen(p->data.mz);i++)
            {
                if(p->data.mz[i]>='0')break;
            }
            if(i<strlen(p->data.mz)){printf("�����������������\n");continue;}
            else x=0;
            }
            break;
            case 3:
            x=1;
            while(x)
            {stringinput(p->data.ssl,10,"�µ�����¥(�� �н���):");
            int i;
            for(i=0;i<strlen(p->data.ssl);i++)
            {
                if(p->data.ssl[i]>='0')break;
            }
            if(i<strlen(p->data.ssl)){printf("�����������������\n");continue;}
            else x=0;
            }
            break;
            case 4:
            x=1;
            while(x)
            {stringinput(p->data.qsh,4,"�µ����Һţ���A000��:");
            int i;
            for(i=0;i<strlen(p->data.qsh);i++)
            {
                if(!((p->data.qsh[0]>='a'&&p->data.qsh[0]<='z')||(p->data.qsh[0]>='A'&&p->data.qsh[0]<='Z')))break;
                if(i>0&&(!(p->data.qsh[i]>='0'&&p->data.qsh[i]<='9')))break;
            }
            if(i<strlen(p->data.qsh)){printf("�����������������\n");continue;}
            else x=0;
            }
            break;
            case 5:
            while(x)
            {stringinput(p->data.sj,11,"�µ��ֻ�����:");
            x=1;
            int i;
            for(i=0;i<strlen(p->data.sj);i++)
            {
                if(!(p->data.sj[i]>='0'&&p->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(p->data.sj)){printf("�����������������\n");continue;}
            else x=0;
            }
            break;
            case 0:break;
        }
        }
        printf("\n*****�޸ĳɹ���*****\n");
        Disp(l);
        printf("\n�����������\n");
        saveflag=1;
    }
    else
    {Nofind();
    printf("\n���س������ز˵���\n");
    getchar();
    }
    getchar();
}

void Insert(Link l)
{
    Link p,v,newinfo;/*p newinfo  ǰ ��*/
    char ch,s[20]={' '},num[20]={' '};/*s,num*/
    int flag=0;
    v=l->next;
    system("cls");
    Disp(l);
    while(1)
    {

        int x=1;
            while(x)
            {stringinput(s,12,"������������ĸ�ѧ�ź���:");
            int i;
            for(i=0;i<strlen(s);i++)
            {
                if(s[i]<'0'||s[i]>'9')break;
            }
            if(i<strlen(s)){printf("�����������������\n");continue;}
            else x=0;
            }

        flag=0;
        v=l->next;
        while(v)/*��֤ѧ�Ŵ���*/
        {
            if(strcmp(v->data.xh,s)==0)
            {
                flag=1;
                break;
            }
            v=v->next;
        }
        if(flag==1)break;/*����ִ�в������*/
        else
        {
            getchar();
            printf("\n*****ѧ�� %s �ļ�¼δ�ҵ����������룿\n����y�����������������˳�\n",s);
            scanf("%c",&ch);
            if(ch=='y'||ch=='Y')continue;
            else return;
        }
    }

    int x=1;
            while(x)
            {stringinput(num,12,"������������ѧ��:");
            int i;
            for(i=0;i<strlen(num);i++)
            {
                if(num[i]<'0'||num[i]>'9')break;
            }
            if(i<strlen(num)){printf("�����������������\n");continue;}
            else x=0;
            }

    v=l->next;
    while(v)/*��֤ѧ���Ƿ��Ѿ�����*/
    {
        if(strcmp(v->data.xh,num)==0)
        {
        printf("***** %s ��ѧ���Ѿ����ڣ�*****\n",num);
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
        printf("\n*****����ռ�ʧ�ܣ�*****\n");
        return;
    }
    strcpy(newinfo->data.xh,num);



     x=1;
            while(x)
            {stringinput(newinfo->data.mz,8,"����:");
            int i;
            for(i=0;i<strlen(newinfo->data.mz);i++)
            {
                if(newinfo->data.mz[i]>='0')break;
            }
            if(i<strlen(newinfo->data.mz)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.ssl,10,"����¥(�� �н���):");

            int i;
            for(i=0;i<strlen(newinfo->data.ssl);i++)
            {
                if(newinfo->data.ssl[i]>='0')break;
            }
            if(i<strlen(newinfo->data.ssl)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.qsh,4,"���Һţ���A000��:");
            int i;
            for(i=0;i<strlen(newinfo->data.qsh);i++)
            {
                if(!((newinfo->data.qsh[0]>='a'&&newinfo->data.qsh[0]<='z')||(newinfo->data.qsh[0]>='A'&&newinfo->data.qsh[0]<='Z')))break;
                if(i>0&&(!(newinfo->data.qsh[i]>='0'&&newinfo->data.qsh[i]<='9')))break;
            }
            if(i<strlen(newinfo->data.qsh)){printf("�����������������\n");continue;}
            else x=0;
            }


        x=1;
            while(x)
            {stringinput(newinfo->data.sj,11,"�ֻ�����:");
            int i;
            for(i=0;i<strlen(newinfo->data.sj);i++)
            {
                if(!(newinfo->data.sj[i]>='0'&&newinfo->data.sj[i]<='9')||strlen(p->data.sj)<11)break;
            }
            if(i<strlen(newinfo->data.sj)){printf("�����������������\n");continue;}
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
    Node *p1,*p2,*p;/*p1 p2ָ��Ҫ����Ľڵ㣬pָ��˳��ǰ�Ľڵ�*/
    int i=0;
    system("cls");
    printf("\n1.��ѧ������   2.������¥����\n������1��2\n");
    scanf("%d",&select);

    if(l->next==NULL)
    {
        system("cls");
        printf("\n*****û��ѧ���ļ�¼��\n*****\n");
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
    printf("\n*****��ѧ��������ɣ�*****\n");
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
    printf("\n*****������¥������ɣ�*****\n");
    }
    else {
        printf("\n�������������ѡ��:");
        scanf("%d",&select);
        getchar();

    }
    }
}

void Save(Link l)/*����*/
{
    FILE *fp;
    Node *p;
    int count=0;
    fp=fopen(".\\student","wb");                                   /*ֻд �򿪶������ļ������������ļ���*/
    if(fp==NULL)
    {
        printf("\n*****���ļ�����*****\n");
        getchar();
        return;
    }
    p=l->next;
    while(p)
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)/*ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�*/
        {
            p=p->next;
            count++;
        }
        else break;
    }
    if(count>0)
    {
        getchar();
        printf("\n\n*****������ɣ��� %d ����¼*****\n",count);
        getchar();
        saveflag=0;
    }
    else{
        system("cls");
        printf("*****����Ϊ�գ�û�м�¼�ɱ��棡\n");
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
       printf("\n*****�����ڴ�ռ�ʧ�ܣ�*****\n");
       return 0;
   }
   l->next=NULL;
   r=l;
   fp=fopen("F:\\student","ab+");/*�ɶ���д�������Զ������ļ�*/
   if(fp==NULL)
   {
    printf("\n*****�޷����ļ���*****\n");
    exit(0);
   }
   while(!feof(fp))
   {
       p=(Node *)malloc(sizeof(Node));
       if(!p)
       {
           printf("*****�����ڴ�ռ�ʧ�ܣ�*****\n");
           exit(0);
       }
       if(fread(p,sizeof(Node),1,fp)==1)/*ÿ�ζ�ȡһ����¼*/
       {
           p->next=NULL;
           r->next=p;
           r=p;
           count++;
       }
   }
   fclose(fp);
   printf("\n*****���ļ��ɹ������� %d ����¼*****\n",count);
   printf("\n*****���س�������˵�*****\n");
   getchar();
   while(l)
   {
       system("cls");
       menu();
       p=r;
       printf("\n�������Ӧ�����ֽ�����Ӧ����:\n");
       scanf("%d",&select);
       if(select==0)
       {
           if(saveflag==1)
           {
               getchar();
               printf("*****�Ƿ񱣴��޸ģ�*****\n������yȷ�ϣ�����n������\n");
               int a=1;
               while(a)
               {scanf("%c",&ch);
               if(ch=='y'||ch=='Y')
                {Save(l);a=0;}
               else if(ch=='n'||ch=='N'){printf("\n*****δ���棡*****\n");a=0;}
               else {printf("\n*****�����������������*****\n");a=1;}
               }
           }
           printf("\n*****��лʹ�ã�*****\n");
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
        case 8:Sort(l);printf("\n���س���������\n");getchar();break;
        default:wrong();getchar();break;
       }
   }
   return 0;
}
