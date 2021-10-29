#include <cstring> 
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "221900128_�⽨��_HugeInt.h"

//��ʾ��Ȩ��Ϣ
void Copyright()
{
	cout << "Copyright (c) 2020 �⽨��(221900128). All Rights Reserved.\n\n";
}

//��ʾϵͳ���ڡ�ʱ�� 
void SystemTime()
{
	time_t CurrentTime; 
    struct tm *Date;
 	time(&CurrentTime);
    Date = localtime(&CurrentTime);
    cout << "��ǰ���ڡ�ʱ�� : " << Date->tm_year + 1900<< '-' ;
	cout << setw(2) << setfill('0') << Date->tm_mon + 1 << '-' ;
	cout << setw(2) << setfill('0') << Date->tm_mday;
    switch(Date->tm_wday)
	{
		case 0 : cout << " (������)"; break; 
		case 1 : cout << " (����һ)"; break; 
		case 2 : cout << " (���ڶ�)"; break; 
		case 3 : cout << " (������)"; break; 
		case 4 : cout << " (������)"; break; 
		case 5 : cout << " (������)"; break; 
		case 6 : cout << " (������)"; break; 
	}
	cout << "    " ;
	cout << setw(2) << setfill('0') << Date->tm_hour << ':' ;
	cout << setw(2) << setfill('0') << Date->tm_min  << ':' ;
	cout << setw(2) << setfill('0') << Date->tm_sec  << endl;
}

//��ʾ�˵����� 
void Menu()
{
	cout << "*********************************"
	  	    "********************************\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*\t\t   ����������������ϵͳ  \t\t\t*\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*\tA����Long����������\t\t\t\t\t*\n";
	cout << "*\tB������ȷ���ַ�������\t\t\t\t\t*\n";
	cout << "*\tC���ð����Ƿ��ַ����ַ�������\t\t\t\t*\n";
	cout << "*\tD�������֤�ź�ѧ�Ž���ʮ������\t\t\t\t*\n";
	cout << "*\tE��������100λ�ַ���������������ʮ������\t\t*\n";
	cout << "*\tF��������100λ�ַ������������������ֹ�ϵ����\t\t*\n";
	cout << "*\tG��������ֵ��0������������\t\t\t\t*\n";
	cout << "*\tH��100λ�ַ�������������Ĭ�Ϲ�����������++��--����\t*\n";
	cout << "*\tI��100λ�ַ�����������������Ĭ�Ϲ����������и�ֵ����\t*\n";
	cout << "*\tJ����100λ�ַ����������첢����������\t\t\t*\n";
	cout << "*\tK��100λ�ַ���������Long��������ʮ������\t\t*\n";
	cout << "*\tL���ַ�������������Long�����������ֹ�ϵ����\t\t*\n";
	cout << "*\tM���ַ��������������ַ����������ֹ�ϵ����\t\t*\n";
	cout << "*\tN���˳�ϵͳ\t\t\t\t\t\t*\n";
	cout << "*\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t*\n";
	cout << "*********************************"
	  	   "********************************\n";
}

//�����ַ����Ƿ���ʮ������ 
bool isDec(string s)
{
    const char *ptr = s.c_str();
    
	//Ѱ�ҵ�һ���ǿհ��ַ� 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //��һ���ǿհ��ַ�������ʮ���ƻ��������ַ�֮һ'0'~'9',����Ϊ����'+',���߸���'-'
    //���������һ���ַ�Ϊ���Ż��߸��ŵĻ�,����Ҫ����һ���ַ�,�����ֻʣһ�����Ż��߸�����
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
    
    //����еڶ����ǿհ��ַ��Ļ�,�ʹӵڶ����ǿհ��ַ�����
    while(*ptr != 0)
    {
        if(!isdigit(*ptr))//ֻҪ���ַ�ʮ���ƻ��������ַ��ͷ��ؼ�
            return false;
        ptr++;
    }
    return true;

} 

