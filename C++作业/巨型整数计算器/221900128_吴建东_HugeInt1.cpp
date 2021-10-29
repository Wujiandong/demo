#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "221900128_吴建东_HugeInt.h"

//显示版权信息
void Copyright()
{
	cout << "Copyright (c) 2020 吴建东(221900128). All Rights Reserved.\n\n";
}

//显示系统日期、时间 
void SystemTime()
{
	time_t CurrentTime; 
    struct tm *Date;
 	time(&CurrentTime);
    Date = localtime(&CurrentTime);
    cout << "当前日期、时间 : " << Date->tm_year + 1900<< '-' ;
	cout << setw(2) << setfill('0') << Date->tm_mon + 1 << '-' ;
	cout << setw(2) << setfill('0') << Date->tm_mday;
    switch(Date->tm_wday)
	{
		case 0 : cout << " (星期日)"; break; 
		case 1 : cout << " (星期一)"; break; 
		case 2 : cout << " (星期二)"; break; 
		case 3 : cout << " (星期三)"; break; 
		case 4 : cout << " (星期四)"; break; 
		case 5 : cout << " (星期五)"; break; 
		case 6 : cout << " (星期六)"; break; 
	}
	cout << "    " ;
	cout << setw(2) << setfill('0') << Date->tm_hour << ':' ;
	cout << setw(2) << setfill('0') << Date->tm_min  << ':' ;
	cout << setw(2) << setfill('0') << Date->tm_sec  << endl;
}

//显示菜单界面 
void Menu()
{
	cout << "*********************************"
	  	    "********************************\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*\t\t   巨型整数类程序测试系统  \t\t\t*\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*\tA；用Long整型数构造\t\t\t\t\t*\n";
	cout << "*\tB；用正确的字符串构造\t\t\t\t\t*\n";
	cout << "*\tC；用包含非法字符的字符串构造\t\t\t\t*\n";
	cout << "*\tD；用身份证号和学号进行十种运算\t\t\t\t*\n";
	cout << "*\tE；用两个100位字符串构造整数进行十种运算\t\t*\n";
	cout << "*\tF；用两个100位字符串构造整数进行六种关系运算\t\t*\n";
	cout << "*\tG；用任意值与0进行五种运算\t\t\t\t*\n";
	cout << "*\tH；100位字符串构造整数与默认构造整数进行++和--运算\t*\n";
	cout << "*\tI；100位字符串构造整数与两个默认构造整数进行赋值运算\t*\n";
	cout << "*\tJ；用100位字符串拷贝构造并进行求负运算\t\t\t*\n";
	cout << "*\tK；100位字符串构造与Long整数进行十种运算\t\t*\n";
	cout << "*\tL；字符串构造整数与Long整数进行六种关系运算\t\t*\n";
	cout << "*\tM；字符串构造整数与字符串进行六种关系运算\t\t*\n";
	cout << "*\tN；退出系统\t\t\t\t\t\t*\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*********************************"
	  	   "********************************\n";
}

//检验字符串是否是十进制数 
bool isDec(string s)
{
    const char *ptr = s.c_str();
    
	//寻找第一个非空白字符 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //第一个非空白字符必须是十进制基数数字字符之一'0'~'9',或者为正号'+',或者负号'-'
    //而且如果第一个字符为正号或者负号的话,必须要有下一个字符,否则就只剩一个正号或者负号了
    if(*ptr == '+' || *ptr == '-')
    {
        if(*(ptr+1) == 0)
            return false;
        if(*(ptr+1) == '0'&&(*(ptr+2) != 0))
        	return false;
    }
    else if(!isdigit(*ptr))
    {
        return false;
    }
    else if(*(ptr) == '0'&&(*(ptr+1) != 0))
    {
    	return false;
	}  
    ptr++;
    
    //如果有第二个非空白字符的话,就从第二个非空白字符遍历
    while(*ptr != 0)
    {
        if(!isdigit(*ptr))//只要出现非十进制基数数字字符就返回假
            return false;
        ptr++;
    }
    return true;

} 

