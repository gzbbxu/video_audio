#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

//��������
/*
template <typename T>
class Func
{
public:
	//���ء�()��
	void operator()(T &t){
		cout << t << endl;
	}
};

void main()
{
	
	int i = 9;
	//��ͨд��
	//Func<int> func;
	//func(i); //funcʵ����һ���������ƣ���������д������������

	//����������������
	Func<int>(a);

	system("pause");
}
*/

//��������ĺô�
//����û��״̬���������״̬�����Լ�¼����ִ�е�״̬
/*
template <typename T>
class MyPrint
{
public:
	void operator()(T &t)
	{
		cout << t << endl;		
	}
};

void main()
{	
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(20);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(40);

	//����v1����
	//��������
	//for_each����ִ�й����У��Զ��������е�Ԫ�ش���MyPrint��operator()������
	for_each(v1.begin(), v1.end(), MyPrint<int>());
	system("pause");
}
*/

//ν�ʣ����ݲ����������ɷ�Ϊ��һԪν�ʡ���Ԫν�ʣ�
//���󣺲��Ҽ������ܹ���5�����ĵ�һ��Ԫ��
//����STL�㷨���������ض�������
/*
template <typename T>
class MyDivision
{
public:
	bool operator()(T &t)
	{
		return (t % 5 == 0);
	}
};

void main()
{
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(20);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(40);

	vector<int>::iterator it = find_if(v1.begin(), v1.end(), MyDivision<int>());
	cout << "��һ���ܱ�5������Ԫ�أ�"<< *it << endl;

	system("pause");
}
*/

/*
//��Ԫν��
//��������Vector��v1, v2 ������v1��v2������Ԫ����ӣ�Ȼ������װ��һ���µ�����v3��
template <typename T>
class MyAdd
{
public:
	T operator()(T &t1, T &t2)
	{
		return t1 + t2;
	}
};

template <typename T>
class MyPrint
{
public:
	MyPrint()
	{
		this->num = 0;
	}
	void operator()(T &t)
	{
		cout << t << endl;
		//ͳ��
		if (t > 50)
		{
			num++;
		}
	}

public:
	int num;
};


void main()
{
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(20);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(40);

	vector<int> v2;
	v2.push_back(17);
	v2.push_back(24);
	v2.push_back(12);
	v2.push_back(67);
	v2.push_back(28);

	//v3����ռ��v2�Ĵ�Сһ��
	vector<int> v3(v2.size());	
	
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), MyAdd<int>());

	//����v3
	//ͳ��v3�д���50�����ֵĸ���
	//MyPrint<int> pobj;
	//pobj = for_each(v3.begin(), v3.end(), pobj);

	//for_each�ķ���ֵ���㴫�������
	MyPrint<int> pobj = for_each(v3.begin(), v3.end(), MyPrint<int>());

	cout << "����50�����ָ�����" << pobj.num << endl;

	system("pause");
}
*/

//ʹ�ö�Ԫν�ʽ�������Set
//�����ַ������������Դ�Сд����һ���ַ���
/*
#include <set>
struct CompareNoCase
{
	bool operator()(const string &str1, const string &str2)
	{
		//ȫ�����Сд֮�������Ƚ�
		string str_1;
		str_1.resize(str1.size()); //ת��֮��ĳ��Ȳ���
		transform(str1.begin(), str1.end(), str_1.begin(), tolower); //Ԥ���庯������

		string str_2;
		str_2.resize(str2.size()); //ת��֮��ĳ��Ȳ���
		transform(str2.begin(), str2.end(), str_2.begin(), tolower); //Ԥ���庯������		

		cout << "------" << endl;
		return (str_1 == str_2);
	}
};

void main()
{
	set<string, CompareNoCase> s1;
	s1.insert("jason");
	s1.insert("Jack");
	s1.insert("rose");
	s1.insert("evan");

	set<string, CompareNoCase>::iterator it = s1.find("Rose");
	if (it != s1.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	system("pause");
}
*/

//Ԥ������
//plus<int> greater<int> equal_to<string>
/*
void main()
{
	//plus<int> myPlus;
	//������Ҫ��;
	//int x = 9;
	//int y = 10;
	//myPlus(x,y);

	//plus<string> myPlus;
	//string str1 = "alan ";
	//string str2 = "jackson";
	//str1 = myPlus(str1, str2);

	//transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());

	//ͳ��һ���ַ��������г��֡�rose���Ĵ���
	vector<string> v1;
	v1.push_back("jack");
	v1.push_back("rose");
	v1.push_back("jason");
	v1.push_back("rose");
	v1.push_back("alan");

	string key = "rose";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), key));

	cout << "���ֵĴ�����" << num << endl;

	system("pause");
}
*/

//����������
//bind2nd(equal_to<string>(), key)
//��Ԥ���庯������͵ڶ����������а�
//���󣺲���һ��������Ԫ�ش���20�ĸ���
//�Ƚ���
template <typename T>
class IsGreat
{
public:
	IsGreat(T num)
	{
		this->num = num;
	}
	bool operator()(T &n)
	{
		return (n > this->num);		
	}

private:
	T num;
};

void main()
{
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(20);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(40);

	//v1�����е�Ԫ�ػ��10������Խ��бȽ�
	//int num = count_if(v1.begin(), v1.end(), IsGreat<int>(10));
	//ǰ���Ԫν�ʵ���������������transform�㷨�����Զ������
	//IsGreat������д�ģ����ǿ��Ը����캯�����Σ���Ԥ����ĺ�������
	//����ͨ�������󶨽��
	//Collections.sort Java api  �㷨����
	//bind to second
	int num = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 10));

	cout << "����20��Ԫ�صĸ���:" << num << endl;

	system("pause");
}