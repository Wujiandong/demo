#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

#ifndef HEADER_FILE
#define HEADER_FILE


//��    �ܣ���ʾ��Ȩ��Ϣ
//��ڲ������� 
//��    �أ��� 
void Copyright()
{
	printf("Copyright (c) 2020 �⽨��(221900128). All Rights Reserved.\n\n");
}


//��    �ܣ���ʾϵͳ���ڡ�ʱ�� 
//��ڲ������� 
//��    �أ��� 
void SystemTime()
{
	time_t CurrentTime; 
    struct tm *Date;
 	time(&CurrentTime);
    Date = localtime(&CurrentTime);
    printf("��ǰ���ڡ�ʱ�� : %02d-%02d-%02d ",
            Date->tm_year + 1900, Date->tm_mon + 1, Date->tm_mday);
    switch(Date->tm_wday)
	{
		case 0 : printf("(������)"); break; 
		case 1 : printf("(����һ)"); break; 
		case 2 : printf("(���ڶ�)"); break; 
		case 3 : printf("(������)"); break; 
		case 4 : printf("(������)"); break; 
		case 5 : printf("(������)"); break; 
		case 6 : printf("(������)"); break; 
	}
	printf("    %02d:%02d:%02d\n",Date->tm_hour, Date->tm_min, Date->tm_sec);
}


//��    �ܣ���ʾ�˵����� 
//��ڲ������� 
//��    �أ��� 
void Menu()
{
	printf("*********************************"
	  	   "********************************\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t   ����Demo����ϵͳ�˵�  \t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*\tA������һ������������ݵ�(����)����\t\t\t*\n");
	printf("*\tB����ʾ����ǰ�����ڵ����������\t\t\t\t*\n");
	printf("*\tC��������������������ݴ����ļ���\t\t\t*\n");
	printf("*\tD��������ʾ���������ļ���(ȫ��)����\t\t\t*\n");
	printf("*\tE����ʾ���ܹ��ɺϷ����ڵ�(����)���\t\t\t*\n");
	printf("*\tF��ɾ������ĵ�һ�������һ�������ܹ��ɺϷ����ڵĽ��\t*\n");
	printf("*\tG��������(����ͷ����β�����֮ǰ�����֮��)\t\t*\n");
	printf("*\tH����ʾ�������ڶ�Ӧ������\t\t\t\t*\n");
	printf("*\tI���������ڴ�С��������\t\t\t\t*\n");
	printf("*\tJ������������\"������\"���������Ľ��\t\t\t*\n");
	printf("*\tK��(����)����ת\t\t\t\t\t*\n");
	printf("*\tL���˳�ϵͳ\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*********************************"
	  	   "********************************\n");
}


//��������ṹ��
typedef struct Node     
{  
    int year;           //�������е�������   
	int month;
	int day;      
    struct Node *next;  //�������ָ����   
}Node;


Node *Head = NULL;      //����ͷ����β��� 
Node *End = NULL;


//��    �ܣ��ͷ����� 
//��ڲ���������ͷ���ָ�� 
//��    �أ��� 
void FreeList(Node *Head)
{
	Node *freeNode;
	while (Head != NULL)
	{
		freeNode = Head;
		Head = Head->next;
		free(freeNode);
	}
}


//��    �ܣ���������
//��ڲ���������� 
//��    �أ������ 
void BuildList(int NodeNum)
{
	if(Head != NULL)     //����Ѵ����������ͷ����� 
	{
		FreeList(Head);
		printf("\n���ͷž�����׼������������....\n");
	}
	Head = (Node *)malloc(sizeof(Node));
	if (Head == NULL)    //���ڴ�����ʧ�ܽ��еĴ��� 
	{ 
		printf("\n����ʧ��, ������ֹ!\n\n");     
		exit(-1);
	}
	End = Head;
	for(int i = 0; i < NodeNum; i++)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->year = rand() % 121 + 1900;    //Ϊ������������ 
		p->month = rand() % 12 + 1;       //Ϊ�·���������� 
		p->day = rand() % 31 + 1;		  //Ϊ������������� 
		End->next = p;
		End = p;
	}
	End->next = NULL;
}


