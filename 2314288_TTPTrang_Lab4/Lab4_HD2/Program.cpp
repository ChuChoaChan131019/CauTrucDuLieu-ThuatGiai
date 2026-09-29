#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	LL l;
	BD g;
	if (TapTin_List_LL((char*)"LLSV.txt", l) && TapTin_List_BD((char*)"DiemQT.txt", g))
		XuatBangDiem(l, g);
	else
		cout << "\nLoi mo tap tin";
	_getch();
}