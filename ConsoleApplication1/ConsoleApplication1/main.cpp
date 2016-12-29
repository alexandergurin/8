
#include "list.h"
#include <cassert> 
int m;
template <class Type> void del(List<Type> a, int x, int y, char *s)
{
	const char *q = "Right";
	int i;
	if (s == q)
	{
		for (i = x; i < x + y; i++)
			a(x);
	}
	else
	{
		if(x - y > 1) x -= 1;
		for (i = x - y; i < x; i++)
			a(x - y);
	}
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 20;
	int val = 0;
	List<int> a;
	a(1, 0);
	a(2, 0);
	a(3, 10);
	a(5, 1);
	a(6, -1);
	a(10, 10);
	cout << "List A: "; 
	a.show();
	cout<<"Введите элемент для удаления"<<endl;
	cin>>m;
	a(m);
	a.show();
	system("pause"); 
}