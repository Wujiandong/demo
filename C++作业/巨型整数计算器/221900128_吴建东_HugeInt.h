/*
* �������⽨�� 
* ѧ�ţ�221900128 
* �༶���������һ�� 
* �绰��18750512590 
* �ʼ���ַ��1261768875@qq.com 
* ���ݽṹ���ַ��� 
* ��Ҫ�㷨�������ַ����Ӽ��˳������ʵ�� 
* ����������Dev-C++ 5.11 
* ���л�����Windows 10 
* 
* ����˵������������ʱ�޶����λ��MaxΪ3000�����û���Ҫ���������޸�Maxֵ 
* ���˵������ 
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
		
		string a;   //��ž����������ַ��� 
	
	public:
		
		HugeInt(long i = 0L);
		
		HugeInt(string s);
		
		HugeInt(const HugeInt &i);
		
		HugeInt& operator=(const HugeInt &i);
		
		
		friend HugeInt operator+(HugeInt x, HugeInt y);    	//�������� + �������� 
		
		friend HugeInt operator+(HugeInt x, long y);		//�������� + �������� 
		
		friend HugeInt operator+(long y, HugeInt x);		//�������� + �������� 
		
		friend HugeInt operator+(HugeInt x, string y);		//�������� + �ַ��� 
		
		friend HugeInt operator+(string y, HugeInt x);		//  �ַ��� + �������� 
		
		
		
		friend HugeInt operator-(HugeInt x);     			//������
		
		friend HugeInt operator-(HugeInt x, HugeInt y);    	//�������� - �������� 
		
		friend HugeInt operator-(HugeInt x, long y);		//�������� - �������� 
		
		friend HugeInt operator-(long y, HugeInt x);		//�������� - �������� 
		
		friend HugeInt operator-(HugeInt x, string y);		//�������� - �ַ��� 
		
		friend HugeInt operator-(string y, HugeInt x);		//  �ַ��� - �������� 
		
		
		
		friend HugeInt operator*(HugeInt x, HugeInt y);    	//�������� * �������� 
		
		friend HugeInt operator*(HugeInt x, long y);		//�������� * �������� 
		
		friend HugeInt operator*(long y, HugeInt x);		//�������� * �������� 
		
		friend HugeInt operator*(HugeInt x, string y);		//�������� * �ַ��� 
		
		friend HugeInt operator*(string y, HugeInt x);		//  �ַ��� * �������� 
		
		
		
		friend HugeInt operator/(HugeInt x, HugeInt y);    	//�������� / �������� 
		
		friend HugeInt operator/(HugeInt x, long y);		//�������� / �������� 
		
		friend HugeInt operator/(long y, HugeInt x);		//�������� / �������� 
		
		friend HugeInt operator/(HugeInt x, string y);		//�������� / �ַ��� 
		
		friend HugeInt operator/(string y, HugeInt x);		//  �ַ��� / �������� 
		
		
		
		friend HugeInt operator%(HugeInt x, HugeInt y);    	//�������� % �������� 
		
		friend HugeInt operator%(HugeInt x, long y);		//�������� % �������� 
		
		friend HugeInt operator%(long y, HugeInt x);		//�������� % �������� 
		
		friend HugeInt operator%(HugeInt x, string y);		//�������� % �ַ��� 
		
		friend HugeInt operator%(string y, HugeInt x);		//  �ַ��� % �������� 
		
		
		
		friend bool operator<(HugeInt x, HugeInt y);     	//�������� < �������� 
		
		friend bool operator<(HugeInt x, long y);			//�������� < �������� 
		
		friend bool operator<(long y, HugeInt x);			//�������� < �������� 
		
		friend bool operator<(HugeInt x, string y);			//�������� < �ַ��� 
		
		friend bool operator<(string y, HugeInt x);			//  �ַ��� < �������� 
		
		
		
		friend bool operator>(HugeInt x, HugeInt y);     	//�������� > �������� 
		
		friend bool operator>(HugeInt x, long y);			//�������� > �������� 
		
		friend bool operator>(long y, HugeInt x);			//�������� > �������� 
		
		friend bool operator>(HugeInt x, string y);			//�������� > �ַ��� 
		
		friend bool operator>(string y, HugeInt x);			//  �ַ��� > �������� 
		
		
		
		friend bool operator==(HugeInt x, HugeInt y);     	//�������� == �������� 
		
		friend bool operator==(HugeInt x, long y);			//�������� == �������� 
		
		friend bool operator==(long y, HugeInt x);			//�������� == �������� 
		
		friend bool operator==(HugeInt x, string y);		//�������� == �ַ��� 
		
		friend bool operator==(string y, HugeInt x);		//  �ַ��� == �������� 
		
		
		
		friend bool operator<=(HugeInt x, HugeInt y);     	//�������� <= �������� 
		
		friend bool operator<=(HugeInt x, long y);			//�������� <= �������� 
		
		friend bool operator<=(long y, HugeInt x);			//�������� <= �������� 
		
		friend bool operator<=(HugeInt x, string y);		//�������� <= �ַ��� 
		
		friend bool operator<=(string y, HugeInt x);		//  �ַ��� <= �������� 
		
		
		
		friend bool operator>=(HugeInt x, HugeInt y);     	//�������� >= �������� 
		
		friend bool operator>=(HugeInt x, long y);			//�������� >= �������� 
		
		friend bool operator>=(long y, HugeInt x);			//�������� >= �������� 
		
		friend bool operator>=(HugeInt x, string y);		//�������� >= �ַ��� 
		
		friend bool operator>=(string y, HugeInt x);		//  �ַ��� >= �������� 
		
		
		
		friend bool operator!=(HugeInt x, HugeInt y);     	//�������� != �������� 
		
		friend bool operator!=(HugeInt x, long y);			//�������� != �������� 
		
		friend bool operator!=(long y, HugeInt x);			//�������� != �������� 
		
		friend bool operator!=(HugeInt x, string y);		//�������� != �ַ��� 
		
		friend bool operator!=(string y, HugeInt x);		//  �ַ��� != ��������
		
		
		
		HugeInt& operator+=(const HugeInt &i);				//�������� += �������� 
		
		HugeInt& operator+=(const long &i);					//�������� += �������� 
		
		HugeInt& operator+=(const string &i);						//�������� += �ַ���
		
		
		
		HugeInt& operator-=(const HugeInt &i);				//�������� -= �������� 
		
		HugeInt& operator-=(const long &i);					//�������� -= �������� 
		
		HugeInt& operator-=(const string &i);						//�������� -= �ַ���
		
		
		
		HugeInt& operator*=(const HugeInt &i);				//�������� *= �������� 
		
		HugeInt& operator*=(const long &i);					//�������� *= �������� 
	
		HugeInt& operator*=(const string &i);						//�������� *= �ַ���
		
		
		
		HugeInt& operator/=(const HugeInt &i);				//�������� /= �������� 
		
		HugeInt& operator/=(const long &i);					//�������� /= �������� 
		
		HugeInt& operator/=(const string &i);						//�������� /= �ַ���
		
		
		
		HugeInt& operator%=(const HugeInt &i);				//�������� %= �������� 
		
		HugeInt& operator%=(const long &i);					//�������� %= �������� 
		
		HugeInt& operator%=(const string &i);						//�������� %= �ַ���
		
		
		
		HugeInt operator++();     			//++�������� 
		
		HugeInt operator++(int);  			//�������� ++
		
		HugeInt operator--();     			//--�������� 
		
		HugeInt operator--(int);  			//�������� --
		
		
			
		friend istream &operator>>(istream &in, HugeInt &i);        //������������� 
		
		friend ostream &operator<<(ostream &out, const HugeInt &i); //������������ 
		
				
	
		string PrintOct();			//��������ת���ɰ˽����ַ��� 
	
		string PrintHex();			//��������ת����16�����ַ��� 
		
}; 


#endif
