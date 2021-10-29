#include "221900128_�⽨��_student.h" 

//��    �ܣ���ʾ��Ȩ��Ϣ
//��ڲ������� 
//��    �أ��� 
void Copyright()
{
	printf("Copyright (c) 2020 �⽨��(221900128). All Rights Reserved.\n\n");
}


//��    �ܣ���ʾ�˵����� 
//��ڲ������� 
//��    �أ��� 
void Menu()
{
	printf("*****************************"
	  	   "****************************\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*\t\t   ѧ����Ϣ����ϵͳ�˵�  \t\t*\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*\t\t    A��¼��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    B������ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    C��ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    D������ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    E����ѯѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    F��ѧ������ͳ��\t\t\t*\n");
	printf("*\t\t    G��ѧ����Ϣ����\t\t\t*\n");
	printf("*\t\t    H����ʾѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    I������ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t    J���˳�ϵͳ\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t*\n");
	printf("*****************************"
	  	   "****************************\n");
}


//����ͷ����β��� 
StuData *Head = NULL;
StuData *End = NULL;


//��    �ܣ��ַ�������ת������������
//��ڲ������ַ��� 
//��    �أ���Ӧ���������� 
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

int MaxNum = 0, MaxCountry = 0, MaxNation = 0, MaxMarry = 0,   MaxFace = 0;    	//��������������ֵ 

int MaxID = 0,  MaxType = 0,    MaxWay = 0,    MaxCollege = 0, MaxTeacher = 0;	//��������������ֵ 

char strNum[50][10]; 		//����һ����ά����������ȡѧԺ���� 

char strCountry[200][25]; 	//����һ����ά����������ȡ��������

char strNation[60][20];		//����һ����ά����������ȡ��������
 
char strMarry[10][10];		//����һ����ά����������ȡ����״��

char strFace[15][30];		//����һ����ά����������ȡ������ò

char strID[3600][7];		//����һ����ά����������ȡ�������� 

char strType[15][30];		//����һ����ά����������ȡѧ�����

char strWay[15][30];		//����һ����ά����������ȡ��ѧ��ʽ

char strCollege[40][10][30];//����һ����ά����������ȡѧԺרҵ

char strTeacher[40][5][30];	//����һ����ά����������ȡ����Ա��


//��    �ܣ����ļ�����д���Ӧ���� 
//��ڲ���������������ֵ 
//��    �أ��� 
void FileToArray( int &MaxNum, int &MaxCountry, int &MaxNation, int &MaxMarry,   int &MaxFace, 
                  int &MaxID,  int &MaxType,    int &MaxWay,    int &MaxCollege, int &MaxTeacher  )
{
	char ch[50]; 
	FILE *Num = fopen("221900128_�⽨��_ѧԺ�����.txt", "r");   //���ļ�
	while( !feof(Num) )
	{
		fscanf(Num, "%s%s", strNum[MaxNum], ch);  //��ȡһ��
		MaxNum++;
	}
											
	FILE *Country = fopen("221900128_�⽨��_�������Ʊ�.txt", "r");   
	while( ! feof(Country) )    
   	{
       	fscanf(Country, "%s\n", strCountry[MaxCountry]);
       	MaxCountry++;
    }
    									
	FILE *Nation = fopen("221900128_�⽨��_�����.txt", "r");  
	while( !feof(Nation) )       
    {
		fscanf(Nation, "%s", strNation[MaxNation]);
		MaxNation++;
    }
    								
	FILE *Marry = fopen("221900128_�⽨��_����״����.txt", "r");
	while( !feof(Marry) )
	{
		fscanf(Marry, "%s", strMarry[MaxMarry]);
		MaxMarry++;
	}
    										
	FILE *Face = fopen("221900128_�⽨��_������ò��.txt", "r");
	while( !feof(Face) )
    {
		fscanf(Face, "%s", strFace[MaxFace]);  
 		MaxFace++;
    }
										    
	FILE *ID = fopen("221900128_�⽨��_�������ű�.txt", "r");
	while( !feof(ID) )
    {
		fscanf(ID, "%s", strID[MaxID]);  
		MaxID++; 
    }
    									
	FILE *Type = fopen("221900128_�⽨��_ѧ������.txt", "r");
	while( !feof(Type) ) 
    {
		fscanf(Type, "%s", strType[MaxType]); 
		MaxType++;
    }
    										
	FILE *Way = fopen("221900128_�⽨��_��ѧ��ʽ��.txt", "r");
	while( !feof(Way) )  
    {
		fscanf(Way, "%s", strWay[MaxWay]);
		MaxWay++;
    }
    								
	FILE *College = fopen("221900128_�⽨��_ѧԺרҵ���Ʊ�.txt", "r");
	while( !feof(College) )
    {
		fscanf(College, "%s%s%s%s%s%s", strCollege[MaxCollege][0], strCollege[MaxCollege][1], strCollege[MaxCollege][2],
										strCollege[MaxCollege][3], strCollege[MaxCollege][4], strCollege[MaxCollege][5] );
		MaxCollege++;
    }
    								
	FILE *Teacher = fopen("221900128_�⽨��_����Ա��Ϣ��.txt", "r");
	while( !feof(Teacher) ) 
    {
		fscanf(Teacher, "%s%s", strTeacher[MaxTeacher][0], strTeacher[MaxTeacher][1]);
		MaxTeacher++;
    }
    
} 

