#include <iostream>
#include "dbase.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	dbase dbase(3);
	dbase.Vvod();
	dbase.Vivod();
	string poisk;
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter product name to search: ";
		cin >> poisk;
		dbase.Poisk(poisk);
	}
	system("pause");
 	return 0;
}