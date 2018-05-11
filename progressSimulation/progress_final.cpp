#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100
typedef struct pcb
{
    char name[Max];  //������
    int priority;    //���ȼ�
    int arrtime;     //����ʱ��
    int needtime;    //��Ҫ����ʱ��
    int usedtime;
    char state;      //����״̬
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
    printf("\t\t��ӭʹ�ý��̵���ģ��\n\n");
    initPCB();
    Print();
    Attemper();
    return 0;
}

void initPCB()
{
    do{
        printf("\n---�������%d�����̽���---\n",n);
        printf("\n������:");
        scanf("%s",pcb[n].name);
        printf("�������ȼ�:");
        scanf("%d",&pcb[n].priority);
        printf("������Ҫ��ʱ��:");
        scanf("%d",&pcb[n].needtime);
        pcb[n].state='W';
        n++;
    }while(n<6);
}

void Print()
{
    int i;
    Sort();
    printf("\n   ������    ���ȼ�  ����ʱ��   ����״̬ \n");
    for(i=0;i<n;i++)
    {
        printf("%8s%8d %10d %10c\n",pcb[i].name,pcb[i].priority,pcb[i].usedtime,pcb[i].state);
    }
}

void Sort()
{
    int i,j;
    PCB temp;
    for(i=0;i<n-1;i++)         //���յ���ʱ������
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

    for(i=0;i<n-1;i++)      //�������ȼ�����
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
        if((pcb[0].priority>pcb[1].priority))   //�жϽ���ʣ�������ʱ���Ƿ����ʱ��Ƭ
        {
            pcb[0].needtime--;
            pcb[0].priority--;
            pcb[0].state='W';
        }
        else                       //����ɵĽ���
        {
            pcb[0].needtime=0;
            pcb[0].priority=-1;
            pcb[0].usedtime++;
            pcb[0].state='F';
        }
        Print();
    }while(pcb[0].state!='F');
}

