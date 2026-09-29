void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "==========================Menu=======================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach";
	cout << "\n2. Xem danh sach";
	cout << "\n3. Tinh gia tri nho nhat";
	cout << "\n4. Tinh gia tri lon nhat";
	cout << "\n===================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap chon chuc nang: ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, LIST& l)
{
	char filename[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = TaoDL(filename, l);
			if (!kq)
				cout << "\nLoi!!! nhap lai\n";
		} while (!kq);
		XuatDS(l);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu\n";
		XuatDS(l);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Tinh gia tri nho nhat";
		cout << "\nDanh sach ban dau:\n";
		XuatDS(l);
		cout << "\nGia tri nho nhat trong danh sach la: " << TimMin(l) << endl;
		break;
	case 4:
		cout << "\n4. Tinh gia tri lon nhat";
		cout << "\nDanh sach ban dau:\n";
		XuatDS(l);
		cout << "\nGia tri lon nhat trong danh sach la: " << TimMax(l)<<endl;
		break;
	}
}

