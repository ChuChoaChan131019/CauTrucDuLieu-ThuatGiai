#define MAX 100

struct SinhVien
{
	char maSV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	double dtb;
};
//kb nguyen mau
int TaoDL(char* filename, SinhVien a[MAX], int& n);
void XuatTieuDe();
void Xuat1SV(SinhVien a);
void XuatDSSV(SinhVien a[MAX], int& n);
void TKTT_TrungHoTen_TheoNam(SinhVien a[MAX], int& n, char ho[10], char ten[10], int nam);
int TKTT_LC_TheoTen(SinhVien a[MAX], int n, char ten[10]);
void HoanVi(SinhVien& a, SinhVien& b);
void ChonTT_TangNam(SinhVien a[MAX], int& n);
void PhanHoach(SinhVien a[MAX], int l, int r);
void QuickSort_GiamDTB(SinhVien a[MAX], int n);
int KTTang_NamSinh(SinhVien a[MAX], int n);
int KTGiam_NamSinh(SinhVien a[MAX], int n); 
int TKNP_TangNamSinh(SinhVien a[MAX], int n, int namSinh);
int TKNP_GiamNamSinh(SinhVien a[MAX], int n, int namSinh);
void TKNP_Theo_NamSinh(SinhVien a[MAX], int n);
void Xuat_NamSinh_Cuoi_Cung(int namSinh, int kq);
int KTTang_DTB(SinhVien a[MAX], int n);
int KTGiam_DTB(SinhVien a[MAX], int n);
int TKNP_TangDTB(SinhVien a[MAX], int n, double dtb);
int TKNP_GiamDTB(SinhVien a[MAX], int n, double dtb);
void Xuat_DTB_Cuoi_Cung(double dtb, int kq);
void TKNP_Theo_DTB(SinhVien a[MAX], int n);







int TaoDL(char* filename, SinhVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].ho;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		n++;
	}
	in.close();
	return 1;
}
void XuatTieuDe()
{
	cout << endl << "|";
	for (int i = 1; i <= 80; i++)
		cout << "=";
	cout << "|\n";
	cout << setiosflags(ios::left);
	cout << "|";
	cout << setw(13) << "Ma SV"
		<< "|"
		<< setw(13) << "Ho"
		<< setw(13) << "Ten lot"
		<< setw(14) << "Ten"
		<< "|"
		<< setw(12) << "Nam sinh"
		<< "|"
		<< setw(12) << "Diem TB"
		<< "|";
	cout << endl << "|";
	for (int i = 1; i <= 80; i++)
		cout << "=";
	cout << "|\n";

}

void Xuat1SV(SinhVien a)
{
	cout << "|";
	cout << setiosflags(ios::left)
		<< setw(13) << a.maSV
		<< "|"
		<< setw(13) << a.ho
		<< setw(13) << a.tenLot
		<< setw(14) << a.ten
		<< "|"
		<< setw(12) << a.namSinh
		<< "|"
		<< setw(12) << a.dtb
		<< "|";
}
void XuatDSSV(SinhVien a[MAX], int& n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1SV(a[i]);
		cout << endl;
	}
	cout << "|";
	for (int i = 1; i <= 80; i++)
		cout << "=";
	cout << "|\n";
}
void TKTT_TrungHoTen_TheoNam(SinhVien a[MAX], int& n, char ho[10], char ten[10], int nam)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].namSinh < nam)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ho '" << ho << "' , ten '" << ten << "'"
		<< "\n va nam sinh < " << nam ;
	else
	{
		cout << "\nDanh sach nhung nhan vien co ho '" << ho << "' va ten '" << ten << "'"
			<< "\n va nam sinh < " << nam << " trong danh sach";
		cout << endl;
		XuatTieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].namSinh < nam)
			{
				Xuat1SV(a[i]);
				cout << endl;
			}
		cout << ':';
		for (int i = 1; i <= 54; i++)
			cout << '=';
		cout << ':';
	}
}