//检验字符串是否是八进制数 
bool isOct(string s)
{
	const char *ptr = s.c_str();
    
	//寻找第一个非空白字符 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //第一个非空白字符必须是八进制基数数字字符'0',或者为正号'+',或者负号'-'
    //而且如果第一个字符为正号或者负号的话,下一个字符为'0',且必须要有下一个字符,否则就只剩一个正号或者负号和 0了
    if(*ptr == '+' || *ptr == '-')
    {
        if(*(ptr+1) == 0)
            return false;
        if(*(ptr+1) != '0'||*(ptr+2) == 0)
        	return false;
        ptr++;	
    }
    else if(*ptr != '0'||*(ptr+1) == 0)
    {
        return false;
    }
    ptr++;
    
    //如果有第二个非空白字符的话,就从第二个非空白字符遍历
    while(*ptr != 0)
    {
        if(*ptr < '0'||*ptr > '7')//只要出现非八进制基数数字字符就返回假
            return false;
        ptr++;
    }
    return true;
}

//检验字符串是否是十六进制数 
bool isHex(string s)
{
	const char *ptr = s.c_str();
    
	//寻找第一个非空白字符 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //第一个非空白字符必须是十六进制基数数字字符'0',或者为正号'+',或者负号'-'
    //而且如果第一个字符为正号或者负号的话,必须要有下一个字符,否则就只剩一个正号或者负号了
    //下两个字符为'0x'或者'0X' 
    if(*ptr == '+' || *ptr == '-')
    {
        if(*(ptr+1) == 0)
            return false;
        if(*(ptr+1) != '0'||(*(ptr+2) != 'x'&&*(ptr+2) != 'X')||*(ptr+3) == 0) 
        	return false;
        ptr += 3;	
        //如果有第二个非空白字符的话,就从第二个非空白字符遍历
	    while(*ptr != 0)
	    {
	        //只要出现非十六进制基数数字字符就返回假
			if(!isdigit(*ptr)&&(*ptr < 'a'|| *ptr > 'f')&&(*ptr < 'A'|| *ptr > 'F'))
	            return false;
	        ptr++;
	    }
	    return true;
    }
    else if(*ptr != '0'||(*(ptr+1) != 'x'&&*(ptr+1) != 'X')||*(ptr+2) == 0)
    {
		return false;
    }
	else
	{
		ptr += 2;
		//如果有第二个非空白字符的话,就从第二个非空白字符遍历
	    while(*ptr != 0)
	    {
	        //只要出现非十六进制基数数字字符就返回假
			if(!isdigit(*ptr)&&(*ptr < 'a'|| *ptr > 'f')&&(*ptr < 'A'|| *ptr > 'F'))
	            return false;
	        ptr++;
	    }
	    return true;
	}
}

//比较字符串，相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2) 
{
    //长度长的整数大于长度小的整数
	if(str1.size() > str2.size()) 
		return 1; 
    else if(str1.size() < str2.size()) 
		return -1;
    else	//若长度相等，则头到尾按位比较    
		return str1.compare(str2); 
}

string Sub(string str1, string str2);

//字符串加法运算 
string Add(string str1, string str2) 
{
    int sign = 1; //sign 为符号位
    string str;
    if(str1[0] == '-') 
	{
        //若两个数均为负数，同时去除负号进行运算，最后再补负号 
		if (str2[0]=='-') 
		{
            sign = -1;
            str = Add(str1.erase(0,1), str2.erase(0,1));
        } 
		else //若其中一个数为负数，直接进行两个正数的减法运算 
		{
            str = Sub(str2, str1.erase(0,1));
        }
    } 
	else 
	{
        //若其中一个数为负数，直接进行两个正数的减法运算 
		if(str2[0] == '-') 
		{
            str=Sub(str1,str2.erase(0,1));
        } 
		else //把两个整数对齐，短整数前面加0补齐
		{ 
            string::size_type L1, L2;
            int i;
            L1 = str1.size();
            L2 = str2.size();
            if(L1 < L2) 
			{
                for(i = 1; i <= L2 - L1; i++) 
					str1 = "0" + str1;
            } 
			else 
			{
                for(i = 1; i <= L1 - L2; i++) 
					str2 = "0" + str2;
            }
            int int1 = 0, int2 = 0; //int2 记录进位
            //逐位相加并记录进位 
            for(i = str1.size() - 1; i >= 0; i--) 
			{
                int1 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) % 10;
                int2 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) / 10;
                str = char(int1 + '0') + str;
            }
            if(int2 != 0) 
				str = char(int2 + '0') + str;
        }
    }
    //运算后处理符号位
    if ((sign == -1)&&(str[0] != '0')) 
		str = "-" + str;
    return str;
}

