void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, SinhVien a[MAX], int& n);

void XuatMenu()
{
	cout << "=============================================MENU=============================================";
	cout << "\n0. Thoat";
	cout << "\n1. Tao danh sach tu file";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc va nam sinh < x";
	cout << "\n4. Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc";
	cout << "\n5. Chon truc tiep sap tang theo nam sinh";
	cout << "\n6. Chen truc tiep sap tang theo ho, ten sinh vien";
	cout << "\n7. Quick sort sap giam theo diem trung binh";
	cout << "\n8. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc";
	cout << "\n9. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc";
	cout << "\n==============================================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0..." << soMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, SinhVien a[MAX], int& n)
{
	int kq, namSinh;
	char filename[MAX], ho[10], ten[10];
	SinhVien b[MAX];
	Copy(b, a, n);
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat";
		break;

	case 1:
		cout << "\n1. Tao danh sach tu file";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = Tap_Tin(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		XuatDSSV(a, n);
		cout << endl;
		break;

	case 2:
		cout << "\n2. Xem danh sach sinh vien";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		XuatDSSV(a, n);
		cout << endl;
		break;

	case 3:
		cout << "\n3. Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc va nam sinh < x";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		XuatDSSV(a, n);
		cout << "\nNhap ho: ";
		cin >> ho;
		cout << "\nNhap ten: ";
		cin >> ten;
		cout << "\nNhap nam sinh: ";
		cin >> namSinh;
		Tim_Ho_Ten_NamSinh(a, n, ho, ten, namSinh);
		cout << endl;
		break;

	case 4:
		cout << "\n4. Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		XuatDSSV(a, n);
		cout << "\nNhap ten: ";
		cin >> ten;
		kq = Tim_Ten_LinhCanh(a, n, ten);
		if (kq != -1)
		{
			cout << "\nSinh vien dau tien co ten '" << ten << "' o chi so: " << kq;
			cout << endl;
			cout << "\nThong tin sinh vien:\n";
			TieuDe();
			{
				Xuat1SV(a[kq]);
				cout << endl;
			}
			cout << ':';
			for (int i = 1; i <= 54; i++)
				cout << '=';
			cout << ':';
		}
		else
			cout << "\nKhong tim thay sinh vien co ten '" << ten << "' trong danh sach.";
		break;

	case 5:
		cout << "\n5. Chon truc tiep sap tang theo nam sinh";
		cout << "\nDanh sach truoc khi sap:\n";
		XuatDSSV(a, n);
		cout << "\nDanh sach sau khi sap:\n";
		SelectionSort(b, n);
		XuatDSSV(b, n);
		break;

	case 6:
		cout << "\n6. Chen truc tiep sap tang theo ho, ten sinh vien";
		cout << "\nDanh sach truoc khi sap:\n";
		XuatDSSV(a, n);
		cout << "\nDanh sach sau khi sap:\n";
		InsertionSort(b, n);
		XuatDSSV(b, n);
		break;

	case 7:
		cout << "\n7. Quick sort sap giam theo diem trung binh";
		cout << "\nDanh sach truoc khi sap:\n";
		XuatDSSV(a, n);
		cout << "\nDanh sach sau khi sap:\n";
		QuickSort(b, n);
		XuatDSSV(b, n);
		break;

	case 8:
		cout << "\n8. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		SelectionSort(a, n);
		XuatDSSV(a, n);
		TKNP_Theo_NamSinh(a, n);
		break;

	case 9:
		cout << "\n9. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc";
		QuickSort(a, n);
		XuatDSSV(a, n);
		TKNP_Theo_DTB(a, n);
		break;
	}
	(void)_getch();
}