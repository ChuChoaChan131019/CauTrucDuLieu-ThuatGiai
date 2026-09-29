#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "thuvien.h"

void ChayChuongTrinh();
int main()
{
	ChayChuongTrinh();
	return 1;
}
void ChayChuongTrinh()
{
	int a[MAX], n;
	int l, r;
	int min = 0, max = 0;
	cout << "\nn=";
	cin >> n;
	NhapDay(a, n);
	cout << "\nl="; cin >> l;
	cout << "\nr="; cin >> r;
	MinMax(a, l, r, min, max);
	cout << "\nDay da cho la:";
	XuatDay(a, n);
	cout << "\nMin a["<<l<<",...,"<<r<<"]="<<min; 
	cout << "\nMax a[" << l << ",...," << r << "]=" << max;
	system("PAUSE");
}

