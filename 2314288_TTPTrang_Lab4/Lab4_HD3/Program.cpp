#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
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
	LIST danhSach;

	int soMenu = 6,
		menu;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, danhSach);
		system("PAUSE");
	} while (menu > 0);

}