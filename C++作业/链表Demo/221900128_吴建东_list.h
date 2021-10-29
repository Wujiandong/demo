#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

#ifndef HEADER_FILE
#define HEADER_FILE


//功    能：显示版权信息
//入口参数：无 
//返    回：无 
void Copyright()
{
	printf("Copyright (c) 2020 吴建东(221900128). All Rights Reserved.\n\n");
}


//功    能：显示系统日期、时间 
//入口参数：无 
//返    回：无 
void SystemTime()
{
	time_t CurrentTime; 
    struct tm *Date;
 	time(&CurrentTime);
    Date = localtime(&CurrentTime);
    printf("当前日期、时间 : %02d-%02d-%02d ",
            Date->tm_year + 1900, Date->tm_mon + 1, Date->tm_mday);
    switch(Date->tm_wday)
	{
		case 0 : printf("(星期日)"); break; 
		case 1 : printf("(星期一)"); break; 
		case 2 : printf("(星期二)"); break; 
		case 3 : printf("(星期三)"); break; 
		case 4 : printf("(星期四)"); break; 
		case 5 : printf("(星期五)"); break; 
		case 6 : printf("(星期六)"); break; 
	}
	printf("    %02d:%02d:%02d\n",Date->tm_hour, Date->tm_min, Date->tm_sec);
}


//功    能：显示菜单界面 
//入口参数：无 
//返    回：无 
void Menu()
{
	printf("*********************************"
	  	   "********************************\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t   链表Demo程序系统菜单  \t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*\tA；创建一个存放日期数据的(无序)链表\t\t\t*\n");
	printf("*\tB；显示链表前几个节点的日期数据\t\t\t\t*\n");
	printf("*\tC；将整个链表的所有数据存入文件中\t\t\t*\n");
	printf("*\tD；分屏显示日期数据文件的(全部)内容\t\t\t*\n");
	printf("*\tE；显示不能构成合法日期的(所有)结点\t\t\t*\n");
	printf("*\tF；删除链表的第一个、最后一个、不能构成合法日期的结点\t*\n");
	printf("*\tG；插入结点(至链头、链尾、结点之前、结点之后)\t\t*\n");
	printf("*\tH；显示结点的日期对应的天数\t\t\t\t*\n");
	printf("*\tI；链表按日期从小到大排序\t\t\t\t*\n");
	printf("*\tJ；查找链表中\"年月日\"都是素数的结点\t\t\t*\n");
	printf("*\tK；(单向)链表翻转\t\t\t\t\t*\n");
	printf("*\tL；退出系统\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n");
	printf("*********************************"
	  	   "********************************\n");
}


//定义链表结构体
typedef struct Node     
{  
    int year;           //单链表中的数据域   
	int month;
	int day;      
    struct Node *next;  //单链表的指针域   
}Node;


Node *Head = NULL;      //声明头结点和尾结点 
Node *End = NULL;


//功    能：释放链表 
//入口参数：链表头结点指针 
//返    回：无 
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


//功    能：建立链表
//入口参数：结点数 
//返    回：结点数 
void BuildList(int NodeNum)
{
	if(Head != NULL)     //如果已存在链表，则释放链表 
	{
		FreeList(Head);
		printf("\n已释放旧链表。准备创建新链表....\n");
	}
	Head = (Node *)malloc(sizeof(Node));
	if (Head == NULL)    //对内存申请失败进行的处理 
	{ 
		printf("\n分配失败, 程序终止!\n\n");     
		exit(-1);
	}
	End = Head;
	for(int i = 0; i < NodeNum; i++)
	{
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->year = rand() % 121 + 1900;    //为年份设置随机数 
		p->month = rand() % 12 + 1;       //为月份设置随机数 
		p->day = rand() % 31 + 1;		  //为日期设置随机数 
		End->next = p;
		End = p;
	}
	End->next = NULL;
}


