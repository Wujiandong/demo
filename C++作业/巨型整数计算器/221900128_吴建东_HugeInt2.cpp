#include <iostream>
#include "221900128_吴建东_HugeInt.h"

using namespace std;

int main()
{
	char input;        //声明用户选择变量 
	Copyright();       //显示版权
	SystemTime();      //显示系统时间
	Menu();            //显示菜单界面 
	cout << "\n请选择(A,B,C,D,E,F,G,H,I,J,K,L,M,N):";
	cin >> input;
	while(input != 'N')
	{
		if((input < 'A') || (input > 'N'))
			cout << "\n\n选择错误，请重新选择......\n\n";
		else
		{
			switch(input)
			{
				//用Long整型数构造
				case 'A' :	{
								HugeInt n1, n2(0L), n3(LONG_MAX), n4(LONG_MIN);
								cout << "\n";
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								cout << "n3 = " << n3 << endl;
								cout << "n4 = " << n4 << endl;
								
							} 	break;
				//用正确的字符串构造
				case 'B' :	{
								HugeInt n1("123456789"), n2("-123456789"), n3("00012345670");
								HugeInt n4("0x0123456789abcdef"), n5("0XFEDCBA9876543210");
								HugeInt n6("0"), n7("0000"), n8("+0"), n9("-0");
								HugeInt n10("123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321");
								HugeInt n11("-123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321234567898765432123456789876543212345678987654321");
								cout << "\n";
								cout << "n1 = " << n1 << endl;
								cout << "n1 = " << n1.PrintOct() << endl;
								cout << "n1 = " << n1.PrintHex() << endl;
								cout << "\n";
								cout << "n2 = " << n2 << endl;
								cout << "n2 = " << n2.PrintOct() << endl;
								cout << "n2 = " << n2.PrintHex() << endl;
								cout << "\n";
								cout << "n3 = " << n3 << endl;
								cout << "n3 = " << n3.PrintOct() << endl;
								cout << "n3 = " << n3.PrintHex() << endl;
								cout << "\n";
								cout << "n4 = " << n4 << endl;
								cout << "n4 = " << n4.PrintOct() << endl;
								cout << "n4 = " << n4.PrintHex() << endl;
								cout << "\n";
								cout << "n5 = " << n5 << endl;
								cout << "n5 = " << n5.PrintOct() << endl;
					    		cout << "n5 = " << n5.PrintHex() << endl;
					    		cout << "\n";
					    		cout << "n6 = " << n6 << endl;
					    		cout << "n7 = " << n7 << endl;
					    		cout << "n8 = " << n8 << endl;
					    		cout << "n9 = " << n9 << endl;
					    		cout << "\n";
					    		cout << "n10 = " << n10 << endl;
					    		cout << "\n";
					    		cout << "n11 = " << n11 << endl;
					    		
						  	} 	break;	
				//用包含非法字符的字符串构造
				case 'C' :	{
								cout << "\n" ;
								try
								{
									cout << "n1为"; 
									HugeInt n1("123456abcd");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n2为"; 
									HugeInt n2("1A2B3C4D5F");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n3为"; 
									HugeInt n3("012345678");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n4为"; 
									HugeInt n4("0123456789");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n5为"; 
									HugeInt n5("0123456abcd");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n6为"; 
									HugeInt n6("0x123asd");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}
								try
								{
									cout << "n7为"; 
									HugeInt n7("0XABCDEFGHIJK");
								}
								catch(const char* ex)
								{
									cout << ex << "\n" << endl;
								}	
							
						  	}	break;	
				//用身份证号和学号进行十种运算
				case 'D' :	{
								HugeInt n1("350581200106222712"), n2("221900128"), temp = n1;
								cout << "\nn1为" << n1  << "      n2为"  << n2 << endl;
								cout << "\nn1 + n2 = "  << n1 +  n2 << endl;
								cout << "\nn1 - n2 = "  << n1 -  n2 << endl;
								cout << "\nn1 * n2 = "  << n1 *  n2 << endl;
								cout << "\nn1 / n2 = "  << n1 /  n2 << endl;
								cout << "\nn1 % n2 = "  << n1 %  n2 << endl;
								n1 += n2;
								cout << "\nn1 += n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 -= n2;
								cout << "\nn1 -= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 *= n2;
								cout << "\nn1 *= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 /= n2;
								cout << "\nn1 /= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 %= n2;
								cout << "\nn1 %= n2 后 n1= " << n1 << endl;
								
						  	} 	break;
				//用两个100位字符串构造整数进行十种运算
				case 'E' :	{
								HugeInt n1("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt n2("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
								HugeInt temp = n1;
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								cout << "\nn1 + n2 = "  << n1 +  n2 << endl;
								cout << "\nn1 - n2 = "  << n1 -  n2 << endl;
								cout << "\nn1 * n2 = "  << n1 *  n2 << endl;
								cout << "\nn1 / n2 = "  << n1 /  n2 << endl;
								cout << "\nn1 % n2 = "  << n1 %  n2 << endl;
								cout << "\nn2 / n1 = "  << n2 /  n1 << endl;
								cout << "\nn2 % n1 = "  << n2 %  n1 << endl;
								n1 += n2;
								cout << "\nn1 += n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 -= n2;
								cout << "\nn1 -= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 *= n2;
								cout << "\nn1 *= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 /= n2;
								cout << "\nn1 /= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 %= n2;
								cout << "\nn1 %= n2 后 n1= " << n1 << endl;
								
						  	} 	break;
				//用两个100位字符串构造整数进行六种关系运算
				case 'F' :	{
								HugeInt n1("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt n2("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								if(n1 < n2)
									cout << "\nn1 < n2" <<endl;
								if(n1 <= n2)
									cout << "\nn1 <= n2" <<endl;
								if(n1 > n2)
									cout << "\nn1 > n2" <<endl;
								if(n1 >= n2)
									cout << "\nn1 >= n2" <<endl;
								if(n1 != n2)
									cout << "\nn1 != n2" <<endl;
								if(n1 == n2)
									cout << "\nn1 == n2" <<endl;
								if(n2 < n1)
									cout << "\nn2 < n1" <<endl;
								if(n2 <= n1)
									cout << "\nn2 <= n1" <<endl;
								if(n2 > n1)
									cout << "\nn2 > n1" <<endl;
								if(n2 >= n1)
									cout << "\nn1 >= n1" <<endl;
								
						  	} 	break;
				//用任意值与0进行五种运算
				case 'G' :	{	
								HugeInt n1("666666");
								HugeInt n2("0");
								cout << "\nn1为" << n1 << "    n2为" << n2 << endl;
								cout << "\nn1 / n2   ";
								try
								{
									cout << n1 / n2 << endl;
								}
								catch(const char* ex)
								{
									cout << ex << endl;
								}
								cout << "\nn1 % n2   ";
								try
								{
									cout << n1 % n2 << endl;
								}
								catch(const char* ex)
								{
									cout << ex << endl;
								}
								cout << "\nn1 + n2 = "  << n1 +  n2 << endl;
								cout << "\nn1 - n2 = "  << n1 -  n2 << endl;
								cout << "\nn1 * n2 = "  << n1 *  n2 << endl;
						  	} 	break;
				//100位字符串构造整数与默认构造整数进行++和--运算
				case 'H' :	{
								HugeInt n1("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt n2;
								HugeInt temp1 = n1, temp2 = n2;
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								
								cout << "\nn2=++n1操作前" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								n2 = ++n1;
								cout << "n2=++n1操作后" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								
								n1 = temp1;
								n2 = temp2;
								cout << "\nn2=n1++操作前" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								n2 = n1++;
								cout << "n2=n1++操作后" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								
								n1 = temp1;
								n2 = temp2;
								cout << "\nn2=--n1操作前" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								n2 = --n1;
								cout << "n2=--n1操作后" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								
								n1 = temp1;
								n2 = temp2;
								cout << "\nn2=n1--操作前" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								n2 = n1--;
								cout << "n2=n1--操作后" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								
						  	} 	break;
				//100位字符串构造整数与两个默认构造整数进行赋值运算
				case 'I' :	{	
								HugeInt n1 ("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt n2, n3;
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << "      n3为" << n3 << endl;
								n3 = n2 = n1;
								cout << "\n经过n3=n2=n1操作后\n" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								cout << "n3 = " << n3 << endl;
								
						  	} 	break;
				//用100位字符串拷贝构造并进行求负运算
				case 'J' :	{	
								HugeInt n1 ("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt n2(n1);
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								n2 = -n1;
								cout << "\n经过n2=-n1操作后\n" << endl;
								cout << "n1 = " << n1 << endl;
								cout << "n2 = " << n2 << endl;
								
						  	}	break;
				//100位字符串构造与Long整数进行十种运算
				case 'K' :	{
								HugeInt n1 ("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
								HugeInt temp = n1;
								long n2 = 123456789L; 
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								cout << "\nn1 + n2 = "  << n1 +  n2 << endl;
								cout << "\nn1 - n2 = "  << n1 -  n2 << endl;
								cout << "\nn1 * n2 = "  << n1 *  n2 << endl;
								cout << "\nn1 / n2 = "  << n1 /  n2 << endl;
								cout << "\nn1 % n2 = "  << n1 %  n2 << endl;
								cout << "\nn2 / n1 = "  << n2 /  n1 << endl;
								cout << "\nn2 % n1 = "  << n2 %  n1 << endl;
								n1 += n2;
								cout << "\nn1 += n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 -= n2;
								cout << "\nn1 -= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 *= n2;
								cout << "\nn1 *= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 /= n2;
								cout << "\nn1 /= n2 后 n1= " << n1 << endl;
								n1 = temp;
								n1 %= n2;
								cout << "\nn1 %= n2 后 n1= " << n1 << endl;
								
						  	} 	break;
				//字符串构造整数与Long整数进行六种关系运算
				case 'L' :	{
								HugeInt n1 ("987654321");
								HugeInt temp = n1;
								long n2 = 123456789L;
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								if(n1 < n2)
									cout << "\nn1 < n2" <<endl;
								if(n1 <= n2)
									cout << "\nn1 <= n2" <<endl;
								if(n1 > n2)
									cout << "\nn1 > n2" <<endl;
								if(n1 >= n2)
									cout << "\nn1 >= n2" <<endl;
								if(n1 != n2)
									cout << "\nn1 != n2" <<endl;
								if(n1 == n2)
									cout << "\nn1 == n2" <<endl;
								if(n2 < n1)
									cout << "\nn2 < n1" <<endl;
								if(n2 <= n1)
									cout << "\nn2 <= n1" <<endl;
								if(n2 > n1)
									cout << "\nn2 > n1" <<endl;
								if(n2 >= n1)
									cout << "\nn1 >= n1" <<endl;
								
						  	} 	break;
				//字符串构造整数与字符串进行六种关系运算
				case 'M' :	{
								HugeInt n1 ("987654321");
								HugeInt temp = n1;
								string n2 = "123456789";
								cout << "\nn1为" << n1 << endl;
								cout << "n2为"   << n2 << endl;
								if(n1 < n2)
									cout << "\nn1 < n2" <<endl;
								if(n1 <= n2)
									cout << "\nn1 <= n2" <<endl;
								if(n1 > n2)
									cout << "\nn1 > n2" <<endl;
								if(n1 >= n2)
									cout << "\nn1 >= n2" <<endl;
								if(n1 != n2)
									cout << "\nn1 != n2" <<endl;
								if(n1 == n2)
									cout << "\nn1 == n2" <<endl;
								if(n2 < n1)
									cout << "\nn2 < n1" <<endl;
								if(n2 <= n1)
									cout << "\nn2 <= n1" <<endl;
								if(n2 > n1)
									cout << "\nn2 > n1" <<endl;
								if(n2 >= n1)
									cout << "\nn1 >= n1" <<endl;
								
						  	} 	break;
							  	  	
			}	
		}	 
		cout << "\n";
		Copyright();     
		SystemTime();    
		Menu();
		cout << "\n请选择(A,B,C,D,E,F,G,H,I,J,K,L,M,N):";   
		cin >> input;
	}
	return 0; 
} 
