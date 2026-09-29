#define MAX 100

struct sinhvien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
};
int TaoTapTin(char* filename, sinhvien a[MAX], int& n);
void TieuDe();
void Xuat_SV(sinhvien p);
void Xuat_DSSV(sinhvien a[MAX], int n);
int Tim_MSSV(char maSV[10], sinhvien a[MAX], int n);
void Tim_Ten(char ten[10], sinhvien a[MAX], int n);
void Tim_Ho(char hoSV[10], sinhvien a[MAX], int n);
void Tim_DTB(double dtb, sinhvien a[MAX], int n);
void Tim_Lop(char lop[6], sinhvien a[MAX], int n);
int KiemTraDayTang(int x[MAX], int n);
int KiemTraDayGiam(int x[MAX], int n);
int TKNP_Tang(int x[MAX], int n, int tichLuy);
int TKNP_Giam(int x[MAX], int n, int tichLuy);
void Xuat_TKNP_Theo_TichLuy(int tichLuy, sinhvien a[MAX], int n, int kq);
void TKNP_Theo_TichLuy(sinhvien a[MAX], int n);


int TaoTapTin(char* filename, sinhvien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].lop;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		in >> a[n].tichLuy;
		n++;
	}
	in.close();
	return 1;
}
void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << " Ho va Ten sinh vien"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(8) << "TichLuy"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}
void Xuat_SV(sinhvien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(10) << p.lop
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.dtb
		<< ':'
		<< setw(8) << p.tichLuy
		<< ':';
}
void Xuat_DSSV(sinhvien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_SV(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

int Tim_MSSV(char maSV[10], sinhvien a[MAX], int n)
{
	int i = 0;
	while ((i < n) && (_stricmp(a[i].maSV, maSV)))
		i++;
	if (i == n)
		return -1;
	return i;
}


void Tim_Ten(char ten[10], sinhvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].ten, ten) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co ten sinh vien : " << ten;
	else
	{
		cout << "\nthong tin sinh vien trong danh sach co ten " << ten;
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].ten, ten) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_Ho(char hoSV[10], sinhvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].hoSV, hoSV) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co sinh vien mang ho : " << hoSV;
	else
	{
		cout << "\nCac sinh vien trong danh sach mang ho " << hoSV << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].hoSV, hoSV) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}
void Tim_DTB(double dtb, sinhvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].dtb >= dtb)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co sinh vien nao co diem trung binh >= " << dtb;
	else
	{
		cout << "\nCac sinh vien trong danh sach co diem trung bin >= " << dtb << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (a[i].dtb >= dtb)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_Lop(char lop[6], sinhvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].lop, lop) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co lop : " << lop;
	else
	{
		cout << "\nCac sinh vien trong danh sach thuoc lop " << lop << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].lop, lop) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

int KiemTraDayTang(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i] > x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

int KiemTraDayGiam(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i] < x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

int TKNP_Tang(int x[MAX], int n, int tichLuy)
{
	int kq = -1, left = 0, right = n - 1;
	double middle;
	do
	{
		middle = (left + right) / 2;
		if (tichLuy == middle)
		{
			kq = middle;
			break;
		}
		else
			if (tichLuy < middle)
				right = middle - 1;
			else
				left = middle + 1;
	} while (left <= right);
	return kq;
}

int TKNP_Giam(int x[MAX], int n, int tichLuy)
{
	int kq = -1, left = 0, right = n - 1;
	double middle;
	do
	{
		middle = (left + right) / 2;
		if (tichLuy == middle)
		{
			kq = middle;
			break;
		}
		else
			if (tichLuy < middle)
				left = middle + 1;
			else
				right = middle - 1;
	} while (left <= right);
	return kq;
}

void Xuat_TKNP_Theo_TichLuy(int tichLuy, sinhvien a[MAX], int n, int kq)
{
	if (kq == -1)
	{
		cout << "\nKhong co sinh vien trong danh sach co so TC tich luy = " << tichLuy << "\n";
		return;
	}
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co so TC tich luy = " << tichLuy << " :\n";
		TieuDe();
		Xuat_SV(a[kq]);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 74; i++)
			cout << '=';
		cout << ':';
		cout << endl;
		return;
	}
}

void TKNP_Theo_TichLuy(sinhvien a[MAX], int n)
{
	int i, kq;
	int x[MAX];
	for (i = 0; i < n; i++)
		x[i] = a[i].tichLuy;
	if (!KiemTraDayGiam(x, n) && !KiemTraDayTang(x, n))
	{
		cout << "\nDay so nguyen tao boi truong tich luy khong don dieu";
		cout << "\nKhong su dung duoc thuat giai tim kiem nhi phan!\n";
		return;
	}
	int tichLuy;
	cout << "\nNhap so tich luy : ";
	cin >> tichLuy;
	if (KiemTraDayTang(x, n))
	{
		kq = TKNP_Tang(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
	if (KiemTraDayGiam(x, n))
	{
		kq = TKNP_Giam(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
}
