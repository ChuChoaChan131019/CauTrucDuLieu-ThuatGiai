void XuatMenu()
{
	cout << "\n=======================================Menu===============================================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao danh sach tu file";
	cout << "\n2.Xem danh sach sinh vien";
	cout << "\n3.Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc va nam sinh < x";
	cout << "\n4.Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc";
	cout << "\n5.Chon truc tiep sap danh sach tang dan theo nam sinh";
	cout << "\n6.Quick sort sap danh sach giam dan theo diem trung binh ";
	cout << "\n7.Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc";
	cout << "\n8.Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc";
	cout << "\n9.Radix sort sap danh sach giam dan theo ten";
	cout << "\n10.Thong ke diem TB theo loai";
	cout << "\n==========================================================================================";
}
int ChonMenu(int somenu)
{
	int so;
	for (;;)
	{
		XuatMenu();
		cout << "\nChon chuc nang (0..." << somenu << "):"; cin >> so;
		if (0 <= so && so <= somenu)
			break;
	}
	return so;
}
void XLMenu(int menu, SinhVien a[MAX], int& n)
{
	char filename[MAX], ho[10], ten[10]; 
	int kq,nam;
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		system("CLS");
		cout << "\n1.Tao danh sach tu file";
		do
		{
			cout << "\nNhap file (ban co file Text.txt):"; cin >> filename;
			kq = TaoDL(filename, a, n);
			if (!kq)
				cout << "\nLoi!!! Moi nhap lai";
		} while (!kq);
		XuatDSSV(a, n);
		break;
	case 2:
		system("CLS");
		cout << "\n2.Xem danh sach sinh vien";
		XuatDSSV(a, n);
		break;
	case 3:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n3.Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc va nam sinh < x";
		cout << "\nNhap ho: ";
		cin >> ho;
		cout << "\nNhap ten: ";
		cin >> ten;
		cout << "\nNhap nam sinh: ";
		cin >> nam;
		TKTT_TrungHoTen_TheoNam(a, n, ho, ten, nam);
		cout << endl;
		break;
	case 4:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n4.Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc";
		cout << "\nNhap ten can tim : ";
		cin >> ten;
		kq=TKTT_LC_TheoTen(a, n, ten);
		cout << "\nSinh vien co ten "<<ten<<" duoc tim thay dau tien tai vi tri: " << kq<<endl;
		break;
	case 5:
		system("CLS");
		cout << "Danh sach ban dau:\n";
		XuatDSSV(a, n);
		cout << "\n5.Chon truc tiep sap danh sach tang dan theo nam sinh\n";
		cout << "Danh sach sau khi xep:\n";
		ChonTT_TangNam(a, n);
		XuatDSSV(a, n);
		break;
	case 6:
		system("CLS");
		cout << "Danh sach ban dau:\n";
		XuatDSSV(a, n);
		cout << "\n6.Quick sort sap danh sach giam dan theo diem trung binh ";
		QuickSort_GiamDTB(a, n);
		XuatDSSV(a, n);
		break;
	case 7:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n7.Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc";
		ChonTT_TangNam(a, n);
		TKNP_Theo_NamSinh(a, n);
		break;
	case 8:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n8.Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc";
		QuickSort_GiamDTB(a, n);
		TKNP_Theo_DTB(a, n);
		break;
	case 9:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n9.Radix sort sap danh sach giam dan theo ten";
		break;
	case 10:
		system("CLS");
		XuatDSSV(a, n);
		cout << "\n10.Thong ke diem TB theo loai";
		break;
	}
}