//字符串减法运算 
string Sub(string str1, string str2) 
{
    int sign = 1; //sign 为符号位
    string str;
    int i, j;
    //若减数为负数，直接进行一个数与正数的加法运算 
    if(str2[0] == '-') 
	{
        str = Add(str1, str2.erase(0,1));
    }
	else
	{
        int res = compare(str1, str2);
        if(res == 0) 
			return "0";
			
        //交换位置，保证大数减小数 
		if (res < 0) 
		{
            sign = -1;
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        string::size_type tempint; //记录两个字符串的长度差绝对值 
        tempint = str1.size() - str2.size();
        for(i = str2.size() - 1; i >= 0; i--) 
		{
            //如果被减数某一位小于减数对应的某一位，那么前一位减1 
			if(str1[i + tempint] < str2[i])
			{
                j = 1;
                while(1) 
				{
                    //如果前一位为0，则变成9，并继续让前一位减1，直到前一位不为0 
					if (str1[i + tempint - j] == '0') 
					{
                        str1[i + tempint - j] = '9';
                        j++;
                    } 
					else 
					{
                        str1[i + tempint - j] = char(int(str1[i + tempint - j]) - 1);
                        break;
                    }
                }
                str = char(str1[i + tempint] - str2[i] + ':') + str;
            } 
			else 
			{
                str = char(str1[i + tempint] - str2[i] + '0') + str;
            }
        }
        for (i = tempint - 1; i >= 0; i--) 
			str = str1[i] + str;
    }
    
    //去除结果中多余的前导0
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) 
		str = "0";
    if ((sign == -1) && (str[0] != '0')) 
		str = "-" + str;
    return str;
}

//字符串乘法运算 
string Mul(string str1, string str2) 
{
    int sign = 1; //sign 为符号位
    string str;
    
    //设定好结果的符号位 
	if (str1[0] == '-') 
	{
        sign *= -1;
        str1 = str1.erase(0,1);
    }
    if (str2[0] == '-') 
	{
        sign *= -1;
        str2 = str2.erase(0,1);
    }
    
    int i, j;
    string::size_type L1, L2;
    L1 = str1.size();
    L2 = str2.size();
    
    //模拟手工乘法竖式
	for(i = L2 - 1; i >= 0; i--)
	{ 
        string tempstr;
        int int1 = 0, int2 = 0, int3 = int(str2[i]) - '0';
        if (int3 != 0) 
		{
            for(j = 1; j <= (int)(L2 - 1 - i); j++)
			{
				tempstr = "0" + tempstr;
			}
            for(j = L1 - 1; j >= 0; j--) 
			{
                int1 = (int3 * (int(str1[j]) - '0') + int2) % 10;
                int2 = (int3 * (int(str1[j]) - '0') + int2) / 10;
                tempstr = char(int1 + '0') + tempstr;
            }
            if(int2 != 0) 
			{
				tempstr = char(int2 + '0') + tempstr;
			}	
        }
        str = Add(str, tempstr);
    }
    
    //去除结果中的前导0
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) 
		str = "0";
    if((sign == -1) && (str[0] != '0')) 
		str = "-" + str;
    return str;
}

