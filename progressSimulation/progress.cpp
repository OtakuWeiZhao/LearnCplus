#include<stdio.h>
#include <malloc.h>
//#include <string>   //c里面没有string，因为string是一个类，而c没有类
#include <string.h>
//using namespace std;

struct PCB
{
	int ProcessReachTime;//标志进程到达时间
	char PID[10];//进程ID
	//int priority;//进程优先数，在这里的FCFS没有用
	//int chip;//时间片
	int needTime;
	int cputime;//进程已经占用CPU的时间
	int alltime;//进程还需要运行的时间（当进程运行完毕时，其值为0）
	char state;//进程的状态STATE（为简化起见。设每个进程处于运行E（excecuting）、就绪R（ready）和完成F（finish）三种状态之一，并假设起始状态都是就绪状态R。）
	struct PCB* next;//进程队列指针NEXT（用来将PCB排成队列）等
};

int time;//用于进程到达时间和需要时间
char strPID[10];
int num;
struct PCB  *start,*startHead,*temp,*newNode;
int totalTime=0;
int main()
{
	printf("请输入进程数:");
	scanf("%d",&num);

	start=(PCB*)malloc(sizeof(PCB));
	startHead=(PCB*)malloc(sizeof(PCB));
	start=NULL;
	startHead=start;

	temp=(PCB*)malloc(sizeof(PCB));
	temp=startHead;

	for (int i=0;i<num;i++)
	{
		startHead=start;
		temp=startHead;
		newNode=(PCB*)malloc(sizeof(PCB));
		//--------------------------
		printf("请输入进程ID:");
		scanf("%s",strPID);
		strcpy(newNode->PID,strPID);//不能用newNode->PID=strPID;因为PID是一个字符数组newNode->PID是一个常量，不能复制
		//--------------------------
		printf("请输入进程到达时间:");
		scanf("%d",&time);
		newNode->ProcessReachTime=time;
		//--------------------------
		printf("请输入进程需要时间:");
		scanf("%d",&time);
		newNode->needTime=time;
		//--------------------------
		newNode->state='R';


		newNode->next=NULL;
		if(i==0)
		{
			start=newNode;
			startHead=start;
		}
		else if (i==1)
		{
			if(start->ProcessReachTime<=newNode->ProcessReachTime)
			{
				startHead->next=newNode;
			}
			else
			{
				newNode->next=startHead;
				start=newNode;
			}
		}
		else
		{
			for(startHead=start;startHead!=NULL;startHead=startHead->next)
			{
				temp=startHead;
				if(start->ProcessReachTime>newNode->ProcessReachTime)
				{
					newNode->next=startHead;
					start=newNode;
					break;
				}
				
				else if(startHead->ProcessReachTime<=newNode->ProcessReachTime &&startHead->next!=NULL&& startHead->next->ProcessReachTime>newNode->ProcessReachTime)//注意后面两个的顺序，如果顺序调换会发生错误
				{
					newNode->next=startHead->next;
					temp->next=newNode;
					break;
				}

				else if(startHead->next==NULL)
				{
					temp->next=newNode;
					break;
				}
			}
		}
		
	}

	int startTime=0;//用于记录一个进程开始运行的时间
	startHead=start;
	for(int i=0;startHead!=NULL;i++)
	{
		if (startHead->ProcessReachTime<=i&&startHead->state=='R')
		{
			startTime=i;//记录开始时间i为astartTime
			startHead->state='E';//进程为执行状态
			printf("在%d时刻：",i);
			printf("进程%s开始运行\n",startHead->PID);
		}
		else if (i-startTime<startHead->needTime&&i-startTime>0&&startHead->state=='E')
		{
			printf("在%d时刻：",i);
			printf("进程%s正在运行\n",startHead->PID);
		}
		else if (i-startTime==startHead->needTime&&startHead->state=='E')
		{
			startHead->state='F';
			printf("在%d时刻：",i);
			printf("进程%s结束运行\n",startHead->PID);
			startHead=startHead->next;
			i--;//这个很重要，主要在结束时刻是否有进程执行
		}

		if(startHead==NULL)
		{
			printf("进程调度结束");
		}
	}


	
	while(1);
}
