#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
#include "Thuvien.h"
#include "Menu.h"
void ChayCT();
int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	int soMenu = 7, menu;
	List nv;
	do {
		system("CLS");
		XuatMenu();
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, nv);
		system("PAUSE");
	} while (menu > 0);
}