#define MAX 100

int TaoFile(char* filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}

void Xuat(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
//void Buble_R(int a[MAX], int n)
//{
//	int i, j;
//	for (j = n - 1; j > 0; j--)
//	{
//		for (i = 0; i < n - 1; i++)
//			if (a[i] < a[i + 1])
//				HoanVi(a[i + 1], a[i]);
//		cout << "\nBuoc " << n - j << " : ";
//		Output(a, n);
//		cout << "\n";
//	}
//	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
//}

void HoanVi(int& a, int& b)
{
	int an = a;
	a = b;
	b = an;
}

void ChonTT_GTNN(int a[MAX], int n)
{
	int i, j,min;
	for (i = 1; i < n-1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		HoanVi(a[i], a[min]);
		cout << "\nBuoc " << i << " : ";
				Xuat(a, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
}

void Chon2Dau(int a[MAX], int n)
{
	int i, j, min, max;
	for (i = 0; i < n / 2; i++)
	{
		min = i;
		max = n - 1 - i;
		for (j = i; j <= n - 1 - i; j++)
		{
			if (a[j] < a[min])
				min = j;
			if (a[j] > a[max])
				max = j;
		}
		if (min == n - i - 1)
		{
			HoanVi(a[i], a[min]);
			if (max != i)
				HoanVi(a[max], a[n - i - 1]);
		}
		else
		{
			HoanVi(a[max], a[n - i - 1]);
			HoanVi(a[i], a[min]);
		}
	}
}
void ChenTT_DayTang(int a[MAX], int n)
{
	int i, x, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		for (j = i - 1; (j >= 0) && (a[j] > x); j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}
void ChenTT_DayGiam(int a[MAX], int n)
{
	int i, x, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		for (j = i - 1; (j >= 0) && (a[j] < x); j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}
void DoiChoTT_GTNN(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				HoanVi(a[i], a[j]);
		cout << "\nBuoc " << i << " : ";
		Xuat(a, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
}
void DoiChoTT_GTLN(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				HoanVi(a[i], a[j]);
		cout << "\nBuoc " << i << " : ";
		Xuat(a, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
}
