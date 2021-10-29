#include "221900128_吴建东_student.h" 

//功    能：显示版权信息
//入口参数：无 
//返    回：无 
void Copyright()
{
	printf("Copyright (c) 2020 吴建东(221900128). All Rights Reserved.\n\n");
}


//功    能：显示菜单界面 
//入口参数：无 
//返    回：无 
void Menu()
{
	printf("*****************************"
	  	   "****************************\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*\t\t   学生信息管理系统菜单  \t\t*\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*\t\t    A；录入学生信息\t\t\t*\n");
	printf("*\t\t    B；增加学生信息\t\t\t*\n");
	printf("*\t\t    C；删除学生信息\t\t\t*\n");
	printf("*\t\t    D；更改学生信息\t\t\t*\n");
	printf("*\t\t    E；查询学生信息\t\t\t*\n");
	printf("*\t\t    F；学生人数统计\t\t\t*\n");
	printf("*\t\t    G；学生信息排序\t\t\t*\n");
	printf("*\t\t    H；显示学生信息\t\t\t*\n");
	printf("*\t\t    I；保存学生信息\t\t\t*\n");
	printf("*\t\t    J；退出系统\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*****************************"
	  	   "****************************\n");
}


//声明头结点和尾结点 
StuData *Head = NULL;
StuData *End = NULL;


//功    能：字符串数字转换成整型数字
//入口参数：字符串 
//返    回：对应的整型数字 
int ChToNum(char str[])
{
	int i, n, num = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] -'0';	
	}
	return num;
}

int MaxNum = 0, MaxCountry = 0, MaxNation = 0, MaxMarry = 0,   MaxFace = 0;    	//声明各数组的最大值 

int MaxID = 0,  MaxType = 0,    MaxWay = 0,    MaxCollege = 0, MaxTeacher = 0;	//声明各数组的最大值 

char strNum[50][10]; 		//创建一个二维数组用来存取学院代码 

char strCountry[200][25]; 	//创建一个二维数组用来存取国家名称

char strNation[60][20];		//创建一个二维数组用来存取民族名称
 
char strMarry[10][10];		//创建一个二维数组用来存取婚姻状况

char strFace[15][30];		//创建一个二维数组用来存取政治面貌

char strID[3600][7];		//创建一个二维数组用来存取行政区号 

char strType[15][30];		//创建一个二维数组用来存取学生类别

char strWay[15][30];		//创建一个二维数组用来存取入学方式

char strCollege[40][10][30];//创建一个三维数组用来存取学院专业

char strTeacher[40][5][30];	//创建一个三维数组用来存取辅导员名


//功    能：将文件内容写入对应数组 
//入口参数：各数组的最大值 
//返    回：无 
void FileToArray( int &MaxNum, int &MaxCountry, int &MaxNation, int &MaxMarry,   int &MaxFace, 
                  int &MaxID,  int &MaxType,    int &MaxWay,    int &MaxCollege, int &MaxTeacher  )
{
	char ch[50]; 
	FILE *Num = fopen("221900128_吴建东_学院代码表.txt", "r");   //打开文件
	while( !feof(Num) )
	{
		fscanf(Num, "%s%s", strNum[MaxNum], ch);  //读取一行
		MaxNum++;
	}
											
	FILE *Country = fopen("221900128_吴建东_国家名称表.txt", "r");   
	while( ! feof(Country) )    
   	{
       	fscanf(Country, "%s\n", strCountry[MaxCountry]);
       	MaxCountry++;
    }
    									
	FILE *Nation = fopen("221900128_吴建东_民族表.txt", "r");  
	while( !feof(Nation) )       
    {
		fscanf(Nation, "%s", strNation[MaxNation]);
		MaxNation++;
    }
    								
	FILE *Marry = fopen("221900128_吴建东_婚姻状况表.txt", "r");
	while( !feof(Marry) )
	{
		fscanf(Marry, "%s", strMarry[MaxMarry]);
		MaxMarry++;
	}
    										
	FILE *Face = fopen("221900128_吴建东_政治面貌表.txt", "r");
	while( !feof(Face) )
    {
		fscanf(Face, "%s", strFace[MaxFace]);  
 		MaxFace++;
    }
										    
	FILE *ID = fopen("221900128_吴建东_行政区号表.txt", "r");
	while( !feof(ID) )
    {
		fscanf(ID, "%s", strID[MaxID]);  
		MaxID++; 
    }
    									
	FILE *Type = fopen("221900128_吴建东_学生类别表.txt", "r");
	while( !feof(Type) ) 
    {
		fscanf(Type, "%s", strType[MaxType]); 
		MaxType++;
    }
    										
	FILE *Way = fopen("221900128_吴建东_入学方式表.txt", "r");
	while( !feof(Way) )  
    {
		fscanf(Way, "%s", strWay[MaxWay]);
		MaxWay++;
    }
    								
	FILE *College = fopen("221900128_吴建东_学院专业名称表.txt", "r");
	while( !feof(College) )
    {
		fscanf(College, "%s%s%s%s%s%s", strCollege[MaxCollege][0], strCollege[MaxCollege][1], strCollege[MaxCollege][2],
										strCollege[MaxCollege][3], strCollege[MaxCollege][4], strCollege[MaxCollege][5] );
		MaxCollege++;
    }
    								
	FILE *Teacher = fopen("221900128_吴建东_辅导员信息表.txt", "r");
	while( !feof(Teacher) ) 
    {
		fscanf(Teacher, "%s%s", strTeacher[MaxTeacher][0], strTeacher[MaxTeacher][1]);
		MaxTeacher++;
    }
    
} 

