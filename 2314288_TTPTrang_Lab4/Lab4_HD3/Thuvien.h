#define MAX 100

struct nhanVien
{
	char maNV[8];
	char ho[10];
	char tenLot[10];
	char ten[10];
	char diaChi[15];
	int nSinh;
	double luong;

};

typedef nhanVien Data;
struct tagNode
{
	Data info;
	tagNode* pNext;
};
typedef tagNode NODE;
struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

//khai bao nguyen mau
NODE* GetNode(Data x);
void TaoRong(LIST& l);
int KTRong(LIST& l);
void ChenXDau(LIST& l, Data x);
void ChenXCuoi(LIST& l, Data x);
int TaoDL(char* f, LIST& l);
void XuatTieuDe();
void Xuat_NV(Data p);
void  XuatDSNV(LIST& l); 
void TachLuong_x(LIST l, double x);
void Tach_LuanPhien(LIST l);
void DaoNguoc_DS(LIST l);
void Hoanvi(nhanVien& a, nhanVien& b);
void SelectionSort(LIST& l);
void SapTang_TenHoTLot(LIST& l);





NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void TaoRong(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int KTRong(LIST& l)
{
	return l.pHead == NULL;

}
void ChenXDau(LIST& l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}
void ChenXCuoi(LIST& l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}
int TaoDL(char* f,LIST& l)
{
	Data x;
	ifstream in(f);
	if (!in)
		return 0;
	TaoRong(l);
	while (!in.eof())
	{
		in >> x.maNV;
		in >> x.ho;
		in >> x.tenLot;
		in >> x.ten;
		in >> x.diaChi;
		in >> x.nSinh;
		in >> x.luong;
		ChenXCuoi(l, x);
	}
	in.close();
	return 1;
}

void XuatTieuDe() 
{
	int i;
	cout << endl;
	cout << ':';
	for (i = 1; i <= 78; i++)
		cout << '=';
	cout << ':' << endl;
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(10) << "Ma NV"
		<< ':'
		<< setw(11) << "Ho"
		<< setw(11) << "Ten lot"
		<< setw(11) << "Ten"
		<< ':'
		<< setw(15) << "Dia chi"
		<< ':'
		<< setw(6) << "Nam Sinh"
		<< ':'
		<< setw(8) << "Luong"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i <= 78; i++)
		cout << '=';
	cout << ':'<<endl;
}
void Xuat_NV(Data p)
{
	cout << ':';
	cout << setiosflags(ios::left);
	cout << setw(10) << p.maNV
		<< ':'
		<< setw(11) << p.ho
		<< setw(11) << p.tenLot
		<< setw(11) << p.ten
		<< ':'
		<< setw(15) << p.diaChi
		<< ':'
		<< setw(8) << p.nSinh
		<< ':'
		<< setw(8) <<setiosflags(ios::fixed)<<setprecision(0)<< p.luong
		<< ':';
	cout << endl;
}
void  XuatDSNV(LIST& l)
{
	NODE* p = l.pHead;
	XuatTieuDe();
	while (p != NULL)
	{
		Xuat_NV(p->info);
		p = p->pNext;
	}
	cout << endl;
}
void TachLuong_x(LIST l, double x)
{
	NODE* p;
	LIST l1, l2;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	TaoRong(l1);
	TaoRong(l2);
	while (p != NULL)
	{
		if (p->info.luong <= x)
			ChenXCuoi(l1, p->info);
		else
			ChenXCuoi(l2, p->info);
		p = p->pNext;
	}
	cout << "\n- Danh sach 1 (luong <= " << x << "):\n";
	XuatDSNV(l1);
	cout << "\n- Danh sach 2 (luong > " << x << "):\n";
	XuatDSNV(l2);
	cout << endl;
}
void Tach_LuanPhien(LIST l)
{
	NODE* p;
	LIST l1, l2;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS  rong";
		system("PAUSE");
		return;
	}
	int k = 1; 
	TaoRong(l1);
	TaoRong(l2);
	while (p != NULL)
	{
		if (k == 1)
			ChenXCuoi(l1, p->info);
		else
			ChenXCuoi(l2, p->info);
		p = p->pNext;
		k = 3 - k;
	}
	cout << "\n- Danh sach 1:\n";
	XuatDSNV(l1);
	cout << "\n- Danh sach 2 :\n";
	XuatDSNV(l2);
	cout << endl;
}
void DaoNguoc_DS(LIST l)
{
	NODE* p;
	LIST l1;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	TaoRong(l1);
	while (p != NULL)
	{
		ChenXDau(l1, p->info);
		p = p->pNext;
	}
	cout << "\n- Danh sach dao nguoc :\n";
	XuatDSNV(l1);
}

void Hoanvi(nhanVien& a, nhanVien& b)
{
	nhanVien x;
	x = a;
	a = b;
	b = x;
}

void SelectionSort(LIST& l)
{
	NODE* min;
	NODE* p, * q;
	p = l.pHead;
	while (p != l.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (_strcmpi(q->info.ten, min->info.ten) < 0)
				min = q;
			q = q->pNext;
		}
		Hoanvi(min->info, p->info);
		p = p->pNext;
	}
}
void SapTang_TenHoTLot(LIST& l)
{
	SelectionSort(l);
	NODE* p, * q;
	for (p = l.pHead; p != l.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->info.ten, q->info.ten) == 0)
				if (_strcmpi(p->info.ho, q->info.ho) > 0)
					Hoanvi(q->info, p->info);

	for (p = l.pHead; p != l.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->info.ten, q->info.ten) == 0 && _strcmpi(p->info.ho, q->info.ho) == 0)
				if (_strcmpi(p->info.tenLot, q->info.tenLot) > 0)
					Hoanvi(q->info, p->info);
}