//��    �ܣ���ӡ��������
//��ڲ�����ָ����������ܽ���� 
//��    �أ��� 
void ShowList(int n, int NodeNum)    
{
	int t = 0;    //�������б��� 
	Node *Temp;
	if((n < 0)||(n > NodeNum))      //�Դ���������ж� 
	{
		printf("\n������������...\n\n");
	}
	else if((n == 0)||(n == NodeNum))  //�������ȫ������ 
	{	
		n = NodeNum; 
		Temp = Head;
		while(Temp->next != NULL)
		{
			if(t % 5 == 0)     //һ������5������ʱ���� 
				printf("\n");
			Temp = Temp->next;
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++; 
		}
		printf("\n\n");
		printf("���������%d����ǰ��ʾ�Ľ������%d\n\n",NodeNum, NodeNum);
	}
	else    //���ָ������������ 
	{
		int temp = n;
		Temp = Head;
		while(temp--)
		{
			if(t % 5 == 0)
			printf("\n");
			Temp = Temp->next;
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++;
		}
		printf("\n\n");
		printf("���������%d����ǰ��ʾ�Ľ������%d\n\n",NodeNum, n);
	}
}


//��    �ܣ���������д���ļ�
//��ڲ������ļ�ָ�룬���ͷָ�� 
//��    �أ��� 
void listToFile(FILE *File, Node *Head)
{
	int t = 0;    //�������б��� 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(t % 5 == 0)     //һ������5������ʱ���� 
			fprintf(File, "\n");
		Temp = Temp->next;
		fprintf(File, "%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
		t++; 
	}
}


//��    �ܣ��жϴ�С�� 
//��ڲ������·� 
//��    �أ���С�»���� 
int isMonth(int m)   
{
	if((m == 1) || (m == 3) || (m == 5) || (m == 7) ||
	   (m == 8) || (m == 10) || (m == 12))
		return 1;        //����1Ϊ���� 
	if((m == 4)||(m == 6)||(m == 9)||(m == 11))
		return 3;        //����3ΪС�� 
	if(m == 2)
		return 2;		 //����2Ϊ���� 
}


//��    �ܣ��ж����� 
//��ڲ�������� 
//��    �أ��Ƿ�Ϊ���� 
int LeapYear(int y)    
{
	if((y % 4 == 0)&&(y % 100 != 0)||(y % 400 == 0))
		return 1;		//����1Ϊ���� 
	else 
		return 0;		//����0��Ϊ���� 
}


//��    �ܣ��жϲ��Ϸ����� 
//��ڲ������꣬�£��� 
//��    �أ��Ƿ�Ϊ�Ϸ����� 
int ErrorDate(int year, int month, int day)
{
	if(((month == 4)||(month == 6)||(month == 9)||(month == 11)) && (day == 31))
		return 1;		//����1Ϊ���Ϸ����� 
	else if((LeapYear(year) == 1) && (month == 2) && (day > 29))
		return 1;
	else if((LeapYear(year) == 0) && (month == 2) && (day > 28))
		return 1;
	else 
		return 0;		//����0Ϊ�Ϸ����� 
}


//��    �ܣ���ʾ�����Ϸ�����
//��ڲ������� 
//��    �أ��� 
void ShowErrorDate()
{
	int Sum = 0, t = 0;   //Sum����ͳ�Ʋ��Ϸ����ڸ�����tΪ���б��� 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(ErrorDate(Temp->year, Temp->month, Temp->day)) 
		{
			if(t % 5 == 0)     //һ������5������ʱ���� 
				printf("\n");
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++;
			Sum++;
		}
		Temp = Temp->next;	
	}
	printf("\n\n���ܹ��ɺϷ���������Ϊ��%d\n\n",Sum);
}


//��    �ܣ�������ʾȫ������
//��ڲ������ܽ���� 
//��    �أ��� 
void MultiPartShowList(int NodeNum)
{
	int i, t = 0, RowNum = 1;    //tΪ���б���,RowNumΪ�к� 
	Node *Temp = Head;
	for(i = 1; i <= NodeNum; i++)
	{
		if(t % 5 == 0)     //һ������5������ʱ���� 
		{
			printf("\n");
			printf("%6d��",RowNum++);
		}
		Temp = Temp->next;
		printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
		t++;
		if(i % 125 == 0)
		{
			printf("\n\n�밴�������ʾ��һҳ......\n\n");
			getch();
		}
	}
	printf("\n\n");
}


//��    �ܣ�ɾ��ͷ���
//��ڲ������ܽ���� 
//��    �أ��� 
void DeleteFirstNode(int & NodeNum)
{
	Node *Temp;
	Temp = Head;
	free(Temp);
	Head = Head->next;
	NodeNum--;
}


//��    �ܣ�ɾ��β���
//��ڲ������ܽ���� 
//��    �أ��� 
void DeleteLastNode(int & NodeNum)
{
	Node *Temp = Head;
	Node *PreNode;     //����ǰ����� 
	while(Temp->next != NULL)
	{
		PreNode = Temp;
		Temp = Temp->next;
	}
	PreNode->next = NULL;
	free(Temp);
	NodeNum--;
}


