// Тян Виктория задача 5b
// 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct Point							//точка
{
	double x, y;
	Point(double ax = 0, double ay = 0)
	{
		x = ax;
		y = ay;
	}
};

ostream& operator <<(ostream &os, Point &p) //вывод точки
{
	os << "(" << p.x << ";" << p.y << ")";
	return os;
}

istream& operator >>(istream &in, Point &p) //ввод точки
{
	in >> p.x >> p.y;
	return in;
}

template <typename T>
struct node                                 //звено списка
{
	T val;
	node *next, *prev;
	node(T el)
	{
		val = el;
		next = prev = NULL;
	}

};

template <typename T>
class Deque									
{
	private:

		node<T> *Head, *Tail;
		int Count;
		
	public:

		Deque()
		{
			Head = Tail = NULL;
			Count = 0;
		}

		~Deque()
		{
			while (Count != 0)
				PopHead();
		}

		T PopHead()
		{
			if (Head != NULL)
			{
				node<T> *temp = Head;
				T el = temp->val;
				Count--;
				if (Count == 0)
					Head = Tail = NULL;
				else
				{
					Head = Head->next;
					Head->prev = NULL;
				}
				delete temp;
				return el;
			}
			else throw out_of_range("Список пуст!");
		}

		T PopTail()
		{
			if (Tail != NULL)
			{
				node<T> *temp = Tail;
				T el = temp->val;
				Count--;
				if (Count == 0)
					Head = Tail = NULL;
				else
				{
					Tail = Tail->prev;
					Tail->next = NULL;
				}
				delete temp;
				return el;
			}
			else throw out_of_range("Список пуст!");
		}

		T GetHead()
		{
			if (Head != NULL)
			{
				return Head->val;
			}
			else throw out_of_range("Список пуст!");
		}

		T GetTail()
		{
			if (Tail != NULL)
			{
				return Tail->val;
			}
			else throw out_of_range("Список пуст!");
		}

		void PushHead(T el)
		{
			node<T> * temp = new node<T>(el);
			temp->next = Head;
			if (Head != NULL)
				Head->prev = temp;
			if (Count == 0)
				Head = Tail = temp;
			else
				Head = temp;
			Count++;
		}

		void PushTail(T el)
		{
			node<T> * temp = new node<T>(el);			
			temp->prev = Tail;
			if (Tail != NULL)
				Tail->next = temp;
			if (Count == 0)
				Head = Tail = temp;
			else
				Tail = temp;
			Count++;
		}

		int GetCount() const
		{
			return Count;
		}

		void Print() const
		{
			if (Head == NULL)
				cout << "Список пуст!" << endl;
			else
			{
				node<T> *temp = Head;
				while (temp != NULL)
				{
					cout << temp->val << " ";
					temp = temp->next;
				}
			}
		}
};

//воод числа в определенном диапазоне
int InputNum(const char *txt, int min, int max) 
{
	int num;
	cout << txt << endl; //вывод вопроса на экран
	cin >> num;
	while ((num < min) || (num > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> num;
	}
	return num;
}

//меню выбора типа данных
int SelectTypeMenuItem(void)
{
	cout << "1 - целый" << endl;
	cout << "2 - строковый" << endl;
	cout << "3 - точка" << endl;
	return InputNum("", 0, 3);
}

//меню методов
int SelectInputMenuItem(void)
{
	cout << "" << endl;
	cout << "1 - Вывести длину дека" << endl;
	cout << "2 - Добавление нового элемента в начало" << endl;
	cout << "3 - Добавление нового элемента в конец" << endl;
	cout << "4 - Удаление элемента с начала" << endl;
	cout << "5 - Удаление элемента с конца" << endl;
	cout << "6 - Получение элемента с начала" << endl;
	cout << "7 - Получение элемента с конца" << endl;
	cout << "8 - Печать" << endl;
	return InputNum("0 - выход", 0, 8);
}

int main()
{
	//setlocale(LC_ALL, "Russian"); //подключаем кириллицу
	cout << "Выберите тип данных:" << endl;
	int TypeMenuItem = SelectTypeMenuItem(); //запоминаем тип
	Deque<int> i; int n;
	Deque<string> s; string st;
	Deque<Point> p; Point pt;
	int MenuItem = -1;

	while (MenuItem != 0)
	{
		try
		{
			MenuItem = SelectInputMenuItem();
			switch (MenuItem)
			{
			case 1:                           //вывод длины дека
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1: cout << i.GetCount() << endl; break;
				case 2: cout << s.GetCount() << endl; break;
				case 3: cout << p.GetCount() << endl; break;
				}
				break;
			case 2:							  //добавление звена в начало
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1: cout << "Введите элемент" << endl;
					cin >> n;
					i.PushHead(n);
					break;
				case 2: cout << "Введите элемент" << endl;
					cin >> st;
					s.PushHead(st);
					break;
				case 3: cout << "Введите элемент" << endl;
					cin >> pt;
					p.PushHead(pt);
					break;
				}
				break;						 //добавление звена в конец
			case 3:
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1: cout << "Введите элемент" << endl;
					cin >> n;
					i.PushTail(n);
					break;
				case 2: cout << "Введите элемент" << endl;
					cin >> st;
					s.PushTail(st);
					break;
				case 3: cout << "Введите элемент" << endl;
					cin >> pt;
					p.PushTail(pt);
					break;
				}
				break;
			case 4:							//удаление звена с начала					  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	i.PopHead(); break;
				case 2: s.PopHead(); break;
				case 3: p.PopHead(); break;
				}
				break;
			case 5:							//удаление звена с конца		  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	i.PopTail(); break;
				case 2: s.PopTail(); break;
				case 3: p.PopTail(); break;
				}
				break;
			case 6:							//получение звена с начала		  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	cout << i.GetHead() << endl; break;
				case 2: cout << s.GetHead() << endl; break;
				case 3: cout << p.GetHead() << endl; break;
				}
				break;
			case 7:							//получение звена с конца		  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	cout << i.GetTail() << endl; break;
				case 2: cout << s.GetTail() << endl; break;
				case 3: cout << p.GetTail() << endl; break;
				}
				break;
			case 8:
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	i.Print(); break;
				case 2: s.Print(); break;
				case 3: p.Print(); break;
				}
				break;
			case 0:
				return 0;
			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}

}



