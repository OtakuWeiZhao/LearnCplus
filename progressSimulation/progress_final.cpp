#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
typedef struct pcb
{
    char name[Max];  //进程名
    int priority;    //优先级
    int arrtime;     //到达时间
    int needtime;    //需要运行时间
    int usedtime;
    char state;      //进程状态
    int *ip;
}PCB;

PCB pcb[Max];

int n=1;
void initPCB();
void Sort();
void Print();
void Attemper();

int main()
{
    int choice;

    //n=1;
    printf("                       \n");
    printf("\t\t欢迎使用进程调度模拟\n\n");
    initPCB();
    Print();
    Attemper();
    return 0;
}

void initPCB()
{
    do{
        printf("\n---请输入第%d个进程进程---\n",n);
        printf("\n进程名:");
        scanf("%s",pcb[n].name);
        printf("进程优先级:");
        scanf("%d",&pcb[n].priority);
        printf("进程需要的时间:");
        scanf("%d",&pcb[n].needtime);
        pcb[n].state='W';
        n++;
    }while(n<6);
}

void Print()
{
    int i;
    Sort();
    printf("\n   进程名    优先级  运行时间   进程状态 \n");
    for(i=0;i<n;i++)
    {
        printf("%8s%8d %10d %10c\n",pcb[i].name,pcb[i].priority,pcb[i].usedtime,pcb[i].state);
    }
}

void Sort()
{
    int i,j;
    PCB temp;
    for(i=0;i<n-1;i++)         //按照到达时间排序
    {
        for(j=n-2;j>=i;j--)
        {
            if(pcb[j+1].arrtime<pcb[j].arrtime)
            {
                temp=pcb[j];
                pcb[j]=pcb[j+1];
                pcb[j+1]=temp;
            }
        }
    }

    for(i=0;i<n-1;i++)      //按照优先级排序
    {
        for(j=n-2;j>=i;j--)
        {
            if(pcb[j+1].priority>pcb[j].priority)
            {
                temp=pcb[j];
                pcb[j]=pcb[j+1];
                pcb[j+1]=temp;
            }
        }
    }
    if(pcb[0].state!='F')
    {
        pcb[0].state='R';
    }
}


void Attemper()
{
    do{
        if((pcb[0].priority>pcb[1].priority))   //判断进程剩余的运行时间是否大于时间片
        {
            pcb[0].needtime--;
            pcb[0].priority--;
            pcb[0].state='W';
        }
        else                       //已完成的进程
        {
            pcb[0].needtime=0;
            pcb[0].priority=-1;
            pcb[0].usedtime++;
            pcb[0].state='F';
        }
        Print();
    }while(pcb[0].state!='F');
}