//字符串除法和求余运算。flag==1时,返回商; flag==0时,返回余数
string Devide(string str1, string str2, int flag) 
{
    string quotient, residue; //定义商和余数
    int sign1 = 1, sign2 = 1;
    
    //判断除数是否为0
	if(str2 == "0") 
	{  
        throw "除0错！"; 
    }
	//判断被除数是否为0
    if(str1 == "0") 
	{ 
        quotient = "0";
        residue = "0";
    }
    
    //设定好结果的符号位 
    if(str1[0] == '-')
	{
        str1   = str1.erase(0,1);
        sign1 *= -1;
        sign2  = -1;
    }
    if(str2[0] == '-') 
	{
        str2   = str2.erase(0,1);
        sign1 *= -1;
    }
    
    int res = compare(str1, str2);
    if(res < 0) 
	{
        quotient = "0";
        residue  = str1;
    } 
	else if(res == 0) 
	{
        quotient = "1";
        residue  = "0";
    } 
	else 
	{
        string::size_type L1, L2;
        L1 = str1.size();
        L2 = str2.size();
        string tempstr;
        tempstr.append(str1, 0, L2 - 1);
		
		//模拟手工除法竖式
        for(int i = L2 - 1; i < L1; i++) 
		{ 
            tempstr = tempstr + str1[i];
            //去除前导0 
			tempstr.erase(0, tempstr.find_first_not_of('0'));
            if(tempstr.empty())
				tempstr = "0";
            
			for(char ch = '9'; ch >= '0'; ch--) //试商
			{ 
                string str;
                str = str + ch;
                if(compare(Mul(str2, str), tempstr) <= 0) 
				{
                    quotient = quotient + ch;
                    tempstr = Sub(tempstr , Mul(str2, str));
                    break;
                }
            }
        }
        residue = tempstr;
    }
    
    //去除结果中的前导0
    quotient.erase(0, quotient.find_first_not_of('0'));
    if(quotient.empty()) 
		quotient = "0";
    if((sign1 == -1) && (quotient[0] != '0')) 
		quotient="-" + quotient;
    if((sign2 == -1) && (residue [0] != '0')) 
		residue = "-" + residue;
		
    if(flag == 1) 
		return quotient;
    else        
		return residue;
}
//字符串除法运算 
string Div(string str1, string str2)
{
    return Devide(str1, str2, 1);
}

//字符串求余运算 
string Mod(string str1, string str2) 
{
    return Devide(str1, str2, 0);
}

//长整型转换成十进制字符串 
string LongToDec(long a) 
{		
	string str;
	char s[Max];
	itoa(a, s, 10);
	str = s;
	return str; 
}

//八进制字符串转换成十进制字符串
string OctToDec(string oct)
{
	int i, j;
	string dec = "0", temp1 = "0", temp2 = "8", temp3 = "+";
	
	//设定好结果的符号位 
	if(oct[0] == '-')
	{
		oct.erase(0,1);
		temp3 = "-";
	}
	
	//从最高位开始，位数乘8后加上下一位的和继续乘8，以此类推直至最低位。 
	for(i = 1; i < oct.size(); i++)
	{
		temp1[0] = oct[i];
		if(i != oct.size() - 1)
		{
			dec = Mul(Add(dec, temp1), temp2);
		}
		else
			dec = Add(dec, temp1);
	}
	if(temp3 == "-")
		dec = "-" + dec;
	return dec;
}

//十六进制基数字符对应十进制数值 
string HexSingleIndex(char hex)
{	
	string index;
	switch(hex)
	{
		case '0' : index = "0" ; break;
		case '1' : index = "1" ; break;
		case '2' : index = "2" ; break;
		case '3' : index = "3" ; break;
		case '4' : index = "4" ; break;
		case '5' : index = "5" ; break;
		case '6' : index = "6" ; break;
		case '7' : index = "7" ; break;
		case '8' : index = "8" ; break;
		case '9' : index = "9" ; break;
		case 'a' : 
		case 'A' : index = "10"; break;
		case 'b' : 
		case 'B' : index = "11"; break;
		case 'c' : 
		case 'C' : index = "12"; break;
		case 'd' : 
		case 'D' : index = "13"; break;
		case 'e' : 
		case 'E' : index = "14"; break;
		case 'f' : 
		case 'F' : index = "15"; break;
	}
	return index;
}

//十六进制字符串转换成十进制字符串
string HexToDec(string hex)
{
	int i, j;
	string dec = "0", temp1, temp2 = "16", temp3 = "+";
	
	//设定好结果的符号位 
	if(hex[0] == '-')
	{
		hex.erase(0,1); 
		temp3 = "-";
	}
	
	//从最高位开始，位数乘16后加上下一位的和继续乘16，以此类推直至最低位。 
	for(i = 2; i < hex.size(); i++)
	{
		temp1 = HexSingleIndex(hex[i]);
		if(i != hex.size() - 1)
		{
			dec = Mul(Add(dec, temp1), temp2);
		}
		else
			dec = Add(dec, temp1);
	}
	if(temp3 == "-")
		dec = "-" + dec;
	return dec;
}


HugeInt::HugeInt(long i)
{
	a = LongToDec(i);
}


