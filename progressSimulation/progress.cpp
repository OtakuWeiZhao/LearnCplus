#include<stdio.h>
#include <malloc.h>
//#include <string>   //c����û��string����Ϊstring��һ���࣬��cû����
#include <string.h>
//using namespace std;

struct PCB
{
	int ProcessReachTime;//��־���̵���ʱ��
	char PID[10];//����ID
	//int priority;//�������������������FCFSû����
	//int chip;//ʱ��Ƭ
	int needTime;
	int cputime;//�����Ѿ�ռ��CPU��ʱ��
	int alltime;//���̻���Ҫ���е�ʱ�䣨�������������ʱ����ֵΪ0��
	char state;//���̵�״̬STATE��Ϊ���������ÿ�����̴�������E��excecuting��������R��ready�������F��finish������״̬֮һ����������ʼ״̬���Ǿ���״̬R����
	struct PCB* next;//���̶���ָ��NEXT��������PCB�ųɶ��У���
};

int time;//���ڽ��̵���ʱ�����Ҫʱ��
char strPID[10];
int num;
struct PCB  *start,*startHead,*temp,*newNode;
int totalTime=0;
int main()
{
	printf("�����������:");
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
		printf("���������ID:");
		scanf("%s",strPID);
		strcpy(newNode->PID,strPID);//������newNode->PID=strPID;��ΪPID��һ���ַ�����newNode->PID��һ�����������ܸ���
		//--------------------------
		printf("��������̵���ʱ��:");
		scanf("%d",&time);
		newNode->ProcessReachTime=time;
		//--------------------------
		printf("�����������Ҫʱ��:");
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
				
				else if(startHead->ProcessReachTime<=newNode->ProcessReachTime &&startHead->next!=NULL&& startHead->next->ProcessReachTime>newNode->ProcessReachTime)//ע�����������˳�����˳������ᷢ������
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

	int startTime=0;//���ڼ�¼һ�����̿�ʼ���е�ʱ��
	startHead=start;
	for(int i=0;startHead!=NULL;i++)
	{
		if (startHead->ProcessReachTime<=i&&startHead->state=='R')
		{
			startTime=i;//��¼��ʼʱ��iΪastartTime
			startHead->state='E';//����Ϊִ��״̬
			printf("��%dʱ�̣�",i);
			printf("����%s��ʼ����\n",startHead->PID);
		}
		else if (i-startTime<startHead->needTime&&i-startTime>0&&startHead->state=='E')
		{
			printf("��%dʱ�̣�",i);
			printf("����%s��������\n",startHead->PID);
		}
		else if (i-startTime==startHead->needTime&&startHead->state=='E')
		{
			startHead->state='F';
			printf("��%dʱ�̣�",i);
			printf("����%s��������\n",startHead->PID);
			startHead=startHead->next;
			i--;//�������Ҫ����Ҫ�ڽ���ʱ���Ƿ��н���ִ��
		}

		if(startHead==NULL)
		{
			printf("���̵��Ƚ���");
		}
	}


	
	while(1);
}
