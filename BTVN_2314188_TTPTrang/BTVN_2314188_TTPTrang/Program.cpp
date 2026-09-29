#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
#include"Thuvien.h"
#include"Menu.h"
void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int somenu = 7, menu;
	List nv;
	do
	{
		system("CLS");
		XuatMenu();
		menu = ChonMenu(somenu);
		XuLyMenu(menu, nv);
		system("PAUSE");
	} while (menu > 0);
}