HugeInt::HugeInt(string s)
{
	if(isOct(s))
	{
		a = OctToDec(s);
	}
	else if(isDec(s))
	{
		a = s;
		if(a[0] == '+')
			a.erase(0, 1);
		if(Mul(a, "1") == "0")
			a = "0";
	}
	else if(isHex(s))
	{
		a = HexToDec(s);
	}
	else
	{
		a = "0";
		throw "非法数字字符串"; 
	}
}

HugeInt::HugeInt(const HugeInt &i)
{
	a = i.a;
}

HugeInt& HugeInt::operator=(const HugeInt &i)
{
	if(this != &i)		//避免自赋值 
	{
		a = i.a;
	}
	return *this;
}


//巨型整数 + 巨型整数 
HugeInt operator+(HugeInt x, HugeInt y)    		
{
	HugeInt Ans;
	Ans.a = Add(x.a, y.a);
	return Ans;
}

//巨型整数 + 长整型数 
HugeInt operator+(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Add(x.a, LongToDec(y));
	return Ans;
}

//长整型数 + 巨型整数 
HugeInt operator+(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Add(LongToDec(y), x.a);
	return Ans;
}

//巨型整数 + 字符串 
HugeInt operator+(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Add(x.a, strY);
	return Ans;
}

//字符串 + 巨型整数 
HugeInt operator+(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Add(strY, x.a);
	return Ans;
}



//求负运算
HugeInt operator-(HugeInt x)
{
	if(x.a[0] == '-')
		x.a.erase(0, 1);
	else
		x.a = "-" + x.a;
	return x;
}

//巨型整数 - 巨型整数 
HugeInt operator-(HugeInt x, HugeInt y)     	
{
	HugeInt Ans;
	Ans.a = Sub(x.a, y.a);
	return Ans;
}

//巨型整数 - 长整型数 
HugeInt operator-(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Sub(x.a, LongToDec(y));
	return Ans;
}

//长整型数 - 巨型整数 
HugeInt operator-(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Sub(LongToDec(y), x.a);
	return Ans;
}

//巨型整数 - 字符串 
HugeInt operator-(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Sub(x.a, strY);
	return Ans;
}

//字符串 - 巨型整数
HugeInt operator-(string y, HugeInt x)		 
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Sub(strY, x.a);
	return Ans;
}



//巨型整数 * 巨型整数 
HugeInt operator*(HugeInt x, HugeInt y)	    	
{
	HugeInt Ans;
	Ans.a = Mul(x.a, y.a);
	return Ans;
}

//巨型整数 * 长整型数 
HugeInt operator*(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Mul(x.a, LongToDec(y));
	return Ans;
}

//长整型数 * 巨型整数 
HugeInt operator*(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Mul(LongToDec(y), x.a);
	return Ans;
}

//巨型整数 * 字符串 
HugeInt operator*(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mul(x.a, strY);
	return Ans;
}

//字符串 * 巨型整数 
HugeInt operator*(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mul(strY, x.a);
	return Ans;
}



//巨型整数 / 巨型整数 
HugeInt operator/(HugeInt x, HugeInt y)	    	
{
	HugeInt Ans;
	Ans.a = Div(x.a, y.a);
	return Ans;
}

//巨型整数 / 长整型数 
HugeInt operator/(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Div(x.a, LongToDec(y));
	return Ans;
}

//长整型数 / 巨型整数 
HugeInt operator/(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Div(LongToDec(y), x.a);
	return Ans;
}

//巨型整数 / 字符串 
HugeInt operator/(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Div(x.a, strY);
	return Ans;
}

//字符串 / 巨型整数 
HugeInt operator/(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Div(strY, x.a);
	return Ans;
}



//巨型整数 % 巨型整数 
HugeInt operator%(HugeInt x, HugeInt y)     	
{
	HugeInt Ans;
	Ans.a = Mod(x.a, y.a);
	return Ans;
}

//巨型整数 % 长整型数 
HugeInt operator%(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Mod(x.a, LongToDec(y));
	return Ans;
}

//长整型数 % 巨型整数 
HugeInt operator%(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Mod(LongToDec(y), x.a);
	return Ans;
}

//巨型整数 % 字符串 
HugeInt operator%(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mod(x.a, strY);
	return Ans;
}

