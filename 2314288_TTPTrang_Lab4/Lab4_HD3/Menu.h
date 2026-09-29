
void XuatMenu()
{
	cout << "===============================menu===============================";
	cout << "\n0. Thoat chuong trinh.";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tach danh sach thanh danh sach gom nhan vien co luong <=x\nva danh sach nhan vien con lai";
	cout << "\n4. Tach danh sach luan phien theo thu tu";
	cout << "\n5. Dao nguoc danh sach";
	cout << "\n6. Sap tang theo ten, ten trung thi tang theo ho, ho ten trung\nthi tang theo ten lot";
	cout << "\n================================================================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap so de chon chuc nang tuong ung: ";
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
	double luong;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TaoDL(filename, l);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		XuatDSNV(l);
		cout << endl;
		break;
	case 2:
		cout << "\n2. Xem du lieu";
		XuatDSNV(l);
		break;
	case 3:

		cout << "\n3. Tach danh sach thanh danh sach gom nhan vien co luong <=x va danh sach nhan vien con lai";
		cout << "\nDanh sach ban dau:\n";
		XuatDSNV(l);
		cout << "Nhap luong de tach :"; cin >> luong;
		TachLuong_x(l, luong);
		break;
	case 4:
		cout << "\n4. Tach danh sach luan phien theo thu tu";
		cout << "\nDanh sach ban dau:\n";
		XuatDSNV(l);
		Tach_LuanPhien(l);
		break;
	case 5:
		cout << "\n5. Dao nguoc danh sach";
		cout << "\nDanh sach ban dau:\n";
		XuatDSNV(l);
		DaoNguoc_DS(l);
		break;
	case 6:
		cout << "\n6. Sap tang theo ten, ten trung thi tang theo ho, ho ten trung\thi tang theo ten lot";
		cout << "\nDanh sach ban dau:\n";
		XuatDSNV(l);
		SapTang_TenHoTLot(l);
		XuatDSNV(l);

		break;
	}
}