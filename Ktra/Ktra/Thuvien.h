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

int Tap_Tin(char* filename, SinhVien a[MAX], int& n);
void TieuDe();
void Xuat1SV(SinhVien q);
void XuatDSSV(SinhVien a[MAX], int n);
void Tim_Ho_Ten_NamSinh(SinhVien a[MAX], int n, char ho[10], char ten[10], int namSinh);
int Tim_Ten_LinhCanh(SinhVien a[MAX], int n, char ten[10]);
void Copy(SinhVien b[MAX], SinhVien a[MAX], int n);
void SelectionSort(SinhVien a[MAX], int n);
void InsertionSort(SinhVien a[MAX], int n);
void Partition(SinhVien a[MAX], int l, int r);
void QuickSort(SinhVien a[MAX], int n);
int KiemTraDayTang_NamSinh(SinhVien a[MAX], int n);
int KiemTraDayGiam_NamSinh(SinhVien a[MAX], int n);
void TKNP_Theo_NamSinh(SinhVien a[MAX], int n);
int TKNP_Tang_NamSinh(SinhVien a[MAX], int n, int namSinh);
int TKNP_Giam_NamSinh(SinhVien a[MAX], int n, int namSinh);
void Xuat_TKNP_Theo_NamSinh(int namSinh, SinhVien a[MAX], int n, int kq);
int KiemTraDayTang_DTB(SinhVien a[MAX], int n);
int KiemTraDayGiam_DTB(SinhVien a[MAX], int n);
void TKNP_Theo_DTB(SinhVien a[MAX], int n);
int TKNP_Tang_DTB(SinhVien a[MAX], int n, double dtb);
int TKNP_Giam_DTB(SinhVien a[MAX], int n, double dtb);
void Xuat_TKNP_Theo_DTB(double dtb, SinhVien a[MAX], int n, int kq);

int Tap_Tin(char* filename, SinhVien a[MAX], int& n)
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

void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
	cout << "\n";

	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << "Ho va Ten sinh vien"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':';

	cout << "\n";
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat1SV(SinhVien q)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << q.maSV
		<< ':'
		<< setw(10) << q.ho
		<< setw(10) << q.tenLot
		<< setw(10) << q.ten
		<< ':'
		<< setw(6) << q.namSinh
		<< ':'
		<< setw(6) << q.dtb
		<< ':';
}

void XuatDSSV(SinhVien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat1SV(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Tim_Ho_Ten_NamSinh(SinhVien a[MAX], int n, char ho[10], char ten[10], int namSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].namSinh < namSinh)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay nhan vien co ho '" << ho << "' va ten '" << ten << "'"
		<< "\n va nam sinh < " << namSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung nhan vien co ho '" << ho << "' va ten '" << ten << "'"
			<< "\n va nam sinh < " << namSinh << " trong danh sach";
		cout << endl;
		TieuDe();
		for (int i = 0; i < n; i++)
			if (_strcmpi(a[i].ho, ho) == 0 && _strcmpi(a[i].ten, ten) == 0 && a[i].namSinh < namSinh)
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

int Tim_Ten_LinhCanh(SinhVien a[MAX], int n, char ten[10])
{
	int i = 0;
	strcpy_s(a[n].ten, ten); //linh canh
	while (_strcmpi(a[i].ten, ten) != 0)
		i++;
	if (i == n)
		return -1;
	return i; 
}

void Copy(SinhVien b[MAX], SinhVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void SelectionSort(SinhVien a[MAX], int n)
{
	int cs_min, i, j;
	for (i = 0; i < n; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (a[cs_min].namSinh > a[j].namSinh)
				cs_min = j;
		swap(a[cs_min], a[i]);
	}
}

void SelectionSort1(SinhVien a[MAX], int n)
{
	int cs_min, i, j;
	for (i = 0; i < n; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (a[cs_min].dtb > a[j].dtb)
				cs_min = j;
		swap(a[cs_min], a[i]);
	}
}

void InsertionSort(SinhVien a[MAX], int n)
{
	SinhVien x;
	int pos;
	for (int i = n - 2; i >= 0; i--)  
	{
		x = a[i]; 
		for (pos = i + 1; (pos < n) && (_strcmpi(a[pos].ho, x.ho) < 0 ||
			(_strcmpi(a[pos].ho, x.ho) == 0 && _strcmpi(a[pos].ten, x.ten) < 0)); pos++)
			a[pos - 1] = a[pos];  
		a[pos - 1] = x;  
	}
}

void Partition(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	x = a[(l + r) / 2]; 
	i = l;
	j = r;
	do 
	{
		while (a[i].dtb > x.dtb) 
			i++; 
		while (a[j].dtb < x.dtb) 
			j--;  
		if (i <= j) 
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (l < j) 
		Partition(a, l, j); 
	if (i < r) 
		Partition(a, i, r);  
}

void QuickSort(SinhVien a[MAX], int n)
{
	Partition(a, 0, n - 1); 
}

int KiemTraDayTang_NamSinh(SinhVien a[MAX], int n) 
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].namSinh > a[i + 1].namSinh)
			return 0; // Không t?ng
	return 1; // T?ng
}