//�����ַ����Ƿ��ǰ˽����� 
bool isOct(string s)
{
	const char *ptr = s.c_str();
    
	//Ѱ�ҵ�һ���ǿհ��ַ� 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //��һ���ǿհ��ַ������ǰ˽��ƻ��������ַ�'0',����Ϊ����'+',���߸���'-'
    //���������һ���ַ�Ϊ���Ż��߸��ŵĻ�,��һ���ַ�Ϊ'0',�ұ���Ҫ����һ���ַ�,�����ֻʣһ�����Ż��߸��ź� 0��
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
    
    //����еڶ����ǿհ��ַ��Ļ�,�ʹӵڶ����ǿհ��ַ�����
    while(*ptr != 0)
    {
        if(*ptr < '0'||*ptr > '7')//ֻҪ���ַǰ˽��ƻ��������ַ��ͷ��ؼ�
            return false;
        ptr++;
    }
    return true;
}

//�����ַ����Ƿ���ʮ�������� 
bool isHex(string s)
{
	const char *ptr = s.c_str();
    
	//Ѱ�ҵ�һ���ǿհ��ַ� 
    while(isspace(*ptr) && *ptr != 0)
    {
        ptr++;
    }
	
    //��һ���ǿհ��ַ�������ʮ�����ƻ��������ַ�'0',����Ϊ����'+',���߸���'-'
    //���������һ���ַ�Ϊ���Ż��߸��ŵĻ�,����Ҫ����һ���ַ�,�����ֻʣһ�����Ż��߸�����
    //�������ַ�Ϊ'0x'����'0X' 
    if(*ptr == '+' || *ptr == '-')
    {
        if(*(ptr+1) == 0)
            return false;
        if(*(ptr+1) != '0'||(*(ptr+2) != 'x'&&*(ptr+2) != 'X')||*(ptr+3) == 0) 
        	return false;
        ptr += 3;	
        //����еڶ����ǿհ��ַ��Ļ�,�ʹӵڶ����ǿհ��ַ�����
	    while(*ptr != 0)
	    {
	        //ֻҪ���ַ�ʮ�����ƻ��������ַ��ͷ��ؼ�
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
		//����еڶ����ǿհ��ַ��Ļ�,�ʹӵڶ����ǿհ��ַ�����
	    while(*ptr != 0)
	    {
	        //ֻҪ���ַ�ʮ�����ƻ��������ַ��ͷ��ؼ�
			if(!isdigit(*ptr)&&(*ptr < 'a'|| *ptr > 'f')&&(*ptr < 'A'|| *ptr > 'F'))
	            return false;
	        ptr++;
	    }
	    return true;
	}
}

//�Ƚ��ַ�������ȷ���0�����ڷ���1��С�ڷ���-1
int compare(string str1, string str2) 
{
    //���ȳ����������ڳ���С������
	if(str1.size() > str2.size()) 
		return 1; 
    else if(str1.size() < str2.size()) 
		return -1;
    else	//��������ȣ���ͷ��β��λ�Ƚ�    
		return str1.compare(str2); 
}

string Sub(string str1, string str2);

//�ַ����ӷ����� 
string Add(string str1, string str2) 
{
    int sign = 1; //sign Ϊ����λ
    string str;
    if(str1[0] == '-') 
	{
        //����������Ϊ������ͬʱȥ�����Ž������㣬����ٲ����� 
		if (str2[0]=='-') 
		{
            sign = -1;
            str = Add(str1.erase(0,1), str2.erase(0,1));
        } 
		else //������һ����Ϊ������ֱ�ӽ������������ļ������� 
		{
            str = Sub(str2, str1.erase(0,1));
        }
    } 
	else 
	{
        //������һ����Ϊ������ֱ�ӽ������������ļ������� 
		if(str2[0] == '-') 
		{
            str=Sub(str1,str2.erase(0,1));
        } 
		else //�������������룬������ǰ���0����
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
            int int1 = 0, int2 = 0; //int2 ��¼��λ
            //��λ��Ӳ���¼��λ 
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
    //����������λ
    if ((sign == -1)&&(str[0] != '0')) 
		str = "-" + str;
    return str;
}

//�ַ����������� 
string Sub(string str1, string str2) 
{
    int sign = 1; //sign Ϊ����λ
    string str;
    int i, j;
    //������Ϊ������ֱ�ӽ���һ�����������ļӷ����� 
    if(str2[0] == '-') 
	{
        str = Add(str1, str2.erase(0,1));
    }
	else
	{
        int res = compare(str1, str2);
        if(res == 0) 
			return "0";
			
        //����λ�ã���֤������С�� 
		if (res < 0) 
		{
            sign = -1;
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        string::size_type tempint; //��¼�����ַ����ĳ��Ȳ����ֵ 
        tempint = str1.size() - str2.size();
        for(i = str2.size() - 1; i >= 0; i--) 
		{
            //���������ĳһλС�ڼ�����Ӧ��ĳһλ����ôǰһλ��1 
			if(str1[i + tempint] < str2[i])
			{
                j = 1;
                while(1) 
				{
                    //���ǰһλΪ0������9����������ǰһλ��1��ֱ��ǰһλ��Ϊ0 
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
    
    //ȥ������ж����ǰ��0
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) 
		str = "0";
    if ((sign == -1) && (str[0] != '0')) 
		str = "-" + str;
    return str;
}

//�ַ����˷����� 
string Mul(string str1, string str2) 
{
    int sign = 1; //sign Ϊ����λ
    string str;
    
    //�趨�ý���ķ���λ 
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
    
    //ģ���ֹ��˷���ʽ
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
    
    //ȥ������е�ǰ��0
    str.erase(0, str.find_first_not_of('0'));
    if(str.empty()) 
		str = "0";
    if((sign == -1) && (str[0] != '0')) 
		str = "-" + str;
    return str;
}

//�ַ����������������㡣flag==1ʱ,������; flag==0ʱ,��������
string Devide(string str1, string str2, int flag) 
{
    string quotient, residue; //�����̺�����
    int sign1 = 1, sign2 = 1;
    
    //�жϳ����Ƿ�Ϊ0
	if(str2 == "0") 
	{  
        throw "��0��"; 
    }
	//�жϱ������Ƿ�Ϊ0
    if(str1 == "0") 
	{ 
        quotient = "0";
        residue = "0";
    }
    
    //�趨�ý���ķ���λ 
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
		
		//ģ���ֹ�������ʽ
        for(int i = L2 - 1; i < L1; i++) 
		{ 
            tempstr = tempstr + str1[i];
            //ȥ��ǰ��0 
			tempstr.erase(0, tempstr.find_first_not_of('0'));
            if(tempstr.empty())
				tempstr = "0";
            
			for(char ch = '9'; ch >= '0'; ch--) //����
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
    
    //ȥ������е�ǰ��0
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
//�ַ����������� 
string Div(string str1, string str2)
{
    return Devide(str1, str2, 1);
}

//�ַ����������� 
string Mod(string str1, string str2) 
{
    return Devide(str1, str2, 0);
}

//������ת����ʮ�����ַ��� 
string LongToDec(long a) 
{		
	string str;
	char s[Max];
	itoa(a, s, 10);
	str = s;
	return str; 
}

//�˽����ַ���ת����ʮ�����ַ���
string OctToDec(string oct)
{
	int i, j;
	string dec = "0", temp1 = "0", temp2 = "8", temp3 = "+";
	
	//�趨�ý���ķ���λ 
	if(oct[0] == '-')
	{
		oct.erase(0,1);
		temp3 = "-";
	}
	
	//�����λ��ʼ��λ����8�������һλ�ĺͼ�����8���Դ�����ֱ�����λ�� 
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

//ʮ�����ƻ����ַ���Ӧʮ������ֵ 
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

//ʮ�������ַ���ת����ʮ�����ַ���
string HexToDec(string hex)
{
	int i, j;
	string dec = "0", temp1, temp2 = "16", temp3 = "+";
	
	//�趨�ý���ķ���λ 
	if(hex[0] == '-')
	{
		hex.erase(0,1); 
		temp3 = "-";
	}
	
	//�����λ��ʼ��λ����16�������һλ�ĺͼ�����16���Դ�����ֱ�����λ�� 
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
		throw "�Ƿ������ַ���"; 
	}
}

HugeInt::HugeInt(const HugeInt &i)
{
	a = i.a;
}

HugeInt& HugeInt::operator=(const HugeInt &i)
{
	if(this != &i)		//�����Ը�ֵ 
	{
		a = i.a;
	}
	return *this;
}


//�������� + �������� 
HugeInt operator+(HugeInt x, HugeInt y)    		
{
	HugeInt Ans;
	Ans.a = Add(x.a, y.a);
	return Ans;
}

//�������� + �������� 
HugeInt operator+(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Add(x.a, LongToDec(y));
	return Ans;
}

//�������� + �������� 
HugeInt operator+(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Add(LongToDec(y), x.a);
	return Ans;
}

//�������� + �ַ��� 
HugeInt operator+(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Add(x.a, strY);
	return Ans;
}

//�ַ��� + �������� 
HugeInt operator+(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Add(strY, x.a);
	return Ans;
}



//������
HugeInt operator-(HugeInt x)
{
	if(x.a[0] == '-')
		x.a.erase(0, 1);
	else
		x.a = "-" + x.a;
	return x;
}

//�������� - �������� 
HugeInt operator-(HugeInt x, HugeInt y)     	
{
	HugeInt Ans;
	Ans.a = Sub(x.a, y.a);
	return Ans;
}

//�������� - �������� 
HugeInt operator-(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Sub(x.a, LongToDec(y));
	return Ans;
}

//�������� - �������� 
HugeInt operator-(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Sub(LongToDec(y), x.a);
	return Ans;
}

//�������� - �ַ��� 
HugeInt operator-(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Sub(x.a, strY);
	return Ans;
}

//�ַ��� - ��������
HugeInt operator-(string y, HugeInt x)		 
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Sub(strY, x.a);
	return Ans;
}



//�������� * �������� 
HugeInt operator*(HugeInt x, HugeInt y)	    	
{
	HugeInt Ans;
	Ans.a = Mul(x.a, y.a);
	return Ans;
}

//�������� * �������� 
HugeInt operator*(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Mul(x.a, LongToDec(y));
	return Ans;
}

//�������� * �������� 
HugeInt operator*(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Mul(LongToDec(y), x.a);
	return Ans;
}

//�������� * �ַ��� 
HugeInt operator*(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mul(x.a, strY);
	return Ans;
}

//�ַ��� * �������� 
HugeInt operator*(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mul(strY, x.a);
	return Ans;
}



//�������� / �������� 
HugeInt operator/(HugeInt x, HugeInt y)	    	
{
	HugeInt Ans;
	Ans.a = Div(x.a, y.a);
	return Ans;
}

//�������� / �������� 
HugeInt operator/(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Div(x.a, LongToDec(y));
	return Ans;
}

//�������� / �������� 
HugeInt operator/(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Div(LongToDec(y), x.a);
	return Ans;
}

//�������� / �ַ��� 
HugeInt operator/(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Div(x.a, strY);
	return Ans;
}

//�ַ��� / �������� 
HugeInt operator/(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Div(strY, x.a);
	return Ans;
}



//�������� % �������� 
HugeInt operator%(HugeInt x, HugeInt y)     	
{
	HugeInt Ans;
	Ans.a = Mod(x.a, y.a);
	return Ans;
}

//�������� % �������� 
HugeInt operator%(HugeInt x, long y)			
{
	HugeInt Ans;
	Ans.a = Mod(x.a, LongToDec(y));
	return Ans;
}

//�������� % �������� 
HugeInt operator%(long y, HugeInt x)			
{
	HugeInt Ans;
	Ans.a = Mod(LongToDec(y), x.a);
	return Ans;
}

//�������� % �ַ��� 
HugeInt operator%(HugeInt x, string y)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mod(x.a, strY);
	return Ans;
}

//�ַ��� % �������� 
HugeInt operator%(string y, HugeInt x)		
{
	HugeInt Ans;
	string strY = y;
	Ans.a = Mod(strY, x.a);
	return Ans;
}



//�������� < �������� 
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

//�������� < �������� 
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

//�������� < �������� 
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

//�������� < �ַ��� 
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

//�ַ��� < �������� 
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



//�������� > �������� 
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

//�������� > �������� 
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

//�������� > �������� 
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

//�������� > �ַ��� 
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

//�ַ��� > �������� 
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



//�������� == �������� 
bool operator==(HugeInt x, HugeInt y)     	
{
	return (x.a.compare(y.a) == 0);
}

//�������� == �������� 
bool operator==(HugeInt x, long y)			
{
	return (x.a.compare(LongToDec(y)) == 0);
}

//�������� == �������� 
bool operator==(long y, HugeInt x)			
{
	return (LongToDec(y).compare(x.a) == 0);
}

//�������� == �ַ��� 
bool operator==(HugeInt x, string y)	
{
	string strY = y;
	return (x.a.compare(strY) == 0);
}

//�ַ��� == �������� 
bool operator==(string y, HugeInt x)	
{
	string strY = y;
	return (strY.compare(x.a) == 0);
}



//�������� <= �������� 
bool operator<=(HugeInt x, HugeInt y)     	
{
	return (x < y || x == y);
}

//�������� <= �������� 
bool operator<=(HugeInt x, long y)			
{
	return (x < y || x == y);
}

//�������� <= �������� 
bool operator<=(long y, HugeInt x)			
{
	return (y < x || y == x);
}

//�������� <= �ַ��� 
bool operator<=(HugeInt x, string y)	
{
	return (x < y || x == y);
}

//�ַ��� <= �������� 
bool operator<=(string y, HugeInt x)	
{
	return (y < x || y == x);
}



//�������� >= �������� 
bool operator>=(HugeInt x, HugeInt y)     	
{
	return (x > y || x == y);
}

//�������� >= �������� 
bool operator>=(HugeInt x, long y)			
{
	return (x > y || x == y);
}

//�������� >= �������� 
bool operator>=(long y, HugeInt x)			
{
	return (y > x || y == x);
}

//�������� >= �ַ��� 
bool operator>=(HugeInt x, string y)	
{
	return (x > y || x == y);
}

//�ַ��� >= �������� 
bool operator>=(string y, HugeInt x)	
{
	return (y > x || y == x);
}



//�������� != �������� 
bool operator!=(HugeInt x, HugeInt y)     	
{
	return !(x == y);
}

//�������� != �������� 
bool operator!=(HugeInt x, long y)			
{
	return !(x == y);
}

//�������� != �������� 
bool operator!=(long y, HugeInt x)			
{
	return !(y == x);
}

//�������� != �ַ��� 
bool operator!=(HugeInt x, string y)	
{
	return !(x == y);
}

//�ַ��� != ��������
bool operator!=(string y, HugeInt x)	
{
	return !(y == x);
}



//�������� += �������� 
HugeInt& HugeInt::operator+=(const HugeInt &i)			
{
	*this = *this + i;
	return *this;
}

//�������� += �������� 
HugeInt& HugeInt::operator+=(const long &i)				
{
	*this = *this + i;
	return *this;
}

//�������� += �ַ���
HugeInt& HugeInt::operator+=(const string &i)			
{
	*this = *this + i;
	return *this;
}



//�������� -= �������� 
HugeInt& HugeInt::operator-=(const HugeInt &i)			
{
	*this = *this - i;
	return *this;
}

//�������� -= �������� 
HugeInt& HugeInt::operator-=(const long &i)				
{
	*this = *this - i;
	return *this;
}

//�������� -= �ַ���
HugeInt& HugeInt::operator-=(const string &i)			
{
	*this = *this - i;
	return *this;
}



//�������� *= �������� 
HugeInt& HugeInt::operator*=(const HugeInt &i)			
{
	*this = *this * i;
	return *this;
}

//�������� *= �������� 
HugeInt& HugeInt::operator*=(const long &i)				
{
	*this = *this * i;
	return *this;
}

//�������� *= �ַ���
HugeInt& HugeInt::operator*=(const string &i)			
{
	*this = *this * i;
	return *this;
}



//�������� /= �������� 
HugeInt& HugeInt::operator/=(const HugeInt &i)			
{
	*this = *this / i;
	return *this;
}

//�������� /= �������� 
HugeInt& HugeInt::operator/=(const long &i)				
{
	*this = *this / i;
	return *this;
}

//�������� /= �ַ���
HugeInt& HugeInt::operator/=(const string &i)			
{
	*this = *this / i;
	return *this;
}



//�������� %= �������� 
HugeInt& HugeInt::operator%=(const HugeInt &i)			
{
	*this = *this % i;
	return *this;
}

//�������� %= �������� 
HugeInt& HugeInt::operator%=(const long &i)				
{
	*this = *this % i;
	return *this;
}

//�������� %= �ַ���
HugeInt& HugeInt::operator%=(const string &i)			
{
	*this = *this % i;
	return *this;
}



//++�������� 
HugeInt HugeInt::operator++()   			
{
	*this = *this + 1;
	return *this;
}

//�������� ++
HugeInt HugeInt::operator++(int)  			
{
	HugeInt temp = *this;
	*this = *this + 1;
	return temp;
}

//--�������� 
HugeInt HugeInt::operator--()    			
{
	*this = *this - 1;
	return *this;
}

//�������� --
HugeInt HugeInt::operator--(int) 			
{
	HugeInt temp = *this;
	*this = *this - 1;
	return temp;
}



//������������� 
istream &operator>>(istream &in, HugeInt &i)        	
{
	char temp[Max];
	in >> temp;
	if(isDec(temp) || isOct(temp) || isHex(temp))
		i.a = temp;
	else
	{
		i.a = "0";
		throw "�Ƿ������ַ���"; 
	}
	return in;
}

//������������ 
ostream &operator<<(ostream &out, const HugeInt &i) 	
{
	string temp = i.a;
	int j, size = temp.size();
	for(j = 0; j < size; j += 4)
	{
		temp.insert(size - j, ",");
	}
	temp.erase(temp.size() - 1, 1);
	
	//ȥ�����ź�������Ķ��� 
	if(temp[0] == '-' && temp[1] == ',')
		temp.erase(1, 1);
	out << temp;
	return out;
}

		

//��������ת����8�����ַ��� 
string HugeInt::PrintOct()			
{
	int sign = 0; //��¼����λ 
	string oct, temp = a;
	
	//�趨�ý���ķ���λ 
	if(temp[0] == '+')
		temp.erase(0, 1);
	if(temp[0] == '-')
	{
		temp.erase(0, 1);
		sign = 1;
	}
	
	while(temp != "0")
	{
		//���ȡ��������8�����ַ���ǰ�� 
		oct = Mod(temp, "8") + oct;
		
		//ȡ��������һ��8
		temp = Div(temp, "8");
	}
	oct = "0" + oct;
	if(sign) //������
		oct = "-" + oct;
	return oct;
}

//ʮ������ֵ��Ӧʮ�����ƻ����ַ�
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

//��������ת����16�����ַ���  
string HugeInt::PrintHex()			
{
	int sign = 0; //��¼����λ 
	string hex, temp = a;
	
	//�趨�ý���ķ���λ 
	if(temp[0] == '+')
		temp.erase(0, 1);
	if(temp[0] == '-')
	{
		temp.erase(0, 1);
		sign = 1;
	}	
	
	while(temp != "0") 
	{
		//���ȡ��������16�����ַ���ǰ�� 
		hex  = DecToHexIndex(Mod(temp, "16")) + hex;
		
		//ȡ��������һ��16 
		temp = Div(temp, "16");
	}
	hex = "0X" + hex;
	if(sign) //������ 
		hex = "-" + hex;
	return hex;
}