int TKTT_LC_TheoTen(SinhVien a[MAX], int n, char ten[10])
{
	int i = 0;
	strcpy_s(a[n].ten, ten);
	while (_strcmpi(a[i].ten, ten) != 0)
		i++;
	if (i == n)
		return -1;
	return i;
}
void HoanVi(SinhVien& a,SinhVien& b)
{
	SinhVien tam;
	tam = a;
	a = b;
	b = tam;
}
void ChonTT_TangNam(SinhVien a[MAX], int& n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[min].namSinh > a[j].namSinh)
				min = j;
		HoanVi(a[min], a[i]);
	}
		
}
void PhanHoach(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien sv;
	sv = a[(l + r) / 2];
	i = l;
	j = r;
	do
	{
		while (a[i].dtb >sv.dtb)
			i++;
		while (a[j].dtb < sv.dtb)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (l < j)
		PhanHoach(a, l, j);
	if (i < r)
		PhanHoach(a, i, r);
}

void QuickSort_GiamDTB(SinhVien a[MAX], int n)
{
	PhanHoach(a, 0, n - 1);
}
//TKNP namsinh
int KTTang_NamSinh(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].namSinh > a[i + 1].namSinh)
			return 0; 
	return 1; 
}

int KTGiam_NamSinh(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].namSinh < a[i + 1].namSinh)
			return 0; 
	return 1;
}

int TKNP_TangNamSinh(SinhVien a[MAX], int n, int namSinh)
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid].namSinh == namSinh)
		{
			kq = mid;
			left = mid + 1;
		}
		else if (a[mid].namSinh < namSinh)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}

int TKNP_GiamNamSinh(SinhVien a[MAX], int n, int namSinh)
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid].namSinh == namSinh)
		{
			kq = mid;
			right = mid - 1; 
		}
		else if (a[mid].namSinh > namSinh)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}
void Xuat_NamSinh_Cuoi_Cung(int namSinh, int kq) {
	if (kq == -1)
		cout << "\nKhong co sinh vien nao trong danh sach co nam sinh = " << namSinh << ".\n";
	else
		cout << "\nVi tri cuoi cung cua sinh vien co năm sinh = " << namSinh << " la: " << kq << ".\n";
}
void TKNP_Theo_NamSinh(SinhVien a[MAX], int n)
{
	if (!KTTang_NamSinh(a, n) && !KTGiam_NamSinh(a, n))
	{
		cout << "\nDanh sach sinh vien khong duoc sap theo nam sinh,khong dung duoc thuat toan tim kiem nhi phan\n";
		return;
	}

	int namSinh;
	cout << "\nNhap nam sinh can tim: ";
	cin >> namSinh;
	int kq;

	if (KTTang_NamSinh(a, n)) {
		kq = TKNP_TangNamSinh(a, n, namSinh);
		Xuat_NamSinh_Cuoi_Cung(namSinh, kq);
	}

	if (KTGiam_NamSinh(a, n)) {
		kq = TKNP_GiamNamSinh(a, n, namSinh);
		Xuat_NamSinh_Cuoi_Cung(namSinh, kq);
	}
}
//TKNP dtb
int KTTang_DTB(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].dtb > a[i + 1].dtb)
			return 0;
	return 1;
}

int KTGiam_DTB(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].dtb< a[i + 1].dtb)
			return 0;
	return 1;
}

int TKNP_TangDTB(SinhVien a[MAX], int n, double dtb)
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid].dtb == dtb)
		{
			kq = mid;
			left = mid + 1;
		}
		else if (a[mid].dtb < dtb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}

int TKNP_GiamDTB(SinhVien a[MAX], int n, double dtb)
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid].dtb == dtb)
		{
			kq = mid;
			right = mid - 1;
		}
		else if (a[mid].dtb > dtb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}
void Xuat_DTB_Cuoi_Cung(double dtb, int kq) {
	if (kq == -1)
		cout << "\nKhong co sinh vien nao trong danh sach co nam sinh = " << dtb << ".\n";
	else
		cout << "\nVi tri cuoi cung cua sinh vien co năm sinh = " << dtb << " la: " << kq << ".\n";
}
void TKNP_Theo_DTB(SinhVien a[MAX], int n)
{
	if (!KTTang_DTB(a, n) && !KTGiam_DTB(a, n))
	{
		cout << "\nDanh sach sinh vien khong duoc sap theo DTB,khong dung duoc thuat toan tim kiem nhi phan\n";
		return;
	}

	double dtb;
	cout << "\nNhap DTB can tim: ";
	cin >> dtb;
	int kq;

	if (KTTang_DTB	(a, n)) {
		kq = TKNP_TangNamSinh(a, n, dtb);
		Xuat_DTB_Cuoi_Cung(dtb, kq);
	}

	if (KTGiam_NamSinh(a, n)) {
		kq = TKNP_GiamNamSinh(a, n, dtb);
		Xuat_DTB_Cuoi_Cung(dtb, kq);
	}
}



