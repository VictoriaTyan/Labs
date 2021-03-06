﻿/* Создать класс Circle для представления окружности. Поля данных должны включать
центр окружности в декартовых координатах и радиус. Требуется реализовать операции:
получения и изменения полей, вычисление площади, периметра, сравнение окружностей.*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#define eps 1e-3

using namespace std;

class Circle
{
	private:
		double x,y;  //координаты центра окружности
		double R;    //радиус окружности

	public:
		Circle(double ax = 0, double by = 0, double cr = 0)  //конструктор
		{
			x = ax;
			y = by;
			R = cr;
		}

		double Get_x() const//получаем координату х
		{
			return x;
		}

		double Get_y() const //получаем координату y
		{
			return y;
		}

		double Get_R() const //получаем радиус
		{
			return R;
		}

		void Set_x(double a) //изменяем координату х
		{
			x = a;
		}

		void Set_y(double b) //изменяем координату y
		{
			y = b;
		}

		void Set_R(double b) //изменяем радиус
		{
			R = b;
		}

		double Square() const //площадь
		{
			return M_PI * R * R;
		}

		double Perimeter() const //периметр
		{
			return 2 * M_PI * R;
		}

		void Read() //ввод данных с консоли
		{
			cout << "Введите координаты центра окружности:"<< endl;
			cin >> x >> y;
			cout << "Введите радиус окружности:" << endl;
			cin >> R;
			while (R <= 0)
			{
				cout << "Введите радиус окружности:" << endl;
				cin >> R;
			}
		}

		void Display() const //вывод данных на консоль
		{
			cout << "Координаты центра окружности: " << x << " " << y <<endl;
			cout << "Радиус окружности: " << R << endl;
		}

		//операция >
		bool operator >(Circle &c2)
		{
			if (this->Get_R() - c2.Get_R() > eps)
				return true;
			else return false;
		}

		//операция <
		bool operator <(Circle &c2)
		{
			if (this->Get_R() - c2.Get_R() < -eps)
				return true;
			else return false;
		}

		//операция ==
		bool operator ==(Circle &c2)
		{
			if (this->Get_R() - c2.Get_R() >= -eps || this->Get_R() - c2.Get_R() <= eps)
				return true;
			else return false;
		}
};

int InputNum(const char *txt, int min, int max) //воод числа в определенном диапазоне
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

//сравнение двух окружностей
void Compare() 
{
	double R1,R2;
	Circle c1; 
	cout << "Введите радиус первой окружности: " << endl;
	cin >> R1;
	c1.Set_R(R1);
	cin.get();
	Circle c2(0,0);
	cout << "Введите радиус второй окружности: " << endl;
	cin >> R2;
	c2.Set_R(R2);
	cin.get();
	if (c1 > c2)
		cout << "Окружность с радиусом " << c1.Get_R() << " больше окружности с радиусом " << c2.Get_R() << endl;
	else if (c1 < c2)
		cout << "Окружность с радиусом " << c1.Get_R() << " меньше окружности с радиусом " << c2.Get_R() << endl;
	else
		cout << "Окружность с радиусом " << c1.Get_R() << " и окружность с радиусом " << c2.Get_R() << " равны " << endl;
}

//основное меню
int SelectSubMenuItem(void)
{
	cout << "" << endl;
	cout << "1 - Изменить координаты центра окружности" << endl;
	cout << "2 - Изменить радиус окружности" << endl;
	return InputNum("0 - Вернуться в главное меню", 0, 2);
}

//меню изменения данных
int SelectInputMenuItem(void)
{
	cout << "" << endl;
	cout << "1 - Вывести данные" << endl;
	cout << "2 - Изменить данные" << endl;
	cout << "3 - Площадь окружности" << endl;
	cout << "4 - Периметр окружности" << endl;
	cout << "5 - Сравнить 2 окружности" << endl;
	return InputNum("0 - выход", 0, 5);
}

//Главная программа
int main()
{
	setlocale(LC_ALL, "Russian"); //подключаем кириллицу
	Circle c;
	c.Read();
	int MenuItem = -1;
	int SubMenuItem = -1;

	menu1:
	while (MenuItem != 0)
	{
		MenuItem = SelectInputMenuItem();
		switch (MenuItem)
		{
		case 1:                           //вывод данных
			cout << "" << endl;
			c.Display();
			break;
		case 2:							  //изменение данных
			SubMenuItem = SelectSubMenuItem();
			MenuItem = 0;
			break;
		case 3:							  //вывод площади
			cout << "" << endl;
			cout << c.Square() << endl;
			break;
		case 4:							  //вывод периметра
			cout << "" << endl;
			cout << c.Perimeter() << endl;
			break;
		case 5:							  //сравнение двух окружностей
			cout << "" << endl;
			Compare();
			break;
		case 0:							  //выход
			return 0;
		}
	}

	while (SubMenuItem != -1)
	{
		switch (SubMenuItem)
		{
		case 1:                       //изменение центра окружности
			double a, b;
			cout << "" << endl;
			cout << "Введите координаты центра окружности:" << endl;
			cin >> a >> b;
			c.Set_x(a);
			c.Set_y(b);
			SubMenuItem = SelectSubMenuItem();
			break;
		case 2:                       //изменение радиуса окружности
			double r;
			cout << "" << endl;
			cout << "Введите радиус окружности:" << endl;
			cin >> r;
			c.Set_R(r);
			SubMenuItem = SelectSubMenuItem();
			break;
		case 0:						  //возврат в основное меню
			MenuItem = -1;
			SubMenuItem = -1;
			goto menu1;
			break;
		}
	}

}

