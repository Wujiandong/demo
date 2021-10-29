#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "221900128_�⽨��_list.h"

int main()
{
	int NodeNum, n;    //�����ܽ������ָ������� 
	char input;        //�����û�ѡ����� 
	Copyright();       //��ʾ��Ȩ
	SystemTime();      //��ʾϵͳʱ��
	Menu();            //��ʾ�˵����� 
	printf("\n��ѡ��(A,B,C,D,E,F,G,H,I,J,K,L):");
	scanf("%c", &input);
	getchar();
	while(input != 'L')
	{
		if((input < 'A') || (input > 'L'))
			printf("\n\nѡ�����������ѡ��......\n\n");
		else
		{
			switch(input)
			{
				//�ò���ִ������Ĵ��� 
				case 'A' :	{
								NodeNum = 2020; 
						
								BuildList(NodeNum);     //�������� 
								printf("\n������%d�����ڽ�㡣" 
								       "(1900<=��<=2020,1<=��<=12,1<=��<=31)��\n\n", NodeNum);
								system("pause");
								
							} 	break;
				//�ò���ִ���������ݵ���ʾ				
				case 'B' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");	
								}
								else
								{
									printf("\n��������ʾ����Ľ����n��");
									scanf("%d", &n);
									getchar();
									ShowList(n, NodeNum);    //��ӡ�������� 
									system("pause");
								}
									
						  	} 	break;	
				//�ò���ִ�н��������ָ���ļ�	  	
				case 'C' :	{
								int file;    //�ж��ļ����Ķ��巽ʽ 
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									printf("\n��ѡ�������ļ���(1.Date.txt 2.�Զ���)\n");
									printf("\n�������Ӧ����ţ�");
									scanf("%d", &file);
									getchar(); 
									if((file != 1) && (file != 2))
									{
										printf("\n�������\n\n"); 
										system("pause");
									}
									else if(file == 1)
									{
										FILE * File = fopen("Date.txt", "w");   //���ļ�
										if (File == NULL)   //�����ļ�ʧ�����˳�
										{
											printf("\n�ļ���ʧ�ܡ�\n\n");
											system("pause");
										}
										else
										{
											listToFile(File, Head);     //���ݴ����ļ� 
											printf("\n�ѽ�%d�����д���ļ�\"Date.txt\"�С�\n\n", NodeNum);
											fclose(File); 
											system("pause");
										}
									}
									else
									{
										char FileName[50];    //�����Զ����ļ���
										printf("\n�������Զ����ļ���(ע����Ӻ�׺������ .txt ��.dat)��");
										gets(FileName);
										FILE * File = fopen(FileName, "w");   //���ļ�
										if (File == NULL)     //�����ļ�ʧ�����˳�
										{
											printf("\n�ļ���ʧ�ܡ�\n\n");
											system("pause");
										}
										else
										{
											listToFile(File, Head);
											printf("\n�ѽ�%d�����д���ļ�\"%s\"�С�\n\n", NodeNum, FileName);
											fclose(File);
											system("pause");
										}
									}
								}
								
						  	}	break;	
				//�ò���ִ�з�����ʾȫ������			  	
				case 'D' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									MultiPartShowList(NodeNum);
									system("pause");
								}

						  	} 	break;
				//�ò���ִ����ʾ���Ϸ����ڽ��		  	
				case 'E' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									ShowErrorDate();
									system("pause");
								}

						  	} 	break;
				//�ò���ִ��ɾ��ָ�����		  	
				case 'F' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									int Num;
									printf("\n��ѡ��ɾ������λ��(1.��һ�� 2.���һ�� 3.���ܹ��ɺϷ�����)��\n\n");
									printf("�������Ӧ����ţ�");
									scanf("%d",&Num);
									getchar();
									if(Num == 1)     //ɾ����һ����� 
									{
										DeleteFirstNode(NodeNum);
										printf("\n��ɾ����һ����㡣\n\n");
										system("pause");
									}
									else if(Num == 2)     //ɾ�����һ����� 
									{
										DeleteLastNode(NodeNum);
										printf("\n��ɾ�����һ����㡣\n\n");
										system("pause");
									}
									else if(Num == 3)
									{
										DeleteErrorNode(NodeNum);
										system("pause");
									}
									else
									{
										printf("\n�������...\n\n");
										system("pause");
									} 
								}
								
						  	} 	break;
				//�ò���ִ�в���ָ����� 
				case 'G' :	{	
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									int cnt, Judge = 0;    //�����жϱ���Judge�����ж��Ƿ����ɹ� , cnt���ڹ���ѡ��;
									printf("\n��ѡ��������λ��");
									printf("(1.��ͷ 2.��β 3.��һ�����ڵ�ǰ����ǰ 4.��һ��С�ڵ�ǰ���ں�)��\n\n");
									printf("�������Ӧ����ţ�");
									scanf("%d", &cnt);
									getchar(); 
									if(cnt == 1)     //���뵽��ͷ 
									{
										InsertFirstNode(NodeNum); 
										printf("\n�ѽ���ǰ���ڽ����뵽��ͷ��\n\n");
										system("pause");
									}
									else if(cnt == 2)  //���뵽��β 
									{
										InsertLastNode(NodeNum); 
										printf("\n�ѽ���ǰ���ڽ����뵽��β��\n\n");
										system("pause");
									}
									else if(cnt == 3)
									{
										InsertNodeToBig(Judge, NodeNum);   //����ǰ���ڽ����뵽��һ�����ڸý�����ڵ�ǰ��
										if(Judge == 1)
										{
											printf("\n�ѽ���ǰ���ڽ����뵽��һ�����ڸý�����ڵ�ǰ�档\n\n"); 
										}
										else
										{
											printf("\n����ʧ�ܣ�û���ҵ����ڵ�ǰ���ڵĽ�㡣\n\n");
										}
										system("pause");
									}
									else if(cnt == 4)
									{
										InsertNodeToSmall(Judge, NodeNum);  //����ǰ���ڽ����뵽��һ��С�ڸý�����ڵ�ǰ��
										if(Judge == 1)
										{
											printf("\n�ѽ���ǰ���ڽ����뵽��һ��С�ڸý�����ڵĺ��档\n\n"); 
										}
										else
										{
											printf("\n����ʧ�ܣ�û���ҵ�С�ڵ�ǰ���ڵĽ�㡣\n\n");
										}
										system("pause");
									}
									else
									{
										printf("\n�������...\n\n");
										system("pause");
									}
								}
								
						  	} 	break;
				//�ò���ִ����ʾ������ڶ�Ӧ������		  	
				case 'H' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									
									printf("\n��������ʾ����Ľ����n��");
									scanf("%d", &n);
									getchar();
									ShowNodeDateDiffer(n, NodeNum);    //��ӡ�������� 
									system("pause");
								}
								
						  	} 	break;
				//�ò���ִ���������� 
				case 'I' :	{	
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									printf("\n�����������Ժ�......\n");
									ListSort();
									printf("\n���������\n\n");
									system("pause");
								}
								
						  	} 	break;
				//�ò���ִ�в���������� 
				case 'J' :	{	
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									FindPrimeNode();
									system("pause");
								}
								
						  	}	break;
				//�ò���ִ������ת 
				case 'K' :	{
								if(Head == NULL)
								{
									printf("\n����Ϊ�գ�\n\n");
									system("pause");
								}
								else
								{
									ReverseList();
									printf("\n�����ѳɹ���ת��\n\n");
									system("pause");
								} 
								
						  	} 	break;
							  	  	
			}	
		}	 
		printf("\n");
		Copyright();     
		SystemTime();    
		Menu();
		printf("\n��ѡ��(A,B,C,D,E,F,G,H,I,J,K,L):");   
		scanf("%c", &input);
		getchar();
	}
	return 0; 
}