//字符串 % 巨型整数 
HugeInt operator%(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mod(strY, x.a);
	return Ans;
}



//巨型整数 < 巨型整数 
bool operator<(HugeInt x, HugeInt y)     	
{
	if(x.a[0] == '-' && y.a[0] != '-')
		return true;
	else if(x.a[0] != '-' && y.a[0] == '-')
		return false;
	else if(x.a[0] == '-' && y.a[0] == '-')
	{
		return (x.a.compare(y.a) == 1);
	}
	else
	{
		return (x.a.compare(y.a) == -1);
	}
}

//巨型整数 < 长整型数 
bool operator<(HugeInt x, long y)			
{
	string strY = LongToDec(y);
	if(x.a[0] == '-' && strY[0] != '-')
		return true;
	else if(x.a[0] != '-' && strY[0] == '-')
		return false;
	else if(x.a[0] == '-' && strY[0] == '-')
	{
		return (x.a.compare(strY) == 1);
	}
	else
	{
		return (x.a.compare(strY) == -1);
	}
}

//长整型数 < 巨型整数 
bool operator<(long y, HugeInt x)			
{
	string strY = LongToDec(y);
	if(strY[0] == '-' && x.a[0] != '-')
		return true;
	else if(strY[0] != '-' && x.a[0] == '-')
		return false;
	else if(strY[0] == '-' && x.a[0] == '-')
	{
		return (strY.compare(x.a) == 1);
	}
	else
	{
		return (strY.compare(x.a) == -1);
	}
}

//巨型整数 < 字符串 
bool operator<(HugeInt x, string y)	
{
	string strY = y;
	if(x.a[0] == '-' && strY[0] != '-')
		return true;
	else if(x.a[0] != '-' && strY[0] == '-')
		return false;
	else if(x.a[0] == '-' && strY[0] == '-')
	{
		return (x.a.compare(strY) == 1);
	}
	else
	{
		return (x.a.compare(strY) == -1);
	}
}

//字符串 < 巨型整数 
bool operator<(string y, HugeInt x)	
{
	string strY = y;
	if(strY[0] == '-' && x.a[0] != '-')
		return true;
	else if(strY[0] != '-' && x.a[0] == '-')
		return false;
	else if(strY[0] == '-' && x.a[0] == '-')
	{
		return (strY.compare(x.a) == 1);
	}
	else
	{
		return (strY.compare(x.a) == -1);
	}
}



//巨型整数 > 巨型整数 
bool operator>(HugeInt x, HugeInt y)     	
{
	if(x.a[0] == '-' && y.a[0] != '-')
		return false;
	else if(x.a[0] != '-' && y.a[0] == '-')
		return true;
	else if(x.a[0] == '-' && y.a[0] == '-')
	{
		return (x.a.compare(y.a) == -1);
	}
	else
	{
		return (x.a.compare(y.a) == 1);
	}
}

//巨型整数 > 长整型数 
bool operator>(HugeInt x, long y)			
{
	string strY = LongToDec(y);
	if(x.a[0] == '-' && strY[0] != '-')
		return false;
	else if(x.a[0] != '-' && strY[0] == '-')
		return true;
	else if(x.a[0] == '-' && strY[0] == '-')
	{
		return (x.a.compare(strY) == -1);
	}
	else
	{
		return (x.a.compare(strY) == 1);
	}
}

//长整型数 > 巨型整数 
bool operator>(long y, HugeInt x)			
{
	string strY = LongToDec(y);
	if(strY[0] == '-' && x.a[0] != '-')
		return false;
	else if(strY[0] != '-' && x.a[0] == '-')
		return true;
	else if(strY[0] == '-' && x.a[0] == '-')
	{
		return (strY.compare(x.a) == -1);
	}
	else
	{
		return (strY.compare(x.a) == 1);
	}
}

//巨型整数 > 字符串 
bool operator>(HugeInt x, string y)	
{
	string strY = y;
	if(x.a[0] == '-' && strY[0] != '-')
		return false;
	else if(x.a[0] != '-' && strY[0] == '-')
		return true;
	else if(x.a[0] == '-' && strY[0] == '-')
	{
		return (x.a.compare(strY) == -1);
	}
	else
	{
		return (x.a.compare(strY) == 1);
	}
}