//��    �ܣ�ɾ���Ƿ����ڽ��
//��ڲ������ܽ���� 
//��    �أ��� 
void DeleteErrorNode(int & NodeNum)
{
	int Sum = 0;      //����cnt���ڼ�¼���Ϸ������� 
	Node *Temp = Head;
	Node *PreNode;      //����ǰ����� 
	while(Temp->next != NULL)
	{
		if(ErrorDate(Temp->year, Temp->month, Temp->day))
		{
			PreNode->next = Temp->next;
			free(Temp);
			Temp = PreNode->next;
			Sum++; 
		}
		else
		{
			PreNode = Temp;
			Temp = Temp->next;
		}	
	}
	printf("\n��ɾ��%d�����Ϸ������ڽ�㡣\n\n", Sum);
	NodeNum -= Sum;
}


//��    �ܣ�����ǰ���ڴ�����
//��ڲ�����������ָ�� 
//��    �أ��� 
void CurrentNode(Node *Temp)
{
	time_t CurrentTime;       //��ȡ��ǰ���� 
    struct tm *Date;
 	time(& CurrentTime);
    Date = localtime(& CurrentTime);
    Temp->year = Date->tm_year + 1900;    //����ǰ���ڴ����� 
	Temp->month = Date->tm_mon + 1;
	Temp->day = Date->tm_mday;
} 


//��    �ܣ����뵱ǰ���ڽ�㵽��ͷ
//��ڲ������ܽ���� 
//��    �أ��� 
void InsertFirstNode(int & NodeNum)
{
	Node *Temp;
	Temp = (Node *)malloc(sizeof(Node));
	CurrentNode(Temp);    //����ǰ���ڴ����� 
	Temp->next = Head->next; 
	Head->next = Temp;
	NodeNum++;      //����������һ 
}


//��    �ܣ����뵱ǰ���ڽ�㵽��β
//��ڲ������ܽ���� 
//��    �أ��� 
void InsertLastNode(int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode;     //�����ݴ��� 
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);    //����ǰ���ڴ����ݴ��� 
	while(Temp->next != NULL)
		Temp = Temp->next;
	Temp->next = tNode;
	tNode->next = NULL;
	NodeNum++;	    //����������һ 
}


//��    �ܣ����뵱ǰ���ڽ�㵽��һ�����ڸý�����ڵ�ǰ��
//��ڲ������Ƿ����ɹ����ж�ֵ���ܽ���� 
//��    �أ��� 
void InsertNodeToBig(int & Judge, int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode, *PreNode = Temp;    //�����ݴ����ǰ�����  
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);       //����ǰ���ڴ����ݴ��� 
	while(Temp->next != NULL)
	{
		if( (Temp->year > tNode->year)   ||       //�ж���ݴ�С 
			((Temp->year == tNode->year) && (Temp->month > tNode->month)) ||     //�ж��·ݴ�С 
			((Temp->year == tNode->year) && (Temp->month == tNode->month)  && (Temp->day > tNode->day)))   //�ж����ڴ�С 
		{
			tNode->next = PreNode->next;
			PreNode->next = tNode;
			NodeNum++;     //����������һ 
			Judge++;       //����ɹ� 
			break;
		}		
		else  //������� 
		{
			PreNode = Temp; 
			Temp = Temp->next;
		}
	} 
}


//��    �ܣ����뵱ǰ���ڽ�㵽��һ��С�ڸý�����ڵĺ���
//��ڲ����������Ƿ�ɹ����ж�ֵ���ܽ���� 
//��    �أ��� 
void InsertNodeToSmall(int & Judge, int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode;       //�����ݴ���
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);       //����ǰ���ڴ����ݴ��� 
	while(Temp->next != NULL)
	{
		if( (Temp->year < tNode->year)   ||       //�ж���ݴ�С 
			((Temp->year == tNode->year) && (Temp->month < tNode->month)) ||     //�ж��·ݴ�С 
			((Temp->year == tNode->year) && (Temp->month == tNode->month)  && (Temp->day < tNode->day)) )   //�ж����ڴ�С 
		{
			tNode->next = Temp->next;
			Temp->next = tNode;
			NodeNum++;     //����������һ 
			Judge++;       //����ɹ� 
			break;
		}		
		else    //������� 
		{
			Temp = Temp->next;
		}
	} 
}


//��    �ܣ�������һ���������Ԫ���м���
//��ڲ������꣬�£��� 
//��    �أ����� 
int DayNum(int year,int month,int day)   
{
	int i, Sum = 0;      //Sum�����洢���� 
	for(i = 1; i < month; i++)
	{
		if(isMonth(i) == 1)
			Sum += 31;
		if(isMonth(i) == 2)
		{
			if(LeapYear(year) == 1)
				Sum += 29;
			else 
				Sum += 28;
		}
		if(isMonth(i) == 3)
			Sum += 30;
	}
	Sum += day;
	
	return Sum;
} 


