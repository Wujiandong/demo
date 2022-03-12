#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "221900128_吴建东_list.h"

int main()
{
	int NodeNum, n;    //声明总结点数和指定结点数 
	char input;        //声明用户选择变量 
	Copyright();       //显示版权
	SystemTime();      //显示系统时间
	Menu();            //显示菜单界面 
	printf("\n请选择(A,B,C,D,E,F,G,H,I,J,K,L):");
	scanf("%c", &input);
	getchar();
	while(input != 'L')
	{
		if((input < 'A') || (input > 'L'))
			printf("\n\n选择错误，请重新选择......\n\n");
		else
		{
			switch(input)
			{
				//该部分执行链表的创建 
				case 'A' :	{
								NodeNum = 2020; //创建2020个日期结点
								BuildList(NodeNum);     //建立链表 
								printf("\n共创建%d个日期结点。" 
								       "(1900<=年<=2020,1<=月<=12,1<=日<=31)。\n\n", NodeNum);
								system("pause");
								
							} 	break;
				//该部分执行日期数据的显示				
				case 'B' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");	
								}
								else
								{
									printf("\n请输入显示链表的结点数n：");
									scanf("%d", &n);
									getchar();
									ShowList(n, NodeNum);    //打印链表数据 
									system("pause");
								}
									
						  	} 	break;	
				//该部分执行将链表存入指定文件	  	
				case 'C' :	{
								int file;    //判断文件名的定义方式 
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									printf("\n请选择存入的文件名(1.Date.txt 2.自定义)\n");
									printf("\n请输入对应的序号：");
									scanf("%d", &file);
									getchar(); 
									if((file != 1) && (file != 2))
									{
										printf("\n输入错误！\n\n"); 
										system("pause");
									}
									else if(file == 1)
									{
										FILE * File = fopen("Date.txt", "w");   //打开文件
										if (File == NULL)   //若打开文件失败则退出
										{
											printf("\n文件打开失败。\n\n");
											system("pause");
										}
										else
										{
											listToFile(File, Head);     //数据存入文件 
											printf("\n已将%d个结点写入文件\"Date.txt\"中。\n\n", NodeNum);
											fclose(File); 
											system("pause");
										}
									}
									else
									{
										char FileName[50];    //声明自定义文件名
										printf("\n请输入自定义文件名(注意添加后缀，例如 .txt 、.dat)：");
										gets(FileName);
										FILE * File = fopen(FileName, "w");   //打开文件
										if (File == NULL)     //若打开文件失败则退出
										{
											printf("\n文件打开失败。\n\n");
											system("pause");
										}
										else
										{
											listToFile(File, Head);
											printf("\n已将%d个结点写入文件\"%s\"中。\n\n", NodeNum, FileName);
											fclose(File);
											system("pause");
										}
									}
								}
								
						  	}	break;	
				//该部分执行分屏显示全部内容			  	
				case 'D' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									MultiPartShowList(NodeNum);
									system("pause");
								}

						  	} 	break;
				//该部分执行显示不合法日期结点		  	
				case 'E' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									ShowErrorDate();
									system("pause");
								}

						  	} 	break;
				//该部分执行删除指定结点		  	
				case 'F' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									int Num;
									printf("\n请选择删除结点的位置(1.第一个 2.最后一个 3.不能构成合法日期)：\n\n");
									printf("请输入对应的序号：");
									scanf("%d",&Num);
									getchar();
									if(Num == 1)     //删除第一个结点 
									{
										DeleteFirstNode(NodeNum);
										printf("\n已删除第一个结点。\n\n");
										system("pause");
									}
									else if(Num == 2)     //删除最后一个结点 
									{
										DeleteLastNode(NodeNum);
										printf("\n已删除最后一个结点。\n\n");
										system("pause");
									}
									else if(Num == 3)
									{
										DeleteErrorNode(NodeNum);
										system("pause");
									}
									else
									{
										printf("\n输入错误...\n\n");
										system("pause");
									} 
								}
								
						  	} 	break;
				//该部分执行插入指定结点 
				case 'G' :	{	
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									int cnt, Judge = 0;    //声明判断变量Judge用于判断是否插入成功 , cnt用于功能选择;
									printf("\n请选择插入结点的位置");
									printf("(1.链头 2.链尾 3.第一个大于当前日期前 4.第一个小于当前日期后)：\n\n");
									printf("请输入对应的序号：");
									scanf("%d", &cnt);
									getchar(); 
									if(cnt == 1)     //插入到链头 
									{
										InsertFirstNode(NodeNum); 
										printf("\n已将当前日期结点插入到链头。\n\n");
										system("pause");
									}
									else if(cnt == 2)  //插入到链尾 
									{
										InsertLastNode(NodeNum); 
										printf("\n已将当前日期结点插入到链尾。\n\n");
										system("pause");
									}
									else if(cnt == 3)
									{
										InsertNodeToBig(Judge, NodeNum);   //将当前日期结点插入到第一个大于该结点日期的前面
										if(Judge == 1)
										{
											printf("\n已将当前日期结点插入到第一个大于该结点日期的前面。\n\n"); 
										}
										else
										{
											printf("\n插入失败，没有找到大于当前日期的结点。\n\n");
										}
										system("pause");
									}
									else if(cnt == 4)
									{
										InsertNodeToSmall(Judge, NodeNum);  //将当前日期结点插入到第一个小于该结点日期的前面
										if(Judge == 1)
										{
											printf("\n已将当前日期结点插入到第一个小于该结点日期的后面。\n\n"); 
										}
										else
										{
											printf("\n插入失败，没有找到小于当前日期的结点。\n\n");
										}
										system("pause");
									}
									else
									{
										printf("\n输入错误...\n\n");
										system("pause");
									}
								}
								
						  	} 	break;
				//该部分执行显示结点日期对应的天数		  	
				case 'H' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									
									printf("\n请输入显示链表的结点数n：");
									scanf("%d", &n);
									getchar();
									ShowNodeDateDiffer(n, NodeNum);    //打印链表数据 
									system("pause");
								}
								
						  	} 	break;
				//该部分执行链表排序 
				case 'I' :	{	
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									printf("\n正在排序，请稍候......\n");
									ListSort();
									printf("\n排序结束。\n\n");
									system("pause");
								}
								
						  	} 	break;
				//该部分执行查找素数结点 
				case 'J' :	{	
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									FindPrimeNode();
									system("pause");
								}
								
						  	}	break;
				//该部分执行链表翻转 
				case 'K' :	{
								if(Head == NULL)
								{
									printf("\n链表为空！\n\n");
									system("pause");
								}
								else
								{
									ReverseList();
									printf("\n链表已成功翻转。\n\n");
									system("pause");
								} 
								
						  	} 	break;
							  	  	
			}	
		}	 
		printf("\n");
		Copyright();     
		SystemTime();    
		Menu();
		printf("\n请选择(A,B,C,D,E,F,G,H,I,J,K,L):");   
		scanf("%c", &input);
		getchar();
	}
	return 0; 
}
