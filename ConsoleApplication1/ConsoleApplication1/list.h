#pragma once
#include <iostream>
#include <cassert> 
using namespace std;
template <class T>
class List
{
private:
	int kol;
	T value;
	List *head;
	List *next;
public:
	class Error
	{
	public:
		int index;
		Error(int i): index(i)
		{}
	};
	class NegativeIndex{}; 
	class NullHead {};
	List()
	{
		head = NULL;
		next = NULL;
		value = NULL;
		kol = 0;
	}
	void operator () (int i)
	{
		try
		{
			if (i > kol) throw Error(i);
			List *ptr1, *ptr2;
			int k = 0;
			if (head == NULL)
				return;
			if ((head)->next == NULL) {
				free(head);
				head = NULL;
				return;
			}
			ptr1 = head;
			ptr2 = (head)->next;
			if (i == 0)
			{
				head = head->next;
				delete ptr1;
			}
			else
			{
				while (k != i)
				{
					ptr1 = ptr2;
					ptr2 = ptr2->next;
					k++;
				}
				ptr1->next = ptr2->next;
				delete ptr2;
			}
		}
		catch (Error e)
		{
			cout << "»сключение. Ёлемента c индексом " << e.index << " не существует" << endl;
		}

	}
	void operator () (T val, int index)
	{
		try
		{
			if (!head) throw NullHead();
			if (index < 0 || index > kol) throw NegativeIndex();
			if (index == 0)
			{
				List *q = new List();
				q->value = val;
				q->next = head;
				head = q;
				kol++;
			}

			if (index > 0)
			{
				List *ptr1, *ptr2;
				ptr1 = head;
				ptr2 = new List();
				for (int i = 1; i < index; i++)
					ptr1 = ptr1->next;
				ptr2->value = val;
				ptr2->next = ptr1->next;
				ptr1->next = ptr2;
				kol++;
			}
		}
		catch (NegativeIndex)
		{
			cout << "»сключение отрицательный индекс . Ёлемент добавлен в конец списка" << endl;
			List * q = head;
			if (q->next == NULL)
			{
				q->next = new List();
				q->next->next = NULL;
				q->next->value = val;
				kol++;
			}
			else
			{
				while (q->next != NULL)
				{
					q = q->next;
				};
				q->next = new List();
				q->next->next = NULL;
				q->next->value = val;
				kol++;
			}
		}
		catch (NullHead)
		{
			cout << "Ёлемент добавлен в начало списка" << endl;
			head = new List();
			head->next = NULL;
			head->value = val;
			kol++;
			return;
		}
	}
	friend bool operator != (List &a, List &b)
	{
		List *temp1 = a.head;
		List *temp2 = b.head;
		while ((temp1) || (temp2))
		{
			if (temp1 == NULL) return false;
			if (temp2 == NULL) return false;
			if (temp1->value == temp2->value)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	void show()
	{
		List *q = this->head;
		while (q)
		{
			cout << q->value << " ";
			q = q->next;
		}
		cout << endl;
	}
	void showData()
	{
		List *q = head;
		while (q)
		{
			T temp = q->value;
			cout << temp.getData() << " ";
			q = q->next;
		}
		cout << endl;
	}
};
class Object
{
private:
	char* data;
public:
	Object()
	{
		data = "";
	}
	Object(char* d)
	{
		data = d;
	}
	void setData(char *d)
	{
		data = d;
	}
	char* getData()
	{
		return data;
	}
	void print()
	{
		cout << data << " ";
	}
};


