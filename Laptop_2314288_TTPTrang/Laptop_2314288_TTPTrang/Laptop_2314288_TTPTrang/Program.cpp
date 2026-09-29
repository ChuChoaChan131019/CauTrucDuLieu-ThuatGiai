#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int somenu = 10, menu, n = 0;
	SinhVien a[MAX];
	do
	{
		system("CLS");
		menu = ChonMenu(somenu);
		XLMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}