//功    能：打印链表数据
//入口参数：指定结点数，总结点数 
//返    回：无 
void ShowList(int n, int NodeNum)    
{
	int t = 0;    //声明换行变量 
	Node *Temp;
	if((n < 0)||(n > NodeNum))      //对错误个数的判断 
	{
		printf("\n输入数字有误...\n\n");
	}
	else if((n == 0)||(n == NodeNum))  //输出链表全部数据 
	{	
		n = NodeNum; 
		Temp = Head;
		while(Temp->next != NULL)
		{
			if(t % 5 == 0)     //一行输入5个日期时换行 
				printf("\n");
			Temp = Temp->next;
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++; 
		}
		printf("\n\n");
		printf("结点总数：%d，当前显示的结点数：%d\n\n",NodeNum, NodeNum);
	}
	else    //输出指定个数的数据 
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
		printf("结点总数：%d，当前显示的结点数：%d\n\n",NodeNum, n);
	}
}


//功    能：链表数据写入文件
//入口参数：文件指针，结点头指针 
//返    回：无 
void listToFile(FILE *File, Node *Head)
{
	int t = 0;    //声明换行变量 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(t % 5 == 0)     //一行输入5个日期时换行 
			fprintf(File, "\n");
		Temp = Temp->next;
		fprintf(File, "%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
		t++; 
	}
}


//功    能：判断大小月 
//入口参数：月份 
//返    回：大小月或二月 
int isMonth(int m)   
{
	if((m == 1) || (m == 3) || (m == 5) || (m == 7) ||
	   (m == 8) || (m == 10) || (m == 12))
		return 1;        //返回1为大月 
	if((m == 4)||(m == 6)||(m == 9)||(m == 11))
		return 3;        //返回3为小月 
	if(m == 2)
		return 2;		 //返回2为二月 
}


//功    能：判断闰年 
//入口参数：年份 
//返    回：是否为闰年 
int LeapYear(int y)    
{
	if((y % 4 == 0)&&(y % 100 != 0)||(y % 400 == 0))
		return 1;		//返回1为闰年 
	else 
		return 0;		//返回0不为闰年 
}


//功    能：判断不合法日期 
//入口参数：年，月，日 
//返    回：是否为合法日期 
int ErrorDate(int year, int month, int day)
{
	if(((month == 4)||(month == 6)||(month == 9)||(month == 11)) && (day == 31))
		return 1;		//返回1为不合法日期 
	else if((LeapYear(year) == 1) && (month == 2) && (day > 29))
		return 1;
	else if((LeapYear(year) == 0) && (month == 2) && (day > 28))
		return 1;
	else 
		return 0;		//返回0为合法日期 
}


//功    能：显示出不合法日期
//入口参数：无 
//返    回：无 
void ShowErrorDate()
{
	int Sum = 0, t = 0;   //Sum用于统计不合法日期个数，t为换行变量 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(ErrorDate(Temp->year, Temp->month, Temp->day)) 
		{
			if(t % 5 == 0)     //一行输入5个日期时换行 
				printf("\n");
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++;
			Sum++;
		}
		Temp = Temp->next;	
	}
	printf("\n\n不能构成合法日期总数为：%d\n\n",Sum);
}


//功    能：分屏显示全部内容
//入口参数：总结点数 
//返    回：无 
void MultiPartShowList(int NodeNum)
{
	int i, t = 0, RowNum = 1;    //t为换行变量,RowNum为行号 
	Node *Temp = Head;
	for(i = 1; i <= NodeNum; i++)
	{
		if(t % 5 == 0)     //一行输入5个日期时换行 
		{
			printf("\n");
			printf("%6d：",RowNum++);
		}
		Temp = Temp->next;
		printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
		t++;
		if(i % 125 == 0)
		{
			printf("\n\n请按任意键显示下一页......\n\n");
			getch();
		}
	}
	printf("\n\n");
}


//功    能：删除头结点
//入口参数：总结点数 
//返    回：无 
void DeleteFirstNode(int & NodeNum)
{
	Node *Temp;
	Temp = Head;
	free(Temp);
	Head = Head->next;
	NodeNum--;
}