//功    能：检验学号 
//入口参数：学号字符串 ，学院代码数组  ， 学生个数 
//返    回：0 或 1 
int CheckStuID(char *StudentID, char strNum[][10], int NodeNum)
{
	if(strlen(StudentID) != 9)
	{
		printf("学号长度错误。"); 
		return 0;
	}
	for(int i = 0; i < 9; i++)
	{
		if( !isdigit(StudentID[i]))
		{
			printf("学号出现非数字字符。"); 
			return 0;
		}
	}
	
	//检验重复学号 
	if(NodeNum != 0)
	{
		StuData *Temp = Head->next;
		while(Temp != NULL)
		{
			if(!strcmp(Temp->StudentID, StudentID))
			{
				printf("学号出现重复。"); 
				return 0;
			}
			Temp = Temp->next;	
		}
	}
	
	//检验与当前日期是否一致
	time_t CurrentTime; 
    struct tm *NowDate;
 	time(&CurrentTime);
    NowDate = localtime(&CurrentTime); 
    int year =  NowDate->tm_year - 100;
    if((StudentID[2] - '0') * 10 + (StudentID[3] - '0') > 20 )
    {
		printf("入学年份有误。"); 
		return 0;
	}
	else if(StudentID[2] != (char)(year / 10 + '0') || StudentID[3] != (char)(year % 10 + '0') ) 
	{
		printf("入学年份与当前日期年份不一致。"); 
	}
	
	//检验学院代码 
	for(int j = 0; j < 50; j++)
	{
		if(strNum[j][0] == StudentID[0] && strNum[j][1] == StudentID[1])
			return 1;
	}
	printf("学院代码有误。"); 
	return 0;
}

//功    能：检验姓名 
//入口参数：姓名字符串 , 国家代码 
//返    回：0 或 1 
int CheckName(char *Name, int country)
{
	int k = 0;
	if(country == 1)
	{
		for(int i = 0; i < strlen(Name); i++)
		{
			if(Name[i] > 0)
				k++;
		}
		if(k != 0)
		{
			printf("姓名出现非汉字字符。"); 
			return 0;
		}
		else if(strlen(Name) < 4 || strlen(Name) > 40)
		{
			printf("姓名不在2~20个汉字之间。"); 
			return 0; 
		}
		else
			return 1;		
	}
	else
	{
		for(int i = 0; i < strlen(Name); i++)
		{
			if(!isalpha(Name[i]))
				k++;
		}
		if(k == 0 && strlen(Name) <= 40)
			return 1;
		else
			return 0;
	}
		
}


