/*
* �������⽨�� 
* ѧ�ţ�221900128 
* �༶���������һ�� 
* �绰��18750512590 
* �ʼ���ַ��1261768875@qq.com 
* ���ݽṹ������ 
* ��Ҫ�㷨�����������ڵ� 
* ����������Dev-C++ 5.11 
* ���л�����Windows 10 
* 
* ����˵����ѧ����ѧԺ��רҵ��ѧ�ơ�������κ͸���Ա��Ϣ��ѧ�ŵõ�������Ҫ�������롣 
* ���˵��������ѧ����Ϣ��������������Ϣ��ʾΪ  "X" 
* 
*/


#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


//��    �ܣ���ʾ��Ȩ��Ϣ
//��ڲ������� 
//��    �أ��� 
void Copyright();


//��    �ܣ���ʾ�˵����� 
//��ڲ������� 
//��    �أ��� 
void Menu();


//��������ṹ��
typedef struct StuData     
{  
    char StudentID[10];    	//ѧ�� 
	char Name[40];        	//���� 
	char Sex[5];			//�Ա� 
	int Country;		   	//���� 
	char BirthDate[12];	   	//�������� 
	int Nation;		  	   	//���� 
	int Marriage;		   	//����״�� 
	int PoliticalFace;	   	//������ò 
	char idNumber[19];	   	//���֤�� 
	int StudentType;	 	//ѧ����� 
	char SchoolDate[12];	//��ѧ���� 
	int EnterWay;			//��ѧ��ʽ
	char CollegeName[30];	//ѧԺ����
	char MajorName[30];		//רҵ����
	char Grade[5];			//�꼶 
	char Arrange[10];		//ѧ�� 
	char TrainLevel[10];	//�������
	char ClassNum[3];		//�༶��
	char Teacher[40];		//����Ա 
	   
    struct StuData *next;  //�������ָ����   
}StuData;


//��    �ܣ��ַ�������ת������������
//��ڲ������ַ��� 
//��    �أ���Ӧ���������� 
int ChToNum(char str[]);


//��    �ܣ����ļ�����д���Ӧ���� 
//��ڲ���������������ֵ 
//��    �أ��� 
void FileToArray( int &MaxNum, int &MaxCountry, int &MaxNation, int &MaxMarry,   int &MaxFace, 
                  int &MaxID,  int &MaxType,    int &MaxWay,    int &MaxCollege, int &MaxTeacher  );


//��    �ܣ�����ѧ�� 
//��ڲ�����ѧ���ַ��� ��ѧԺ��������  �� ѧ������ 
//��    �أ�0 �� 1 
int CheckStuID(char *StudentID, char strNum[][10], int NodeNum);


//��    �ܣ��������� 
//��ڲ����������ַ��� , ���Ҵ��� 
//��    �أ�0 �� 1 
int CheckName(char *Name, int country);


//��    �ܣ��������֤�� 
//��ڲ��������֤���ַ���,���ڣ��Ա������������飬���鳤�ȣ�ѧ������ 
//��    �أ�0 �� 1 
int CheckID(char *ID, char *Date, char *sex, char AreaCode[][7], int len, int NodeNum);


//��    �ܣ��ж����� 
//��ڲ�������� 
//��    �أ��Ƿ�Ϊ���� 
int LeapYear(int y);


//��    �ܣ��жϲ��Ϸ����� 
//��ڲ������꣬�£��� 
//��    �أ��Ƿ�Ϊ�Ϸ����� 
int ErrorDate(int year, int month, int day);


//��    �ܣ��������� 
//��ڲ����������ַ��� 
//��    �أ�0 �� 1 
int CheckDate(char *Date);



//��    �ܣ��������䷶Χ�Ƿ��� (10 ~ 60)�� 
//��ڲ����������ַ��� 
//��    �أ�0 �� 1 
int CheckRange(char *Date);

#endif 
