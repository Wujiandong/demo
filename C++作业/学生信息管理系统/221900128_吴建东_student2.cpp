#include <stdio.h>
#include "221900128_吴建东_student.h"

int main()
{
	int NodeNum = 0;   //声明学生数据总结点数
	char input;        //声明用户选择变量 
	Copyright();       //显示版权
	Menu();            //显示菜单界面
	printf("\n请选择(A,B,C,D,E,F,G,H,I,J):");
	scanf("%c", &input);
	getchar();
	while(input != 'J')
	{
		if((input < 'A') || (input > 'J'))
			printf("\n选择错误，请重新选择......\n");
		else
		{
			switch(input)
			{
				//该部分执行录入学生信息 
				case 'A' :	{
								int temp = 1;      
								char i; 		 
								Head = (StuData *)malloc(sizeof(StuData)); //为头结点申请空间 
								End = Head;
								
								FileToArray( MaxNum, MaxCountry, MaxNation, MaxMarry,   MaxFace, 
                  							 MaxID,  MaxType,    MaxWay,    MaxCollege, MaxTeacher ); //将文件内容写入数组
								while(temp)
								{
									printf("\n请选择输入学生信息的方式(1.键盘输入 2.文件输入)：");
									scanf("%c", &i);    //获取用户输入学生信息的方式 
									getchar();
									
									//键盘输入 
									if(i == '1')
									{
										while(temp)
										{
											StuData *p;
											p = (StuData *)malloc(sizeof(StuData));
											
											printf("\n接下来录入第%d个学生的信息。\n", NodeNum + 1); 
											
											//学号的输入
											while(temp)
											{
												printf("\n请输入学号："); 
												scanf("%s", p->StudentID);
												getchar();
												printf("\n");
												if( CheckStuID(p->StudentID, strNum, NodeNum) )  //对输入的学号进行检验 
												{
													printf("您输入的学号是：%s", p->StudentID);
													temp = 0;
												}
												else
												{
													printf("请重新输入。"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//国家的输入
											printf("\n在以下的国家中选择一个国家:\n\n");
											
										    int i;
										    //文件内容显示 
											for(i = 0; i < MaxCountry; i++)
											{
												printf("%-25s", strCountry[i]);
												if((i + 1) % 5 == 0)
													printf("\n");
											}
													
											while(temp)
											{
												printf("\n\n请输入国家序号和(回车)："); 
												char t[4];
												gets(t);
												
												//对输入回车的默认值处理
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
													printf("您输入的国家是：%s",strCountry[p->Country - 1]);
													temp = 0; 
												}
												else
												{
													printf("国家序号输入有误，请重新输入。"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//姓名的输入
											while(temp)
											{
												printf("\n请输入姓名："); 
												scanf("%s", p->Name);
												getchar();
												printf("\n");
												if( CheckName(p->Name, p->Country) )
												{
													printf("您输入的姓名是：%s", p->Name);
													temp = 0;
												}
												else
												{
													printf("请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//性别的输入
											while(temp)
											{
												printf("\n请输入性别(男/女)："); 
												scanf("%s", p->Sex);
												getchar();
												printf("\n");
												if(!strcmp(p->Sex, "男") || !strcmp(p->Sex, "女"))
												{
													printf("您输入的性别是：%s", p->Sex);
													temp = 0;
												}
												else
												{
													printf("性别输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//出生日期的输入
											while(temp)
											{
												printf("\n请输入出生日期(xxxx.xx.xx)："); 
												scanf("%s", p->BirthDate);
												getchar(); 
												printf("\n");
												if( CheckDate(p->BirthDate) )
												{
													if(CheckRange(p->BirthDate))
													{
														printf("您输入的出生日期是：%s", p->BirthDate);
														temp = 0;
													} 
													else
														printf("请重新输入。");
												}
												else 
												{
													printf("请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//民族的输入
											printf("\n在以下的民族中选择一个民族:\n\n");
											
											//文件内容显示 
											for(i = 0; i < MaxNation; i++)
											{
												printf("%-20s", strNation[i]);
										        if((i + 1) % 5 ==0)   
													printf("\n");
											}
											
										    while(temp)
											{
												printf("\n\n请输入民族序号和(回车)："); 
												char t[3];
												gets(t);
												
												//对输入回车的默认值处理
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->Nation = ChToNum(t);
												printf("\n");
												if( p->Nation >= 1 && p->Nation <= 58 )
												{
													printf("您输入的是：%s", strNation[p->Nation - 1]);
													temp = 0; 
												}
												else
												{
													printf("序号输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											//婚姻状况的输入 
											printf("\n在以下的婚姻状况选项中选择一个:\n\n");
											
											//文件内容显示 
											for(i = 0; i < MaxMarry; i++) 
											{  
												printf("%-12s", strMarry[i]);
											} 
										    while(temp)
											{
												printf("\n\n请输入婚姻状况序号和(回车)："); 
												char t[3];
												gets(t);
												
												//对输入回车的默认值处理
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; 
													t[1] = '1';
												}
												p->Marriage = ChToNum(t);
												
												printf("\n");
												if( p->Marriage >= 1 && p->Marriage <= 5 )
												{
													printf("您输入的是：%s", strMarry[p->Marriage - 1]);
													temp = 0; 
												}
												else
												{
													printf("序号输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//政治面貌的输入 
										    printf("\n在以下的政治面貌选项中选择一个:\n\n");
										    
											//文件内容显示 
											for(i = 0; i < MaxFace; i++)
											{
												printf("%-30s", strFace[i]);
												if((i + 1) % 3 == 0)
													printf("\n");
											}
											
										    while(temp)
											{
												printf("\n\n请输入政治面貌序号和(回车)："); 
												char t[3];
												gets(t);
												
												//对输入回车的默认值处理
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->PoliticalFace = ChToNum(t);
												
												printf("\n");
												if( p->PoliticalFace >= 1 && p->PoliticalFace <= 13 )
												{
													printf("您输入的是：%s", strFace[p->PoliticalFace - 1]);
													temp = 0; 
												}
												else
												{
													printf("序号输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//身份证号的输入
											while(temp)
											{
												printf("\n请输入身份证号和(回车)："); 
												gets(p->idNumber);
												printf("\n");
												if(p->Country != 1)
													strcpy(p->idNumber, "外籍学生暂无"); 
												if( CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
												{
													printf("您输入的是：%s", p->idNumber);
													temp = 0; 
												}
												else
												{
													printf("请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//学生类别的输入
											printf("\n在以下的学生类别选项中选择一个:\n\n");
											
											//文件内容显示 
											for(i = 0; i < MaxType; i++)
											{
												printf("%-15s", strType[i]);
											}
											
										    while(temp)
											{
												printf("\n\n请输入学生类别序号和(回车)："); 
												char t[3];
												gets(t);
												
												//对输入回车的默认值处理
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; t[1] = '1';
												}
												p->StudentType = ChToNum(t);
												
												printf("\n");
												if( p->StudentType >= 1 && p->StudentType <= 2 )
												{
													printf("您输入的是：%s", strType[p->StudentType - 1]);
													temp = 0; 
												}
												else
												{
													printf("序号输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											//入学年月的输入
											while(temp)
											{
												printf("\n请输入入学年月(xxxx.xx.xx)："); 
												scanf("%s", p->SchoolDate);
												getchar(); 
												printf("\n");
												if( CheckDate(p->SchoolDate) )
												{
													if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
														printf("您输入的年份与学号年份不一致。"); 
													printf("您输入的入学年月是：%s", p->SchoolDate);
													temp = 0; 
												}
												else
												{
													printf("请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1;
											
											//入学方式的输入
										    printf("\n在以下的入学方式选项中选择一个:\n\n");
											
											//文件内容显示 
											for(i = 0; i < MaxWay; i++)
											{
												printf("%-15s", strWay[i]);	
											} 
											
										    while(temp)
											{
												printf("\n\n请输入入学方式序号和(回车)："); 
												char t[3];
												gets(t);
												
												//对输入回车的默认值处理
												if(!strcmp(t, "\0"))
												{
													t[0] = '0'; 
													t[1] = '1';
												}
												p->EnterWay = ChToNum(t);
												
												printf("\n");
												if( p->EnterWay >= 1 && p->EnterWay <= 3 )
												{
													printf("您输入的是：%s", strWay[p->EnterWay - 1]);
													temp = 0; 
												}
												else
												{
													printf("序号输入有误，请重新输入。"); 
												}
												printf("\n");
											} 
											temp = 1; 
											
											
											//年级的输入
											while(temp)
											{
												printf("\n请输入年级(20xx)：");
												gets(p->Grade);
												
												//对输入回车时的默认值处理
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
														printf("您输入的是：%s", p->Grade);
														temp = 0;
													}
													else
													{
														printf("您输入的年级与学号中的年级代码不匹配。(已录入)");
														temp = 0;
													} 
												}
												else
												{
													printf("输入有误，请重新输入。"); 
												}
												printf("\n");
											}
											temp = 1;
																				
											//班级号的输入 
											while(temp)
											{
												printf("\n请输入班级号(01-09)和(回车):");
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
													printf("您输入的是：%s", p->ClassNum);
													temp = 0; 
												}
												else
												{
													printf("班级号与学号的班级代码不匹配，请重新输入。"); 
												}
												printf("\n");
											}
											temp = 1;
											
											//学院、专业名称、学制和培养层次的输入 
											for(int i = 0; i < MaxCollege; i++)
											{
												if(strCollege[i][0][0] == p->StudentID[0] && strCollege[i][0][1] == p->StudentID[1] &&
												   strCollege[i][2][0] == p->StudentID[4] && strCollege[i][2][1] == p->StudentID[5]  )
												{
													strcpy(p->CollegeName, strCollege[i][1]);
													strcpy(p->MajorName, strCollege[i][3]);
													strcpy(p->Arrange, strCollege[i][4]);
													strcpy(p->TrainLevel, strCollege[i][5]);
												
													printf("\n根据学号可得：\n\n对应的学院为：%s\n", p->CollegeName);
													printf("\n对应的专业为：%s\n", p->MajorName);
													printf("\n对应的学制为：%s\n", p->Arrange);
													printf("\n对应的培养层次为：%s\n", p->TrainLevel);
													
													temp = 0;
													break;
												}
											} 
											if(temp)
											{
												printf("\n学号对应的学院专业信息不足。暂时无法录入。\n");
												strcpy(p->CollegeName, "未知");
												strcpy(p->MajorName, "未知");
												strcpy(p->Arrange, "未知");
												strcpy(p->TrainLevel, "未知");
											}
											temp = 1; 
											
											//辅导员的输入
											for(int i = 0; i < MaxTeacher; i++)
											{
												if( !strcmp(p->MajorName, strTeacher[i][0]) )
												{
													strcpy(p->Teacher, strTeacher[i][1]);
													printf("\n%s的辅导员为：%s\n", p->MajorName, p->Teacher);
													temp = 0;
													break;
												}
											} 
											if(temp)
											{
												printf("\n学号对应的专业辅导员信息不足。暂时无法录入。\n");
												strcpy(p->Teacher, "未知");
											}
											temp = 1;
											
											End->next = p;
											End = p;
											End->next = NULL;
											NodeNum++; 
											
											printf("\n是否输入下一个学生的信息？(\"是\"按 1，\"否\"按 2)");
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
													printf("\n选择有误，请重新选择。\n"); 
													temp = 1; 
												}
											}
										}
									}
									
									//文件输入 
									else if(i == '2')
									{
										char FileName[50];    //声明自定义文件名
										printf("\n请输入文件名称(注意添加后缀)：");
										gets(FileName);
										FILE * File = fopen(FileName, "r+");   //打开文件
										if (File == NULL)     //若打开文件失败则退出
										{
											printf("\n文件打开失败。\n\n");
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
														
												printf("\n第%d个学生：", ++Num);
												
												//检验学号 
												if( !CheckStuID(p->StudentID, strNum, NodeNum) ) 
												{
													strcpy(p->StudentID, "X");
													printf("录入失败。\n");
													continue;
												}
												
												//检验国家 
												if( p->Country < 1 || p->Country > 197 )
												{
													printf("国家序号有误。");
													p->Country = 1;  //赋默认值1 
												}
												
												//检验姓名 
												if( !CheckName(p->Name, p->Country) )
												{
													strcpy(p->Name, "X");
												}
												
												//检验性别 
												if( strcmp(p->Sex, "男") && strcmp(p->Sex, "女"))
												{
													printf("性别有误。"); 
													strcpy(p->Sex, "X");
												}
												
												//检验出生日期 
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
												
												//检验民族 
												if( p->Nation < 1 || p->Nation > 58 )
												{
													printf("民族序号有误。"); 
													p->Nation = 0;
												}

												//检验婚姻状况 
												if( p->Marriage < 1 || p->Marriage > 5 )
												{
													printf("婚姻状况序号有误。"); 
													p->Marriage = 0;
												}
												
												//检验政治面貌 
												if( p->PoliticalFace < 1 || p->PoliticalFace > 13 )
												{
													printf("政治面貌序号有误。"); 
													p->PoliticalFace = 0;
												}
											
												//检验身份证号 
												if( !CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
												{
													strcpy(p->idNumber, "X		"); 
												}
												
												//检验学生类别 
												if( p->StudentType < 1 || p->StudentType > 2 )
												{
													printf("学生类别序号有误。"); 
													p->StudentType = 0;
												}
												
												//检验入学日期 
												if( !CheckDate(p->SchoolDate) )
												{
													strcpy(p->SchoolDate, "X"); 
												}
												else
												{
													if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
														printf("入学年份与学号年份不一致。"); 
												}
												
												//检验入学方式 
												if( p->EnterWay < 1 || p->EnterWay > 3 )
												{
													printf("入学方式序号有误。"); 
													p->EnterWay = 0; 
												}
											
												//检验年级 
												if(isdigit(p->Grade[0]) && isdigit(p->Grade[1]) && 
												   isdigit(p->Grade[2]) && isdigit(p->Grade[3])  )
												{
													if(p->Grade[2] != p->StudentID[2] || p->Grade[3] != p->StudentID[3])
													{
														printf("年级与学号年级不匹配。"); 
														strcpy(p->Grade, "X"); 
													}
												}
												else
												{
													printf("年级出现非数字字符。"); 
													strcpy(p->Grade, "X"); 
												}
												
												//检验班级号							
												if( ChToNum(p->ClassNum) < 1 || ChToNum(p->ClassNum) > 9 || (p->ClassNum[0] == '0' && p->ClassNum[1] != p->StudentID[6]))
												{
													printf("班级与学号班级不匹配。"); 
													strcpy(p->ClassNum, "X");
												}
											
												//录入学院、专业名称、学制和培养层次 
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
													strcpy(p->CollegeName, "未知");
													strcpy(p->MajorName, "未知");
													strcpy(p->Arrange, "未知");
													strcpy(p->TrainLevel, "未知");
													printf("学号对应的学院专业信息不足。");
												}
												temp = 1;
												
												//录入辅导员名称 
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
													strcpy(p->Teacher, "未知");
													printf("\n学号对应的专业辅导员不足。\n");
												}
												temp = 1;
								
												End->next = p;
												End = p;
												End->next = NULL;
												NodeNum++; 
												printf("\n");
											}
											printf("\n文件内学生信息已录入。\n\n");
											system("pause");
											temp = 0;
										}
									}
									else
										printf("\n输入错误，请重新输入。\n");
								}
							} 	break;
							
				//该部分执行增加学生信息 
				case 'B' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									while(temp)
									{
										StuData *p;
										p = (StuData *)malloc(sizeof(StuData));
										
										printf("\n接下来录入第%d个学生的信息。\n", NodeNum + 1); 
										
										//学号的输入
										while(temp)
										{
											printf("\n请输入要添加的学生的学号："); 
											scanf("%s", p->StudentID);
											getchar();
											printf("\n");
											if( CheckStuID(p->StudentID, strNum, NodeNum) )  //对输入的学号进行检验 
											{
												printf("您输入的学号是：%s", p->StudentID);
												temp = 0;
											}
											else
											{
												printf("请重新输入。"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//国家的输入
										printf("\n在以下的国家中选择一个国家:\n\n");
										
									    int i;
									    //文件内容显示 
										for(i = 0; i < MaxCountry; i++)
										{
											printf("%-25s", strCountry[i]);
											if((i + 1) % 5 == 0)
												printf("\n");
										}
												
										while(temp)
										{
											printf("\n\n请输入国家序号和(回车)："); 
											char t[4];
											gets(t);
											
											//对输入回车的默认值处理
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
												printf("您输入的国家是：%s",strCountry[p->Country - 1]);
												temp = 0; 
											}
											else
											{
												printf("国家序号输入有误，请重新输入。"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//姓名的输入
										while(temp)
										{
											printf("\n请输入姓名："); 
											scanf("%s", p->Name);
											getchar();
											printf("\n");
											if( CheckName(p->Name, p->Country) )
											{
												printf("您输入的姓名是：%s", p->Name);
												temp = 0;
											}
											else
											{
												printf("请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//性别的输入
										while(temp)
										{
											printf("\n请输入性别(男/女)："); 
											scanf("%s", p->Sex);
											getchar();
											printf("\n");
											if(!strcmp(p->Sex, "男") || !strcmp(p->Sex, "女"))
											{
												printf("您输入的性别是：%s", p->Sex);
												temp = 0;
											}
											else
											{
												printf("性别输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//出生日期的输入
										while(temp)
										{
											printf("\n请输入出生日期(xxxx.xx.xx)："); 
											scanf("%s", p->BirthDate);
											getchar(); 
											printf("\n");
											if( CheckDate(p->BirthDate) )
											{
												if(CheckRange(p->BirthDate))
												{
													printf("您输入的出生日期是：%s", p->BirthDate);
													temp = 0;
												} 
												else
													printf("请重新输入。");
											}
											else 
											{
												printf("请重新输入。\n"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//民族的输入
										printf("\n在以下的民族中选择一个民族:\n\n");
										
										//文件内容显示 
										for(i = 0; i < MaxNation; i++)
										{
											printf("%-20s", strNation[i]);
									        if((i + 1) % 5 ==0)   
												printf("\n");
										}
										
									    while(temp)
										{
											printf("\n\n请输入民族序号和(回车)："); 
											char t[3];
											gets(t);
											
											//对输入回车的默认值处理
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->Nation = ChToNum(t);
											printf("\n");
											if( p->Nation >= 1 && p->Nation <= 58 )
											{
												printf("您输入的是：%s", strNation[p->Nation - 1]);
												temp = 0; 
											}
											else
											{
												printf("序号输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										//婚姻状况的输入 
										printf("\n在以下的婚姻状况选项中选择一个:\n\n");
										
										//文件内容显示 
										for(i = 0; i < MaxMarry; i++) 
										{  
											printf("%-12s", strMarry[i]);
										} 
									    while(temp)
										{
											printf("\n\n请输入婚姻状况序号和(回车)："); 
											char t[3];
											gets(t);
											
											//对输入回车的默认值处理
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; 
												t[1] = '1';
											}
											p->Marriage = ChToNum(t);
											
											printf("\n");
											if( p->Marriage >= 1 && p->Marriage <= 5 )
											{
												printf("您输入的是：%s", strMarry[p->Marriage - 1]);
												temp = 0; 
											}
											else
											{
												printf("序号输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//政治面貌的输入 
									    printf("\n在以下的政治面貌选项中选择一个:\n\n");
									    
										//文件内容显示 
										for(i = 0; i < MaxFace; i++)
										{
											printf("%-30s", strFace[i]);
											if((i + 1) % 3 == 0)
												printf("\n");
										}
										
									    while(temp)
										{
											printf("\n\n请输入政治面貌序号和(回车)："); 
											char t[3];
											gets(t);
											
											//对输入回车的默认值处理
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->PoliticalFace = ChToNum(t);
											
											printf("\n");
											if( p->PoliticalFace >= 1 && p->PoliticalFace <= 13 )
											{
												printf("您输入的是：%s", strFace[p->PoliticalFace - 1]);
												temp = 0; 
											}
											else
											{
												printf("序号输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//身份证号的输入
										while(temp)
										{
											printf("\n请输入身份证号和(回车)："); 
											gets(p->idNumber);
											printf("\n");
											if(p->Country != 1)
												strcpy(p->idNumber, "外籍学生暂无"); 
											if( CheckID(p->idNumber, p->BirthDate, p->Sex, strID, 3100, NodeNum) || p->Country != 1 )
											{
												printf("您输入的是：%s", p->idNumber);
												temp = 0; 
											}
											else
											{
												printf("请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//学生类别的输入
										printf("\n在以下的学生类别选项中选择一个:\n\n");
										
										//文件内容显示 
										for(i = 0; i < MaxType; i++)
										{
											printf("%-15s", strType[i]);
										}
										
									    while(temp)
										{
											printf("\n\n请输入学生类别序号和(回车)："); 
											char t[3];
											gets(t);
											
											//对输入回车的默认值处理
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; t[1] = '1';
											}
											p->StudentType = ChToNum(t);
											
											printf("\n");
											if( p->StudentType >= 1 && p->StudentType <= 2 )
											{
												printf("您输入的是：%s", strType[p->StudentType - 1]);
												temp = 0; 
											}
											else
											{
												printf("序号输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										//入学年月的输入
										while(temp)
										{
											printf("\n请输入入学年月(xxxx-xx-xx)："); 
											scanf("%s", p->SchoolDate);
											getchar(); 
											printf("\n");
											if( CheckDate(p->SchoolDate) )
											{
												if(p->SchoolDate[2] != p->StudentID[2] || p->SchoolDate[3] != p->StudentID[3])
													printf("您输入的年份与学号年份不一致。"); 
												printf("您输入的入学年月是：%s", p->SchoolDate);
												temp = 0; 
											}
											else
											{
												printf("请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1;
										
										//入学方式的输入
									    printf("\n在以下的入学方式选项中选择一个:\n\n");
										
										//文件内容显示 
										for(i = 0; i < MaxWay; i++)
										{
											printf("%-15s", strWay[i]);	
										} 
										
									    while(temp)
										{
											printf("\n\n请输入入学方式序号和(回车)："); 
											char t[3];
											gets(t);
											
											//对输入回车的默认值处理
											if(!strcmp(t, "\0"))
											{
												t[0] = '0'; 
												t[1] = '1';
											}
											p->EnterWay = ChToNum(t);
											
											printf("\n");
											if( p->EnterWay >= 1 && p->EnterWay <= 3 )
											{
												printf("您输入的是：%s", strWay[p->EnterWay - 1]);
												temp = 0; 
											}
											else
											{
												printf("序号输入有误，请重新输入。"); 
											}
											printf("\n");
										} 
										temp = 1; 
										
										
										//年级的输入
										while(temp)
										{
											printf("\n请输入年级(20xx)：");
											gets(p->Grade);
											
											//对输入回车时的默认值处理
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
													printf("您输入的是：%s", p->Grade);
													temp = 0;
												}
												else
												{
													printf("您输入的年级与学号中的年级代码不匹配。(已录入)");
													temp = 0;
												} 
											}
											else
											{
												printf("输入有误，请重新输入。"); 
											}
											printf("\n");
										}
										temp = 1;
																			
										//班级号的输入 
										while(temp)
										{
											printf("\n请输入班级号(01-09)和(回车):");
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
												printf("您输入的是：%s", p->ClassNum);
												temp = 0; 
											}
											else
											{
												printf("班级号与学号的班级代码不匹配，请重新输入。"); 
											}
											printf("\n");
										}
										temp = 1;
										
										//学院、专业名称、学制和培养层次的输入 
										for(int i = 0; i < MaxCollege; i++)
										{
											if(strCollege[i][0][0] == p->StudentID[0] && strCollege[i][0][1] == p->StudentID[1] &&
											   strCollege[i][2][0] == p->StudentID[4] && strCollege[i][2][1] == p->StudentID[5]  )
											{
												strcpy(p->CollegeName, strCollege[i][1]);
												strcpy(p->MajorName, strCollege[i][3]);
												strcpy(p->Arrange, strCollege[i][4]);
												strcpy(p->TrainLevel, strCollege[i][5]);
											
												printf("\n根据学号可得：\n\n对应的学院为：%s\n", p->CollegeName);
												printf("\n对应的专业为：%s\n", p->MajorName);
												printf("\n对应的学制为：%s\n", p->Arrange);
												printf("\n对应的培养层次为：%s\n", p->TrainLevel);
												
												temp = 0;
												break;
											}
										} 
										if(temp)
										{
											printf("\n学号对应的学院专业信息不足。暂时无法录入。\n");
											strcpy(p->CollegeName, "未知");
											strcpy(p->MajorName, "未知");
											strcpy(p->Arrange, "未知");
											strcpy(p->TrainLevel, "未知");
										}
										temp = 1; 
										
										//辅导员的输入
										for(int i = 0; i < MaxTeacher; i++)
										{
											if( !strcmp(p->MajorName, strTeacher[i][0]) )
											{
												strcpy(p->Teacher, strTeacher[i][1]);
												printf("\n%s的辅导员为：%s\n", p->MajorName, p->Teacher);
												temp = 0;
												break;
											}
										} 
										if(temp)
										{
											printf("\n学号对应的专业辅导员信息不足。暂时无法录入。\n");
											strcpy(p->Teacher, "未知");
										}
										temp = 1;
										
										End->next = p;
										End = p;
										End->next = NULL;
										NodeNum++; 
										
										printf("\n是否输入下一个学生的信息？(\"是\"按 1，\"否\"按 2)");
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
												printf("\n选择有误，请重新选择。\n"); 
												temp = 1; 
											}
										}
									}
								}
									
						  	} 	break;
							  	
				//该部分执行删除学生信息 
				case 'C' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int temp = 1;
									char stuID[12], stuMajor[30], stuGrade[6];
									StuData *Temp = Head->next;
									StuData *PreNode = Head;
									StuData *tNode;
									
									printf("\n请选择删除类型(\"单个学生\"按 1，\"专业+年级\"按 2)");
									while(temp)
									{
										scanf("%d", &temp);
										getchar(); 
										if(temp == 1)
										{
											printf("\n请输入需要删除的学生的学号：");
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
												printf("\n学号输入有误或该学生不存在。\n\n");
											}
											else
											{
												printf("\n该学生信息已删除。\n\n"); 
											}
											temp = 0;
											break;
										}
										else if(temp == 2) 
										{
											printf("\n请输入需要删除的专业：");
											scanf("%s", stuMajor);
											getchar();
											printf("\n请输入需要删除的年级：");
											scanf("%s", stuGrade);
											getchar();
											printf("\n再次确认是否删除%s%s级的学生？(\"是\"按 1，\"否\"按 2)", stuMajor, stuGrade);
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
														printf("\n信息输入有误或该专业年级学生不存在。\n\n");
														break;
													}
													else
													{
														printf("\n该专业、年级的学生信息已删除。\n\n"); 
														break;
													}
												}
												else if(temp == 2)
												{
													printf("\n取消删除。\n\n");
													break;
												}
												else
												{
													printf("\n选择有误，请重新选择。\n"); 
													temp = 1; 
												}
											}
											temp = 0;
											break;
										}	
										else
										{
											printf("\n选择有误，请重新选择。\n"); 
											temp = 1; 
										}
									}
									system("pause");
								}
								
						  	}	break;	
						  	
				//该部分执行更改学生信息	
				case 'D' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									char ch, stuID[12];
									StuData *Temp = Head->next;
									printf("\n请输入需要更改的学生的学号：");
									scanf("%s", stuID);
									getchar();
									while(Temp != NULL)
									{
										if(!strcmp(Temp->StudentID, stuID) )
										{
											printf("\n请输入需要更改的内容(输入对应的字符)：\n");
											printf("A:国家\t\tB:姓名\t\tC:性别\nD:民族\t\tE:婚姻状况\tF:政治面貌\n"
												   "G:学生类别\tH:入学年月\tI:入学方式\n\n请输入：");
											scanf("%c", &ch);
											getchar(); 
											switch(ch)
											{
												//国家的更改 
												case 'A' : 	{
																printf("\n在以下的国家中选择一个国家:\n\n");
																
															    int i;
															    //文件内容显示 
																for(i = 0; i < MaxCountry; i++)
																{
																	printf("%-25s", strCountry[i]);
																	if((i + 1) % 5 == 0)
																		printf("\n");
																}
																while(temp)
																{
																	printf("\n\n请输入国家序号和(回车)："); 
																	char t[4];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1'; 
																		t[2] = '\0';
																	}
																	Temp->Country = ChToNum(t);
																	
																	if( Temp->Country >= 1 && Temp->Country <= 197 )
																	{
																		printf("\n您输入的国家是：%s\n\n",strCountry[Temp->Country - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																}
																
															} break;
												
												//姓名的更改			
												case 'B' : 	{
																while(temp)
																{
																	printf("\n请输入姓名："); 
																	scanf("%s", Temp->Name);
																	getchar();
																	if( CheckName(Temp->Name, Temp->Country) )
																	{
																		printf("\n您输入的姓名是：%s\n\n", Temp->Name);
																		temp = 0;
																	}
																	else
																	{
																		printf("\n姓名输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//性别的更改			
												case 'C' : 	{
																while(temp)
																{
																	printf("\n请输入性别(男/女)："); 
																	scanf("%s", Temp->Sex);
																	getchar();
																	if(!strcmp(Temp->Sex, "男") || !strcmp(Temp->Sex, "女"))
																	{
																		printf("\n您输入的性别是：%s\n\n", Temp->Sex);
																		temp = 0;
																	}
																	else
																	{
																		printf("\n性别输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//民族的更改			
												case 'D' : 	{	
																printf("\n在以下的民族中选择一个民族:\n\n");
																
																//文件内容显示 
																for(int i = 0; i < MaxNation; i++)
																{
																	printf("%-20s", strNation[i]);
															        if((i + 1) % 5 ==0)   
																		printf("\n");
																}
																
															    while(temp)
																{
																	printf("\n\n请输入民族序号和(回车)："); 
																	char t[3];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->Nation = ChToNum(t);
																	
																	if( Temp->Nation >= 1 && Temp->Nation <= 58 )
																	{
																		printf("\n您输入的是：%s\n\n", strNation[Temp->Nation - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//婚姻状况的更改 
												case 'E' : 	{
																printf("\n在以下的婚姻状况选项中选择一个:\n\n");
																
																//文件内容显示 
																for(int i = 0; i < MaxMarry; i++) 
																{  
																	printf("%-12s", strMarry[i]);
																} 
															    while(temp)
																{
																	printf("\n\n请输入婚姻状况序号和(回车)："); 
																	char t[3];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1';
																	}
																	Temp->Marriage = ChToNum(t);
																	
																	if( Temp->Marriage >= 1 && Temp->Marriage <= 5 )
																	{
																		printf("\n您输入的是：%s\n\n", strMarry[Temp->Marriage - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//政治面貌的更改			
												case 'F' : 	{
															    printf("\n在以下的政治面貌选项中选择一个:\n\n");
															    
																//文件内容显示 
																for(int i = 0; i < MaxFace; i++)
																{
																	printf("%-30s", strFace[i]);
																	if((i + 1) % 3 == 0)
																		printf("\n");
																}
																
															    while(temp)
																{
																	printf("\n\n请输入政治面貌序号和(回车)："); 
																	char t[3];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->PoliticalFace = ChToNum(t);
																	
																	if( Temp->PoliticalFace >= 1 && Temp->PoliticalFace <= 13 )
																	{
																		printf("\n您输入的是：%s\n\n", strFace[Temp->PoliticalFace - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//学生类别的更改			
												case 'G' : 	{
																printf("\n在以下的学生类别选项中选择一个:\n\n");
																
																//文件内容显示 
																for(int i = 0; i < MaxType; i++)
																{
																	printf("%-15s", strType[i]);
																}
																
															    while(temp)
																{
																	printf("\n\n请输入学生类别序号和(回车)："); 
																	char t[3];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; t[1] = '1';
																	}
																	Temp->StudentType = ChToNum(t);
																	
																	if( Temp->StudentType >= 1 && Temp->StudentType <= 2 )
																	{
																		printf("\n您输入的是：%s\n\n", strType[Temp->StudentType - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//入学年月的更改		
												case 'H' : 	{
																while(temp)
																{
																	printf("\n请输入入学年月(xxxx.xx.xx)："); 
																	scanf("%s", Temp->SchoolDate);
																	getchar(); 
																	if( CheckDate(Temp->SchoolDate) )
																	{
																		if(Temp->SchoolDate[2] != Temp->StudentID[2] || Temp->SchoolDate[3] != Temp->StudentID[3])
																			printf("\n您输入的年份与学号年份不一致。\n"); 
																		printf("\n您输入的入学年月是：%s\n\n", Temp->SchoolDate);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n入学年月输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												//入学方式的更改			
												case 'I' : 	{
															    printf("\n在以下的入学方式选项中选择一个:\n\n");
																
																//文件内容显示 
																for(int i = 0; i < MaxWay; i++)
																{
																	printf("%-15s", strWay[i]);	
																} 
																
															    while(temp)
																{
																	printf("\n\n请输入入学方式序号和(回车)："); 
																	char t[3];
																	gets(t);
																	
																	//对输入回车的默认值处理
																	if(!strcmp(t, "\0"))
																	{
																		t[0] = '0'; 
																		t[1] = '1';
																	}
																	Temp->EnterWay = ChToNum(t);
																	
																	if( Temp->EnterWay >= 1 && Temp->EnterWay <= 3 )
																	{
																		printf("\n您输入的是：%s\n\n", strWay[Temp->EnterWay - 1]);
																		temp = 0; 
																	}
																	else
																	{
																		printf("\n序号输入有误，请重新输入。\n"); 
																	}
																} 
																
															} break;
												
												default  :  {
																printf("\n输入错误。\n\n"); 
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
										printf("\n学号输入有误或该学生不存在。\n\n");
									}
									system("pause");
								}

						  	} 	break;
						  	
				//该部分执行查询学生信息 
				case 'E' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int temp = 1; 
									char stuID[12];
									StuData *Temp = Head->next;
									
									//分别单独查询或者组合查询对个人来说较为棘手，所以仅用了学号来查询 
									printf("\n请输入需要查询的学生的学号："); 
									scanf("%s", stuID);
									getchar();
									while(Temp != NULL)
									{
										if(!strcmp(Temp->StudentID, stuID) )
										{
											printf("\n\n学号\t\t姓名\t性别\t出生日期\t民族\t政治面貌"
										   		   "\t身份证号\t\t学院名称\t专业名称\t\t年级\t班级号\n");
										   		   
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
										printf("\n学号输入有误或该学生不存在。\n\n");
									}
									system("pause"); 	 
								}

						  	} 	break;
						  	
				//该部分执行学生人数统计 
				case 'F' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int sum = 0, temp = 1, choice; 
									char stuMajor[30], stuGrade[5], stuSex[3], stuCollege[20], stuTeacher[10];
									StuData *Temp = Head->next;
									
									printf("\n请选择统计类型对应的序号(1.专业+年级+性别  2.学院  3.辅导员)：");
									scanf("%d", &choice);
									getchar();
									if(choice == 1)
									{
										printf("\n请输入专业名称："); 
										scanf("%s", stuMajor);
										getchar();
										printf("\n请输入年级："); 
										scanf("%s", stuGrade);
										getchar();
										printf("\n请输入性别："); 
										scanf("%s", stuSex);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->MajorName, stuMajor) && !strcmp(Temp->Grade, stuGrade)
											   && !strcmp(Temp->Sex, stuSex) )
											{
												if(sum == 0)
												{
													printf("\n\n学号\t\t姓名\t性别\t出生日期\t民族\t政治面貌"
											   			   "\t身份证号\t\t学院名称\t专业名称\t\t年级\t班级号\n");
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
											printf("\n信息输入有误或没有符合要求的学生。\n\n");
										}
										else
										{
											printf("\n符合要求的学生总人数为%d人。\n\n", sum);
										}
									}
									else if(choice == 2)
									{
										printf("\n请输入学院名称："); 
										scanf("%s", stuCollege);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->CollegeName, stuCollege) )
											{
												if(sum == 0)
												{
													printf("\n\n学号\t\t姓名\t性别\t出生日期\t民族\t政治面貌"
											   			   "\t身份证号\t\t学院名称\t专业名称\t\t年级\t班级号\n");
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
											printf("\n信息输入有误或没有符合要求的学生。\n\n");
										}
										else
										{
											printf("\n符合要求的学生总人数为%d人。\n\n", sum);
										}
									}
									else if(choice == 3)
									{
										printf("\n请输入辅导员名称："); 
										scanf("%s", stuTeacher);
										getchar();
										while(Temp != NULL)
										{
											if(!strcmp(Temp->Teacher, stuTeacher) )
											{
												if(sum == 0)
												{
													printf("\n\n学号\t\t姓名\t性别\t出生日期\t民族\t政治面貌"
											   			   "\t身份证号\t\t学院名称\t专业名称\t\t年级\t班级号\n");
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
											printf("\n信息输入有误或没有符合要求的学生。\n\n");
										}
										else
										{
											printf("\n%s老师的学生总人数为%d人。\n\n", stuTeacher, sum);
										}
									}
									else
									{
										printf("\n序号输入错误。\n\n");
									}
									
									system("pause"); 	 
								}
								
						  	} 	break;
						  	
				//该部分执行学生信息排序 
				case 'G' :	{	
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									int cnt;     //声明cnt用于记录链表遍历一次时，排序的次数
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
									printf("\n学生信息已根据学号顺序排序完成。\n\n");
									system("pause"); 
								}
								
						  	} 	break;
						  	
				//该部分执行显示学生信息 
				case 'H' :	{
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									printf("\n\n学号\t\t姓名\t性别\t出生日期\t民族\t政治面貌"
										   "\t身份证号\t\t学院名称\t专业名称\t\t年级\t班级号\n");
									
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
						  	
				//该部分执行保存学生信息 
				case 'I' :	{	
								if(Head == NULL)
								{
									printf("\n暂无学生信息！\n\n");
									system("pause");
								}
								else
								{
									char FileName[50];    
									printf("\n请输入所要存入的文件名(注意添加后缀)：");
									gets(FileName);
									FILE * File = fopen(FileName, "w+");   //打开文件
									if (File == NULL)     //若打开文件失败则退出
									{
										printf("\n文件打开失败。\n\n");	
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
										printf("\n已将全部学生信息写入%s中。\n\n", FileName);
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
		printf("\n请选择(A,B,C,D,E,F,G,H,I,J):");  
		scanf("%c", &input);
		getchar();
	}
	return 0; 
}