//功    能：删除尾结点
//入口参数：总结点数 
//返    回：无 
void DeleteLastNode(int & NodeNum)
{
	Node *Temp = Head;
	Node *PreNode;     //声明前驱结点 
	while(Temp->next != NULL)
	{
		PreNode = Temp;
		Temp = Temp->next;
	}
	PreNode->next = NULL;
	free(Temp);
	NodeNum--;
}


//功    能：删除非法日期结点
//入口参数：总结点数 
//返    回：无 
void DeleteErrorNode(int & NodeNum)
{
	int Sum = 0;      //声明cnt用于记录不合法日期数 
	Node *Temp = Head;
	Node *PreNode;      //声明前驱结点 
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
	printf("\n已删除%d个不合法的日期结点。\n\n", Sum);
	NodeNum -= Sum;
}


//功    能：将当前日期存入结点
//入口参数：链表结点指针 
//返    回：无 
void CurrentNode(Node *Temp)
{
	time_t CurrentTime;       //读取当前日期 
    struct tm *Date;
 	time(& CurrentTime);
    Date = localtime(& CurrentTime);
    Temp->year = Date->tm_year + 1900;    //将当前日期存入结点 
	Temp->month = Date->tm_mon + 1;
	Temp->day = Date->tm_mday;
} 


//功    能：插入当前日期结点到链头
//入口参数：总结点数 
//返    回：无 
void InsertFirstNode(int & NodeNum)
{
	Node *Temp;
	Temp = (Node *)malloc(sizeof(Node));
	CurrentNode(Temp);    //将当前日期存入结点 
	Temp->next = Head->next; 
	Head->next = Temp;
	NodeNum++;      //链表结点数加一 
}


//功    能：插入当前日期结点到链尾
//入口参数：总结点数 
//返    回：无 
void InsertLastNode(int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode;     //声明暂存结点 
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);    //将当前日期存入暂存结点 
	while(Temp->next != NULL)
		Temp = Temp->next;
	Temp->next = tNode;
	tNode->next = NULL;
	NodeNum++;	    //链表结点数加一 
}


//功    能：插入当前日期结点到第一个大于该结点日期的前面
//入口参数：是否插入成功的判断值，总结点数 
//返    回：无 
void InsertNodeToBig(int & Judge, int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode, *PreNode = Temp;    //声明暂存结点和前驱结点  
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);       //将当前日期存入暂存结点 
	while(Temp->next != NULL)
	{
		if( (Temp->year > tNode->year)   ||       //判断年份大小 
			((Temp->year == tNode->year) && (Temp->month > tNode->month)) ||     //判断月份大小 
			((Temp->year == tNode->year) && (Temp->month == tNode->month)  && (Temp->day > tNode->day)))   //判断日期大小 
		{
			tNode->next = PreNode->next;
			PreNode->next = tNode;
			NodeNum++;     //链表结点数加一 
			Judge++;       //插入成功 
			break;
		}		
		else  //链表遍历 
		{
			PreNode = Temp; 
			Temp = Temp->next;
		}
	} 
}


//功    能：插入当前日期结点到第一个小于该结点日期的后面
//入口参数：插入是否成功的判断值，总结点数 
//返    回：无 
void InsertNodeToSmall(int & Judge, int & NodeNum)
{
	Node *Temp = Head;
	Node *tNode;       //声明暂存结点
	tNode = (Node *)malloc(sizeof(Node));      
	CurrentNode(tNode);       //将当前日期存入暂存结点 
	while(Temp->next != NULL)
	{
		if( (Temp->year < tNode->year)   ||       //判断年份大小 
			((Temp->year == tNode->year) && (Temp->month < tNode->month)) ||     //判断月份大小 
			((Temp->year == tNode->year) && (Temp->month == tNode->month)  && (Temp->day < tNode->day)) )   //判断日期大小 
		{
			tNode->next = Temp->next;
			Temp->next = tNode;
			NodeNum++;     //链表结点数加一 
			Judge++;       //插入成功 
			break;
		}		
		else    //链表遍历 
		{
			Temp = Temp->next;
		}
	} 
}


