void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n=============================== Menu =============================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ma sinh vien";
	cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
	cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
	cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc";
	cout << "\n7. Tim kiem theo lop-Xuat danh sach sinh vien trong lop";
	cout << "\n8. Tim kiem nhi phan theo tich luy (neu truong tich luy co thu tu)";
	cout << "\n==================================================================";

}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	double dtb;
	char an[10];
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach sinh vien";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TaoTapTin(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo ma sinh vien";
		Xuat_DSSV(a,n);
		cout << "\nNhap ma sinh vien can tin:";; cin >> an;
		kq = Tim_MSSV(an, a, n);
		if (kq == -1)
			cout << endl << "Khong co sinh vien co ma so "<<an;
		else
		{
			cout << endl << " sinh vien co ma so: " << an << "la\n"; Xuat_SV(a[kq]);
			
		}
		cout << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
		Xuat_DSSV(a, n);
		cout << "\nNhap ten sinh vien can tim:";; cin >> an;
		Tim_Ten(an, a, n);
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
		Xuat_DSSV(a, n);
		cout << "\nNhap ho sinh vien can tim:";; cin >> an;
		Tim_Ho(an, a, n);
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc\n";
		Xuat_DSSV(a, n);
		cout << "\nNhap DTB can tim:";; cin >> dtb;
		Tim_DTB(dtb, a, n);
		cout << endl;
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo lop--Xuat cac sinh vien thuoc lop\n";
		Xuat_DSSV(a, n);
		cout << "\nNhap ho sinh vien can tim:";; cin >> an;
		Tim_Lop(an, a, n);
		cout << endl;
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kien nhi phan theo tich luy";
		Xuat_DSSV(a, n);
		TKNP_Theo_TichLuy(a, n);
		break;
	}
}