#define MAX 100

typedef int duLieu;

struct tagNode
{
	duLieu info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};



NODE* GetNode(duLieu x);
void CreateList(LIST& l);
int IsEmpty(LIST l);
int TaoDL(char* f, LIST& l);
void XuatDS(LIST l);
void AddTail(LIST& l, NODE* new_ele);
void ChenCuoi(LIST& l, duLieu x);



NODE* GetNode(duLieu x)
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

void CreateList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}


int TaoDL(char* f, LIST& l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateList(l);
	duLieu x;
	while (!in.eof())
	{
		in >> x;
		ChenCuoi(l,x);
	}
	in.close();
	return 1;
}

void XuatDS(LIST l)
{
	NODE* p;
	if (IsEmpty(l))
	{
		cout << "\nDS rong!\n";
		return;
	}
	p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}
void AddTail(LIST& l, NODE* new_ele)
{
	if (IsEmpty(l))
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}
void ChenCuoi(LIST& l, duLieu x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

int TimMax(LIST l)
{
	NODE* p;
	int max = 0;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info > max)
		{
			max = p->info;
		}
		p = p->pNext;
	}
	return max;

	
}
int TimMin(LIST l)
{
	NODE* p;
	int min = INT_MAX;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info < min)
		{
			min = p->info;  
		}
		p = p->pNext; 
	}
	return min;

}
