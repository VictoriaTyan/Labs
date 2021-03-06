// Поменять местами столбцы матрицы так, чтобы элементы первой строки оказались упорядоченными
//

//#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

//ввод размерности из файла
void InputMatrSizeFile(ifstream &in, int* m, int* n)
{
	if (in.is_open())
	{
		in >> *m;
		in >> *n;
	}
}
int** CreateMatr(int m , int n)
{
	int **mas; //создаём матрицу введённой размерности
	mas = new int *[n]; //через массив указателей //n указателей на массив размера m столбцов
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	return mas;
}

//ввод матрицы из файла
void InputMatrFile(int** mas, ifstream &FileIn, int m, int n)
{
	if (FileIn.is_open())
	{
		cout << "Введенная матрица:\n";
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				FileIn >> mas[j][i];
				cout << mas[j][i] << " ";
			}
			cout << endl;
		}
	}
}
//ввод числа с заданными границами
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
//ввод матрицы с клавиатуры
int** InputMatrKey(int* m, int* n)
{
	*m = InputNum("Введите количество строк", 0, 50);
	*n = InputNum("Введите количество столбцов", 0, 50);
	int **mas; //создаём матрицу введённой размерности
	mas = new int *[*n]; //через массив указателей	
	for (int i = 0; i < *n; i++)
		mas[i] = new int[*m];
	cout << " Заполните массив: ""\n";
	for (int i = 0; i < *m; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> mas[j][i];
		}
	}
	cout << "Введенная матрица:\n";
	for (int i = 0; i < *m; ++i)
	{
		for (int j = 0; j < *n; ++j)
		{
			cout << mas[j][i] << " ";
		}
		cout << endl;
	}
	return mas;
}
//вывод результата в файл
void OutputResFile(int **mas, int m, int n)
{
	ofstream FileOut("output.txt");
	if (FileOut.is_open())
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				FileOut << mas[j][i] << " ";
			FileOut << endl;
		}
		FileOut << endl;
	}

	FileOut.close();
}

void Task(int **mas, int m, int n)
{	
	int* t;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (mas[j][0] > mas[j + 1][0])
			{
				t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
			}
}

//вывод результата в консоль
void OutputResKey(int **mas, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << mas[j][i] << " ";
		cout << endl;
	}
	cout << endl;
	
}
//выбор пункта меню ввода
int SelectInputMenuItem(void)
{
	cout << "1 - Ввод массива из консоли" << endl;
	cout << "2 - Ввод массива из файла" << endl;
	return InputNum("0 - выход", 0, 2);
}
//выбор пункта меню вывода результата
int SelectResultMenuItem(void)
{
	cout << "1 - Вывести результат в консоль" << endl;
	cout << "2 - Вывести результат в файл" << endl;
	return InputNum("0 - выход", 0, 2);
}
//главная программа
int main()
{
	setlocale(LC_ALL, "Russian");//русский язык	
	ifstream FileIn("input.txt");
	int m, n;
	int** arr;
	int MenuItem = -1;
	int SubMenuItem = -1;
	MenuItem = SelectInputMenuItem();
	switch (MenuItem)
	{
	case 1:
		arr = InputMatrKey(&m, &n);
		break;
	case 2:
		InputMatrSizeFile(FileIn, &m, &n);
		arr = CreateMatr(m, n);
		InputMatrFile(arr, FileIn, m, n);
		break;
	default:
		return 0;
	}
	Task(arr, m, n);
	SubMenuItem = SelectResultMenuItem();
	switch (SubMenuItem)
	{
	case 1:
		OutputResKey(arr, m, n);
		system("pause");
		break;
	case 2:
		OutputResFile(arr, m, n);
		system("pause");
		break;
	default:
		return 0;
	}
	FileIn.close();
	return 0;
}


