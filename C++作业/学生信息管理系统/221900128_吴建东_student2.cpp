#include <stdio.h>
#include "221900128_�⽨��_student.h"

int main()
{
	int NodeNum = 0;   //����ѧ�������ܽ����
	char input;        //�����û�ѡ����� 
	Copyright();       //��ʾ��Ȩ
	Menu();            //��ʾ�˵�����
	printf("\n��ѡ��(A,B,C,D,E,F,G,H,I,J):");
	scanf("%c", &input);
	getchar();
	while(input != 'J')
	{
		if((input < 'A') || (input > 'J'))
			printf("\nѡ�����������ѡ��......\n");
		else
		{
			switch(input)
			{
				//�ò���ִ��¼��ѧ����Ϣ 
				case 'A' :	{
								int temp = 1;      
								char i; 		 
								Head = (StuData *)malloc(sizeof(StuData)); //Ϊͷ�������ռ� 
								End = Head;
								
								FileToArray( MaxNum, MaxCountry, MaxNation, MaxMarry,   MaxFace, 
                  							 MaxID,  MaxType,    MaxWay,    MaxCollege, MaxTeacher ); //���ļ�����д������
								while(temp)
								{
									printf("\n��ѡ������ѧ����Ϣ�ķ�ʽ(1.�������� 2.�ļ�����)��");
									scanf("%c", &i);    //��ȡ�û�����ѧ����Ϣ�ķ�ʽ 
									getchar();
									
									//�������� 
									if(i == '1')
									{
										while(temp)
										{
											StuData *p;
											p = (StuData *)malloc(sizeof(StuData));
											
											printf("\n������¼���%d��ѧ������Ϣ��\n", NodeNum + 1); 
											
											//ѧ�ŵ�����
											while(temp)
											{
												printf("\n������ѧ�ţ�"); 
												scanf("%s", p->StudentID);
												getchar();
												printf("\n");
												if( CheckStuID(p->StudentID, strNum, NodeNum) )  //�������ѧ�Ž��м��� 
												{
													printf("�������ѧ���ǣ�%s", p->StudentID);
													temp = 0;
												}
												else
												{
													printf("���������롣"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//���ҵ�����
											printf("\n�����µĹ�����ѡ��һ������:\n\n");
											
										    int i;
										    //�ļ�������ʾ 
											for(i = 0; i < MaxCountry; i++)
											{
												printf("%-25s", strCountry[i]);
												if((i + 1) % 5 == 0)
													printf("\n");
											}
													
											while(temp)
											{
												printf("\n\n�����������ź�(�س�)��"); 
												char t[4];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; 
													t[1] = '1'; 
													t[2] = '\0';
												}
												p->Country = ChToNum(t);
												
												printf("\n");
												if( p->Country >= 1 && p->Country <= 197 )
												{
													printf("������Ĺ����ǣ�%s",strCountry[p->Country - 1]);
													temp = 0; 
												}
												else
												{
													printf("������������������������롣"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//����������
											while(temp)
											{
												printf("\n������������"); 
												scanf("%s", p->Name);
												getchar();
												printf("\n");
												if( CheckName(p->Name, p->Country) )
												{
													printf("������������ǣ�%s", p->Name);
													temp = 0;
												}
												else
												{
													printf("���������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//�Ա������
											while(temp)
											{
												printf("\n�������Ա�(��/Ů)��"); 
												scanf("%s", p->Sex);
												getchar();
												printf("\n");
												if(!strcmp(p->Sex, "��") || !strcmp(p->Sex, "Ů"))
												{
													printf("��������Ա��ǣ�%s", p->Sex);
													temp = 0;
												}
												else
												{
													printf("�Ա������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//�������ڵ�����
											while(temp)
											{
												printf("\n�������������(xxxx.xx.xx)��"); 
												scanf("%s", p->BirthDate);
												getchar(); 
												printf("\n");
												if( CheckDate(p->BirthDate) )
												{
													if(CheckRange(p->BirthDate))
													{
														printf("������ĳ��������ǣ�%s", p->BirthDate);
														temp = 0;
													} 
													else
														printf("���������롣");
												}
												else 
												{
													printf("���������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//���������
											printf("\n�����µ�������ѡ��һ������:\n\n");
											
											//�ļ�������ʾ 
											for(i = 0; i < MaxNation; i++)
											{
												printf("%-20s", strNation[i]);
										        if((i + 1) % 5 ==0)   
													printf("\n");
											}
											
										    while(temp)
											{
												printf("\n\n������������ź�(�س�)��"); 
												char t[3];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->Nation = ChToNum(t);
												printf("\n");
												if( p->Nation >= 1 && p->Nation <= 58 )
												{
													printf("��������ǣ�%s", strNation[p->Nation - 1]);
													temp = 0; 
												}
												else
												{
													printf("��������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											//����״�������� 
											printf("\n�����µĻ���״��ѡ����ѡ��һ��:\n\n");
											
											//�ļ�������ʾ 
											for(i = 0; i < MaxMarry; i++) 
											{  
												printf("%-12s", strMarry[i]);
											} 
										    while(temp)
											{
												printf("\n\n���������״����ź�(�س�)��"); 
												char t[3];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; 
													t[1] = '1';
												}
												p->Marriage = ChToNum(t);
												
												printf("\n");
												if( p->Marriage >= 1 && p->Marriage <= 5 )
												{
													printf("��������ǣ�%s", strMarry[p->Marriage - 1]);
													temp = 0; 
												}
												else
												{
													printf("��������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//������ò������ 
										    printf("\n�����µ�������òѡ����ѡ��һ��:\n\n");
										    
											//�ļ�������ʾ 
											for(i = 0; i < MaxFace; i++)
											{
												printf("%-30s", strFace[i]);
												if((i + 1) % 3 == 0)
													printf("\n");
											}
											
										    while(temp)
											{
												printf("\n\n������������ò��ź�(�س�)��"); 
												char t[3];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->PoliticalFace = ChToNum(t);
												
												printf("\n");
												if( p->PoliticalFace >= 1 && p->PoliticalFace <= 13 )
												{
													printf("��������ǣ�%s", strFace[p->PoliticalFace - 1]);
													temp = 0; 
												}
												else
												{
													printf("��������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//���֤�ŵ�����
											while(temp)
											{
												printf("\n���������֤�ź�(�س�)��"); 
												gets(p->idNumber);
												printf("\n");
												if(p->Country != 1)
													strcpy(p->idNumber, "�⼮ѧ������"); 
												if( CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
												{
													printf("��������ǣ�%s", p->idNumber);
													temp = 0; 
												}
												else
												{
													printf("���������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//ѧ����������
											printf("\n�����µ�ѧ�����ѡ����ѡ��һ��:\n\n");
											
											//�ļ�������ʾ 
											for(i = 0; i < MaxType; i++)
											{
												printf("%-15s", strType[i]);
											}
											
										    while(temp)
											{
												printf("\n\n������ѧ�������ź�(�س�)��"); 
												char t[3];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->StudentType = ChToNum(t);
												
												printf("\n");
												if( p->StudentType >= 1 && p->StudentType <= 2 )
												{
													printf("��������ǣ�%s", strType[p->StudentType - 1]);
													temp = 0; 
												}
												else
												{
													printf("��������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											//��ѧ���µ�����
											while(temp)
											{
												printf("\n��������ѧ����(xxxx.xx.xx)��"); 
												scanf("%s", p->SchoolDate);
												getchar(); 
												printf("\n");
												if( CheckDate(p->SchoolDate) )
												{
													if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
														printf("������������ѧ����ݲ�һ�¡�"); 
													printf("���������ѧ�����ǣ�%s", p->SchoolDate);
													temp = 0; 
												}
												else
												{
													printf("���������롣"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//��ѧ��ʽ������
										    printf("\n�����µ���ѧ��ʽѡ����ѡ��һ��:\n\n");
											
											//�ļ�������ʾ 
											for(i = 0; i < MaxWay; i++)
											{
												printf("%-15s", strWay[i]);	
											} 
											
										    while(temp)
											{
												printf("\n\n��������ѧ��ʽ��ź�(�س�)��"); 
												char t[3];
												gets(t);
												
												//������س���Ĭ��ֵ����
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; 
													t[1] = '1';
												}
												p->EnterWay = ChToNum(t);
												
												printf("\n");
												if( p->EnterWay >= 1 && p->EnterWay <= 3 )
												{
													printf("��������ǣ�%s", strWay[p->EnterWay - 1]);
													temp = 0; 
												}
												else
												{
													printf("��������������������롣"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											
											//�꼶������
											while(temp)
											{
												printf("\n�������꼶(20xx)��");
												gets(p->Grade);
												
												//������س�ʱ��Ĭ��ֵ����
												if(!strcmp(p->Grade, "\0"))
												{
													p->Grade[0] = '2'; 
													p->Grade[1] = '0';
													p->Grade[2] = p->StudentID[2];
													p->Grade[3] = p->StudentID[3];
													p->Grade[4] = '\0';
												}
												
												printf("\n");
												if(isdigit(p->Grade[0]) && isdigit(p->Grade[1]) && 
												   isdigit(p->Grade[2]) && isdigit(p->Grade[3])  )
												{
													if(p->Grade[2] == p->StudentID[2] && p->Grade[3] == p->StudentID[3])
													{
														printf("��������ǣ�%s", p->Grade);
														temp = 0;
													}
													else
													{
														printf("��������꼶��ѧ���е��꼶���벻ƥ�䡣(��¼��)");
														temp = 0;
													} 
												}
												else
												{
													printf("�����������������롣"); 
												}
												printf("\n");
											}
											temp = 1;
																				
											//�༶�ŵ����� 
											while(temp)
											{
												printf("\n������༶��(01-09)��(�س�):");
												gets(p->ClassNum);
												printf("\n");
												if(!strcmp(p->ClassNum, "\0"))
												{
													p->ClassNum[1] = p->StudentID[6]; 
													p->ClassNum[0] = '0'; 
													p->ClassNum[2] = '\0';
												}
												if(strlen(p->ClassNum) == 1)
												{
													p->ClassNum[1] = p->ClassNum[0]; 
													p->ClassNum[0] = '0'; 
													p->ClassNum[2] = '\0';
												}
												if( ChToNum(p->ClassNum) >= 1 && ChToNum(p->ClassNum) <= 9 && p->ClassNum[1] == p->StudentID[6])
												{
													printf("��������ǣ�%s", p->ClassNum);
													temp = 0; 
												}
												else
												{
													printf("�༶����ѧ�ŵİ༶���벻ƥ�䣬���������롣"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//ѧԺ��רҵ���ơ�ѧ�ƺ�������ε����� 
											for(int i = 0; i < MaxCollege; i++)
											{
												if(strCollege[i][0][0] == p->StudentID[0] && strCollege[i][0][1] == p->StudentID[1] &&
												   strCollege[i][2][0] == p->StudentID[4] && strCollege[i][2][1] == p->StudentID[5]  )
												{
													strcpy(p->CollegeName, strCollege[i][1]);
													strcpy(p->MajorName, strCollege[i][3]);
													strcpy(p->Arrange, strCollege[i][4]);
													strcpy(p->TrainLevel, strCollege[i][5]);
												
													printf("\n����ѧ�ſɵã�\n\n��Ӧ��ѧԺΪ��%s\n", p->CollegeName);
													printf("\n��Ӧ��רҵΪ��%s\n", p->MajorName);
													printf("\n��Ӧ��ѧ��Ϊ��%s\n", p->Arrange);
													printf("\n��Ӧ���������Ϊ��%s\n", p->TrainLevel);
													
													temp = 0;
													break;
												}
											} 
											if(temp)
											{
												printf("\nѧ�Ŷ�Ӧ��ѧԺרҵ��Ϣ���㡣��ʱ�޷�¼�롣\n");
												strcpy(p->CollegeName, "δ֪");
												strcpy(p->MajorName, "δ֪");
												strcpy(p->Arrange, "δ֪");
												strcpy(p->TrainLevel, "δ֪");
											}
											temp = 1; 
											
											//����Ա������
											for(int i = 0; i < MaxTeacher; i++)
											{
												if( !strcmp(p->MajorName, strTeacher[i][0]) )
												{
													strcpy(p->Teacher, strTeacher[i][1]);
													printf("\n%s�ĸ���ԱΪ��%s\n", p->MajorName, p->Teacher);
													temp = 0;
													break;
												}
											} 
											if(temp)
											{
												printf("\nѧ�Ŷ�Ӧ��רҵ����Ա��Ϣ���㡣��ʱ�޷�¼�롣\n");
												strcpy(p->Teacher, "δ֪");
											}
											temp = 1;
											
											End->next = p;
											End = p;
											End->next = NULL;
											NodeNum++; 
											
											printf("\n�Ƿ�������һ��ѧ������Ϣ��(\"��\"�� 1��\"��\"�� 2)");
											while(temp)
											{
												scanf("%d", &temp);
												getchar(); 
												if(temp == 1 || temp == 2)
												{
													temp %= 2;
													break;
												}
												else
												{
													printf("\nѡ������������ѡ��\n"); 
													temp = 1; 
												}
											}
										}
									}
									
									//�ļ����� 
									else if(i == '2')
									{
										char FileName[50];    //�����Զ����ļ���
										printf("\n�������ļ�����(ע����Ӻ�׺)��");
										gets(FileName);
										FILE * File = fopen(FileName, "r+");   //���ļ�
										if (File == NULL)     //�����ļ�ʧ�����˳�
										{
											printf("\n�ļ���ʧ�ܡ�\n\n");
											system("pause");
										}
										else
										{
											int Num = 0; 
											while( !feof(File) )
											{
												
												StuData *p;
												p = (StuData *)malloc(sizeof(StuData));
												
												fscanf(File, "%s%d%s%s%s%d%d%d%s%d%s%d%s%s", 
														p->StudentID,  &p->Country,    p->Name,          p->Sex,      p->BirthDate,
													   &p->Nation,     &p->Marriage,  &p->PoliticalFace, p->idNumber,&p->StudentType, 
														p->SchoolDate, &p->EnterWay,   p->Grade,         p->ClassNum);
														
												printf("\n��%d��ѧ����", ++Num);
												
												//����ѧ�� 
												if( !CheckStuID(p->StudentID, strNum, NodeNum) ) 
												{
													strcpy(p->StudentID, "X");
													printf("¼��ʧ�ܡ�\n");
													continue;
												}
												
												//������� 
												if( p->Country < 1 || p->Country > 197 )
												{
													printf("�����������");
													p->Country = 1;  //��Ĭ��ֵ1 
												}
												
												//�������� 
												if( !CheckName(p->Name, p->Country) )
												{
													strcpy(p->Name, "X");
												}
												
												//�����Ա� 
												if( strcmp(p->Sex, "��") && strcmp(p->Sex, "Ů"))
												{
													printf("�Ա�����"); 
													strcpy(p->Sex, "X");
												}
												
												//����������� 
												if( CheckDate(p->BirthDate) )
												{
													if( !CheckRange(p->BirthDate) )
													{
														strcpy(p->BirthDate, "X	");
													} 
												}
												else 
												{
													strcpy(p->BirthDate, "X	");
												}
												
												//�������� 
												if( p->Nation < 1 || p->Nation > 58 )
												{
													printf("�����������"); 
													p->Nation = 0;
												}

												//�������״�� 
												if( p->Marriage < 1 || p->Marriage > 5 )
												{
													printf("����״���������"); 
													p->Marriage = 0;
												}
												
												//����������ò 
												if( p->PoliticalFace < 1 || p->PoliticalFace > 13 )
												{
													printf("������ò�������"); 
													p->PoliticalFace = 0;
												}
											
												//�������֤�� 
												if( !CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
												{
													strcpy(p->idNumber, "X		"); 
												}
												
												//����ѧ����� 
												if( p->StudentType < 1 || p->StudentType > 2 )
												{
													printf("ѧ������������"); 
													p->StudentType = 0;
												}
												
												//������ѧ���� 
												if( !CheckDate(p->SchoolDate) )
												{
													strcpy(p->SchoolDate, "X"); 
												}
												else
												{
													if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
														printf("��ѧ�����ѧ����ݲ�һ�¡�"); 
												}
												
												//������ѧ��ʽ 
												if( p->EnterWay < 1 || p->EnterWay > 3 )
												{
													printf("��ѧ��ʽ�������"); 
													p->EnterWay = 0; 
												}
											
												//�����꼶 
												if(isdigit(p->Grade[0]) && isdigit(p->Grade[1]) && 
												   isdigit(p->Grade[2]) && isdigit(p->Grade[3])  )
												{
													if(p->Grade[2] != p->StudentID[2] || p->Grade[3] != p->StudentID[3])
													{
														printf("�꼶��ѧ���꼶��ƥ�䡣"); 
														strcpy(p->Grade, "X"); 
													}
												}
												else
												{
													printf("�꼶���ַ������ַ���"); 
													strcpy(p->Grade, "X"); 
												}
												
												//����༶��							
												if( ChToNum(p->ClassNum) < 1 || ChToNum(p->ClassNum) > 9 || (p->ClassNum[0] == '0' && p->ClassNum[1] != p->StudentID[6]))
												{
													printf("�༶��ѧ�Ű༶��ƥ�䡣"); 
													strcpy(p->ClassNum, "X");
												}
											
												//¼��ѧԺ��רҵ���ơ�ѧ�ƺ�������� 
												for(int i = 0; i < MaxCollege; i++)
												{
													if(strCollege[i][0][0] == p->StudentID[0] && strCollege[i][0][1] == p->StudentID[1] &&
													   strCollege[i][2][0] == p->StudentID[4] && strCollege[i][2][1] == p->StudentID[5]  )
													{
														strcpy(p->CollegeName, strCollege[i][1]);
														strcpy(p->MajorName, strCollege[i][3]);
														strcpy(p->Arrange, strCollege[i][4]);
														strcpy(p->TrainLevel, strCollege[i][5]);
														temp = 0;
														break;
													}
												} 
												if(temp)
												{
													strcpy(p->CollegeName, "δ֪");
													strcpy(p->MajorName, "δ֪");
													strcpy(p->Arrange, "δ֪");
													strcpy(p->TrainLevel, "δ֪");
													printf("ѧ�Ŷ�Ӧ��ѧԺרҵ��Ϣ���㡣");
												}
												temp = 1;
												
												//¼�븨��Ա���� 
												for(int i = 0; i < MaxTeacher; i++)
												{
													if( !strcmp(p->MajorName, strTeacher[i][0]) )
													{
														strcpy(p->Teacher, strTeacher[i][1]);
														temp = 0;
														break;
													}
												} 
												if(temp)
												{
													strcpy(p->Teacher, "δ֪");
													printf("\nѧ�Ŷ�Ӧ��רҵ����Ա���㡣\n");
												}
												temp = 1;
								
												End->next = p;
												End = p;
												End->next = NULL;
												NodeNum++; 
												printf("\n");
											}
											printf("\n�ļ���ѧ����Ϣ��¼�롣\n\n");
											system("pause");
											temp = 0;
										}
									}
									else
										printf("\n����������������롣\n");
								}
							} 	break;
							
				//�ò���ִ������ѧ����Ϣ 
				case 'B' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									while(temp)
									{
										StuData *p;
										p = (StuData *)malloc(sizeof(StuData));
										
										printf("\n������¼���%d��ѧ������Ϣ��\n", NodeNum + 1); 
										
										//ѧ�ŵ�����
										while(temp)
										{
											printf("\n������Ҫ��ӵ�ѧ����ѧ�ţ�"); 
											scanf("%s", p->StudentID);
											getchar();
											printf("\n");
											if( CheckStuID(p->StudentID, strNum, NodeNum) )  //�������ѧ�Ž��м��� 
											{
												printf("�������ѧ���ǣ�%s", p->StudentID);
												temp = 0;
											}
											else
											{
												printf("���������롣"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//���ҵ�����
										printf("\n�����µĹ�����ѡ��һ������:\n\n");
										
									    int i;
									    //�ļ�������ʾ 
										for(i = 0; i < MaxCountry; i++)
										{
											printf("%-25s", strCountry[i]);
											if((i + 1) % 5 == 0)
												printf("\n");
										}
												
										while(temp)
										{
											printf("\n\n�����������ź�(�س�)��"); 
											char t[4];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; 
												t[1] = '1'; 
												t[2] = '\0';
											}
											p->Country = ChToNum(t);
											
											printf("\n");
											if( p->Country >= 1 && p->Country <= 197 )
											{
												printf("������Ĺ����ǣ�%s",strCountry[p->Country - 1]);
												temp = 0; 
											}
											else
											{
												printf("������������������������롣"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//����������
										while(temp)
										{
											printf("\n������������"); 
											scanf("%s", p->Name);
											getchar();
											printf("\n");
											if( CheckName(p->Name, p->Country) )
											{
												printf("������������ǣ�%s", p->Name);
												temp = 0;
											}
											else
											{
												printf("���������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//�Ա������
										while(temp)
										{
											printf("\n�������Ա�(��/Ů)��"); 
											scanf("%s", p->Sex);
											getchar();
											printf("\n");
											if(!strcmp(p->Sex, "��") || !strcmp(p->Sex, "Ů"))
											{
												printf("��������Ա��ǣ�%s", p->Sex);
												temp = 0;
											}
											else
											{
												printf("�Ա������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//�������ڵ�����
										while(temp)
										{
											printf("\n�������������(xxxx.xx.xx)��"); 
											scanf("%s", p->BirthDate);
											getchar(); 
											printf("\n");
											if( CheckDate(p->BirthDate) )
											{
												if(CheckRange(p->BirthDate))
												{
													printf("������ĳ��������ǣ�%s", p->BirthDate);
													temp = 0;
												} 
												else
													printf("���������롣");
											}
											else 
											{
												printf("���������롣\n"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//���������
										printf("\n�����µ�������ѡ��һ������:\n\n");
										
										//�ļ�������ʾ 
										for(i = 0; i < MaxNation; i++)
										{
											printf("%-20s", strNation[i]);
									        if((i + 1) % 5 ==0)   
												printf("\n");
										}
										
									    while(temp)
										{
											printf("\n\n������������ź�(�س�)��"); 
											char t[3];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->Nation = ChToNum(t);
											printf("\n");
											if( p->Nation >= 1 && p->Nation <= 58 )
											{
												printf("��������ǣ�%s", strNation[p->Nation - 1]);
												temp = 0; 
											}
											else
											{
												printf("��������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										//����״�������� 
										printf("\n�����µĻ���״��ѡ����ѡ��һ��:\n\n");
										
										//�ļ�������ʾ 
										for(i = 0; i < MaxMarry; i++) 
										{  
											printf("%-12s", strMarry[i]);
										} 
									    while(temp)
										{
											printf("\n\n���������״����ź�(�س�)��"); 
											char t[3];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; 
												t[1] = '1';
											}
											p->Marriage = ChToNum(t);
											
											printf("\n");
											if( p->Marriage >= 1 && p->Marriage <= 5 )
											{
												printf("��������ǣ�%s", strMarry[p->Marriage - 1]);
												temp = 0; 
											}
											else
											{
												printf("��������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//������ò������ 
									    printf("\n�����µ�������òѡ����ѡ��һ��:\n\n");
									    
										//�ļ�������ʾ 
										for(i = 0; i < MaxFace; i++)
										{
											printf("%-30s", strFace[i]);
											if((i + 1) % 3 == 0)
												printf("\n");
										}
										
									    while(temp)
										{
											printf("\n\n������������ò��ź�(�س�)��"); 
											char t[3];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->PoliticalFace = ChToNum(t);
											
											printf("\n");
											if( p->PoliticalFace >= 1 && p->PoliticalFace <= 13 )
											{
												printf("��������ǣ�%s", strFace[p->PoliticalFace - 1]);
												temp = 0; 
											}
											else
											{
												printf("��������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//���֤�ŵ�����
										while(temp)
										{
											printf("\n���������֤�ź�(�س�)��"); 
											gets(p->idNumber);
											printf("\n");
											if(p->Country != 1)
												strcpy(p->idNumber, "�⼮ѧ������"); 
											if( CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
											{
												printf("��������ǣ�%s", p->idNumber);
												temp = 0; 
											}
											else
											{
												printf("���������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//ѧ����������
										printf("\n�����µ�ѧ�����ѡ����ѡ��һ��:\n\n");
										
										//�ļ�������ʾ 
										for(i = 0; i < MaxType; i++)
										{
											printf("%-15s", strType[i]);
										}
										
									    while(temp)
										{
											printf("\n\n������ѧ�������ź�(�س�)��"); 
											char t[3];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->StudentType = ChToNum(t);
											
											printf("\n");
											if( p->StudentType >= 1 && p->StudentType <= 2 )
											{
												printf("��������ǣ�%s", strType[p->StudentType - 1]);
												temp = 0; 
											}
											else
											{
												printf("��������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										//��ѧ���µ�����
										while(temp)
										{
											printf("\n��������ѧ����(xxxx-xx-xx)��"); 
											scanf("%s", p->SchoolDate);
											getchar(); 
											printf("\n");
											if( CheckDate(p->SchoolDate) )
											{
												if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
													printf("������������ѧ����ݲ�һ�¡�"); 
												printf("���������ѧ�����ǣ�%s", p->SchoolDate);
												temp = 0; 
											}
											else
											{
												printf("���������롣"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//��ѧ��ʽ������
									    printf("\n�����µ���ѧ��ʽѡ����ѡ��һ��:\n\n");
										
										//�ļ�������ʾ 
										for(i = 0; i < MaxWay; i++)
										{
											printf("%-15s", strWay[i]);	
										} 
										
									    while(temp)
										{
											printf("\n\n��������ѧ��ʽ��ź�(�س�)��"); 
											char t[3];
											gets(t);
											
											//������س���Ĭ��ֵ����
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; 
												t[1] = '1';
											}
											p->EnterWay = ChToNum(t);
											
											printf("\n");
											if( p->EnterWay >= 1 && p->EnterWay <= 3 )
											{
												printf("��������ǣ�%s", strWay[p->EnterWay - 1]);
												temp = 0; 
											}
											else
											{
												printf("��������������������롣"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										
										//�꼶������
										while(temp)
										{
											printf("\n�������꼶(20xx)��");
											gets(p->Grade);
											
											//������س�ʱ��Ĭ��ֵ����
											if(!strcmp(p->Grade, "\0"))
											{
												p->Grade[0] = '2'; 
												p->Grade[1] = '0';
												p->Grade[2] = p->StudentID[2];
												p->Grade[3] = p->StudentID[3];
												p->Grade[4] = '\0';
											}
											
											printf("\n");
											if(isdigit(p->Grade[0]) && isdigit(p->Grade[1]) && 
											   isdigit(p->Grade[2]) && isdigit(p->Grade[3])  )
											{
												if(p->Grade[2] == p->StudentID[2] && p->Grade[3] == p->StudentID[3])
												{
													printf("��������ǣ�%s", p->Grade);
													temp = 0;
												}
												else
												{
													printf("��������꼶��ѧ���е��꼶���벻ƥ�䡣(��¼��)");
													temp = 0;
												} 
											}
											else
											{
												printf("�����������������롣"); 
											}
											printf("\n");
										}
										temp = 1;
																			
										//�༶�ŵ����� 
										while(temp)
										{
											printf("\n������༶��(01-09)��(�س�):");
											gets(p->ClassNum);
											printf("\n");
											if(strlen(p->ClassNum) == 1)
											{
												p->ClassNum[1] = p->ClassNum[0]; 
												p->ClassNum[0] = '0'; 
												p->ClassNum[2] = '\0';
											}
											if( ChToNum(p->ClassNum) >= 1 && ChToNum(p->ClassNum) <= 9 && p->ClassNum[1] == p->StudentID[6])
											{
												printf("��������ǣ�%s", p->ClassNum);
												temp = 0; 
											}
											else
											{
												printf("�༶����ѧ�ŵİ༶���벻ƥ�䣬���������롣"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//ѧԺ��רҵ���ơ�ѧ�ƺ�������ε����� 
										for(int i = 0; i < MaxCollege; i++)
										{
											if(strCollege[i][0][0] == p->StudentID[0] && strCollege[i][0][1] == p->StudentID[1] &&
											   strCollege[i][2][0] == p->StudentID[4] && strCollege[i][2][1] == p->StudentID[5]  )
											{
												strcpy(p->CollegeName, strCollege[i][1]);
												strcpy(p->MajorName, strCollege[i][3]);
												strcpy(p->Arrange, strCollege[i][4]);
												strcpy(p->TrainLevel, strCollege[i][5]);
											
												printf("\n����ѧ�ſɵã�\n\n��Ӧ��ѧԺΪ��%s\n", p->CollegeName);
												printf("\n��Ӧ��רҵΪ��%s\n", p->MajorName);
												printf("\n��Ӧ��ѧ��Ϊ��%s\n", p->Arrange);
												printf("\n��Ӧ���������Ϊ��%s\n", p->TrainLevel);
												
												temp = 0;
												break;
											}
										} 
										if(temp)
										{
											printf("\nѧ�Ŷ�Ӧ��ѧԺרҵ��Ϣ���㡣��ʱ�޷�¼�롣\n");
											strcpy(p->CollegeName, "δ֪");
											strcpy(p->MajorName, "δ֪");
											strcpy(p->Arrange, "δ֪");
											strcpy(p->TrainLevel, "δ֪");
										}
										temp = 1; 
										
										//����Ա������
										for(int i = 0; i < MaxTeacher; i++)
										{
											if( !strcmp(p->MajorName, strTeacher[i][0]) )
											{
												strcpy(p->Teacher, strTeacher[i][1]);
												printf("\n%s�ĸ���ԱΪ��%s\n", p->MajorName, p->Teacher);
												temp = 0;
												break;
											}
										} 
										if(temp)
										{
											printf("\nѧ�Ŷ�Ӧ��רҵ����Ա��Ϣ���㡣��ʱ�޷�¼�롣\n");
											strcpy(p->Teacher, "δ֪");
										}
										temp = 1;
										
										End->next = p;
										End = p;
										End->next = NULL;
										NodeNum++; 
										
										printf("\n�Ƿ�������һ��ѧ������Ϣ��(\"��\"�� 1��\"��\"�� 2)");
										while(temp)
										{
											scanf("%d", &temp);
											getchar(); 
											if(temp == 1 || temp == 2)
											{
												temp %= 2;
												break;
											}
											else
											{
												printf("\nѡ������������ѡ��\n"); 
												temp = 1; 
											}
										}
									}
								}
									
						  	} 	break;
							  	
				//�ò���ִ��ɾ��ѧ����Ϣ 
				case 'C' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int temp = 1;
									char stuID[12], stuMajor[30], stuGrade[6];
									StuData *Temp = Head->next;
									StuData *PreNode = Head;
									StuData *tNode;
									
									printf("\n��ѡ��ɾ������(\"����ѧ��\"�� 1��\"רҵ+�꼶\"�� 2)");
									while(temp)
									{
										scanf("%d", &temp);
										getchar(); 
										if(temp == 1)
										{
											printf("\n��������Ҫɾ����ѧ����ѧ�ţ�");
											scanf("%s", stuID);
											getchar();
											while(Temp != NULL)
											{
												if(!strcmp(Temp->StudentID, stuID) )
												{
													PreNode->next = Temp->next;
													free(Temp);
													NodeNum--;
													temp = 0;
													break;
												}
												else
												{
													PreNode = Temp;
													Temp = Temp->next;
												}	
											}
											if(temp)
											{
												printf("\nѧ������������ѧ�������ڡ�\n\n");
											}
											else
											{
												printf("\n��ѧ����Ϣ��ɾ����\n\n"); 
											}
											temp = 0;
											break;
										}
										else if(temp == 2) 
										{
											printf("\n��������Ҫɾ����רҵ��");
											scanf("%s", stuMajor);
											getchar();
											printf("\n��������Ҫɾ�����꼶��");
											scanf("%s", stuGrade);
											getchar();
											printf("\n�ٴ�ȷ���Ƿ�ɾ��%s%s����ѧ����(\"��\"�� 1��\"��\"�� 2)", stuMajor, stuGrade);
											while(temp)
											{
												scanf("%d", &temp);
												getchar(); 
												if(temp == 1)
												{
													while(Temp != NULL)
													{
														if(!strcmp(Temp->MajorName, stuMajor) && !strcmp(Temp->Grade, stuGrade) )
														{
															tNode = Temp;
															Temp = Temp->next; 
															free(tNode);
															PreNode->next = Temp;
															NodeNum--;
															temp = 0;
														}
														else
														{
															PreNode = Temp;
															Temp = Temp->next;
														}	
													}
													if(temp)
													{
														printf("\n��Ϣ����������רҵ�꼶ѧ�������ڡ�\n\n");
														break;
													}
													else
													{
														printf("\n��רҵ���꼶��ѧ����Ϣ��ɾ����\n\n"); 
														break;
													}
												}
												else if(temp == 2)
												{
													printf("\nȡ��ɾ����\n\n");
													break;
												}
												else
												{
													printf("\nѡ������������ѡ��\n"); 
													temp = 1; 
												}
											}
											temp = 0;
											break;
										}	
										else
										{
											printf("\nѡ������������ѡ��\n"); 
											temp = 1; 
										}
									}
									system("pause");
								}
								
						  	}	break;	
						  	
				//�ò���ִ�и���ѧ����Ϣ	
				case 'D' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									char ch, stuID[12];
									StuData *Temp = Head->next;
									printf("\n��������Ҫ���ĵ�ѧ����ѧ�ţ�");
									scanf("%s", stuID);
									getchar();
									while(Temp != NULL)
									{
										if(!strcmp(Temp->StudentID, stuID) )
										{
											printf("\n��������Ҫ���ĵ�����(�����Ӧ���ַ�)��\n");
											printf("A:����\t\tB:����\t\tC:�Ա�\nD:����\t\tE:����״��\tF:������ò\n"
												   "G:ѧ�����\tH:��ѧ����\tI:��ѧ��ʽ\n\n�����룺");
											scanf("%c", &ch);
											getchar(); 
											switch(ch)
											{
												//���ҵĸ��� 
												case 'A' : 	{
																printf("\n�����µĹ�����ѡ��һ������:\n\n");
																
															    int i;
															    //�ļ�������ʾ 
																for(i = 0; i < MaxCountry; i++)
																{
																	printf("%-25s", strCountry[i]);
																	if((i + 1) % 5 == 0)
																		printf("\n");
																}
																while(temp)
																{
																	printf("\n\n�����������ź�(�س�)��"); 
																	char t[4];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1'; 
																		t[2] = '\0';
																	}
																	Temp->Country = ChToNum(t);
																	
																	if( Temp->Country >= 1 && Temp->Country <= 197 )
																	{
																		printf("\n������Ĺ����ǣ�%s\n\n",strCountry[Temp->Country - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																}
																
															} break;
												
												//�����ĸ���			
												case 'B' : 	{
																while(temp)
																{
																	printf("\n������������"); 
																	scanf("%s", Temp->Name);
																	getchar();
																	if( CheckName(Temp->Name, Temp->Country) )
																	{
																		printf("\n������������ǣ�%s\n\n", Temp->Name);
																		temp = 0;
																	}
																	else
																	{
																		printf("\n���������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//�Ա�ĸ���			
												case 'C' : 	{
																while(temp)
																{
																	printf("\n�������Ա�(��/Ů)��"); 
																	scanf("%s", Temp->Sex);
																	getchar();
																	if(!strcmp(Temp->Sex, "��") || !strcmp(Temp->Sex, "Ů"))
																	{
																		printf("\n��������Ա��ǣ�%s\n\n", Temp->Sex);
																		temp = 0;
																	}
																	else
																	{
																		printf("\n�Ա������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//����ĸ���			
												case 'D' : 	{	
																printf("\n�����µ�������ѡ��һ������:\n\n");
																
																//�ļ�������ʾ 
																for(int i = 0; i < MaxNation; i++)
																{
																	printf("%-20s", strNation[i]);
															        if((i + 1) % 5 ==0)   
																		printf("\n");
																}
																
															    while(temp)
																{
																	printf("\n\n������������ź�(�س�)��"); 
																	char t[3];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->Nation = ChToNum(t);
																	
																	if( Temp->Nation >= 1 && Temp->Nation <= 58 )
																	{
																		printf("\n��������ǣ�%s\n\n", strNation[Temp->Nation - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//����״���ĸ��� 
												case 'E' : 	{
																printf("\n�����µĻ���״��ѡ����ѡ��һ��:\n\n");
																
																//�ļ�������ʾ 
																for(int i = 0; i < MaxMarry; i++) 
																{  
																	printf("%-12s", strMarry[i]);
																} 
															    while(temp)
																{
																	printf("\n\n���������״����ź�(�س�)��"); 
																	char t[3];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1';
																	}
																	Temp->Marriage = ChToNum(t);
																	
																	if( Temp->Marriage >= 1 && Temp->Marriage <= 5 )
																	{
																		printf("\n��������ǣ�%s\n\n", strMarry[Temp->Marriage - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//������ò�ĸ���			
												case 'F' : 	{
															    printf("\n�����µ�������òѡ����ѡ��һ��:\n\n");
															    
																//�ļ�������ʾ 
																for(int i = 0; i < MaxFace; i++)
																{
																	printf("%-30s", strFace[i]);
																	if((i + 1) % 3 == 0)
																		printf("\n");
																}
																
															    while(temp)
																{
																	printf("\n\n������������ò��ź�(�س�)��"); 
																	char t[3];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->PoliticalFace = ChToNum(t);
																	
																	if( Temp->PoliticalFace >= 1 && Temp->PoliticalFace <= 13 )
																	{
																		printf("\n��������ǣ�%s\n\n", strFace[Temp->PoliticalFace - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//ѧ�����ĸ���			
												case 'G' : 	{
																printf("\n�����µ�ѧ�����ѡ����ѡ��һ��:\n\n");
																
																//�ļ�������ʾ 
																for(int i = 0; i < MaxType; i++)
																{
																	printf("%-15s", strType[i]);
																}
																
															    while(temp)
																{
																	printf("\n\n������ѧ�������ź�(�س�)��"); 
																	char t[3];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->StudentType = ChToNum(t);
																	
																	if( Temp->StudentType >= 1 && Temp->StudentType <= 2 )
																	{
																		printf("\n��������ǣ�%s\n\n", strType[Temp->StudentType - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//��ѧ���µĸ���		
												case 'H' : 	{
																while(temp)
																{
																	printf("\n��������ѧ����(xxxx.xx.xx)��"); 
																	scanf("%s", Temp->SchoolDate);
																	getchar(); 
																	if( CheckDate(Temp->SchoolDate) )
																	{
																		if(Temp->SchoolDate[2] != Temp->StudentID[2] || Temp->SchoolDate[3] != Temp->StudentID[3])
																			printf("\n������������ѧ����ݲ�һ�¡�\n"); 
																		printf("\n���������ѧ�����ǣ�%s\n\n", Temp->SchoolDate);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��ѧ���������������������롣\n"); 
																	}
																} 
																
															} break;
												
												//��ѧ��ʽ�ĸ���			
												case 'I' : 	{
															    printf("\n�����µ���ѧ��ʽѡ����ѡ��һ��:\n\n");
																
																//�ļ�������ʾ 
																for(int i = 0; i < MaxWay; i++)
																{
																	printf("%-15s", strWay[i]);	
																} 
																
															    while(temp)
																{
																	printf("\n\n��������ѧ��ʽ��ź�(�س�)��"); 
																	char t[3];
																	gets(t);
																	
																	//������س���Ĭ��ֵ����
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1';
																	}
																	Temp->EnterWay = ChToNum(t);
																	
																	if( Temp->EnterWay >= 1 && Temp->EnterWay <= 3 )
																	{
																		printf("\n��������ǣ�%s\n\n", strWay[Temp->EnterWay - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n��������������������롣\n"); 
																	}
																} 
																
															} break;
												
												default  :  {
																printf("\n�������\n\n"); 
															} 	break;		
											}
											temp = 0;
											break;
										}
										else
										{
											Temp = Temp->next;
										}
									}
									if(temp)
									{
										printf("\nѧ������������ѧ�������ڡ�\n\n");
									}
									system("pause");
								}

						  	} 	break;
						  	
				//�ò���ִ�в�ѯѧ����Ϣ 
				case 'E' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									char stuID[12];
									StuData *Temp = Head->next;
									
									//�ֱ𵥶���ѯ������ϲ�ѯ�Ը�����˵��Ϊ���֣����Խ�����ѧ������ѯ 
									printf("\n��������Ҫ��ѯ��ѧ����ѧ�ţ�"); 
									scanf("%s", stuID);
									getchar();
									while(Temp != NULL)
									{
										if(!strcmp(Temp->StudentID, stuID) )
										{
											printf("\n\nѧ��\t\t����\t�Ա�\t��������\t����\t������ò"
										   		   "\t���֤��\t\tѧԺ����\tרҵ����\t\t�꼶\t�༶��\n");
										   		   
										   	printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\n\n",
													Temp->StudentID, 		Temp->Name,          				Temp->Sex,      				
													Temp->BirthDate,		(Temp->Nation != 0)? strNation[Temp->Nation - 1] + 4 : "X", 	
													(Temp->PoliticalFace != 0)? strFace[Temp->PoliticalFace - 1] + 4 : "X	",
													Temp->idNumber,			Temp->CollegeName,					Temp->MajorName,				
													Temp->Grade,			Temp->ClassNum ); 
											temp = 0;
											break;
										}
										else
										{
											Temp = Temp->next;
										}	
									}
									if(temp)
									{
										printf("\nѧ������������ѧ�������ڡ�\n\n");
									}
									system("pause"); 	 
								}

						  	} 	break;
						  	
				//�ò���ִ��ѧ������ͳ�� 
				case 'F' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int sum = 0, temp = 1, choice; 
									char stuMajor[30], stuGrade[5], stuSex[3], stuCollege[20], stuTeacher[10];
									StuData *Temp = Head->next;
									
									printf("\n��ѡ��ͳ�����Ͷ�Ӧ�����(1.רҵ+�꼶+�Ա�  2.ѧԺ  3.����Ա)��");
									scanf("%d", &choice);
									getchar();
									if(choice == 1)
									{
										printf("\n������רҵ���ƣ�"); 
										scanf("%s", stuMajor);
										getchar();
										printf("\n�������꼶��"); 
										scanf("%s", stuGrade);
										getchar();
										printf("\n�������Ա�"); 
										scanf("%s", stuSex);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->MajorName, stuMajor) && !strcmp(Temp->Grade, stuGrade)
											   && !strcmp(Temp->Sex, stuSex) )
											{
												if(sum == 0)
												{
													printf("\n\nѧ��\t\t����\t�Ա�\t��������\t����\t������ò"
											   			   "\t���֤��\t\tѧԺ����\tרҵ����\t\t�꼶\t�༶��\n");
												}
												printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\n\n",
														Temp->StudentID, 		Temp->Name,          				Temp->Sex,      				
														Temp->BirthDate,		(Temp->Nation != 0)? strNation[Temp->Nation - 1] + 4 : "X", 	
														(Temp->PoliticalFace != 0)? strFace[Temp->PoliticalFace - 1] + 4 : "X	",
														Temp->idNumber,			Temp->CollegeName,					Temp->MajorName,				
														Temp->Grade,			Temp->ClassNum ); 
												sum++;
												temp = 0;
											}
											Temp = Temp->next;
										}
										if(temp)
										{
											printf("\n��Ϣ���������û�з���Ҫ���ѧ����\n\n");
										}
										else
										{
											printf("\n����Ҫ���ѧ��������Ϊ%d�ˡ�\n\n", sum);
										}
									}
									else if(choice == 2)
									{
										printf("\n������ѧԺ���ƣ�"); 
										scanf("%s", stuCollege);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->CollegeName, stuCollege) )
											{
												if(sum == 0)
												{
													printf("\n\nѧ��\t\t����\t�Ա�\t��������\t����\t������ò"
											   			   "\t���֤��\t\tѧԺ����\tרҵ����\t\t�꼶\t�༶��\n");
												}
												printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\n\n",
														Temp->StudentID, 		Temp->Name,          				Temp->Sex,      				
														Temp->BirthDate,		(Temp->Nation != 0)? strNation[Temp->Nation - 1] + 4 : "X", 	
														(Temp->PoliticalFace != 0)? strFace[Temp->PoliticalFace - 1] + 4 : "X	",
														Temp->idNumber,			Temp->CollegeName,					Temp->MajorName,				
														Temp->Grade,			Temp->ClassNum ); 
												sum++;
												temp = 0;
											}
											Temp = Temp->next;
										}
										if(temp)
										{
											printf("\n��Ϣ���������û�з���Ҫ���ѧ����\n\n");
										}
										else
										{
											printf("\n����Ҫ���ѧ��������Ϊ%d�ˡ�\n\n", sum);
										}
									}
									else if(choice == 3)
									{
										printf("\n�����븨��Ա���ƣ�"); 
										scanf("%s", stuTeacher);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->Teacher, stuTeacher) )
											{
												if(sum == 0)
												{
													printf("\n\nѧ��\t\t����\t�Ա�\t��������\t����\t������ò"
											   			   "\t���֤��\t\tѧԺ����\tרҵ����\t\t�꼶\t�༶��\n");
												}
												printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\n\n",
														Temp->StudentID, 		Temp->Name,          				Temp->Sex,      				
														Temp->BirthDate,		(Temp->Nation != 0)? strNation[Temp->Nation - 1] + 4 : "X", 	
														(Temp->PoliticalFace != 0)? strFace[Temp->PoliticalFace - 1] + 4 : "X	",
														Temp->idNumber,			Temp->CollegeName,					Temp->MajorName,				
														Temp->Grade,			Temp->ClassNum ); 
												sum++;
												temp = 0;
											}
											Temp = Temp->next;
										}
										if(temp)
										{
											printf("\n��Ϣ���������û�з���Ҫ���ѧ����\n\n");
										}
										else
										{
											printf("\n%s��ʦ��ѧ��������Ϊ%d�ˡ�\n\n", stuTeacher, sum);
										}
									}
									else
									{
										printf("\n����������\n\n");
									}
									
									system("pause"); 	 
								}
								
						  	} 	break;
						  	
				//�ò���ִ��ѧ����Ϣ���� 
				case 'G' :	{	
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									int cnt;     //����cnt���ڼ�¼�������һ��ʱ������Ĵ���
									StuData *Temp, *PreNode, *Node1;
									do
									{	
										cnt = 0;
										PreNode = Head;
										Node1 = PreNode->next;
										while(Node1->next != NULL)
										{
											Temp = Node1->next;
											if( strcmp(Node1->StudentID, Temp->StudentID) > 0 )   
											{
												Node1->next = Temp->next;
												Temp->next = PreNode->next;
												PreNode->next = Temp;
												PreNode = PreNode->next; 
												cnt++;
											}		 
											else
											{
												PreNode = PreNode->next; 
												Node1 = Node1->next;
											}
											
										}
									} while(cnt != 0);
									printf("\nѧ����Ϣ�Ѹ���ѧ��˳��������ɡ�\n\n");
									system("pause"); 
								}
								
						  	} 	break;
						  	
				//�ò���ִ����ʾѧ����Ϣ 
				case 'H' :	{
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									printf("\n\nѧ��\t\t����\t�Ա�\t��������\t����\t������ò"
										   "\t���֤��\t\tѧԺ����\tרҵ����\t\t�꼶\t�༶��\n");
									
									StuData *Temp = Head->next;	   
									while(Temp != NULL)
									{
										printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s\t%s\n",
												Temp->StudentID, 		Temp->Name,          				Temp->Sex,      				
												Temp->BirthDate,		(Temp->Nation != 0)? strNation[Temp->Nation - 1] + 4 : "X", 	
												(Temp->PoliticalFace != 0)? strFace[Temp->PoliticalFace - 1] + 4 : "X	",
												Temp->idNumber,			Temp->CollegeName,					Temp->MajorName,				
												Temp->Grade,			Temp->ClassNum); 
										
										Temp = Temp->next;
									}
									printf("\n");
								}
								
						  	} 	break;
						  	
				//�ò���ִ�б���ѧ����Ϣ 
				case 'I' :	{	
								if(Head == NULL)
								{
									printf("\n����ѧ����Ϣ��\n\n");
									system("pause");
								}
								else
								{
									char FileName[50];    
									printf("\n��������Ҫ������ļ���(ע����Ӻ�׺)��");
									gets(FileName);
									FILE * File = fopen(FileName, "w+");   //���ļ�
									if (File == NULL)     //�����ļ�ʧ�����˳�
									{
										printf("\n�ļ���ʧ�ܡ�\n\n");	
									}
									else
									{
										StuData *Temp = Head->next;	   
										while(Temp != NULL)
										{
											fprintf(File, "%s\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%s\t%d\t%s\t%d\t%s\t%s\n",
													Temp->StudentID, Temp->Country,  Temp->Name, Temp->Sex, Temp->BirthDate,
													Temp->Nation, 	 Temp->Marriage, Temp->PoliticalFace,   Temp->idNumber,
													Temp->StudentType, Temp->SchoolDate, Temp->EnterWay,  Temp->Grade, Temp->ClassNum); 
											
											Temp = Temp->next;  
										}
										printf("\n�ѽ�ȫ��ѧ����Ϣд��%s�С�\n\n", FileName);
									}
									fclose(File);
									system("pause");
								}
								
						  	} 	break;
			}	
		}	 
		printf("\n");
		Copyright();        
		Menu();
		printf("\n��ѡ��(A,B,C,D,E,F,G,H,I,J):");  
		scanf("%c", &input);
		getchar();
	}
	return 0; 
}
