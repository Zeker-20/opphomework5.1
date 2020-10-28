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
			cout << "ջ�գ�" << endl;
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
			cout << "��ǰջ��û���κ�Ԫ��" << endl;
		else
		{
			while (num != 0)
			{
				cout << "��ջ�׿�ʼ��" << num << "��Ԫ����" << POP() << endl;
				ע��˴�ʹ����POP���Ի��Լ�����num--��

			}
		}
	}*/
	void Display()
	{
		int  index = num;
		cout << "ջ��Ԫ�أ�" << endl;
		for (index;index>0;--index)
		{
			cout << "��ջ�׿�ʼ��" << index << "��Ԫ����" << Data[index-1] << endl;
		}
	}
};
int main()
{
	Stack S;
	S.InitStack();
	cout << "������Ҫ����ջ������" << endl;
	int x, y = 1;
	cin >> x;
	S.PUSH(x);
	int flag=1;
	while (y&&flag<MAXSIZE-1)
	{
		cout << "����1��ʾ����,����0" << endl;
		cin >> y;
		if (y == 0)
			break;
		flag++;
		cout << "������Ҫ����ջ������" << endl;
		cin >> x;
		S.PUSH(x);
	}
	int m;
	m = S.POP();
	cout << "ȡ���ĵ�һ������" << m << endl;
	int n;
	n = S.JudgeFullorVoid();
	if (n == 0)
		cout << "ջΪ��" << endl;
	if (n == 1)
		cout << "ջ��" << endl;
	else
		cout << "ջ�Ȳ���Ҳ����" << endl;
	int z;
	z = S.Size();
	cout << "��ǰջ�Ĵ�СΪ" << z << endl;
	S.Display();
	system("pause");
	return 0;
}