//��    �ܣ���������ھ��� 1900.1.1������ 
//��ڲ������꣬�£��� 
//��    �أ����� 
int DateDiffer(int year, int month, int day)
{
	int i, Sum = 0;     //Sum�����洢���� 
	for(i = 1900; i < year; i++)   //ÿ���365����366 
	{
		if(LeapYear(i) == 1)
			Sum += 366;
		else 
			Sum += 365;
	}
	Sum += DayNum(year, month, day);    //���һ�����ּ�Ŀ�����ڵ�����Ԫ���ľ������� 
		
	return Sum - 1;
}


//��    �ܣ���ʾ����ÿ���������ھ���1900��1��1�յ�����
//��ڲ�����ָ���ڵ��� 
//��    �أ��� 
void ShowNodeDateDiffer(int n, int NodeNum)
{
	int t = 0;    //�������б��� 
	Node *Temp;
	if((n < 0)||(n > NodeNum))      //�Դ���������ж� 
	{
		printf("\n������������...\n\n");
	}
	else
	{
		int temp = n;
		Temp = Head;
		while(temp--)
		{
			if(t % 10 == 0)      //һ������10������ʱ���� 
				printf("\n");
			Temp = Temp->next;
			printf("%6d   ", DateDiffer(Temp->year, Temp->month, Temp->day));
			t++;
		}
		printf("\n\n");
		printf("���������%d����ǰ��ʾ�Ľ������%d\n\n",NodeNum, n);
	}
 } 
 
 
//��    �ܣ���������
//��ڲ������� 
//��    �أ���
void ListSort()
{
	int cnt, temp;     //����cnt���ڼ�¼�������һ��ʱ������Ĵ��� ,temp���ڽ�������ֵ 
	Node *Temp, *PreNode;
	do
	{	
		cnt = 0, temp = 0;
		Temp = Head->next;
		PreNode = Head;
		while(Temp != NULL)
		{
			if( (Temp->year < PreNode->year)   ||       //�ж���ݴ�С 
				((Temp->year == PreNode->year) && (Temp->month < PreNode->month)) ||     //�ж��·ݴ�С 
				((Temp->year == PreNode->year) && (Temp->month == PreNode->month)  && (Temp->day < PreNode->day)))   //�ж����ڴ�С 
			{
				temp = PreNode->year;    PreNode->year = Temp->year;     Temp->year = temp;      //��ݽ���
				temp = PreNode->month;   PreNode->month = Temp->month;   Temp->month = temp;     //�·ݽ���
				temp = PreNode->day;     PreNode->day = Temp->day;       Temp->day = temp;       //���ڽ���
				cnt++; 
			}		
			PreNode = Temp; 
			Temp = Temp->next;
		}
	} while(cnt != 0);
}


//��    �ܣ��ж����� 
//��ڲ�����һ����������
//��    �أ��Ƿ�Ϊ���� 
int isPrime(int Num)
{
	int i, sum = 0;
	for(i = 1; i <= sqrt(Num); i++)
	{
		if(Num % i == 0)
			sum++;
	}
	if((sum == 1) && (Num != 1))
		return 1;
	else
		return 0;
} 


//��    �ܣ����������ն��������Ľ�� 
//��ڲ������� 
//��    �أ���
void FindPrimeNode()
{
	int Sum = 0, t = 0;   //Sum����ͳ���������ڸ�����tΪ���б��� 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(isPrime(Temp->year) && isPrime(Temp->month) && isPrime(Temp->day)) 
		{
			if(t % 5 == 0)     //һ������5������ʱ���� 
				printf("\n");
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++;
			Sum++;
		}
		Temp = Temp->next;	
	}
	printf("\n\n��%d�������ն��������Ľ�㡣\n\n",Sum);
}


//��    �ܣ���ת���� 
//��ڲ������� 
//��    �أ���
void ReverseList()
{
	Node *newHead = NULL;     //����һ���µ�ͷָ�� 
	Node *node, *Temp = Head;     //����һ��"��ʱ��תվ"
	Temp = Temp->next;
	while (Temp != NULL) {
		//��֮ǰ��������ͷɾ
		node = Temp;
		Temp = Temp->next;
		
		//����������ͷ��
		node->next = newHead;
		newHead = node;
	}
	Head->next = newHead;     //���µ�ͷָ��ش���ԭ����ͷָ�� 
}


#endif 