//字符串 > 巨型整数 
bool operator>(string y, HugeInt x)	
{
	string strY = y;
	if(strY[0] == '-' && x.a[0] != '-')
		return false;
	else if(strY[0] != '-' && x.a[0] == '-')
		return true;
	else if(strY[0] == '-' && x.a[0] == '-')
	{
		return (strY.compare(x.a) == -1);
	}
	else
	{
		return (strY.compare(x.a) == 1);
	}
}



//巨型整数 == 巨型整数 
bool operator==(HugeInt x, HugeInt y)     	
{
	return (x.a.compare(y.a) == 0);
}

//巨型整数 == 长整型数 
bool operator==(HugeInt x, long y)			
{
	return (x.a.compare(LongToDec(y)) == 0);
}

//长整型数 == 巨型整数 
bool operator==(long y, HugeInt x)			
{
	return (LongToDec(y).compare(x.a) == 0);
}

//巨型整数 == 字符串 
bool operator==(HugeInt x, string y)	
{
	string strY = y;
	return (x.a.compare(strY) == 0);
}

//字符串 == 巨型整数 
bool operator==(string y, HugeInt x)	
{
	string strY = y;
	return (strY.compare(x.a) == 0);
}



//巨型整数 <= 巨型整数 
bool operator<=(HugeInt x, HugeInt y)     	
{
	return (x < y || x == y);
}

//巨型整数 <= 长整型数 
bool operator<=(HugeInt x, long y)			
{
	return (x < y || x == y);
}

//长整型数 <= 巨型整数 
bool operator<=(long y, HugeInt x)			
{
	return (y < x || y == x);
}

//巨型整数 <= 字符串 
bool operator<=(HugeInt x, string y)	
{
	return (x < y || x == y);
}

//字符串 <= 巨型整数 
bool operator<=(string y, HugeInt x)	
{
	return (y < x || y == x);
}



//巨型整数 >= 巨型整数 
bool operator>=(HugeInt x, HugeInt y)     	
{
	return (x > y || x == y);
}

//巨型整数 >= 长整型数 
bool operator>=(HugeInt x, long y)			
{
	return (x > y || x == y);
}

//长整型数 >= 巨型整数 
bool operator>=(long y, HugeInt x)			
{
	return (y > x || y == x);
}

//巨型整数 >= 字符串 
bool operator>=(HugeInt x, string y)	
{
	return (x > y || x == y);
}

//字符串 >= 巨型整数 
bool operator>=(string y, HugeInt x)	
{
	return (y > x || y == x);
}



//巨型整数 != 巨型整数 
bool operator!=(HugeInt x, HugeInt y)     	
{
	return !(x == y);
}

//巨型整数 != 长整型数 
bool operator!=(HugeInt x, long y)			
{
	return !(x == y);
}

//长整型数 != 巨型整数 
bool operator!=(long y, HugeInt x)			
{
	return !(y == x);
}

//巨型整数 != 字符串 
bool operator!=(HugeInt x, string y)	
{
	return !(x == y);
}

//字符串 != 巨型整数
bool operator!=(string y, HugeInt x)	
{
	return !(y == x);
}



//巨型整数 += 巨型整数 
HugeInt& HugeInt::operator+=(const HugeInt &i)			
{
	*this = *this + i;
	return *this;
}

//巨型整数 += 长整型数 
HugeInt& HugeInt::operator+=(const long &i)				
{
	*this = *this + i;
	return *this;
}

//巨型整数 += 字符串
HugeInt& HugeInt::operator+=(const string &i)			
{
	*this = *this + i;
	return *this;
}



//巨型整数 -= 巨型整数 
HugeInt& HugeInt::operator-=(const HugeInt &i)			
{
	*this = *this - i;
	return *this;
}

//巨型整数 -= 长整型数 
HugeInt& HugeInt::operator-=(const long &i)				
{
	*this = *this - i;
	return *this;
}

//巨型整数 -= 字符串
HugeInt& HugeInt::operator-=(const string &i)			
{
	*this = *this - i;
	return *this;
}



//巨型整数 *= 巨型整数 
HugeInt& HugeInt::operator*=(const HugeInt &i)			
{
	*this = *this * i;
	return *this;
}

//巨型整数 *= 长整型数 
HugeInt& HugeInt::operator*=(const long &i)				
{
	*this = *this * i;
	return *this;
}

