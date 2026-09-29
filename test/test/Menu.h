void XuatMenu()
{
	cout << "=============================Menu=======================================";
	cout << "\n0.Thoat chuong trinh.";
	cout << "\n1.Nhap danh sach du lieu tu file.";
	cout << "\n2.Xuat danh sach";
	cout << "\n3.Dem so luong nhan vien co he so luong>=x";
	cout << "\n4.Tim kiem tuyen tinh theo ten nhan vien tra ve node cuoi cung";
	cout << "\n5.Chen them 1 nhan vien sau nhan vien co ma nhan vien nhap tu ban phim";
	cout << "\n6.Xoa tat ca nhan vien theo ten";
	cout << "\n7.Sap xep chon truc tiep tang theo nam sinh";
	cout << "\n======================================================================";
}

int ChonMenu(int soMenu)
{
	int chon;
	for (;;)
	{
		cout << "Nhap chon menu:"; cin >> chon;
		if (chon >= 0 && chon <= soMenu)
			break;
	}
	return chon;
}

void XuLyMenu(int menu, List& l)
{
	int kq;
	double x;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh.";
		break;
	case 1:
		cout << "\n1.Nhap danh sach du lieu tu file.";
		kq = DocFile((char*)"Text.txt", l);
		if (!kq)
			cout << "Loi";
		XuatDSNV(l);
		break;
	case 2:
		cout << "\n2.Xuat danh sach";
		XuatDSNV(l);
		break;
	case 3:
		cout << "\n3.Dem so luong nhan vien co he so luong>=x";
		XuatDSNV(l);
		cout << "\nNhap he so luong x : ";
		cin >> x;
		cout << "So luong nhan vien co he so luong >=" << x << ":"<<DemHSL(l,x);

		break;
	case 4:
		cout << "\n4.Tim kiem tuyen tinh theo ten nhan vien tra ve node cuoi cung";
		XuatDSNV(l);
		break;
	case 5:
		cout << "\n5.Chen them 1 nhan vien sau nhan vien co ma nhan vien nhap tu ban phim";
		XuatDSNV(l);
		break;
	case 6:
		cout << "\n6.Xoa tat ca nhan vien theo ten";
		XuatDSNV(l);
		break;
	case 7:
		cout << "\n7.Sap xep chon truc tiep tang theo nam sinh"; 
		XuatDSNV(l);
		DoiCho(l);
		cout << "Xuat:";
		XuatDSNV(l);

		break;
	default:
		break;
	}
}