//��    �ܣ�����ѧ�� 
//��ڲ�����ѧ���ַ��� ��ѧԺ��������  �� ѧ������ 
//��    �أ�0 �� 1 
int CheckStuID(char *StudentID, char strNum[][10], int NodeNum)
{
	if(strlen(StudentID) != 9)
	{
		printf("ѧ�ų��ȴ���"); 
		return 0;
	}
	for(int i = 0; i < 9; i++)
	{
		if( !isdigit(StudentID[i]))
		{
			printf("ѧ�ų��ַ������ַ���"); 
			return 0;
		}
	}
	
	//�����ظ�ѧ�� 
	if(NodeNum != 0)
	{
		StuData *Temp = Head->next;
		while(Temp != NULL)
		{
			if(!strcmp(Temp->StudentID, StudentID))
			{
				printf("ѧ�ų����ظ���"); 
				return 0;
			}
			Temp = Temp->next;	
		}
	}
	
	//�����뵱ǰ�����Ƿ�һ��
	time_t CurrentTime; 
    struct tm *NowDate;
 	time(&CurrentTime);
    NowDate = localtime(&CurrentTime); 
    int year =  NowDate->tm_year - 100;
    if((StudentID[2] - '0') * 10 + (StudentID[3] - '0') > 20 )
    {
		printf("��ѧ�������"); 
		return 0;
	}
	else if(StudentID[2] != (char)(year / 10 + '0') || StudentID[3] != (char)(year % 10 + '0') ) 
	{
		printf("��ѧ����뵱ǰ������ݲ�һ�¡�"); 
	}
	
	//����ѧԺ���� 
	for(int j = 0; j < 50; j++)
	{
		if(strNum[j][0] == StudentID[0] && strNum[j][1] == StudentID[1])
			return 1;
	}
	printf("ѧԺ��������"); 
	return 0;
}

//��    �ܣ��������� 
//��ڲ����������ַ��� , ���Ҵ��� 
//��    �أ�0 �� 1 
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
			printf("�������ַǺ����ַ���"); 
			return 0;
		}
		else if(strlen(Name) < 4 || strlen(Name) > 40)
		{
			printf("��������2~20������֮�䡣"); 
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


//��    �ܣ��������֤�� 
//��ڲ��������֤���ַ���,���ڣ��Ա������������飬���鳤�ȣ�ѧ������ 
//��    �أ�0 �� 1 
int CheckID(char *ID, char *Date, char *sex, char AreaCode[][7], int len, int NodeNum)
{
	int i, judge = 0;
	
	//�жϳ����Ƿ�Ϊ18 
	if(strlen(ID) != 18)
	{
		printf("���֤��λ������18λ��");
		return 0;
	}
		
	
	//�ж�ǰ17���ַ��Ƿ�Ϊ����	
	for(i = 0;i < 17; i++)
	{
		if( ! isdigit(ID[i]) )
		{
			printf("���֤���г��ַ������ַ���"); 
			return 0;
		}	
	}	
	
	//�ж��Ƿ����ظ����֤�� 
	if(NodeNum != 0)
	{
		StuData *Temp = Head->next;
		while(Temp != NULL)
		{
			if(!strcmp(Temp->idNumber, ID))
			{
				printf("���֤�ų����ظ���"); 
				return 0;
			}
			Temp = Temp->next;	
		}
	}
	
	//�ж����������Ƿ�Ϸ� 
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
		printf("�����������Ϸ���"); 
		return 0;
	}	
	
	//�ж����֤�����Ƿ�ͳ�������һ��
	if( ID[6]  != Date[0] || ID[7]  != Date[1] || ID[8]  != Date[2] || ID[9]  != Date[3] ||
	    ID[10] != Date[5] || ID[11] != Date[6] || ID[12] != Date[8] || ID[13] != Date[9]  )
	{
		printf("���֤���ںͳ������ڲ�һ�¡�");
		return 0;
	}
	
	//�ж����֤�Ա��Ƿ�������Ա�һ��
	if(!strcmp(sex, "��"))
	{
		i = ID[16] - '0';
		if(i % 2 == 0)
		{
			printf("���֤�Ա�������Ա�һ�¡�"); 
			return 0;
		}	
	}
	if(!strcmp(sex, "Ů"))
	{
		i = ID[16] - '0';
		if(i % 2 != 0)
		{
			printf("���֤�Ա�������Ա�һ�¡�");
			return 0;
		}
	} 
	
	//�ж�У�����Ƿ�Ϸ�
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
		printf("���֤У���벻�Ϸ���");
		return 0;
	}
	
	return 1;	
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
	if(year > 2020 || month < 1 || month > 12 || day < 1 || day > 31)
		return 0;		//����0Ϊ���Ϸ����� 
	else if(((month == 4)||(month == 6)||(month == 9)||(month == 11)) && (day == 31))
		return 0;
	else if((LeapYear(year) == 1) && (month == 2) && (day > 29))
		return 0;
	else if((LeapYear(year) == 0) && (month == 2) && (day > 28))
		return 0;
	else 
		return 1;		//����1Ϊ�Ϸ����� 
}


//��    �ܣ��������� 
//��ڲ����������ַ��� 
//��    �أ�0 �� 1 
int CheckDate(char *Date)
{
	int year, month, day;
	if(strlen(Date) != 10 || Date[4] != '.' || Date[7] != '.')
	{
		printf("���ڸ�ʽ����");
		return 0;
	}
	else if(!isdigit(Date[0]) || !isdigit(Date[1]) || !isdigit(Date[2]) || !isdigit(Date[3]) || 
			!isdigit(Date[5]) || !isdigit(Date[6]) || !isdigit(Date[8]) || !isdigit(Date[9]) )
	{
		printf("���ڳ��ַ������ַ����ʽ����");
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
			printf("���ڷǷ���");
			return 0;
		}
	}
}


//��    �ܣ��������䷶Χ�Ƿ��� (10 ~ 60)�� 
//��ڲ����������ַ��� 
//��    �أ�0 �� 1 
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
		printf("���䲻��(10 ~ 60)�ķ�Χ�ڡ�"); 
		return 0;
	}
		
}