//功    能：检验身份证号 
//入口参数：身份证号字符串,日期，性别，行政区号数组，数组长度，学生个数 
//返    回：0 或 1 
int CheckID(char *ID, char *Date, char *sex, char AreaCode[][7], int len, int NodeNum)
{
	int i, judge = 0;
	
	//判断长度是否为18 
	if(strlen(ID) != 18)
	{
		printf("身份证号位数不足18位。");
		return 0;
	}
		
	
	//判断前17个字符是否为数字	
	for(i = 0;i < 17; i++)
	{
		if( ! isdigit(ID[i]) )
		{
			printf("身份证号中出现非数字字符。"); 
			return 0;
		}	
	}	
	
	//判断是否有重复身份证号 
	if(NodeNum != 0)
	{
		StuData *Temp = Head->next;
		while(Temp != NULL)
		{
			if(!strcmp(Temp->idNumber, ID))
			{
				printf("身份证号出现重复。"); 
				return 0;
			}
			Temp = Temp->next;	
		}
	}
	
	//判断行政区划是否合法 
	for(i = 0; i < len; i++)
	{
		if(AreaCode[i][0] == ID[0] && AreaCode[i][1] == ID[1] && AreaCode[i][2] == ID[2] && 
		   AreaCode[i][3] == ID[3] && AreaCode[i][4] == ID[4] && AreaCode[i][5] == ID[5]  )
		{
			judge++;
		}
	}
	if(judge != 1)
	{
		printf("行政区划不合法。"); 
		return 0;
	}	
	
	//判断身份证日期是否和出生日期一致
	if( ID[6]  != Date[0] || ID[7]  != Date[1] || ID[8]  != Date[2] || ID[9]  != Date[3] ||
	    ID[10] != Date[5] || ID[11] != Date[6] || ID[12] != Date[8] || ID[13] != Date[9]  )
	{
		printf("身份证日期和出生日期不一致。");
		return 0;
	}
	
	//判断身份证性别是否和输入性别一致
	if(!strcmp(sex, "男"))
	{
		i = ID[16] - '0';
		if(i % 2 == 0)
		{
			printf("身份证性别和输入性别不一致。"); 
			return 0;
		}	
	}
	if(!strcmp(sex, "女"))
	{
		i = ID[16] - '0';
		if(i % 2 != 0)
		{
			printf("身份证性别和输入性别不一致。");
			return 0;
		}
	} 
	
	//判断校验码是否合法
	int sum;
	char ch;
	sum = (ID[0]  -'0') * 7 + (ID[1]  -'0') * 9 + (ID[2]  -'0') *  10 + (ID[3]  -'0') * 5 + (ID[4]  -'0') * 8 + 
		  (ID[5]  -'0') * 4 + (ID[6]  -'0') * 2 + (ID[7]  -'0') *  1  + (ID[8]  -'0') * 6 + (ID[9]  -'0') * 3 + 
		  (ID[10] -'0') * 7 + (ID[11] -'0') * 9 + (ID[12] -'0') *  10 + (ID[13] -'0') * 5 + (ID[14] -'0') * 8 + 
		  (ID[15] -'0') * 4 + (ID[16] -'0') * 2 ;
	if(sum % 11 == 0)
		ch = '1';
	if(sum % 11 == 1)
		ch = '0';
	if(sum % 11 == 2)
		ch = 'X';
	if(sum % 11 == 3)
		ch = '9';
	if(sum % 11 == 4)
		ch = '8';
	if(sum % 11 == 5)
		ch = '7';
	if(sum % 11 == 6)
		ch = '6';
	if(sum % 11 == 7)
		ch = '5';
	if(sum % 11 == 8)
		ch = '4';
	if(sum % 11 == 9)
		ch = '3';
	if(sum % 11 == 10)
		ch = '2';
	
	if(ID[17] != ch)
	{
		printf("身份证校验码不合法。");
		return 0;
	}
	
	return 1;	
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
	if(year > 2020 || month < 1 || month > 12 || day < 1 || day > 31)
		return 0;		//返回0为不合法日期 
	else if(((month == 4)||(month == 6)||(month == 9)||(month == 11)) && (day == 31))
		return 0;
	else if((LeapYear(year) == 1) && (month == 2) && (day > 29))
		return 0;
	else if((LeapYear(year) == 0) && (month == 2) && (day > 28))
		return 0;
	else 
		return 1;		//返回1为合法日期 
}


//功    能：检验日期 
//入口参数：日期字符串 
//返    回：0 或 1 
int CheckDate(char *Date)
{
	int year, month, day;
	if(strlen(Date) != 10 || Date[4] != '.' || Date[7] != '.')
	{
		printf("日期格式错误。");
		return 0;
	}
	else if(!isdigit(Date[0]) || !isdigit(Date[1]) || !isdigit(Date[2]) || !isdigit(Date[3]) || 
			!isdigit(Date[5]) || !isdigit(Date[6]) || !isdigit(Date[8]) || !isdigit(Date[9]) )
	{
		printf("日期出现非数字字符或格式错误。");
		return 0;
	}
	else
	{
		year = (Date[0] - '0') * 1000 + (Date[1] - '0') * 100 + (Date[2] - '0') * 10 + Date[3] - '0';
		month = (Date[5] - '0') * 10 + (Date[6] - '0');
		day = (Date[8] - '0') * 10 + (Date[9] - '0');
		if(ErrorDate(year, month, day))
		{
			return 1;
		}
		else
		{
			printf("日期非法。");
			return 0;
		}
	}
}


//功    能：检验年龄范围是否在 (10 ~ 60)内 
//入口参数：日期字符串 
//返    回：0 或 1 
int CheckRange(char *Date)
{
	time_t CurrentTime; 
    struct tm *NowDate;
 	time(&CurrentTime);
    NowDate = localtime(&CurrentTime);
    
	int age, year, month, day, year1, month1, day1;
	year = (Date[0] - '0') * 1000 + (Date[1] - '0') * 100 + (Date[2] - '0') * 10 + Date[3] - '0';
	month = (Date[5] - '0') * 10 + (Date[6] - '0');
	day = (Date[8] - '0') * 10 + (Date[9] - '0');
    year1 = NowDate->tm_year + 1900;
	month1 = NowDate->tm_mon + 1;
	day1 = NowDate->tm_mday;
	
	if(year1 == year)
		age = 0;
	else
	{
		age = year1 - year;
		if(month1 < month || (month1 == month && day1 < day))
			age = age - 1;
	}
	
	if(age >= 10 && age <= 60)
		return 1;
	else
	{
		printf("年龄不在(10 ~ 60)的范围内。"); 
		return 0;
	}
		
}

