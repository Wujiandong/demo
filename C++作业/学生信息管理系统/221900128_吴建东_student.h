/*
* 姓名：吴建东 
* 学号：221900128 
* 班级：软件工程一班 
* 电话：18750512590 
* 邮件地址：1261768875@qq.com 
* 数据结构：链表 
* 主要算法：单链表交换节点 
* 开发环境：Dev-C++ 5.11 
* 运行环境：Windows 10 
* 
* 输入说明：学生的学院、专业、学制、培养层次和辅导员信息由学号得到，不需要另外输入。 
* 输出说明：对于学生信息的输出，错误的信息显示为  "X" 
* 
*/


#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


//功    能：显示版权信息
//入口参数：无 
//返    回：无 
void Copyright();


//功    能：显示菜单界面 
//入口参数：无 
//返    回：无 
void Menu();


//定义链表结构体
typedef struct StuData     
{  
    char StudentID[10];    	//学号 
	char Name[40];        	//姓名 
	char Sex[5];			//性别 
	int Country;		   	//国家 
	char BirthDate[12];	   	//出生日期 
	int Nation;		  	   	//民族 
	int Marriage;		   	//婚姻状况 
	int PoliticalFace;	   	//政治面貌 
	char idNumber[19];	   	//身份证号 
	int StudentType;	 	//学生类别 
	char SchoolDate[12];	//入学年月 
	int EnterWay;			//入学方式
	char CollegeName[30];	//学院名称
	char MajorName[30];		//专业名称
	char Grade[5];			//年级 
	char Arrange[10];		//学制 
	char TrainLevel[10];	//培养层次
	char ClassNum[3];		//班级号
	char Teacher[40];		//辅导员 
	   
    struct StuData *next;  //单链表的指针域   
}StuData;


//功    能：字符串数字转换成整型数字
//入口参数：字符串 
//返    回：对应的整型数字 
int ChToNum(char str[]);


//功    能：将文件内容写入对应数组 
//入口参数：各数组的最大值 
//返    回：无 
void FileToArray( int &MaxNum, int &MaxCountry, int &MaxNation, int &MaxMarry,   int &MaxFace, 
                  int &MaxID,  int &MaxType,    int &MaxWay,    int &MaxCollege, int &MaxTeacher  );


//功    能：检验学号 
//入口参数：学号字符串 ，学院代码数组  ， 学生个数 
//返    回：0 或 1 
int CheckStuID(char *StudentID, char strNum[][10], int NodeNum);


//功    能：检验姓名 
//入口参数：姓名字符串 , 国家代码 
//返    回：0 或 1 
int CheckName(char *Name, int country);


//功    能：检验身份证号 
//入口参数：身份证号字符串,日期，性别，行政区号数组，数组长度，学生个数 
//返    回：0 或 1 
int CheckID(char *ID, char *Date, char *sex, char AreaCode[][7], int len, int NodeNum);


//功    能：判断闰年 
//入口参数：年份 
//返    回：是否为闰年 
int LeapYear(int y);


//功    能：判断不合法日期 
//入口参数：年，月，日 
//返    回：是否为合法日期 
int ErrorDate(int year, int month, int day);


//功    能：检验日期 
//入口参数：日期字符串 
//返    回：0 或 1 
int CheckDate(char *Date);



//功    能：检验年龄范围是否在 (10 ~ 60)内 
//入口参数：日期字符串 
//返    回：0 或 1 
int CheckRange(char *Date);

#endif 
