#include <iostream>
#include <fstream>
using namespace std;
#include "thuvien.h"
#include "menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int soMenu = 6, menu;
	int a[MAX], n = 0;
	do 
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMemu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}

