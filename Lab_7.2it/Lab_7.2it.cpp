// Lab_7_2_1.cpp
// Малаховський Назар
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 20
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int Search(int* a, const int n);
void Swap(int** a, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 10;
	int n;

	cout << "n = "; cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, Low, High);

	cout << "Main Matrix:" << endl;
	Print(a, n);

	Swap(a, n);

	cout << "Changed Matrix:" << endl;
	Print(a, n);

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Search(int* a, const int n)
{
	int minIndex = 0;
	int minValue = a[0];

	for (int j = 1; j < n; j++) {
		if (a[j] < minValue) {
			minValue = a[j];
			minIndex = j;
		}
	}

	return minIndex;
}

void Swap(int** a, const int n) 
{
	for (int i = 0; i < n; i++) {
		int minIndex = Search(a[i], n);

		int secIndex = n - 1 - i;

		if (minIndex != secIndex) {
			swap(a[i][minIndex], a[i][secIndex]);
		}
	}
}