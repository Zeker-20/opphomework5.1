#include <iostream>
using namespace std;
#define MAXSIZE 8
class Stack
{
	//private:
public:
	int *top;
	int Data[MAXSIZE];
	int num;
	void InitStack()
	{
		top = &Data[0];
		num = 0;
	}
	void PUSH(int x)
	{
		*(top) = x;
		top++;
		num++;
	}
	int  POP()
	{
		if (num==0)
		{
			cout << "栈空！" << endl;
			return -10086;
		}
		top--;
		num--; 
		return *(top);
	}
	int Size()
	{
		return num;
	}
	int JudgeFullorVoid()
	{
		if (num == 0)
			return 0;
		if (num == MAXSIZE-1)
			return 1;
		return -1;
	}
	/*void CoutAll()
	{
		if (num == 0)
			cout << "当前栈中没有任何元素" << endl;
		else
		{
			while (num != 0)
			{
				cout << "从栈底开始第" << num << "个元素是" << POP() << endl;
				注意此处使用了POP所以会自己带有num--；

			}
		}
	}*/
	void Display()
	{
		int  index = num;
		cout << "栈中元素：" << endl;
		for (index;index>0;--index)
		{
			cout << "从栈底开始第" << index << "个元素是" << Data[index-1] << endl;
		}
	}
};
int main()
{
	Stack S;
	S.InitStack();
	cout << "输入想要送入栈的数据" << endl;
	int x, y = 1;
	cin >> x;
	S.PUSH(x);
	int flag=1;
	while (y&&flag<MAXSIZE-1)
	{
		cout << "输入1表示继续,否则0" << endl;
		cin >> y;
		if (y == 0)
			break;
		flag++;
		cout << "输入想要送入栈的数据" << endl;
		cin >> x;
		S.PUSH(x);
	}
	int m;
	m = S.POP();
	cout << "取出的第一个数是" << m << endl;
	int n;
	n = S.JudgeFullorVoid();
	if (n == 0)
		cout << "栈为空" << endl;
	if (n == 1)
		cout << "栈满" << endl;
	else
		cout << "栈既不空也不满" << endl;
	int z;
	z = S.Size();
	cout << "当前栈的大小为" << z << endl;
	S.Display();
	system("pause");
	return 0;
}