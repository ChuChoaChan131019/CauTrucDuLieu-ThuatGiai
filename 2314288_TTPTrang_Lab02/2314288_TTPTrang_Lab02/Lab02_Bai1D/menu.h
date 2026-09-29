void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMemu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n=========================== He thong chuc nang==========================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co(Co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
	cout << "\n6. Tra ve tat ca chi so i neu co.";
	cout << "\n========================================================================";

}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMemu(int menu, int a[MAX], int& n)
{
	int kq,x;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh";
		break;
	case 1:
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_mang1c(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu";
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x can tim: ";
		cin >> x;
		kq = TKTT_DauTien(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong xuat hien trong mang";
		else
			cout << endl << x << " xuat hien trong mang tai vi tri dau tien la : " << kq;
		cout << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co(Co linh canh)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x can tim: ";
		cin >> x;
		kq = TKTT_DauTien_LC(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong xuat hien trong mang";
		else
			cout << endl << x << " xuat hien trong mang tai vi tri dau tien la : " << kq;
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x can tim: ";
		cin >> x;
		kq = TKTT_CuoiCung(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong xuat hien trong mang";
		else
			cout << endl << x << " xuat hien trong mang tai vi tri cuoi cung la : " << kq;
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Tra ve tat ca chi so i neu co.";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x can tim: ";
		cin >> x;
		TKTT_AllChiSo(a, n, x);
		break;


	}
}