//功    能：计算这一天距离这年元旦有几天
//入口参数：年，月，日 
//返    回：天数 
int DayNum(int year,int month,int day)   
{
	int i, Sum = 0;      //Sum用来存储日期 
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


//功    能：计算该日期距离 1900.1.1的天数 
//入口参数：年，月，日 
//返    回：天数 
int DateDiffer(int year, int month, int day)
{
	int i, Sum = 0;     //Sum用来存储日期 
	for(i = 1900; i < year; i++)   //每年加365或者366 
	{
		if(LeapYear(i) == 1)
			Sum += 366;
		else 
			Sum += 365;
	}
	Sum += DayNum(year, month, day);    //最后一个部分加目标日期到该年元旦的距离天数 
		
	return Sum - 1;
}


//功    能：显示链表每个结点的日期距离1900年1月1日的天数
//入口参数：指定节点数 
//返    回：无 
void ShowNodeDateDiffer(int n, int NodeNum)
{
	int t = 0;    //声明换行变量 
	Node *Temp;
	if((n < 0)||(n > NodeNum))      //对错误个数的判断 
	{
		printf("\n输入数字有误...\n\n");
	}
	else
	{
		int temp = n;
		Temp = Head;
		while(temp--)
		{
			if(t % 10 == 0)      //一行输入10个日期时换行 
				printf("\n");
			Temp = Temp->next;
			printf("%6d   ", DateDiffer(Temp->year, Temp->month, Temp->day));
			t++;
		}
		printf("\n\n");
		printf("结点总数：%d，当前显示的结点数：%d\n\n",NodeNum, n);
	}
 } 
 
 
//功    能：链表排序
//入口参数：无 
//返    回：无
void ListSort()
{
	int cnt, temp;     //声明cnt用于记录链表遍历一次时，排序的次数 ,temp用于交换日期值 
	Node *Temp, *PreNode;
	do
	{	
		cnt = 0, temp = 0;
		Temp = Head->next;
		PreNode = Head;
		while(Temp != NULL)
		{
			if( (Temp->year < PreNode->year)   ||       //判断年份大小 
				((Temp->year == PreNode->year) && (Temp->month < PreNode->month)) ||     //判断月份大小 
				((Temp->year == PreNode->year) && (Temp->month == PreNode->month)  && (Temp->day < PreNode->day)))   //判断日期大小 
			{
				temp = PreNode->year;    PreNode->year = Temp->year;     Temp->year = temp;      //年份交换
				temp = PreNode->month;   PreNode->month = Temp->month;   Temp->month = temp;     //月份交换
				temp = PreNode->day;     PreNode->day = Temp->day;       Temp->day = temp;       //日期交换
				cnt++; 
			}		
			PreNode = Temp; 
			Temp = Temp->next;
		}
	} while(cnt != 0);
}


//功    能：判断素数 
//入口参数：一个整型数字
//返    回：是否为素数 
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


//功    能：查找年月日都是素数的结点 
//入口参数：无 
//返    回：无
void FindPrimeNode()
{
	int Sum = 0, t = 0;   //Sum用于统计素数日期个数，t为换行变量 
	Node *Temp = Head;
	while(Temp->next != NULL)
	{
		if(isPrime(Temp->year) && isPrime(Temp->month) && isPrime(Temp->day)) 
		{
			if(t % 5 == 0)     //一行输入5个日期时换行 
				printf("\n");
			printf("%04d.%02d.%02d    ", Temp->year, Temp->month, Temp->day);
			t++;
			Sum++;
		}
		Temp = Temp->next;	
	}
	printf("\n\n有%d个年月日都是素数的结点。\n\n",Sum);
}


//功    能：翻转链表 
//入口参数：无 
//返    回：无
void ReverseList()
{
	Node *newHead = NULL;     //建立一个新的头指针 
	Node *node, *Temp = Head;     //建立一个"临时中转站"
	Temp = Temp->next;
	while (Temp != NULL) {
		//对之前的链表做头删
		node = Temp;
		Temp = Temp->next;
		
		//对新链表做头插
		node->next = newHead;
		newHead = node;
	}
	Head->next = newHead;     //将新的头指针回传给原来的头指针 
}


#endif 

