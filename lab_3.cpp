/*Реализовать шаблон класса дек (Deque<X>), хранящий элементы произвольного типа.
Класс должен в обязательном порядке содержать методы:
-Вычисление длины дека;
-Добавление нового элемента в конец;
-Добавление нового элемента в начало;
-Удаление элемента с начала;
-Удаление элемента с конца;
-Получение элемента с начала;
-Получение элемента с конца;
-Печать.
Реализация дека с помощью списка.*/ 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//точка
struct Point							
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

//звено списка
template <typename T>
struct node                                
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
		//конструктор
		Deque()
		{
			Head = Tail = NULL;
			Count = 0;
		}
		//деструктор
		~Deque()
		{
			while (Count != 0)
				PopHead();
		}
		//Взятие элемента из головы дэка (с его удалением в дэке)
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
		//Взятие элемента с конца дэка (с его удалением в дэке)
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
		//Получение элемента из головы дэка (без его удаления в дэке)
		T GetHead()
		{
			if (Head != NULL)
			{
				return Head->val;
			}
			else throw out_of_range("Список пуст!");
		}
		//Получение элемента с конца дэка (без его удаления в дэке)
		T GetTail()
		{
			if (Tail != NULL)
			{
				return Tail->val;
			}
			else throw out_of_range("Список пуст!");
		}
		//Добавления элемента в начало дэка
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
		//Добавления элемента в конец дэка
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
		//Получение количества элементов в дэке
		int GetCount() const
		{
			return Count;
		}
		//Печать дэка
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

//главная программа
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
			//вывод длины дека
			case 1:                          
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1: cout << i.GetCount() << endl; break;
				case 2: cout << s.GetCount() << endl; break;
				case 3: cout << p.GetCount() << endl; break;
				}
				break;
			//добавление звена в начало
			case 2:							
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
				break;	
			//добавление звена в конец
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
			//удаление звена в начало
			case 4:												  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	i.PopHead(); break;
				case 2: s.PopHead(); break;
				case 3: p.PopHead(); break;
				}
				break;
			//удаление звена с конца
			case 5:									  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	i.PopTail(); break;
				case 2: s.PopTail(); break;
				case 3: p.PopTail(); break;
				}
				break;
			//получение звена с начала	
			case 6:								  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	cout << i.GetHead() << endl; break;
				case 2: cout << s.GetHead() << endl; break;
				case 3: cout << p.GetHead() << endl; break;
				}
				break;
			//получение звена с конца
			case 7:									  
				cout << "" << endl;
				switch (TypeMenuItem)
				{
				case 1:	cout << i.GetTail() << endl; break;
				case 2: cout << s.GetTail() << endl; break;
				case 3: cout << p.GetTail() << endl; break;
				}
				break;
			//Вывод дэка
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