int KiemTraDayGiam_NamSinh(SinhVien a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++) 
		if (a[i].namSinh < a[i + 1].namSinh) 
			return 0; // Không gi?m
	return 1; // Gi?m
}

void TKNP_Theo_NamSinh(SinhVien a[MAX], int n) 
{
	if (!KiemTraDayTang_NamSinh(a, n) && !KiemTraDayGiam_NamSinh(a, n)) 
	{
		cout << "\nDanh sach sinh vien khong duoc sap xep don dieu theo nam sinh";
		cout << "\nKhong su dung duoc thuat toan tim kiem nhi phan\n";
		return;
	}

	int namSinh;
	cout << "\nNhap nam sinh can tim: ";
	cin >> namSinh;
	int kq;

	if (KiemTraDayTang_NamSinh(a, n)) 
	{
		kq = TKNP_Tang_NamSinh(a, n, namSinh);
		Xuat_TKNP_Theo_NamSinh(namSinh, a, n, kq);
	}

	if (KiemTraDayGiam_NamSinh(a, n)) 
	{
		kq = TKNP_Giam_NamSinh(a, n, namSinh);
		Xuat_TKNP_Theo_NamSinh(namSinh, a, n, kq);
	}
}

int TKNP_Tang_NamSinh(SinhVien a[MAX], int n, int namSinh) 
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (a[mid].namSinh == namSinh) 
		{
			kq = mid;
			left = mid + 1; // Tìm ti?p bên ph?i ?? tìm v? trí cu?i cùng
		}
		else if (a[mid].namSinh < namSinh)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return kq;
}

int TKNP_Giam_NamSinh(SinhVien a[MAX], int n, int namSinh) 
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid].namSinh == namSinh) 
		{
			kq = mid;
			right = mid - 1; // Tìm ti?p bên trái ?? tìm v? trí cu?i cùng
		}
		else if (a[mid].namSinh > namSinh)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}

void Xuat_TKNP_Theo_NamSinh(int namSinh, SinhVien a[MAX], int n, int kq) 
{
	if (kq == -1) 
		cout << "\nKhong co sinh vien trong danh sach co nam sinh = " << namSinh << ":\n";
	else 
	{
		cout << "\nThong tin sinh vien trong danh sach co nam sinh = " << namSinh << ":\n";
		TieuDe();
		Xuat1SV(a[kq]);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 54; i++)
			cout << '=';
		cout << ':';
	}
}

int KiemTraDayTang_DTB(SinhVien a[MAX], int n) 
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].dtb > a[i + 1].dtb)
			return 0; // Không t?ng
	return 1; // T?ng
}

int KiemTraDayGiam_DTB(SinhVien a[MAX], int n) 
{
	for (int i = 0; i < n - 1; i++)
		if (a[i].dtb < a[i + 1].dtb)
			return 0; // Không gi?m
	return 1; // Gi?m
}

void TKNP_Theo_DTB(SinhVien a[MAX], int n) 
{
	if (!KiemTraDayTang_DTB(a, n) && !KiemTraDayGiam_DTB(a, n)) {
		cout << "\nDanh sach sinh vien khong duoc sap xep don dieu theo diem trung binh";
		cout << "\nKhong su dung duoc thuat toan tim kiem nhi phan\n";
		return;
	}

	double dtb;
	cout << "\nNhap diem trung binh can tim: ";
	cin >> dtb;
	int kq;

	if (KiemTraDayTang_DTB(a, n)) 
	{
		kq = TKNP_Tang_DTB(a, n, dtb);
		Xuat_TKNP_Theo_DTB(dtb, a, n, kq);
	}

	if (KiemTraDayGiam_DTB(a, n)) 
	{
		kq = TKNP_Giam_DTB(a, n, dtb);
		Xuat_TKNP_Theo_DTB(dtb, a, n, kq);
	}
}

int TKNP_Tang_DTB(SinhVien a[MAX], int n, double dtb) 
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (a[mid].dtb == dtb) 
		{
			kq = mid;  // Ghi nh?n v? trí
			left = mid + 1; // Tìm ti?p bên ph?i ?? tìm v? trí cu?i cùng
		}
		else if (a[mid].dtb < dtb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}

int TKNP_Giam_DTB(SinhVien a[MAX], int n, double dtb) 
{
	int left = 0, right = n - 1;
	int kq = -1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (a[mid].dtb == dtb) 
		{
			kq = mid;  // Ghi nh?n v? trí
			right = mid - 1; // Tìm ti?p bên trái ?? tìm v? trí cu?i cùng
		}
		else if (a[mid].dtb > dtb)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return kq;
}

void Xuat_TKNP_Theo_DTB(double dtb, SinhVien a[MAX], int n, int kq) 
{
	if (kq == -1) 
		cout << "\nKhong co sinh vien trong danh sach co diem trung binh = " << dtb << ":\n";
	else 
	{
		cout << "\nThong tin sinh vien trong danh sach co diem trung binh = " << dtb << ":\n";
		TieuDe();
		Xuat1SV(a[kq]);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 54; i++)
			cout << '=';
		cout << ':';
	}
}