/*
* 姓名：吴建东 
* 学号：221900128 
* 班级：软件工程一班 
* 电话：18750512590 
* 邮件地址：1261768875@qq.com 
* 数据结构：字符串 
* 主要算法：大数字符串加减乘除求余的实现 
* 开发环境：Dev-C++ 5.11 
* 运行环境：Windows 10 
* 
* 输入说明：本程序暂时限定最大位数Max为3000，若用户需要，可随意修改Max值 
* 输出说明：无 
* 
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef HugeInt_Head
#define HugeInt_Head

#define Max 3000

class HugeInt
{
	private:
		
		string a;   //存放巨型整数的字符串 
	
	public:
		
		HugeInt(long i = 0L);
		
		HugeInt(string s);
		
		HugeInt(const HugeInt &i);
		
		HugeInt& operator=(const HugeInt &i);
		
		
		friend HugeInt operator+(HugeInt x, HugeInt y);    	//巨型整数 + 巨型整数 
		
		friend HugeInt operator+(HugeInt x, long y);		//巨型整数 + 长整型数 
		
		friend HugeInt operator+(long y, HugeInt x);		//长整型数 + 巨型整数 
		
		friend HugeInt operator+(HugeInt x, string y);		//巨型整数 + 字符串 
		
		friend HugeInt operator+(string y, HugeInt x);		//  字符串 + 巨型整数 
		
		
		
		friend HugeInt operator-(HugeInt x);     			//求负运算
		
		friend HugeInt operator-(HugeInt x, HugeInt y);    	//巨型整数 - 巨型整数 
		
		friend HugeInt operator-(HugeInt x, long y);		//巨型整数 - 长整型数 
		
		friend HugeInt operator-(long y, HugeInt x);		//长整型数 - 巨型整数 
		
		friend HugeInt operator-(HugeInt x, string y);		//巨型整数 - 字符串 
		
		friend HugeInt operator-(string y, HugeInt x);		//  字符串 - 巨型整数 
		
		
		
		friend HugeInt operator*(HugeInt x, HugeInt y);    	//巨型整数 * 巨型整数 
		
		friend HugeInt operator*(HugeInt x, long y);		//巨型整数 * 长整型数 
		
		friend HugeInt operator*(long y, HugeInt x);		//长整型数 * 巨型整数 
		
		friend HugeInt operator*(HugeInt x, string y);		//巨型整数 * 字符串 
		
		friend HugeInt operator*(string y, HugeInt x);		//  字符串 * 巨型整数 
		
		
		
		friend HugeInt operator/(HugeInt x, HugeInt y);    	//巨型整数 / 巨型整数 
		
		friend HugeInt operator/(HugeInt x, long y);		//巨型整数 / 长整型数 
		
		friend HugeInt operator/(long y, HugeInt x);		//长整型数 / 巨型整数 
		
		friend HugeInt operator/(HugeInt x, string y);		//巨型整数 / 字符串 
		
		friend HugeInt operator/(string y, HugeInt x);		//  字符串 / 巨型整数 
		
		
		
		friend HugeInt operator%(HugeInt x, HugeInt y);    	//巨型整数 % 巨型整数 
		
		friend HugeInt operator%(HugeInt x, long y);		//巨型整数 % 长整型数 
		
		friend HugeInt operator%(long y, HugeInt x);		//长整型数 % 巨型整数 
		
		friend HugeInt operator%(HugeInt x, string y);		//巨型整数 % 字符串 
		
		friend HugeInt operator%(string y, HugeInt x);		//  字符串 % 巨型整数 
		
		
		
		friend bool operator<(HugeInt x, HugeInt y);     	//巨型整数 < 巨型整数 
		
		friend bool operator<(HugeInt x, long y);			//巨型整数 < 长整型数 
		
		friend bool operator<(long y, HugeInt x);			//长整型数 < 巨型整数 
		
		friend bool operator<(HugeInt x, string y);			//巨型整数 < 字符串 
		
		friend bool operator<(string y, HugeInt x);			//  字符串 < 巨型整数 
		
		
		
		friend bool operator>(HugeInt x, HugeInt y);     	//巨型整数 > 巨型整数 
		
		friend bool operator>(HugeInt x, long y);			//巨型整数 > 长整型数 
		
		friend bool operator>(long y, HugeInt x);			//长整型数 > 巨型整数 
		
		friend bool operator>(HugeInt x, string y);			//巨型整数 > 字符串 
		
		friend bool operator>(string y, HugeInt x);			//  字符串 > 巨型整数 
		
		
		
		friend bool operator==(HugeInt x, HugeInt y);     	//巨型整数 == 巨型整数 
		
		friend bool operator==(HugeInt x, long y);			//巨型整数 == 长整型数 
		
		friend bool operator==(long y, HugeInt x);			//长整型数 == 巨型整数 
		
		friend bool operator==(HugeInt x, string y);		//巨型整数 == 字符串 
		
		friend bool operator==(string y, HugeInt x);		//  字符串 == 巨型整数 
		
		
		
		friend bool operator<=(HugeInt x, HugeInt y);     	//巨型整数 <= 巨型整数 
		
		friend bool operator<=(HugeInt x, long y);			//巨型整数 <= 长整型数 
		
		friend bool operator<=(long y, HugeInt x);			//长整型数 <= 巨型整数 
		
		friend bool operator<=(HugeInt x, string y);		//巨型整数 <= 字符串 
		
		friend bool operator<=(string y, HugeInt x);		//  字符串 <= 巨型整数 
		
		
		
		friend bool operator>=(HugeInt x, HugeInt y);     	//巨型整数 >= 巨型整数 
		
		friend bool operator>=(HugeInt x, long y);			//巨型整数 >= 长整型数 
		
		friend bool operator>=(long y, HugeInt x);			//长整型数 >= 巨型整数 
		
		friend bool operator>=(HugeInt x, string y);		//巨型整数 >= 字符串 
		
		friend bool operator>=(string y, HugeInt x);		//  字符串 >= 巨型整数 
		
		
		
		friend bool operator!=(HugeInt x, HugeInt y);     	//巨型整数 != 巨型整数 
		
		friend bool operator!=(HugeInt x, long y);			//巨型整数 != 长整型数 
		
		friend bool operator!=(long y, HugeInt x);			//长整型数 != 巨型整数 
		
		friend bool operator!=(HugeInt x, string y);		//巨型整数 != 字符串 
		
		friend bool operator!=(string y, HugeInt x);		//  字符串 != 巨型整数
		
		
		
		HugeInt& operator+=(const HugeInt &i);				//巨型整数 += 巨型整数 
		
		HugeInt& operator+=(const long &i);					//巨型整数 += 长整型数 
		
		HugeInt& operator+=(const string &i);						//巨型整数 += 字符串
		
		
		
		HugeInt& operator-=(const HugeInt &i);				//巨型整数 -= 巨型整数 
		
		HugeInt& operator-=(const long &i);					//巨型整数 -= 长整型数 
		
		HugeInt& operator-=(const string &i);						//巨型整数 -= 字符串
		
		
		
		HugeInt& operator*=(const HugeInt &i);				//巨型整数 *= 巨型整数 
		
		HugeInt& operator*=(const long &i);					//巨型整数 *= 长整型数 
	
		HugeInt& operator*=(const string &i);						//巨型整数 *= 字符串
		
		
		
		HugeInt& operator/=(const HugeInt &i);				//巨型整数 /= 巨型整数 
		
		HugeInt& operator/=(const long &i);					//巨型整数 /= 长整型数 
		
		HugeInt& operator/=(const string &i);						//巨型整数 /= 字符串
		
		
		
		HugeInt& operator%=(const HugeInt &i);				//巨型整数 %= 巨型整数 
		
		HugeInt& operator%=(const long &i);					//巨型整数 %= 长整型数 
		
		HugeInt& operator%=(const string &i);						//巨型整数 %= 字符串
		
		
		
		HugeInt operator++();     			//++巨型整数 
		
		HugeInt operator++(int);  			//巨型整数 ++
		
		HugeInt operator--();     			//--巨型整数 
		
		HugeInt operator--(int);  			//巨型整数 --
		
		
			
		friend istream &operator>>(istream &in, HugeInt &i);        //输入运算符重载 
		
		friend ostream &operator<<(ostream &out, const HugeInt &i); //输出运算符重载 
		
				
	
		string PrintOct();			//巨型整数转换成八进制字符串 
	
		string PrintHex();			//巨型整数转换成16进制字符串 
		
}; 


#endif