//巨型整数 *= 字符串
HugeInt& HugeInt::operator*=(const string &i)			
{
	*this = *this * i;
	return *this;
}



//巨型整数 /= 巨型整数 
HugeInt& HugeInt::operator/=(const HugeInt &i)			
{
	*this = *this / i;
	return *this;
}

//巨型整数 /= 长整型数 
HugeInt& HugeInt::operator/=(const long &i)				
{
	*this = *this / i;
	return *this;
}

//巨型整数 /= 字符串
HugeInt& HugeInt::operator/=(const string &i)			
{
	*this = *this / i;
	return *this;
}



//巨型整数 %= 巨型整数 
HugeInt& HugeInt::operator%=(const HugeInt &i)			
{
	*this = *this % i;
	return *this;
}

//巨型整数 %= 长整型数 
HugeInt& HugeInt::operator%=(const long &i)				
{
	*this = *this % i;
	return *this;
}

//巨型整数 %= 字符串
HugeInt& HugeInt::operator%=(const string &i)			
{
	*this = *this % i;
	return *this;
}



//++巨型整数 
HugeInt HugeInt::operator++()   			
{
	*this = *this + 1;
	return *this;
}

//巨型整数 ++
HugeInt HugeInt::operator++(int)  			
{
	HugeInt temp = *this;
	*this = *this + 1;
	return temp;
}

//--巨型整数 
HugeInt HugeInt::operator--()    			
{
	*this = *this - 1;
	return *this;
}

//巨型整数 --
HugeInt HugeInt::operator--(int) 			
{
	HugeInt temp = *this;
	*this = *this - 1;
	return temp;
}



//输入运算符重载 
istream &operator>>(istream &in, HugeInt &i)        	
{
	char temp[Max];
	in >> temp;
	if(isDec(temp) || isOct(temp) || isHex(temp))
		i.a = temp;
	else
	{
		i.a = "0";
		throw "非法数字字符串"; 
	}
	return in;
}

//输出运算符重载 
ostream &operator<<(ostream &out, const HugeInt &i) 	
{
	string temp = i.a;
	int j, size = temp.size();
	for(j = 0; j < size; j += 4)
	{
		temp.insert(size - j, ",");
	}
	temp.erase(temp.size() - 1, 1);
	
	//去掉负号后面紧跟的逗号 
	if(temp[0] == '-' && temp[1] == ',')
		temp.erase(1, 1);
	out << temp;
	return out;
}

		

//巨型整数转换成8进制字符串 
string HugeInt::PrintOct()			
{
	int sign = 0; //记录符号位 
	string oct, temp = a;
	
	//设定好结果的符号位 
	if(temp[0] == '+')
		temp.erase(0, 1);
	if(temp[0] == '-')
	{
		temp.erase(0, 1);
		sign = 1;
	}
	
	while(temp != "0")
	{
		//逐次取余数放于8进制字符串前端 
		oct = Mod(temp, "8") + oct;
		
		//取余后自身除一次8
		temp = Div(temp, "8");
	}
	oct = "0" + oct;
	if(sign) //补负号
		oct = "-" + oct;
	return oct;
}

//十进制数值对应十六进制基数字符
string DecToHexIndex(string dec)
{	
	string index;
	if(dec < "10");
		index = dec;
	if(dec == "10")
		index = "A";
	if(dec == "11")
		index = "B";
	if(dec == "12")
		index = "C";
	if(dec == "13")
		index = "D";
	if(dec == "14")
		index = "E";
	if(dec == "15")
		index = "F";
	return index;
}

//巨型整数转换成16进制字符串  
string HugeInt::PrintHex()			
{
	int sign = 0; //记录符号位 
	string hex, temp = a;
	
	//设定好结果的符号位 
	if(temp[0] == '+')
		temp.erase(0, 1);
	if(temp[0] == '-')
	{
		temp.erase(0, 1);
		sign = 1;
	}	
	
	while(temp != "0") 
	{
		//逐次取余数放于16进制字符串前端 
		hex  = DecToHexIndex(Mod(temp, "16")) + hex;
		
		//取余后自身除一次16 
		temp = Div(temp, "16");
	}
	hex = "0X" + hex;
	if(sign) //补负号 
		hex = "-" + hex;
	return hex;
}

