#define MAX 100

struct Nhanvien
{
	char ma[10];
	char ho[10];
	char tenLot[10];
	char ten[10]; 
	int namSinh;
	double hsl;
};
typedef Nhanvien Data;

struct tagNode
{
	Data info;
	tagNode* pNext;
};
typedef tagNode Node;

struct List
{
	Node* pHead;
	Node* pTail;
};
void ChonTT_nam(List& ds);

Node* GetNode(Data nv)
{
	Node* p = new Node;
	if (p != NULL)
	{
		p->info = nv;
		p->pNext = NULL;
	}
	return p;
}

void CreatList(List& ds)
{
	ds.pHead = ds.pTail = NULL;
}

int IsEmpty(List ds)
{
	if (ds.pHead != NULL)
		return 1;
	return 0;
}

void InsertTail(List& ds,Data nv)
{
	Node* new_nv = GetNode(nv);
	if (new_nv == NULL)
	{
		cout << "Loi";
		return ;
	}
	else if (ds.pHead == NULL)
	{
		ds.pHead = new_nv;
		ds.pTail = ds.pHead;
	}
	else
	{
		ds.pTail->pNext = new_nv;
		ds.pTail = new_nv;
	}
}

int DocFile(char* filename, List& ds)
{
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(ds);
	Data nv;
	while (!in.eof())
	{
		in >> nv.ma;
		in >> nv.ho;
		in >> nv.tenLot;
		in >> nv.ten;
		in >> nv.namSinh;
		in >> nv.hsl;
		InsertTail(ds, nv);
	}
	in.close();
	return 1;

}
void XuatTieuDe()
{
	int i;
	cout <<endl<< '|';
	for (i = 0; i < 70; i++)
		cout << "=";
	cout << '|'<<endl;
	cout << setiosflags(ios::left);
	cout << '|'
		<< setw(10) << "Ma nv"
		<< '|'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten lot"
		<< setw(10) << "Ten"
		<< '|'
		<< setw(10) << "Nam sinh"
		<< '|'
		<< setw(10) << "He so luong"
		<< '|'<<endl;
	cout << '|';
	for (i = 0; i < 70; i++)
		cout << "=";
	cout << '|' << endl;
}
void Xuat1NV(Data nv)
{
	cout << setiosflags(ios::left);
	cout << '|'
		<< setw(10) << nv.ma
		<< '|'
		<< setw(10) << nv.ho
		<< setw(10) << nv.tenLot
		<< setw(10) << nv.ten
		<< '|'
		<< setw(10) << nv.namSinh
		<< '|'
		<< setw(10) << nv.hsl
		<< '|' <<endl;
}
void XuatDSNV(List ds)
{
	XuatTieuDe();
	Node* p = ds.pHead;
	while (p!=NULL)
	{
		Xuat1NV(p->info);
		p = p->pNext;
	}
	cout <<endl<< '|';
	for (int i=0;i<70;i++)
		cout << "=";
	cout << '|' << endl;
}

int DemHSL(List ds,double x)
{
	Node* p=ds.pHead;
	int dem = 0;
	for (p; p != NULL; p = p->pNext)
	{
		if (p->info.hsl >= x)
			dem++;
	}
	return dem;
}
int TKTT_Cuoi(List ds, char ten[10])
{
	Node* p = ds.pHead;
	int pos = -1;
	int i = 0;
	while (p!=NULL)
	{
		if (_stricmp(p->info.ten, ten) == 0)
			pos = i;
		i++;
		p = p->pNext;
	}
	return pos;
}

Node* TimMa(List ds,char ma[10])
{
	Node* p = ds.pHead;
	while (p!=NULL)
	{
		if(_stricmp(p->info.ma, ma) == 0)
			p = p->pNext;
		else
		{
			cout << "Khong tim thay ma";
		}
	}
	return p;
}

void ChenSau(List& ds,Data nv,Node*y)
{
	Node* new_nv = GetNode(nv);
	if (new_nv == NULL)
	{
		cout << "Loi";
		return;
	}
	 if (y!=NULL)
	{
		 new_nv->pNext = y->pNext;
		 y->pNext = new_nv;
		 if (y == ds.pTail)
			 ds.pTail = new_nv;
	}
	 else
	 {
		 new_nv->pNext = y->pNext;
		 y->pNext = new_nv;
	 }
}
void ChenSauX(List& ds, char ma[10], Data x)
{
	Node* q = TimMa(ds, ma);
	ChenSau(ds, x,q);
}
//Data Nhap1NV(char ma[10], char ho[10], char tenLot[10], char ten[10], int namS, double hsLuong)
//{
//	Data x;
//
//}
void ChonTT_nam(List& ds)
{
	Node* min, * q, * p;
	p = ds.pHead;
	while (p != NULL)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.namSinh < min->info.namSinh)
				min = q;
			q = q->pNext;
		}
		swap(min->info, p->info);
		p = p->pNext;
	}

}

void ChenTT(List& ds)
{
	Node* pos, * i, * x;
	i = ds.pHead;
	while (i!=NULL)
	{
		x = i;
		pos = i - 1;
		while (pos!=NULL&&pos->info.namSinh>x->info.namSinh)
		{
			pos = pos->pNext;
			pos--;
		}
		pos->pNext = x;
	}
}
void DoiCho(List& ds)
{
	Node * q, * p = ds.pHead;
	while (p!=NULL)
	{
		q = p->pNext;
		while (q!=NULL)
		{
			if (p->info.namSinh > q->info.namSinh)
				swap(q->info, p->info);
				q = q->pNext;

		}

		p = p->pNext;
	}
}